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
vector<int> generate_array(size_t size, int min, int max) {
    vector<int> a(size);
    // random_device используется для получения случайного "зерна" (seed)
    //нужен, чтобы сделать начальное число действительно случайным
    random_device rd;
    // Инициализируем генератор псевдослучайных чисел Mersenne Twister
    mt19937 gen(rd());
    // Определяем равномерное распределение вещественных чисел от min до max
    // Это значит, что каждое число из этого диапазона будет с одинаковой вероятностью
    uniform_int_distribution<> dist(min, max);

    for (size_t i = 0; i < size; ++i) {
        a[i] = dist(gen); // Генерирует случайное число на основе заданного распределения dist и текущего состояния генератора случайных чисел gen
    }

    return a;
}


/// <summary>
/// Генерация квадратной матрицы n x n случайных целых чисел
/// </summary>
/// <param name="n">Размерность матрицы</param>
/// <param name="min">Минимальное значение</param>
/// <param name="max">Максимальное значение</param>
/// <returns>Сгенерированная матрица</returns>
vector<vector<int>> generate_matrix(size_t n, int min, int max) {
    uniform_int_distribution<> dist(min, max);
    vector<vector<int>> matrix(n, vector<int>(n));
    random_device rd;
    mt19937 gen(rd());
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j)
            matrix[i][j] = dist(gen);
    return matrix;
}

/// <summary>
/// Вывод массива
/// </summary>
/// <param name="a"></param>
/// <param name="title"></param>
void print_array(const vector<int>& a) {
    for (int val : a)
        cout << val << " ";
    cout << endl;
}


/// <summary>
/// Вывод матрицы
/// </summary>
/// <param name="matrix"></param>
/// <param name="title"></param>
void print_matrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << "\t";
        cout << endl;
    }
}


/// <summary>
/// Обработка матрицы по условию задачи:
/// Если сумма индексов i + j чётная и значение совпадает с элементом из массива a — обнуляется.
/// </summary>
/// <param name="matrix">Ссылка на матрицу</param>
/// <param name="a">Массив значений для сравнения</param>
void process_matrix(vector<vector<int>>& matrix, const vector<int>& a) {
    size_t n = matrix.size();
#pragma omp parallel for collapse(2)
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if ((i + j) % 2 == 0) {
                for (int x : a) {
                    if (matrix[i][j] == x) {
                        matrix[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}
