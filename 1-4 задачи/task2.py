__author__ = "Бусыгина Татьяна"
# https://ivtipm.github.io/Programming/Glava01/index01.htm#z2

import argparse #позволяет разбирать аргументы командной строки
import mathModule as math
import sympy as sp

def print_formula():
    """Выводит формулу расчёта."""
    x, y = sp.symbols('x y')
    expr = (sp.Abs(x) - sp.Abs(y)) / (1 + sp.Abs(x * y))
    sp.init_printing()
    sp.pprint(expr)

def main():
    parser = argparse.ArgumentParser( #создание объекта парсера, который будет обрабатывать аргументы
        description="Программа для вычисления выражения (|x| - |y|) / (1 + |x * y|)." #то, что отображается при вызове --help
    )
    parser.add_argument("number1", type=float, nargs="?", help="Первое число") #nargs="?" означает что может быть передано одно число или не передано ничего
    parser.add_argument("number2", type=float, nargs="?", help="Второе число")
    args = parser.parse_args() #args специальный объект для хранения аргументов. Создается parse_args()
    
    if args.number1 is not None and args.number2 is not None:
        number1, number2 = args.number1, args.number2
    else:
        try:
            number1 = float(input("Введите первое число: "))
            number2 = float(input("Введите второе число: "))
        except ValueError:
            print("Некорректное значение")
            return 
    
    print("Формула:")
    print_formula()
    
    result = math.calculate_expression(number1, number2)
    print(f"Результат вычислений: {result:.3f}")

if __name__ == "__main__":
    main()
