using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Drawing.Imaging;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Бусыгина Татьяна, ИВТ-22

namespace ProducerAndConsumer
{
    /// <summary>
    /// Класс Consumer отвечает за извлечение путей к изображениям из очереди и применение к ним фильтра
    /// </summary>
    class Consumer
    {
        // Общая потокобезопасная очередь, из которой потребитель извлекает пути к изображениям
        private readonly BlockingCollection<string> queue;
        // Уникальный идентификатор потребителя
        private readonly int id;

        /// <summary>
        /// Конструктор, получает ссылку на очередь и уникальный ID потребителя
        /// </summary>
        /// <param name="queue">Потокобезопасная очередь с путями к изображениям</param>
        /// <param name="id">ID текущего потребителя</param>
        public Consumer(BlockingCollection<string> queue, int id)
        {
            this.queue = queue;
            this.id = id;
        }

        /// <summary>
        /// Потребитель извлекает пути из очереди, загружает изображения, применяет фильтр и сохраняет результат
        /// </summary>
        /// <param name="outputDir">Путь к выходной директории, где сохраняются обработанные изображения</param>
        public void Consume(string outputDir)
        {
            // Перебираем все элементы коллекции
            // Каждая итерация цикла будет присваивать переменной imagePath путь к изображению, полученному из очереди
            // GetConsumingEnumerable() возвращает перечисляемую коллекцию, которая блокирует поток, пока не будут добавлены
            // новые элементы или очередь не будет завершена. Это позволяет потребителю обрабатывать элементы по мере их поступления
            foreach (var imagePath in queue.GetConsumingEnumerable())
            {
                Console.WriteLine($"[Consumer {id}] Обработка: {Path.GetFileName(imagePath)}");
                // Открываем блок кода с автоматическим управлением ресурсами. Объект будет освобожден после завершения блока
                // Создаем новый объект Bitmap, загружая изображение из указанного пути
                using (var bmp = new Bitmap(imagePath))
                {
                    Filter.Apply(bmp); // Применение фильтра
                    // Извлечение имени файла из полного пути
                    string fileName = Path.GetFileName(imagePath);
                    // Создаем полный путь для сохранения обработанного изоб
                    // // Сохраняем измененное изображение в формате JPEG по указанному путиражения, объединяя директорию outputDir и имя файла fileName
                    string outputPath = Path.Combine(outputDir, fileName);
                    bmp.Save(outputPath, ImageFormat.Jpeg);
                }
                Console.WriteLine($"[Consumer {id}] Сохранено: {Path.GetFileName(imagePath)}");
            }
        }
    }
}
