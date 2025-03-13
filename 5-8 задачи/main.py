__author__ = "Бусыгина Татьяна"

import subprocess

print("Выберите задачу для запуска:")
print("1. Задача 136д")
print("2. Задача 178б")
print("3. Задача 334а")
print("4. Задача 674")

choice = input("Введите номер задачи (1-4): ")

if choice == '1':
    subprocess.run(['python', 'task136d.py'])
elif choice == '2':
    subprocess.run(['python', 'task178b.py'])
elif choice == '3':
    subprocess.run(['python', 'task334a.py'])
elif choice == '4':
    subprocess.run(['python', 'task674.py'])
else:
    print("Неверный выбор. Пожалуйста, попробуйте снова.")