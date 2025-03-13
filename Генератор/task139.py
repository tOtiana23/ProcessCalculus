__author__ = "Бусыгина Татьяна"

# https://ivtipm.github.io/Programming/Glava06/index06.htm#z139

from math import factorial
#Генераторы — это специальные функции,
#которые используют ключевое слово yield вместо return. 
#В отличие от обычных функций, которые выполняются один раз и 
#возвращают результат, генераторы могут приостанавливать своё выполнение
#после каждого вызова yield, сохраняя своё состояние, и продолжать работу с того места,
#где они остановились, при следующем обращении

def sequence_a(n):
    for i in range(1, n+1):
        yield i


def sequence_b(n):
    for i in range(1, n+1):
        yield i**i


def sequence_c(n):
    for i in range(1, n + 1):
        yield factorial(i)

def sequence_d(n):
    for i in range(1, n + 1):
        yield 2**(i+1)


def sequence_e(n):
    for i in range(1, n + 1):
        yield 2**i + 3**(i+1)


def sequence_f(n):
    for i in range(1, n + 1):
        yield 2**i/factorial(i)


def sequence_g(n):
    for i in range(1, n + 1):
        yield sum(1/j for j in range(1, i+1))


def sequence_h(n):
    for i in range(1, n + 1):
        yield sum((-1)**(j+1)/j for j in range(1, i+1))


def sequence_i(n):
    for i in range(1, n + 1):
        yield i*sum(1 / factorial(j) for j in range(1, i+1))


def round_list(lst, decimals=3):
    """Функция округляет все элементы списка до указанного количества знаков после запятой."""
    return [round(x, decimals) for x in lst]


n = int(input("Введите количество элементов: "))

print("а:", list(sequence_a(n)))
print("б:", list(sequence_b(n)))
print("в:", list(sequence_c(n)))
print("г:", list(sequence_d(n)))
print("д:", list(sequence_e(n)))
print("е:", round_list(list(sequence_f(n))))
print("ж:", round_list(list(sequence_g(n))))
print("з:", round_list(list(sequence_h(n))))
print("и:", round_list(list(sequence_i(n))))
