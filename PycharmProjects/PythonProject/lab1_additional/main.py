import os


def read_figures_from_file(filename):
    figures = []
    try:
        with open(filename, 'r') as file:
            for line in file:
                data = line.strip().split()  # Розбиваємо рядок на компоненти
                if len(data) == 2:  # Якщо два числа
                    try:
                        width = float(data[0])
                        height = float(data[1])
                        figures.append(f"Rectangle({width}, {height})")
                    except ValueError:
                        print(f"Некоректні дані для прямокутника в рядку: {line}")
                elif len(data) == 1:  # Якщо одне число
                    try:
                        radius = float(data[0])
                        figures.append(f"Circle({radius})")
                    except ValueError:
                        print(f"Некоректні дані для кола в рядку: {line}")
                else:
                    print(f"Невірний формат даних у рядку: {line}")
    except FileNotFoundError:
        print(f"Файл {filename} не знайдено!")
    return figures


def main():
    # Введення імені файлу
    filename = input("Enter input file name: ")

    # Перевірка, чи існує файл
    if os.path.exists(filename):
        print(f"Файл {filename} знайдено!")
    else:
        print(f"Файл {filename} не знайдено!")
        return

    # Зчитування фігур з файлу
    figures = read_figures_from_file(filename)

    # Виведення кожної фігури
    for figure in figures:
        print(figure)


if __name__ == "__main__":
    main()