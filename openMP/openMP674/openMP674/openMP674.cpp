#include <iostream>
#include <vector>
#include <random>
#include <omp.h>
//Бусыгина Татьяна, ИВТ-22
using namespace std;

//https://ivtipm.github.io/Programming/Glava20/index20.htm#z674

//Матрицу шаблонного типа
//комменты к ргументам функции
//передавать диапазон
//size_t

// Генерация случайного массива a из 10 целых чисел
vector<int> generateArray(mt19937& gen, int size = 10) {
    uniform_int_distribution<> dist(-10, 10);
    vector<int> a(size);
    for (int i = 0; i < size; ++i)
        a[i] = dist(gen);
    return a;
}

// Генерация квадратной матрицы размером n x n
vector<vector<int>> generateMatrix(mt19937& gen, int n) {
    uniform_int_distribution<> dist(-20, 20);
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            matrix[i][j] = dist(gen);
    return matrix;
}

// Вывод одномерного массива
void printArray(const vector<int>& a, const string& title = "Массив a:") {
    cout << title << "\n";
    for (int val : a)
        cout << val << " ";
    cout << endl;
}

// Вывод матрицы
void printMatrix(const vector<vector<int>>& matrix, const string& title = "Матрица:") {
    cout << title << "\n";
    for (const auto& row : matrix) {
        for (int val : row)
            cout << val << "\t";
        cout << endl;
    }
}

// Обработка матрицы по условию задачи. Используется openMP
void processMatrix(vector<vector<int>>& matrix, const vector<int>& a) {
    int n = matrix.size();
    //collapse(2) объединяет два вложенных цикла(i и j) в один линейный цикл
    //Вместо обработки n строк по n столбцов, OpenMP рассматривает все пары(i, j) как единый диапазон из n*n итераций.
#pragma omp parallel for collapse(2)
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i + j) % 2 == 0) {
                for (int k = 0; k < a.size(); ++k) {
                    if (matrix[i][j] == a[k]) {
                        matrix[i][j] = 0;
                        break;
                    }
                }
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "ru");

    int n;
    cout << "Введите размер квадратной матрицы (n): ";
    cin >> n;

    // Инициализация генератора случайных чисел
    random_device rd;
    mt19937 gen(rd());

    vector<int> a = generateArray(gen);
    vector<vector<int>> matrix = generateMatrix(gen, n);

    char answer;

    cout << "Вывести массив? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
        printArray(a);

    cout << "Вывести матрицы? (y/n): ";
    cin >> answer;
    if (answer == 'y' || answer == 'Y')
        printMatrix(matrix, "Исходная матрица:");

    processMatrix(matrix, a);
    printMatrix(matrix, "Матрица после обработки:");

    return 0;
}
