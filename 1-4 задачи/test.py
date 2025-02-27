import mathModule as math

def test():
    # первая задача
    # math.isclose(): Этот метод позволяет сравнивать два числа с учетом заданной относительной и абсолютной точности
    assert abs(math.calculate_expression(5, 3) - 0.125) < 1e-9
    assert abs(math.calculate_expression(-5, 3) - 0.125) < 1e-9
    assert abs(math.calculate_expression(5, -3) - 0.125) < 1e-9
    assert abs(math.calculate_expression(-5, -3) - 0.125) < 1e-9
    assert abs(math.calculate_expression(0, 0) - 0) < 1e-9
    assert abs(math.calculate_expression(4, 4) - 0) < 1e-9

    # вторая задача
    assert math.calculate_squares([1, 2, 3]) == [1.0, 4.0, 9.0]
    assert math.calculate_squares([0]) == [0.0]
    assert math.calculate_squares([-1, -2, -3]) == []
    assert math.calculate_squares([-1, 0, 1, 2]) == [0.0, 1.0, 4.0]
    assert math.calculate_squares([]) == []
    assert math.calculate_squares([1000, -1000]) == [1000000.0]
    assert math.calculate_squares([1.5, -1.5]) == [2.25]

    # третья задача
    assert math.count_hundreds(100) == 1
    assert math.count_hundreds(250) == 2 
    assert math.count_hundreds(999) == 9 
    assert math.count_hundreds(1000) == 0
    assert math.count_hundreds(1500) == 5
    assert math.count_hundreds(20000) == 0
    assert math.count_hundreds(123456) == 4

    # четвертая задача
    assert abs(math.calculate_series_sum(0, 0) - 1) < 1e-9
    # assert abs(math.calculate_series_sum(0, 1) - 2.0) < 1e-9
    # assert abs(math.calculate_series_sum(1, 2) - 1.5) < 1e-9
    # assert abs(math.calculate_series_sum(2, 3) - (0.5 + (1/6))) < 1e-9
    # assert abs(math.calculate_series_sum(0, 4) - (1 + 1 + 0.5 + (1/6) + (1/24))) < 1e-9
    # assert abs(math.calculate_series_sum(3, 5) - (1/6 + (1/24) + (1/120))) < 1e-9
    