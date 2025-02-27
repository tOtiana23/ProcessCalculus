__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava03/index03.htm#z64

import argparse
import mathModule as math

def main():
    parser = argparse.ArgumentParser(
        description="Программа для вычисления количества сотен в числе."
    )
    parser.add_argument("number", type=int, nargs="?", help="Натуральное число > 99")
    args = parser.parse_args()
    
    if args.number is not None:
        number = args.number
    else:
        number = int(input("Введите натуральное число > 99: "))
    
    if number < 100:
        raise ValueError("Некорректное значение")
    
    hundreds_count = math.count_hundreds(number)
    print("Количество сотен в числе", number, ":", hundreds_count)

if __name__ == "__main__":
    main()
