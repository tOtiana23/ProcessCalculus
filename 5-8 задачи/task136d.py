__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

import module as math
import argparse

def main():
    parser = argparse.ArgumentParser(description="Вычисление суммы квадратов элементов массива.")
    parser.add_argument("n", type=int, help="Количество элементов")
    parser.add_argument("a", type=float, nargs="+", help="Список действительных чисел")
    args = parser.parse_args()

    if len(args.a) != args.n:
        print("Ошибка: количество введенных чисел не соответствует n")
    else:
        result = math.sum_squares(args.n, args.a)
        print("Сумма квадратов всех элементов:", result)

if __name__ == "__main__":
    main()
