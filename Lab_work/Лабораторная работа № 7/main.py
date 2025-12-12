import time
import sys
import os

# Добавляем папку build в путь для импорта
sys.path.insert(0, os.path.join(os.path.dirname(__file__), 'build', 'lib.win-amd64-cpython-313'))

try:
    import Sub

    print("✅ Библиотека Sub успешно импортирована")
except ImportError as e:
    print(f"❌ Ошибка импорта: {e}")
    print("Попытка найти модуль в текущей директории...")

    # Проверяем, есть ли файл .pyd в текущей папке
    pyd_files = [f for f in os.listdir('.') if f.endswith('.pyd')]
    print(f"Найдены .pyd файлы: {pyd_files}")

    # Если есть Sub.pyd, пробуем загрузить напрямую
    if 'Sub.pyd' in pyd_files:
        import ctypes

        Sub = ctypes.CDLL('./Sub.pyd')
        print("✅ Библиотека загружена через ctypes")
    else:
        print("❌ Файл Sub.pyd не найден")
        sys.exit(1)


def test_basic_subtraction():
    """Тест базового вычитания"""
    print("🧪 Тест 1: Базовое вычитание")

    arr1 = [10, 20, 30, 40, 50]
    arr2 = [1, 2, 3, 4, 5]

    try:
        result, exec_time = Sub.subtract(arr1, arr2)

        expected = [9, 18, 27, 36, 45]

        if result == expected:
            print(f"✅ Успех! Результат: {result}")
            print(f"⏱️ Время выполнения: {exec_time:.8f} сек")
        else:
            print(f"❌ Ошибка! Ожидалось {expected}, получено {result}")
    except Exception as e:
        print(f"❌ Ошибка при выполнении: {e}")

    print()


def test_large_arrays():
    """Тест производительности на больших массивах"""
    print("🧪 Тест 2: Производительность на больших массивах")

    sizes = [1000, 5000, 10000]  # Начнем с меньших размеров

    for size in sizes:
        print(f"\n   Размер массива: {size:,} элементов")

        # Создаем массивы
        arr1 = list(range(size))
        arr2 = list(range(size, 2 * size))

        try:
            # Тест C++ библиотеки
            cpp_result, cpp_time = Sub.subtract(arr1, arr2)

            # Тест Python реализации для сравнения
            start_time = time.perf_counter()
            py_result = [a - b for a, b in zip(arr1, arr2)]
            py_time = time.perf_counter() - start_time

            # Проверка корректности (только первые 3 элемента)
            if cpp_result[:3] == py_result[:3]:
                print(f"   ✅ Результаты совпадают")
                print(f"   ⚡ C++ время: {cpp_time:.6f} сек")
                print(f"   🐍 Python время: {py_time:.6f} сек")
                if cpp_time > 0:
                    print(f"   🚀 Ускорение: {py_time / cpp_time:.2f}x")
            else:
                print(f"   ❌ Результаты не совпадают!")
                print(f"   C++ первые 3: {cpp_result[:3]}")
                print(f"   Python первые 3: {py_result[:3]}")
        except Exception as e:
            print(f"   ❌ Ошибка: {e}")

    print()


def main():
    """Основная функция тестирования"""
    print("=" * 60)
    print("🧪 ТЕСТИРОВАНИЕ БИБЛИОТЕКИ Sub (C++ МОДУЛЬ)")
    print("=" * 60)

    # Запускаем все тесты
    test_basic_subtraction()
    test_large_arrays()

    print("=" * 60)
    print("✅ Тестирование завершено!")
    print("=" * 60)


if __name__ == "__main__":
    main()