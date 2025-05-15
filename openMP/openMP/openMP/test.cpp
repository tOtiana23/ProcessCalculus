#include <vector>
#include <cassert>
#include <iostream>
#include "Utils.h"
//#include "utils.h"

//�������� �������, ���-22

using namespace std;

void test_sum() {
    setlocale(LC_ALL, "ru");
    // ���� 1: ������ ������
    assert(sum_squares_parallel(vector<double>{}) == 0.0);

    // ���� 2: ���� �������
    assert(sum_squares_parallel(vector<double>{3.0}) == 9.0);

    // ���� 3: ������������� ��������
    assert(sum_squares_parallel(vector<double>{1.0, 2.0, 3.0}) == 14.0); // 1+4+9

    // ���� 4: ������������� ��������
    assert(sum_squares_parallel(vector<double>{-1.0, -2.0, -3.0}) == 14.0);

    // ���� 5: ����
    assert(sum_squares_parallel(vector<double>{0.0, 0.0, 0.0}) == 0.0);

    // ���� 6: �������� ��������
    double result = sum_squares_parallel(vector<double>{0.1, 0.2, 0.3}); // 0.01 + 0.04 + 0.09 = 0.14
    assert(fabs(result - 0.14) < 1e-10);

    cout << "����� sum_squares() ��������.\n";
}

void test_generate() {
    setlocale(LC_ALL, "ru");
    // ���� 1: �������� �������
    auto arr = generate_random_array(10, -5.0, 5.0);
    assert(arr.size() == 10);

    // ���� 2: �������� � �������� ���������
    for (double x : arr) {
        assert(x >= -5.0 && x <= 5.0);
    }

    // ���� 3: ������� ������
    auto empty = generate_random_array(0, -1.0, 1.0);
    assert(empty.empty());

    std::cout << "����� generate_random_array() ��������.\n";
}