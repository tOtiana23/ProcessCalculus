import unittest
import numpy as np
from module import process_matrix, sum_squares, count_multiples, calculate_double_sum  

# class TestProcessMatrix(unittest.TestCase):
#     def test_empty_matrix(self):
#         result = process_matrix(np.array([]).reshape(0, 0), [1])
#         np.testing.assert_array_equal(result, np.array([]).reshape(0, 0))

#     def test_no_replacements(self):
#         matrix = np.array([[1, 2], [3, 4]])
#         result = process_matrix(matrix, [5])
#         np.testing.assert_array_equal(result, matrix)  # ничего не должно измениться

#     def test_some_replacements(self):
#         matrix = np.array([[1, 2], [3, 4]])
#         result = process_matrix(matrix, [1, 2])
#         expected = np.array([[0, 0], [3, 4]])  # заменяем на ноль элементы с четными индексами
#         np.testing.assert_array_equal(result, expected)

#     def test_multiple_replacements(self):
#         matrix = np.array([[1, 2], [3, 4], [5, 6]])
#         result = process_matrix(matrix, [2, 6])
#         expected = np.array([[1, 0], [3, 4], [5, 0]])  
#         np.testing.assert_array_equal(result, expected)


class TestSumSquares(unittest.TestCase):
    def test_empty_list(self):
        self.assertEqual(sum_squares(0, []), 0)

    def test_single_element(self):
        self.assertEqual(sum_squares(1, [3]), 9)

    def test_multiple_elements(self):
        self.assertEqual(sum_squares(3, [1, 2, 3]), 14) 

    def test_negative_numbers(self):
        self.assertEqual(sum_squares(3, [-1, -2, -3]), 14) 


class TestCountMultiples(unittest.TestCase):
    def test_no_multiples(self):
        self.assertEqual(count_multiples(2), 0)  

    def test_some_multiples(self):
        self.assertEqual(count_multiples(10), 3)

    def test_exceeding_multiples(self):
        self.assertEqual(count_multiples(15), 4) 

    def test_large_n(self):
        self.assertEqual(count_multiples(30), 8)  


class TestCalculateDoubleSum(unittest.TestCase):
    def test_calculate_double_sum(self):
        result = calculate_double_sum()
        expected_value = 24.645751790263247 
        self.assertAlmostEqual(result, expected_value, places=5)

    def test_large_n(self):
        self.assertGreater(calculate_double_sum(), 0)

    def test_type_of_result(self):
        self.assertIsInstance(calculate_double_sum(), float)


if __name__ == '__main__':
    unittest.main()
