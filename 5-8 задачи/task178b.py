__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava07/index07.htm#z178

import argparse
import module as math


def main():
    parser = argparse.ArgumentParser(description="Определение кол-ва членов последовательности кратных 3 и не кратных 5")
    parser.add_argument("n", type=int, help="Количество элементов")
    args = parser.parse_args()

    count_result = math.count_multiples(args.n, args.a)
    print("Количество элементов, кратных 3 и не кратных 5:", count_result)

if __name__ == "__main__":
    main()
