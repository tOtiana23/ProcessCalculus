__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava20/index20.htm#z674

import argparse
import module as math
import numpy as np

def main():
    parser = argparse.ArgumentParser(description="Обработка матрицы с использованием случайных значений.")
    parser.add_argument("--n", type=int, help="Порядок матрицы n")
    parser.add_argument("--values", type=int, nargs=10, help="10 целых чисел через пробел")

    args = parser.parse_args()

    if args.n is None:
        n = int(input("Введите порядок матрицы n: "))
    else:
        n = args.n

    if args.values is None:
        values = list(map(int, input("Введите 10 целых чисел через пробел: ").split()))
    else:
        values = args.values

    matrix = np.random.randint(1, 20, (n, n))  # Генерация случайной матрицы
    
    print("Исходная матрица:")
    print(matrix)
    
    processed_matrix = math.process_matrix(matrix, values)
    
    print("Изменённая матрица:")
    print(processed_matrix)

if __name__ == "__main__":
    main()