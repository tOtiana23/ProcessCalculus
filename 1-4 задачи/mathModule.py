__author__ = "Бусыгина Татьяна"


def my_abs(number):
    """
    Функция для получения модуля числа number
    """
    if number < 0:
        return -number
    else:
        return number


def my_power(base, exponent):
    """
    Функция для возведения числа base в степень exponent
    """
    return base**exponent


def factorial_generator():
    """
    Бесконечный генератор, который возвращает факториалы последовательно
    """
    current_factorial = 1
    n = 1
    while True:
        yield current_factorial
        n += 1
        current_factorial *= n


def calculate_series_sum(limit_down, limit_up):
    """
    Функция для вычисления суммы ряда 1/n! от limit_down до limit_up.
    Используется внешний генератор factorial_generator.
    """
    total_sum = 0
    factorial_gen = factorial_generator()
    
    # Суммируем 1/n! от limit_down до limit_up
    for _ in range(limit_down, limit_up + 1):
        total_sum += 1 / next(factorial_gen)
    
    return total_sum


def count_hundreds(number):
    """
    Функция для вычисления количества сотен в натуральном числе.
    """
    return (number // 100) % 10


def calculate_squares(numbers):
    """
    Функция для вычисления квадратов неотрицательных чисел
    """
    return [my_power(x, 2) for x in numbers if x >= 0] #если условие выполянется, то происходит math.my_power(x, 2)


def calculate_expression(num1, num2):
    """
    Функция для вычисления выражения по заданной формуле
    """
    result = (my_abs(num1) - my_abs(num2)) / (1 + my_abs(num1 * num2))
    return result