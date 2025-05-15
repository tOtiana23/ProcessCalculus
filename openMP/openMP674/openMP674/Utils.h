#pragma once
#include <vector>
#include <random>
#include <iostream>
#include <string>
#include <omp.h>

//Бусыгина Татьяна, ИВТ-22

using namespace std;


/// <summary>
/// Генерация одномерного массива случайных целых чисел
/// </summary>
/// <param name="size">Размер массива</param>
/// <param name="min">Минимальное значение</param>
/// <param name="max">Максимальное значение</param>
/// <returns>Сгенерированный массив</returns>
vector<int> generate_array(size_t size, int min, int max);

/// <summary>
/// Генерация квадратной матрицы n x n случайных целых чисел
/// </summary>
/// <param name="n">Размерность матрицы</param>
/// <param name="min">Минимальное значение</param>
/// <param name="max">Максимальное значение</param>
/// <returns>Сгенерированная матрица</returns>
vector<vector<int>> generate_matrix(size_t n, int min, int max);

/// <summary>
/// Вывод массива
/// </summary>
/// <param name="a"></param>
/// <param name="title"></param>
void print_array(const vector<int>& a);


/// <summary>
/// Вывод матрицы
/// </summary>
/// <param name="matrix"></param>
/// <param name="title"></param>
void print_matrix(const vector<vector<int>>& matrix);


/// <summary>
/// Обработка матрицы по условию задачи:
/// Если сумма индексов i + j чётная и значение совпадает с элементом из массива a — обнуляется.
/// </summary>
/// <param name="matrix">Ссылка на матрицу</param>
/// <param name="a">Массив значений для сравнения</param>
void process_matrix(vector<vector<int>>& matrix, const vector<int>& a);

void test_single_match_even_index();
void test_match_on_odd_index();
void test_multiple_matches_even_indices();
void test_no_match();

