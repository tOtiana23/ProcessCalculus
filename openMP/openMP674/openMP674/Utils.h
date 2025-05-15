#pragma once
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
vector<int> generate_array(size_t size, int min, int max);

/// <summary>
/// ��������� ���������� ������� n x n ��������� ����� �����
/// </summary>
/// <param name="n">����������� �������</param>
/// <param name="min">����������� ��������</param>
/// <param name="max">������������ ��������</param>
/// <returns>��������������� �������</returns>
vector<vector<int>> generate_matrix(size_t n, int min, int max);

/// <summary>
/// ����� �������
/// </summary>
/// <param name="a"></param>
/// <param name="title"></param>
void print_array(const vector<int>& a);


/// <summary>
/// ����� �������
/// </summary>
/// <param name="matrix"></param>
/// <param name="title"></param>
void print_matrix(const vector<vector<int>>& matrix);


/// <summary>
/// ��������� ������� �� ������� ������:
/// ���� ����� �������� i + j ������ � �������� ��������� � ��������� �� ������� a � ����������.
/// </summary>
/// <param name="matrix">������ �� �������</param>
/// <param name="a">������ �������� ��� ���������</param>
void process_matrix(vector<vector<int>>& matrix, const vector<int>& a);

void test_single_match_even_index();
void test_match_on_odd_index();
void test_multiple_matches_even_indices();
void test_no_match();

