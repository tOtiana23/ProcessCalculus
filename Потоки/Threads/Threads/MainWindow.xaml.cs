using System;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;

namespace Threads
{
    public partial class MainWindow : Window
    {
        private CancellationTokenSource _cancellationTokenSource; // Для отмены фоновой задачи

        public MainWindow()
        {
            InitializeComponent();
        }

        // Сортировка через пул потоков
        private void ThreadPoolSortButton_Click(object sender, RoutedEventArgs e)
        {
            if (!int.TryParse(ArraySizeTextBox.Text, out int arraySize) || arraySize <= 0)
            {
                MessageBox.Show("Пожалуйста, введите положительное число для размера массива.");
                return;
            }

            // Блокируем кнопки, но разрешаем отмену
            MainThreadButton.IsEnabled = false;
            BackgroundThreadButton.IsEnabled = false;
            CancelButton.IsEnabled = true;

            StatusText.Text = "Сортировка через пул потоков...";
            ProgressBar.Value = 0;

            // Генерируем массив
            int[] array = GenerateRandomArray(arraySize);

            // Создаем токен для отмены
            _cancellationTokenSource = new CancellationTokenSource();

            // Используем пул потоков для сортировки
            ThreadPool.QueueUserWorkItem(_ =>
            {
                try
                {
                    MergeSortWithProgress(array, new Progress<int>(percent =>
                    {
                        Dispatcher.Invoke(() =>
                        {
                            ProgressBar.Value = percent;
                            StatusText.Text = $"Сортировка... {percent}%";
                        });
                    }), _cancellationTokenSource.Token);

                    // После завершения обновляем UI
                    Dispatcher.Invoke(() =>
                    {
                        ProgressBar.Value = 100;
                        StatusText.Text = _cancellationTokenSource.IsCancellationRequested
                            ? "Сортировка отменена!"
                            : "Сортировка завершена через пул потоков!";
                        MainThreadButton.IsEnabled = true;
                        BackgroundThreadButton.IsEnabled = true;
                        CancelButton.IsEnabled = false;
                    });
                }
                catch (OperationCanceledException)
                {
                    Dispatcher.Invoke(() =>
                    {
                        ProgressBar.Value = 0;
                        StatusText.Text = "Сортировка отменена!";
                        MainThreadButton.IsEnabled = true;
                        BackgroundThreadButton.IsEnabled = true;
                        CancelButton.IsEnabled = false;
                    });
                }
            });
        }

        // Отмена сортировки
        private void CancelButton_Click(object sender, RoutedEventArgs e)
        {
            _cancellationTokenSource?.Cancel();
            CancelButton.IsEnabled = false;
        }

        // Генерация случайного массива
        private int[] GenerateRandomArray(int size)
        {
            Random random = new Random();
            int[] array = new int[size];
            for (int i = 0; i < size; i++)
            {
                array[i] = random.Next(0, 10000);
            }
            return array;
        }

        // Сортировка слиянием с отображением прогресса
        private void MergeSortWithProgress(int[] array, IProgress<int> progress, CancellationToken cancellationToken = default)
        {
            MergeSort(array, 0, array.Length - 1, progress, cancellationToken);
        }

        private void MergeSort(int[] array, int left, int right, IProgress<int> progress, CancellationToken cancellationToken)
        {
            if (left < right)
            {
                int mid = (left + right) / 2;

                // Рекурсивно сортируем две половины
                MergeSort(array, left, mid, progress, cancellationToken);
                MergeSort(array, mid + 1, right, progress, cancellationToken);

                // Объединяем отсортированные половины
                Merge(array, left, mid, right);

                // Отправляем прогресс
                cancellationToken.ThrowIfCancellationRequested();
                progress.Report((int)((double)(right - left + 1) / array.Length * 100));
            }
        }

        private void Merge(int[] array, int left, int mid, int right)
        {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            int[] leftArray = new int[n1];
            int[] rightArray = new int[n2];

            Array.Copy(array, left, leftArray, 0, n1);
            Array.Copy(array, mid + 1, rightArray, 0, n2);

            int i = 0, j = 0, k = left;
            while (i < n1 && j < n2)
            {
                if (leftArray[i] <= rightArray[j])
                {
                    array[k++] = leftArray[i++];
                }
                else
                {
                    array[k++] = rightArray[j++];
                }
            }

            while (i < n1)
            {
                array[k++] = leftArray[i++];
            }

            while (j < n2)
            {
                array[k++] = rightArray[j++];
            }
        }
        // Обработчик для кнопки сортировки в основном потоке
        private void MainThreadButton_Click(object sender, RoutedEventArgs e)
        {
            if (!int.TryParse(ArraySizeTextBox.Text, out int arraySize) || arraySize <= 0)
            {
                MessageBox.Show("Пожалуйста, введите положительное число для размера массива.");
                return;
            }

            StatusText.Text = "Сортировка в основном потоке...";
            ProgressBar.Value = 0;

            // Генерируем массив
            int[] array = GenerateRandomArray(arraySize);

            // Запускаем сортировку синхронно
            MergeSortWithProgress(array, new Progress<int>(percent =>
            {
                ProgressBar.Value = percent;
                StatusText.Text = $"Сортировка... {percent}%";
            }));

            // Завершаем
            ProgressBar.Value = 100;
            StatusText.Text = "Сортировка завершена в основном потоке!";
            MainThreadButton.IsEnabled = true;
            BackgroundThreadButton.IsEnabled = true;
        }

        // Обработчик для кнопки сортировки в фоновом потоке
        private void BackgroundThreadButton_Click(object sender, RoutedEventArgs e)
        {
            if (!int.TryParse(ArraySizeTextBox.Text, out int arraySize) || arraySize <= 0)
            {
                MessageBox.Show("Пожалуйста, введите положительное число для размера массива.");
                return;
            }

            MainThreadButton.IsEnabled = false;
            BackgroundThreadButton.IsEnabled = false;
            CancelButton.IsEnabled = true;

            StatusText.Text = "Сортировка в фоновом потоке...";
            ProgressBar.Value = 0;

            int[] array = GenerateRandomArray(arraySize);
            _cancellationTokenSource = new CancellationTokenSource();

            Task.Run(() =>
            {
                try
                {
                    MergeSortWithProgress(array, new Progress<int>(percent =>
                    {
                        Dispatcher.Invoke(() =>
                        {
                            ProgressBar.Value = percent;
                            StatusText.Text = $"Сортировка... {percent}%";
                        });
                    }), _cancellationTokenSource.Token);

                    Dispatcher.Invoke(() =>
                    {
                        ProgressBar.Value = 100;
                        StatusText.Text = _cancellationTokenSource.IsCancellationRequested
                            ? "Сортировка отменена!"
                            : "Сортировка завершена в фоновом потоке!";
                        MainThreadButton.IsEnabled = true;
                        BackgroundThreadButton.IsEnabled = true;
                        CancelButton.IsEnabled = false;
                    });
                }
                catch (OperationCanceledException)
                {
                    Dispatcher.Invoke(() =>
                    {
                        ProgressBar.Value = 0;
                        StatusText.Text = "Сортировка отменена!";
                        MainThreadButton.IsEnabled = true;
                        BackgroundThreadButton.IsEnabled = true;
                        CancelButton.IsEnabled = false;
                    });
                }
            });
        }

    }

}
