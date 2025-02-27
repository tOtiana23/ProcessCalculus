__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava02/index02.htm#z43

import argparse
import mathModule as math

def main():
    parser = argparse.ArgumentParser(
        description="Программа для вычисления квадратов неотрицательных чисел."
    )
    parser.add_argument("numbers", type=float, nargs="*", help="Список чисел для обработки") #nargs="*" значит что можно передавать любое кол-во аргументов или не передавать вообще
    args = parser.parse_args()
    
    if args.numbers is not None:
        numbers = args.numbers
    else:
        numbers = []
        while True:
            enter = input("Введите число или 'стоп' для завершения ввода: ")
            if enter.lower() == 'стоп':
                break
            try:
                numbers.append(float(enter))
            except ValueError:
                print("Некорректное значение")
    
    squares = math.calculate_squares(numbers)
    print("Квадраты неотрицательных чисел: ", squares)

if __name__ == "__main__":
    main()