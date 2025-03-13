__author__ = "Бусыгина Татьяна"

import unittest
from task139 import *

# юнит тесты - встроенный модуль, который проверяет отдельные единицы кода на корректность работы
class TestSequences(unittest.TestCase):
    
    def test_sequence_a(self):
        self.assertEqual(list(sequence_a(3)), [1, 2, 3]) #проверка на точное равенство двух объектов
        self.assertEqual(list(sequence_a(5)), [1, 2, 3, 4, 5])
        self.assertEqual(list(sequence_a(1)), [1])

    def test_sequence_b(self):
        self.assertEqual(list(sequence_b(3)), [1, 4, 27])
        self.assertEqual(list(sequence_b(4)), [1, 4, 27, 256])
        self.assertEqual(list(sequence_b(2)), [1, 4])

    def test_sequence_c(self):
        self.assertEqual(list(sequence_c(3)), [1, 2, 6])
        self.assertEqual(list(sequence_c(5)), [1, 2, 6, 24, 120])
        self.assertEqual(list(sequence_c(1)), [1])

    def test_sequence_d(self):
        self.assertEqual(list(sequence_d(3)), [4, 8, 16])
        self.assertEqual(list(sequence_d(5)), [4, 8, 16, 32, 64])
        self.assertEqual(list(sequence_d(2)), [4, 8])

    def test_sequence_e(self):
        self.assertEqual(list(sequence_e(3)), [11, 31, 89])
        self.assertEqual(list(sequence_e(2)), [11, 31])
        self.assertEqual(list(sequence_e(4)), [11, 31, 89, 259])

    def test_sequence_f(self):
        self.assertAlmostEqual(list(sequence_f(3)), [2, 2, 8/6]) #Используется для сравнения двух чисел с учётом возможной погрешности, по умолчанию 7 значащих цифр
        self.assertAlmostEqual(list(sequence_f(2)), [2, 2])
        self.assertAlmostEqual(list(sequence_f(4)), [2, 2, 8/6, 16/24])

    def test_sequence_g(self):
        expected = [1, 1.5, 1.833]
        result = list(sequence_g(3))
        self.assertEqual(round_list(result), expected)

    def test_sequence_h(self):
        expected = [1, 0.5, 0.833]
        result = list(sequence_h(3))
        self.assertEqual(round_list(result), expected)

    def test_sequence_i(self):
        expected = [1, 2 * (1 + 1/2), 3 * (1 + 1/2 + 1/6)]
        result = list(sequence_i(3))
        self.assertEqual(round_list(result), round_list(expected))

if __name__ == '__main__':
    unittest.main()
