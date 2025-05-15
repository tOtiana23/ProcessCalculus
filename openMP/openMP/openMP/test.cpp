#include <vector>
#include <cassert>
#include <iostream>
#include "Utils.h"
//#include "utils.h"

//Бусыгина Татьяна, ИВТ-22

using namespace std;

void test_sum() {
    setlocale(LC_ALL, "ru");
    // Тест 1: пустой массив
    assert(sum_squares_parallel(vector<double>{}) == 0.0);

    // Тест 2: один элемент
    assert(sum_squares_parallel(vector<double>{3.0}) == 9.0);

    // Тест 3: положительные значения
    assert(sum_squares_parallel(vector<double>{1.0, 2.0, 3.0}) == 14.0); // 1+4+9

    // Тест 4: отрицательные значения
    assert(sum_squares_parallel(vector<double>{-1.0, -2.0, -3.0}) == 14.0);

    // Тест 5: нули
    assert(sum_squares_parallel(vector<double>{0.0, 0.0, 0.0}) == 0.0);

    // Тест 6: проверка точности
    double result = sum_squares_parallel(vector<double>{0.1, 0.2, 0.3}); // 0.01 + 0.04 + 0.09 = 0.14
    assert(fabs(result - 0.14) < 1e-10);

    cout << "Тесты sum_squares() пройдены.\n";
}

void test_generate() {
    setlocale(LC_ALL, "ru");
    // Тест 1: проверка размера
    auto arr = generate_random_array(10, -5.0, 5.0);
    assert(arr.size() == 10);

    // Тест 2: значения в пределах диапазона
    for (double x : arr) {
        assert(x >= -5.0 && x <= 5.0);
    }

    // Тест 3: нулевой размер
    auto empty = generate_random_array(0, -1.0, 1.0);
    assert(empty.empty());

    std::cout << "Тесты generate_random_array() пройдены.\n";
}