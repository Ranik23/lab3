#include <iostream>
#include "../include/set.h"
#include <vector>
#include <algorithm>
#include <limits>
#include "../include/splay_tree.h"

template <typename T>
void operatingfunction()
{
    ISet<T> set;

    while (true)
    {

        std::cout << "1. Insert | ";
        std::cout << "2. Size | ";
        std::cout << "3. Empty | ";
        std::cout << "4. Contains | ";
        std::cout << "5. Vizualize | ";
        std::cout << "6. Exit | \n";

        int choice;

        while (!(std::cin >> choice) || choice < 1 || choice > 6)
        {
            std::cout << "Invalid input. Please enter a valid choice (1 to 6).\n";

            std::cin.clear();

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Enter your choice: ";
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
            case 1:
            {
                T value;
                std::cout << "Enter value to insert\n";

                while (!(std::cin >> value))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Try again: ";
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                set.insert(value);
                break;
            }
            case 2:
            {
                std::cout << "Size of the set: " << set.size() << std::endl;
                break;
            }
            case 3:
            {
                std::cout << (set.empty() ? "Set is empty" : "Set is not empty") << std::endl;
                break;
            }
            case 4:
            {
                T value;
                std::cout << "Enter value to check if it exists in the set: ";

                while (!(std::cin >> value))
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Try again: ";
                }

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << (set.contains(value) ? "Value exists in the set" : "Value does not exist in the set") << std::endl;
                break;
            }
            case 5:
            {
                set.generate();
                break;
            }
            case 6:
            {
                exit(0);
            }
            default:
            {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }
}

int main()
{

    int dataType;
    std::cout << "Enter the data type 1) int | 2) double | 3) char  -->  ";

    while (!(std::cin >> dataType) || (dataType < 1 || dataType > 3)) {
        std::cout << "Invalid input. Please enter a valid choice (1, 2, or 3).\n";

        std::cin.clear();

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Enter the data type 1) int | 2) double | 3) char  -->  ";
    }


    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (dataType >= 4) {
        std::cout << "Invalid Input\n";
    } else {
        if (dataType == 1) operatingfunction<int>();
        else if (dataType == 2) operatingfunction<double>();
        else operatingfunction<char>();
    }

    return 0;
}
