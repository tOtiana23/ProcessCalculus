using System;
using System.IO;
using System.Linq;
using System.Threading;
using static System.Runtime.InteropServices.JavaScript.JSType;

// Бусыгина Татьяна, ИВТ-22

class Program
{
    static void Main()
    {
        Console.Write("Введите путь к папке с изображениями: ");
        string inputDir = Console.ReadLine();

        if (!Directory.Exists(inputDir))
        {
            Console.WriteLine("Папка не найдена.");
            return;
        }

        // Создаем новый путь к папке output, которая будет находиться внутри inputDir
        // Path.Combine создает новый путь к директории, комбинируя два компонента
        string outputDir = Path.Combine(inputDir, "output");
        Directory.CreateDirectory(outputDir);

        // Directory.GetFiles(...) — метод, который возвращает массив путей ко всем файлам в папке
        // Where фильтрует коллецию по условию. Отбираются файлы только с расширением .jpg, .png
        // f => — лямбда - выражение, где f — это путь к одному из файлов
        // ToArray преобразует полученную после фильтрации последовательность в массив строк
        // В конце надо делать ToArray, т.к. после фильтрации результат уже не массив, а объект IEnumerable<string>
        string[] imageFiles = Directory.GetFiles(inputDir, "*.*")
            .Where(f => f.EndsWith(".jpg") || f.EndsWith(".png"))
            .ToArray();

        if (imageFiles.Length == 0)
        {
            Console.WriteLine("Нет изображений в папке.");
            return;
        }

        Console.WriteLine($"Найдено {imageFiles.Length} изображений");

        int remaining = imageFiles.Length; // Для отслеживания, сколько файлов удалось обработать

        foreach (string file in imageFiles)
        {
            // Для каждого изображения создаётся задача в пуле потоков
            // ThreadPool.QueueUserWorkItem(...) ставит задачу в очередь на выполнение в одном из свободных потоков пула
            // Как аргумент передаем лямбда-функцию, которая будет выполнена в одном из потоков
            ThreadPool.QueueUserWorkItem(state =>
            {
                // Вызов метода обработки изображения
                ImageProcessor.ApplyFilter(file, outputDir, ImageProcessor.EngravingFilter);

                // Уменьшаем значение remaining атомарно, чтобы избежать ошибок
                // Interlocked.Decrement одновременно:
                // Захватывает значение,
                // Уменьшает его на 1,
                // Записывает обратно,
                // Возвращает новое значение
                // Всё это делается без возможности прерывания другими потокам
                if (Interlocked.Decrement(ref remaining) == 0)
                {
                    Console.WriteLine("Обработка завершена.");
                }
            });
        }

        Console.WriteLine("Идет обработка...");
        Console.ReadLine();
    }
}
