__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava04/index04.htm#z114

import argparse
import mathModule as math

def main():
    parser = argparse.ArgumentParser(
        description="Программа для вычисления суммы ряда в заданных пределах."
    )
    parser.add_argument("limit_down", type=int, nargs="?", help="Нижний предел ряда (должен быть > 0)")
    parser.add_argument("limit_up", type=int, nargs="?", help="Верхний предел ряда (должен быть > 0)")
    args = parser.parse_args()
    
    if args.limit_down is not None and args.limit_up is not None:
        limit_down, limit_up = args.limit_down, args.limit_up
    else:
        limit_down = int(input("Введите нижний предел ряда > 0: "))
        limit_up = int(input("Введите верхний предел ряда > 0: "))
    
    if limit_down < 0 or limit_up < 0:
        raise ValueError("Некорректное значение")
    
    series_sum = math.calculate_series_sum(limit_down, limit_up)
    print(f"Сумма ряда: {series_sum:.3f}")

if __name__ == "__main__":
    main()