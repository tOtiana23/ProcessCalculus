#include "Utils.h"
#include <random>
#include <omp.h>
#include <chrono>
#include <functional>

//Бусыгина Татьяна, ИВТ-22

using namespace std;
using namespace chrono;


/// <summary>
/// Параллельное возведение элементов массива в квадрат и их суммирование. Используется OpenMP
/// </summary>
/// <param name="a">Входной массив</param>
/// <returns>Сумма квадратов элементов</returns>
double sum_squares_parallel(const vector<double>& a) {
    double sum = 0.0;
// Каждый поток обрабатывает свою часть цикла, у каждого локальная копия переменной sum
// По умолчанию используется schedule(static), он делит итерации равномерно между потоками
// Количество потоков создается по количеству ядер
// reduction(+:sum) означает, что используется операция + для объединения значений.
#pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < a.size(); ++i) {
        sum += a[i] * a[i];
    }
    return sum; //все локальные копии sum объединяются в одно целое
}


/// <summary>
/// Последовательное возведение элементов массива в квадрат и их суммирование
/// </summary>
/// <param name="a">Входной массив</param>
/// <returns>Сумма квадратов элементов</returns>
double sum_squares_serial(const std::vector<double>& a) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += a[i] * a[i];
    }
    return sum;
}


/// <summary>
/// Генерирует массив заданного размера со случайными вещественными числами
/// </summary>
/// <param name="size">Размер массива</param>
/// <param name="min">Минимальное значение для генерации</param>
/// <param name="max">Максимальное значение для генерации</param>
/// <returns>Сгенерированный массив</returns>
vector<double> generate_random_array(size_t size, double min, double max) {
    vector<double> a(size);
    // random_device используется для получения случайного "зерна" (seed)
    //нужен, чтобы сделать начальное число действительно случайным
    random_device rd;
    // Инициализируем генератор псевдослучайных чисел Mersenne Twister
    mt19937 gen(rd());
    // Определяем равномерное распределение вещественных чисел от min до max
    // Это значит, что каждое число из этого диапазона будет с одинаковой вероятностью
    uniform_real_distribution<> dist(min, max);

    for (size_t i = 0; i < size; ++i) {
        a[i] = dist(gen); // Генерирует случайное число на основе заданного распределения dist и текущего состояния генератора случайных чисел gen
    }

    return a;
}


/// <summary>
/// Измеряет время выполнения функции в миллисекундах
/// </summary>
/// <param name="func">Функция, время выполнения которой нужно измерить</param>
/// <returns>Время выполнения функции в миллисекундах</returns>
double measure_time_ms(const function<void()>& func) {
    auto start = high_resolution_clock::now();
    func(); // выполняем переданную функцию
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}