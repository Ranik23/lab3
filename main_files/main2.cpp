#include "../include/cache2.h"
#include <iostream>


template <typename T>
T getInput(const std::string& prompt)
{
    static_assert(std::is_default_constructible_v<T>, "Type T must be default constructible.");

    T value;

    do
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail())
        {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Пожалуйста, попробуйте снова.\n";
        }
        else
        {
            break;
        }

    } while (true);

    return value;
}


template<typename KeyType, typename ValueType>
void interactWithCache(LRUCache<KeyType, ValueType>& cache) {
    int user_choice;

    KeyType key;
    ValueType value;

    while (true) {
        std::cout << "1. put | 2. get | 3. print | 4. exit" << std::endl;
        std::cout << "Enter your choice: ";

        while (!(std::cin >> user_choice) || user_choice < 1 || user_choice > 4) {
            std::cout << "Invalid input. Please enter a valid choice (1 to 4).\n";

            std::cin.clear();
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter your choice: ";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (user_choice == 1) {
            std::cout << "Key - ";
            std::cin >> key;

            if (std::is_same<KeyType, decltype(key)>::value == false) {
                std::cerr << "Invalid type!" << std::endl;
                break;
            }

            std::cout << "Value - ";
            std::cin >> value;

            if (std::is_same<ValueType, decltype(value)>::value == false) {
                std::cerr << "Invalid type!" << std::endl;
                break;
            }

            cache.put(key, value);

        } else if (user_choice == 2) {

            std::cout << "Key - ";
            std::cin >> key;

            if (!std::is_same<KeyType, decltype(key)>::value)
            {
                std::cerr << "Invalid type for key!" << std::endl;
                break;
            }
            std::cout << "Value - " << cache.get(key) << std::endl;

        } else if (user_choice == 3) {
            cache.print();
        } else if (user_choice == 4) {
            break;
        }
    }
}





int main() {

    int capacity = getInput<int>("Введите вместимость кэша: ");

    int keyType;
    do
    {
        keyType = getInput<int>("Выберите тип ключа (1 - int, 2 - string): ");
        if (keyType != 1 && keyType != 2)
        {
            std::cout << "Некорректный ввод для типа ключа. Пожалуйста, введите 1 или 2.\n";
        }

    } while (keyType != 1 && keyType != 2);

    int valueType;
    do
    {
        valueType = getInput<int>("Выберите тип значения (1 - int, 2 - string): ");
        if (valueType != 1 && valueType != 2)
        {
            std::cout << "Некорректный ввод для типа значения. Пожалуйста, введите 1 или 2.\n";
        }
    } while (valueType != 1 && valueType != 2);


    if (keyType == 1 && valueType == 1) {
        LRUCache<int, int> cache(capacity);
        interactWithCache(cache);
    } else if (keyType == 1 && valueType == 2) {
        LRUCache<int, std::string> cache(capacity);
        interactWithCache(cache);
    } else if (keyType == 2 && valueType == 1) {
        LRUCache<std::string, int> cache(capacity);
        interactWithCache(cache);
    } else if (keyType == 2 && valueType == 2) {
        LRUCache<std::string, std::string> cache(capacity);
        interactWithCache(cache);
    }

    return 0;
}
