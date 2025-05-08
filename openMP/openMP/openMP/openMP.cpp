#include <iostream>
#include <vector>
#include <omp.h>
#include <random>
//Бусыгина Татьяна, ИВТ-22

using namespace std;

//https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

//тоже вынести в файл
//отдельная функция для заполнения массива

//Параллельное возведение элементов массива в квадрат и их суммирование. Используется OpenMP
double sum_squares(const vector<double>& a) {
    double sum = 0.0;
// Каждый поток обрабатывает свою часть цикла, у каждого локальная копия переменной sum
// По умолчанию используется schedule(static), он делит итерации равномерно между потоками
// Количество потоков создается по количеству ядер
// reduction(+:sum) означает, что используется операция + для объединения значений.
#pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < a.size(); ++i) {
        sum += a[i] * a[i];
    }

    return sum; //все локальные копии sum объединяются в одно целое
}

int main() {
    setlocale(LC_ALL, "ru");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Размер массива должен быть положительным." << endl;
        return 1;
    }

    vector<double> a(size);

    // random_device используется для получения случайного "зерна" (seed)
    //нужен, чтобы сделать начальное число действительно случайным
    random_device rd;

    // Инициализируем генератор псевдослучайных чисел Mersenne Twister
    mt19937 gen(rd());

    // Определяем равномерное распределение вещественных чисел от -10.0 до 10.0
    // Это значит, что каждое число из этого диапазона будет с одинаковой вероятностью
    uniform_real_distribution<> dist(-10.0, 10.0);

    for (int i = 0; i < size; ++i) {
        a[i] = dist(gen);
    }

    char show;
    cout << "Вывести сгенерированный массив? (y/n): ";
    cin >> show;

    if (show == 'y' || show == 'Y') {
        cout << "Массив: ";
        for (double x : a) {
            cout << x << " ";
        }
        cout << endl;
    }

    double result = sum_squares(a);
    cout << "Сумма квадратов всех элементов: " << result << endl;

    return 0;
}
