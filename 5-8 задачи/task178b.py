__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava07/index07.htm#z178

import argparse
import module as math

def main():
    parser = argparse.ArgumentParser(description="Определение кол-ва членов последовательности кратных 3 и не кратных 5")
    parser.add_argument("--n", type=int, help="Количество элементов")

    args = parser.parse_args()

    # Если аргумент --n не передан, запросим ввод у пользователя
    if args.n is None:
        n = int(input("Введите количество элементов n: "))
    else:
        n = args.n

    count_result = math.count_multiples(n, lambda x: x % 3 == 0 and x % 5 != 0)
    print("Количество элементов, кратных 3 и не кратных 5:", count_result)

if __name__ == "__main__":
    main()