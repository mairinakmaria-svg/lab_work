

# Якщо використовуються сторонні бібліотеки, потрібно імпортувати їх
# Якщо таких немає, то цей блок можна пропустити

def read_figures_from_file(filename):
    # Код для зчитування даних з файлу
    pass  # Замінити на реальну логіку

def main():
    filename = input("Enter input file name: ")  # Запитуємо назву файлу
    figures = read_figures_from_file(filename)   # Зчитуємо дані з файлу

    # Тут можна додати логіку для обробки фігур
    for figure in figures:
        print(figure)  # Вивести кожну фігуру

if __name__ == "__main__":  # Перевірка, чи цей файл є головним
    main()


# Функція для зчитування даних з файлу та створення фігур
def read_figures_from_file(filename):
    figures = []

    # Відкриваємо файл для зчитування
    with open(filename, 'r') as file:
        for line in file:
            data = line.strip().split()  # Розділяємо рядок за пробілами

            # Якщо в рядку два числа, це прямокутник
            if len(data) == 2:
                try:
                    # Переводимо числа з рядка в float, щоб обробити розміри
                    width = float(data[0])
                    height = float(data[1])
                    figures.append(f"Rectangle({width}, {height})")
                except ValueError:
                    print(f"Некоректні дані для прямокутника в рядку: {line}")

            # Якщо в рядку одне число, це коло
            elif len(data) == 1:
                try:
                    radius = float(data[0])
                    figures.append(f"Circle({radius})")
                except ValueError:
                    print(f"Некоректні дані для кола в рядку: {line}")

    return figures
def main():
    # Введення імені файлу
    filename = input("Enter input file name: ")

    # Зчитування фігур з файлу
    figures = read_figures_from_file(filename)

    # Виведення кожної фігури
    for figure in figures:
        print(figure)

if __name__ == "__main__":
    main()
filename = "tests/input01.txt"