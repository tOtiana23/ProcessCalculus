import unittest
import numpy as np
from module import process_matrix, sum_squares, count_multiples, calculate_double_sum  

class TestSumSquares(unittest.TestCase):
    def test_empty_list(self):
        self.assertEqual(sum_squares([]), 0)

    def test_single_element(self):
        self.assertEqual(sum_squares([3]), 9)

    def test_multiple_elements(self):
        self.assertEqual(sum_squares([1, 2, 3]), 14) 

    def test_negative_numbers(self):
        self.assertEqual(sum_squares([-1, -2, -3]), 14) 


class TestCountMultiples(unittest.TestCase):
    def test_no_multiples(self):
        self.assertEqual(count_multiples(2, lambda x: x % 3 == 0 and x % 5 != 0), 0)  

    def test_some_multiples(self):
        self.assertEqual(count_multiples(10, lambda x: x % 3 == 0 and x % 5 != 0), 3)

    def test_exceeding_multiples(self):
        self.assertEqual(count_multiples(15, lambda x: x % 3 == 0 and x % 5 != 0), 4) 

    def test_large_n(self):
        self.assertEqual(count_multiples(30, lambda x: x % 3 == 0 and x % 5 != 0), 8)  


class TestProcessMatrix(unittest.TestCase):
    def test_empty_matrix(self):
        result = process_matrix(np.array([]).reshape(0, 0), [1])
        np.testing.assert_array_equal(result, np.array([]).reshape(0, 0))

    def test_no_replacements(self):
        matrix = np.array([[1, 2], [3, 4]])
        result = process_matrix(matrix, [5])
        np.testing.assert_array_equal(result, matrix)


class TestCalculateDoubleSum(unittest.TestCase):
    def test_calculate_double_sum(self):
        result = calculate_double_sum(100, 50)
        expected_value = 24.645751790263247 
        self.assertAlmostEqual(result, expected_value, places=5)

    def test_large_n(self):
        self.assertGreater(calculate_double_sum(100, 50), 0)

    def test_type_of_result(self):
        self.assertIsInstance(calculate_double_sum(100, 50), float)


if __name__ == '__main__':
    unittest.main()
