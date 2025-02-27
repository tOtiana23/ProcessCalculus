__author__ = "Бусыгина Татьяна"

import subprocess
import test
# subprocess — позволяет запускать новые процессы, взаимодействовать с ними и получать их вывод
# subprocess.run() — позволяет запускать команду и ждать ее завершения. ['python', 'task2.py'] пишутся аргументы не через пробел, а как элементы спсика

test.test()

print("Выберите задачу для запуска:")
print("1. Задача 2")
print("2. Задача 43")
print("3. Задача 64")
print("4. Задача 114в")

choice = input("Введите номер задачи (1-4): ")

if choice == '1':
    subprocess.run(['python', 'task2.py'])
elif choice == '2':
    subprocess.run(['python', 'task43.py'])
elif choice == '3':
    subprocess.run(['python', 'task64.py'])
elif choice == '4':
    subprocess.run(['python', 'task114v.py'])
else:
    print("Неверный выбор. Пожалуйста, попробуйте снова.")