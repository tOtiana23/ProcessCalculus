#include <vector>
#include <random>
#include <iostream>
#include <string>
#include <omp.h>

//�������� �������, ���-22

using namespace std;


/// <summary>
/// ��������� ����������� ������� ��������� ����� �����
/// </summary>
/// <param name="size">������ �������</param>
/// <param name="min">����������� ��������</param>
/// <param name="max">������������ ��������</param>
/// <returns>��������������� ������</returns>
vector<int> generate_array(size_t size, int min, int max) {
    vector<int> a(size);
    // random_device ������������ ��� ��������� ���������� "�����" (seed)
    //�����, ����� ������� ��������� ����� ������������� ���������
    random_device rd;
    // �������������� ��������� ��������������� ����� Mersenne Twister
    mt19937 gen(rd());
    // ���������� ����������� ������������� ������������ ����� �� min �� max
    // ��� ������, ��� ������ ����� �� ����� ��������� ����� � ���������� ������������
    uniform_int_distribution<> dist(min, max);

    for (size_t i = 0; i < size; ++i) {
        a[i] = dist(gen); // ���������� ��������� ����� �� ������ ��������� ������������� dist � �������� ��������� ���������� ��������� ����� gen
    }

    return a;
}


/// <summary>
/// ��������� ���������� ������� n x n ��������� ����� �����
/// </summary>
/// <param name="n">����������� �������</param>
/// <param name="min">����������� ��������</param>
/// <param name="max">������������ ��������</param>
/// <returns>��������������� �������</returns>
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
/// ����� �������
/// </summary>
/// <param name="a"></param>
/// <param name="title"></param>
void print_array(const vector<int>& a) {
    for (int val : a)
        cout << val << " ";
    cout << endl;
}


/// <summary>
/// ����� �������
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
/// ��������� ������� �� ������� ������:
/// ���� ����� �������� i + j ������ � �������� ��������� � ��������� �� ������� a � ����������.
/// </summary>
/// <param name="matrix">������ �� �������</param>
/// <param name="a">������ �������� ��� ���������</param>
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
