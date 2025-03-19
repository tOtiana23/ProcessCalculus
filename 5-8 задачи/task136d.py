__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava06/index06.htm#z136

import module as math
import argparse

def main():
    parser = argparse.ArgumentParser(description="Вычисление суммы квадратов элементов массива.")
    parser.add_argument("--a", type=float, nargs="+", help="Список действительных чисел", default=None)

    args = parser.parse_args()


    # Если аргумент --a не передан, запросим ввод у пользователя
    if args.a is None:
        a = list(map(float, input("Введите список действительных чисел через пробел: ").split()))
    else:
        a = args.a


    result = math.sum_squares(a)
    print("Сумма квадратов всех элементов:", result)

if __name__ == "__main__":
    main()