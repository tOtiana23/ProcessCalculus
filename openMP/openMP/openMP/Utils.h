#pragma once
#include <vector>
#include <functional>

//�������� �������, ���-22

using namespace std;


/// <summary>
/// ������������ ���������� ��������� ������� � ������� � �� ������������. ������������ OpenMP
/// </summary>
/// <param name="a">������� ������</param>
/// <returns>����� ��������� ���������</returns>
double sum_squares_parallel(const vector<double>& a);


/// <summary>
/// ���������������� ���������� ��������� ������� � ������� � �� ������������
/// </summary>
/// <param name="a">������� ������</param>
/// <returns>����� ��������� ���������</returns>
double sum_squares_serial(const std::vector<double>& a);


/// <summary>
/// ���������� ������ ��������� ������� �� ���������� ������������� �������
/// </summary>
/// <param name="size">������ �������</param>
/// <param name="min">����������� �������� ��� ���������</param>
/// <param name="max">������������ �������� ��� ���������</param>
/// <returns>��������������� ������</returns>
vector<double> generate_random_array(size_t size, double min, double max);


/// <summary>
/// �������� ����� ���������� ������� � �������������
/// </summary>
/// <param name="func">�������, ����� ���������� ������� ����� ��������</param>
/// <returns>����� ���������� ������� � �������������</returns>
double measure_time_ms(const function<void()>& func);


void test_sum();


void test_generate();