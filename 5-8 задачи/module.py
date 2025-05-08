def my_sum(a):
    '''
    Вычисляет сумму элементов массива
    '''
    total = 0 
    for x in a:
        total += x
    return total  

def sum_squares(a):
    '''
    Вычисляет сумму квадратов элементов массива
    '''
    return my_sum([x**2 for x in a]) 


def count_multiples(sequence, condition):
    '''
    Определение количества чисел, удовлетворяющих заданному условию
    '''
    return my_sum(1 for x in sequence if condition(x))


def calculate_double_sum(outer_limit, inner_limit):
    '''
    Вычисление двойной суммы рядов с заданными пределами.
    '''
    total_sum = 0
    for i in range(1, outer_limit + 1):
        for j in range(1, inner_limit + 1):
            total_sum += 1 / (i + j**2)
    return total_sum

import numpy as np


def process_matrix(matrix, values):
    '''
    Замена нулями в матрице элементов с чётной суммой индексов, для которых имеются равные среди a1, ..., a10.
    '''
    n = matrix.shape[0] #берем кол-во строк матрицы
    # shape это атрибут, который возвращает размерность массива. Для двумерного массива (матрицы) 
    # shape возвращает кортеж, содержащий количество строк и количество столбцов
    even_index_mask = (np.add.outer(np.arange(n), np.arange(n)) % 2 == 0)
    # np.arange(n) – создает массив [0, 1, 2, ..., n-1].
    # np.add.outer(np.arange(n)) — это функция которая создает двумерный массив (матрицу), 
    # используя внешний метод сложения элементов из двух одномерных массивов
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