#pragma once
#include <vector>
#include <functional>

//Бусыгина Татьяна, ИВТ-22

using namespace std;


/// <summary>
/// Параллельное возведение элементов массива в квадрат и их суммирование. Используется OpenMP
/// </summary>
/// <param name="a">Входной массив</param>
/// <returns>Сумма квадратов элементов</returns>
double sum_squares_parallel(const vector<double>& a);


/// <summary>
/// Последовательное возведение элементов массива в квадрат и их суммирование
/// </summary>
/// <param name="a">Входной массив</param>
/// <returns>Сумма квадратов элементов</returns>
double sum_squares_serial(const std::vector<double>& a);


/// <summary>
/// Генерирует массив заданного размера со случайными вещественными числами
/// </summary>
/// <param name="size">Размер массива</param>
/// <param name="min">Минимальное значение для генерации</param>
/// <param name="max">Максимальное значение для генерации</param>
/// <returns>Сгенерированный массив</returns>
vector<double> generate_random_array(size_t size, double min, double max);


/// <summary>
/// Измеряет время выполнения функции в миллисекундах
/// </summary>
/// <param name="func">Функция, время выполнения которой нужно измерить</param>
/// <returns>Время выполнения функции в миллисекундах</returns>
double measure_time_ms(const function<void()>& func);


void test_sum();


void test_generate();