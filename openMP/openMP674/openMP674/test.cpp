#include <cassert>
#include <vector>
#include "Utils.h"

using namespace std;

/// <summary>
/// ������� ����: ���� ������� �� ������� ���� � ������� �� ������ ������� (�� ����� ��������)
/// </summary>
void test_single_match_even_index() {
    vector<int> a = { 5 };
    vector<vector<int>> matrix = {
        {5, 1},
        {2, 3}
    };

    process_matrix(matrix, a);

    assert(matrix[0][0] == 0); // (0+0) % 2 == 0, � ��������� � 5
    assert(matrix[0][1] == 1);
    assert(matrix[1][0] == 2);
    assert(matrix[1][1] == 3);
}

/// <summary>
/// ����: ���������� ����, �� �� �������� ������� (�� ����� ��������) � �������� �� ������
/// </summary>
void test_match_on_odd_index() {
    vector<int> a = { 3 };
    vector<vector<int>> matrix = {
        {1, 3},
        {4, 5}
    };

    process_matrix(matrix, a);

    assert(matrix[0][1] == 3); // (0+1) % 2 == 1 � ��������� ��� ����
}

/// <summary>
/// ����: ��������� ���������� �� ������ ��������
/// </summary>
void test_multiple_matches_even_indices() {
    vector<int> a = { 2, 4 };
    vector<vector<int>> matrix = {
        {2, 1},
        {3, 4}
    };

    process_matrix(matrix, a);

    assert(matrix[0][0] == 0); // 2 -> 0 (0+0)
    assert(matrix[1][1] == 0); // 4 -> 0 (1+1)
    assert(matrix[0][1] == 1); // �� ���������
    assert(matrix[1][0] == 3); // (1+0) % 2 == 1 � ����������
}

/// <summary>
/// ����: ������ �� ��������� � ������� ������� ��� ���������
/// </summary>
void test_no_match() {
    vector<int> a = { 100, 200 };
    vector<vector<int>> matrix = {
        {1, 2},
        {3, 4}
    };

    vector<vector<int>> expected = matrix;
    process_matrix(matrix, a);

    assert(matrix == expected);
}