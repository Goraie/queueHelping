#include "Queue.h"
#include "Queue1Private.h"
#include "Queue1Protected.h"
#include "Queue1Public.h"

#include <iostream>

int readInt(const char* prompt) {
    int value = 0;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }

        std::cout << "Ошибка ввода. Попробуйте еще раз." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

void runPublicMenu() {
    std::cout << "\nРежим наследования: public" << std::endl;
    Queue1Public queue;
    Queue copiedQueue;
    bool hasCopy = false;

    while (true) {
        std::cout
            << "\n1 - Добавить элемент\n"
            << "2 - Извлечь элемент\n"
            << "3 - Вывести очередь\n"
            << "4 - Вычислить требуемое значение\n"
            << "5 - Создать копию очереди\n"
            << "6 - Слить исходную очередь с копией\n"
            << "7 - Выход\n";

        int choice = readInt("Выберите пункт: ");

        if (choice == 1) {
            int value = readInt("Введите целое число: ");
            queue.enqueue(value);
            std::cout << "Элемент добавлен." << std::endl;
        } else if (choice == 2) {
            int value = 0;
            if (queue.dequeue(value)) {
                std::cout << "Извлечен элемент: " << value << std::endl;
            } else {
                std::cout << "Очередь пуста." << std::endl;
            }
        } else if (choice == 3) {
            queue.print();
        } else if (choice == 4) {
            queue.printRequiredValue();
        } else if (choice == 5) {
            copiedQueue = queue.createCopy();
            hasCopy = true;
            std::cout << "Копия очереди создана." << std::endl;
        } else if (choice == 6) {
            if (!hasCopy) {
                std::cout << "Сначала создайте копию (пункт 5)." << std::endl;
            } else {
                Queue merged = Queue::merge(queue, copiedQueue);
                std::cout << "Результат слияния: " << std::endl;
                merged.print();
            }
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Некорректный пункт меню." << std::endl;
        }
    }
}

void runProtectedMenu() {
    std::cout << "\nРежим наследования: protected" << std::endl;
    Queue1Protected queue;
    Queue copiedQueue;
    bool hasCopy = false;

    while (true) {
        std::cout
            << "\n1 - Добавить элемент\n"
            << "2 - Извлечь элемент\n"
            << "3 - Вывести очередь\n"
            << "4 - Вычислить требуемое значение\n"
            << "5 - Создать копию очереди\n"
            << "6 - Слить исходную очередь с копией\n"
            << "7 - Выход\n";

        int choice = readInt("Выберите пункт: ");

        if (choice == 1) {
            int value = readInt("Введите целое число: ");
            queue.add(value);
            std::cout << "Элемент добавлен." << std::endl;
        } else if (choice == 2) {
            int value = 0;
            if (queue.extract(value)) {
                std::cout << "Извлечен элемент: " << value << std::endl;
            } else {
                std::cout << "Очередь пуста." << std::endl;
            }
        } else if (choice == 3) {
            queue.printQueue();
        } else if (choice == 4) {
            queue.printRequiredValue();
        } else if (choice == 5) {
            copiedQueue = queue.createCopyQueue();
            hasCopy = true;
            std::cout << "Копия очереди создана." << std::endl;
        } else if (choice == 6) {
            if (!hasCopy) {
                std::cout << "Сначала создайте копию (пункт 5)." << std::endl;
            } else {
                Queue merged = queue.mergeWith(copiedQueue);
                std::cout << "Результат слияния: " << std::endl;
                merged.print();
            }
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Некорректный пункт меню." << std::endl;
        }
    }
}

void runPrivateMenu() {
    std::cout << "\nРежим наследования: private" << std::endl;
    Queue1Private queue;
    Queue copiedQueue;
    bool hasCopy = false;

    while (true) {
        std::cout
            << "\n1 - Добавить элемент\n"
            << "2 - Извлечь элемент\n"
            << "3 - Вывести очередь\n"
            << "4 - Вычислить требуемое значение\n"
            << "5 - Создать копию очереди\n"
            << "6 - Слить исходную очередь с копией\n"
            << "7 - Выход\n";

        int choice = readInt("Выберите пункт: ");

        if (choice == 1) {
            int value = readInt("Введите целое число: ");
            queue.add(value);
            std::cout << "Элемент добавлен." << std::endl;
        } else if (choice == 2) {
            int value = 0;
            if (queue.extract(value)) {
                std::cout << "Извлечен элемент: " << value << std::endl;
            } else {
                std::cout << "Очередь пуста." << std::endl;
            }
        } else if (choice == 3) {
            queue.printQueue();
        } else if (choice == 4) {
            queue.printRequiredValue();
        } else if (choice == 5) {
            copiedQueue = queue.createCopyQueue();
            hasCopy = true;
            std::cout << "Копия очереди создана." << std::endl;
        } else if (choice == 6) {
            if (!hasCopy) {
                std::cout << "Сначала создайте копию (пункт 5)." << std::endl;
            } else {
                Queue merged = queue.mergeWith(copiedQueue);
                std::cout << "Результат слияния: " << std::endl;
                merged.print();
            }
        } else if (choice == 7) {
            break;
        } else {
            std::cout << "Некорректный пункт меню." << std::endl;
        }
    }
}

int main() {
    std::cout << "Лабораторная работа: очередь с наследованием" << std::endl;
    std::cout << "Требуемое значение для Queue1: количество положительных элементов."
              << std::endl;

    while (true) {
        std::cout << "\nВыберите режим наследования:\n"
                  << "1 - public\n"
                  << "2 - protected\n"
                  << "3 - private\n"
                  << "4 - завершить программу\n";

        int mode = readInt("Ваш выбор: ");
        if (mode == 1) {
            runPublicMenu();
        } else if (mode == 2) {
            runProtectedMenu();
        } else if (mode == 3) {
            runPrivateMenu();
        } else if (mode == 4) {
            break;
        } else {
            std::cout << "Некорректный режим." << std::endl;
        }
    }

    return 0;
}
