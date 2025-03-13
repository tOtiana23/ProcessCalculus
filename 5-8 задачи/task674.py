__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava20/index20.htm#z674

import argparse
import module as math
import numpy as np


def main():
    n = int(input("Введите порядок матрицы n: "))
    matrix = np.random.randint(1, 20, (n, n))  # Генерация случайной матрицы
    values = list(map(int, input("Введите 10 целых чисел через пробел: ").split()))
    
    print("Исходная матрица:")
    print(matrix)
    
    processed_matrix = math.process_matrix(matrix, values)
    
    print("Изменённая матрица:")
    print(processed_matrix)

if __name__ == "__main__":
    main()