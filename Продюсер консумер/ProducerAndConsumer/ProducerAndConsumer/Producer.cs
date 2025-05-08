using System;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

//Бусыгина Татьяна, ИВТ-22

namespace ProducerAndConsumer
{
    /// <summary>
    /// Класс Producer отвечает за чтение изображений из указанной директории
    /// и добавление их путей в потокобезопасную очередь для последующей обработки
    /// </summary>
    class Producer
    {
        // Очередь для обмена данными между между продюсером и консюмерами
        // Является закрытым полем класса, которое может быть инициализировано только в конструкторе или при объявлении, и её значение не может быть изменено после инициализации
        private readonly BlockingCollection<string> queue;

        /// <summary>
        /// Конструктор. Принимает общую очередь, в которую будут помещаться пути к изображениям.
        /// </summary>
        /// <param name="queue">Потокобезопасная очередь с ограниченной ёмкостью</param>
        public Producer(BlockingCollection<string> queue)
        {
            this.queue = queue;
        }

        /// <summary>
        /// Производитель перебирает изображения в папке и добавляет их пути в очередь
        /// </summary>
        /// <param name="inputDir">Путь к папке с изображениями</param>
        public void Produce(string inputDir)
        {
            foreach (var filePath in Directory.GetFiles(inputDir, "*.jpg"))
            {
                Console.WriteLine($"[Producer] Добавление: {Path.GetFileName(filePath)}");
                // Добавляем путь к файлу в очередь
                // Если очередь полна, поток будет заблокирован до освобождения места
                queue.Add(filePath);
                Thread.Sleep(100); // Искусственная задержка
            }
            // Сообщаем консюмерам, что больше элементов не будет
            queue.CompleteAdding();
        }
    }
}
