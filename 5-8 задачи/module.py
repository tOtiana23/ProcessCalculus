def sum_squares(n, a):
    return sum(x**2 for x in a)


def count_multiples(n):
    sequence = list(range(1, n + 1))
    return sum(1 for x in sequence if x % 3 == 0 and x % 5 != 0)


def calculate_double_sum():
    total_sum = 0
    for i in range(1, 101):
        for j in range(1, 51):
            total_sum += 1 / (i + j**2)
    return total_sum

import numpy as np

def process_matrix(matrix, values):
    n = matrix.shape[0]
    even_index_mask = (np.add.outer(np.arange(n), np.arange(n)) % 2 == 0)
    # np.arange(n) – создает массив [0, 1, 2, ..., n-1].
    # np.add.outer(np.arange(n), np.arange(n)) – создает матрицу, где каждый элемент [i, j] равен i + j.
    # % 2 == 0 – проверяет, четная ли сумма индексов i + j. В результате получается булева маска.
    mask_values = np.isin(matrix, values) #создает булеву матрицу, где True стоит там, где элементы matrix содержатся в values
    matrix[np.logical_and(even_index_mask, mask_values)] = 0 
    # создает итоговую булеву маску, в которой True только в тех местах, где:
    # Сумма индексов четная (even_index_mask).
    # Элемент находится в values (mask_values).
    # После этого все элементы, соответствующие True, заменяются на 0.
    return matrix
    # Например, для n = 3:
    # [[0+0, 0+1, 0+2],  -> [[0, 1, 2],
    #  [1+0, 1+1, 1+2],  ->  [1, 2, 3],
    #  [2+0, 2+1, 2+2]]  ->  [2, 3, 4]]

    # [[True, False, True],
    #  [False, True, False],
    #  [True, False, True]]