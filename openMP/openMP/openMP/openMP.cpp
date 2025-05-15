#include <iostream>
#include <vector>
#include <omp.h>
#include <random>
#include "Utils.h"

//Бусыгина Татьяна, ИВТ-22

using namespace std;

//https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

int main() {
    test_sum();
    test_generate();
    setlocale(LC_ALL, "ru");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Размер массива должен быть положительным." << endl;
        return 1;
    }

    // Генерация массива случайных чисел
    vector<double> data = generate_random_array(size, -10.0, 10.0);

    char show;
    cout << "Вывести сгенерированный массив? (y/n): ";
    cin >> show;

    if (show == 'y' || show == 'Y') {
        cout << "Массив: ";
        for (double x : data) {
            cout << x << " ";
        }
        cout << endl;
    }

    double result_serial = 0.0;
    double time_serial = measure_time_ms([&]() {
        result_serial = sum_squares_serial(data);
        });

    double result_parallel = 0.0;
    double time_parallel = measure_time_ms([&]() {
        result_parallel = sum_squares_parallel(data);
        });

    cout << "Последовательный результат: " << result_serial << ", время: " << time_serial << " мс\n";
    cout << "Параллельный результат:     " << result_parallel << ", время: " << time_parallel << " мс\n";

    return 0;
}