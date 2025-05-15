#include "Utils.h"
#include <random>
#include <omp.h>
#include <chrono>
#include <functional>

//�������� �������, ���-22

using namespace std;
using namespace chrono;


/// <summary>
/// ������������ ���������� ��������� ������� � ������� � �� ������������. ������������ OpenMP
/// </summary>
/// <param name="a">������� ������</param>
/// <returns>����� ��������� ���������</returns>
double sum_squares_parallel(const vector<double>& a) {
    double sum = 0.0;
// ������ ����� ������������ ���� ����� �����, � ������� ��������� ����� ���������� sum
// �� ��������� ������������ schedule(static), �� ����� �������� ���������� ����� ��������
// ���������� ������� ��������� �� ���������� ����
// reduction(+:sum) ��������, ��� ������������ �������� + ��� ����������� ��������.
#pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < a.size(); ++i) {
        sum += a[i] * a[i];
    }
    return sum; //��� ��������� ����� sum ������������ � ���� �����
}


/// <summary>
/// ���������������� ���������� ��������� ������� � ������� � �� ������������
/// </summary>
/// <param name="a">������� ������</param>
/// <returns>����� ��������� ���������</returns>
double sum_squares_serial(const std::vector<double>& a) {
    double sum = 0.0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += a[i] * a[i];
    }
    return sum;
}


/// <summary>
/// ���������� ������ ��������� ������� �� ���������� ������������� �������
/// </summary>
/// <param name="size">������ �������</param>
/// <param name="min">����������� �������� ��� ���������</param>
/// <param name="max">������������ �������� ��� ���������</param>
/// <returns>��������������� ������</returns>
vector<double> generate_random_array(size_t size, double min, double max) {
    vector<double> a(size);
    // random_device ������������ ��� ��������� ���������� "�����" (seed)
    //�����, ����� ������� ��������� ����� ������������� ���������
    random_device rd;
    // �������������� ��������� ��������������� ����� Mersenne Twister
    mt19937 gen(rd());
    // ���������� ����������� ������������� ������������ ����� �� min �� max
    // ��� ������, ��� ������ ����� �� ����� ��������� ����� � ���������� ������������
    uniform_real_distribution<> dist(min, max);

    for (size_t i = 0; i < size; ++i) {
        a[i] = dist(gen); // ���������� ��������� ����� �� ������ ��������� ������������� dist � �������� ��������� ���������� ��������� ����� gen
    }

    return a;
}


/// <summary>
/// �������� ����� ���������� ������� � �������������
/// </summary>
/// <param name="func">�������, ����� ���������� ������� ����� ��������</param>
/// <returns>����� ���������� ������� � �������������</returns>
double measure_time_ms(const function<void()>& func) {
    auto start = high_resolution_clock::now();
    func(); // ��������� ���������� �������
    auto end = high_resolution_clock::now();
    return duration_cast<milliseconds>(end - start).count();
}