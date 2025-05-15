#include <iostream>
#include <random>
#include "Utils.h"

int main() {
    test_single_match_even_index();
    test_match_on_odd_index();
    test_multiple_matches_even_indices();
    test_no_match();


    setlocale(LC_ALL, "ru");

    size_t size_matrix;
    cout << "Введите размер квадратной матрицы: ";
    cin >> size_matrix;

    size_t size_array;
    cout << "Введите размер массива: ";
    cin >> size_array;

    size_t min;
    cout << "Введите нижний диапазон для генерации: ";
    cin >> min;

    size_t max;
    cout << "Введите верхний диапазон для генерации: ";
    cin >> max;

    random_device rd;
    mt19937 gen(rd());

    vector<int> a = generate_array(size_array, min, max);
    vector<vector<int>> matrix = generate_matrix(size_matrix, min, max);

    char answer;
    cout << "Вывести массив? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
        print_array(a);

    cout << "Вывести матрицы? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
        cout << "Исходная матрица:";
        print_matrix(matrix);

    process_matrix(matrix, a);

    cout << "Матрица после обработки:";
    print_matrix(matrix);

    return 0;
}
