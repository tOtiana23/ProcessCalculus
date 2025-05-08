#pragma warning disable CA1416
using System;
using System.Collections.Concurrent; //пространство имен содержит классы, которые обеспечивают потокобезопасные коллекции
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Drawing;
using System.Drawing.Imaging;
using ProducerAndConsumer;

//Бусыгина Татьяна, ИВТ-22

//1. Дописала комменты к продюсеру и консумеру
//2. Вынесла применение фильтра в отдельную функцию
//3. Можно выбрать папку с картиночками и для картиночек
//4. всё по отдельным файлам

/// <summary>
/// Главный класс приложения
/// </summary>
class Program
{

    // BlockingCollection позволяет нескольким потокам безопасно добавлять и извлекать элементы
    // Если коллекция достигает своей максимальной емкости(если она ограничена), операции добавления будут блокироваться до тех пор, пока не освободится место
    // Если коллекция пуста, операции извлечения будут блокироваться до тех пор, пока не появится новый элемент

    /// <summary>
    /// Потокобезопасная очередь
    /// Максимальное кол-во элементов: 10. Если коллекция заполнена, то попытка добавления новых элементов будет блокироваться, пока не освободится место
    /// </summary>
    static BlockingCollection<string> imageQueue = new BlockingCollection<string>(10);

    static void Main()
    {
        // Запрос путей у пользователя
        Console.Write("Введите путь к папке с входными изображениями (Enter для значения по умолчанию): ");
        string inputDir = Console.ReadLine();
        if (string.IsNullOrWhiteSpace(inputDir)) inputDir = "input_images";

        Console.Write("Введите путь к папке для сохранения выходных изображений (Enter для значения по умолчанию): ");
        string outputDir = Console.ReadLine();
        if (string.IsNullOrWhiteSpace(outputDir)) outputDir = "output_images";

        // Проверяем, существует ли папка с входными изображениями
        if (!Directory.Exists(inputDir))
        {
            Console.WriteLine($"Папка не найдена: {inputDir}");
            return;
        }

        // Создаём выходную директорию, если она ещё не существует
        Directory.CreateDirectory(outputDir);

        // Создаём объект продюсера, передаём ему общую очередь
        var producer = new Producer(imageQueue);

        // Создается новая задача, которая запускает Producer в отдельном потоке
        // Он будет сканировать папку и добавлять изображения в очередь
        // Task.Run используется для выполнения метода асинхронно в отдельном потоке, основная программа выполняется, не дожидаясь завершения метода.
        // Он создает и запускает новую задачу в пуле потоков. Это позволяет выполнять код в фоновом режиме, не блокируя основной поток выполнения программы
        Task producerTask = Task.Run(() => producer.Produce(inputDir));

        // Получаем количество логических процессоров для создания потребителей
        int consumerCount = Environment.ProcessorCount;
        // Создаём массив задач для консюмеров, который будет хранить ссылки на задачи потребителей
        Task[] consumers = new Task[consumerCount];
        // Запускаем нужное количество консюмеров — каждый в своём потоке
        for (int i = 0; i < consumerCount; i++)
        {
            var consumer = new Consumer(imageQueue, i); // передаём номер для логирования
            // Создается новая задача для каждого потребителя, которая запускает метод Consumer
            consumers[i] = Task.Run(() => consumer.Consume(outputDir));
        }
        // Метод блокирует выполнение текущего потока, пока все задачи consumers не завершат свою работу
        Task.WaitAll(consumers);
        Console.WriteLine("Обработка завершена.");
    }
}
