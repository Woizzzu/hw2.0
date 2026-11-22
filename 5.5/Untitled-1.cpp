#include <iostream>
#include <string>

int calculateAgeInFiveYears(int currentAge) {
    return currentAge + 5;
}

void printProfile(const std::string& name, const std::string& city, int age) {
    std::cout << "\n--- User Profile ---\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "City: " << city << "\n";
    std::cout << "Age: " << age << "\n";
    std::cout << "Age in 5 years: " << calculateAgeInFiveYears(age) << "\n";
    std::cout << "--------------------\n";
}

int main() {
    std::string name;
    std::string city;
    int age = 0;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    std::cout << "Enter your city: ";
    std::getline(std::cin, city);

    while (true) {
        std::cout << "Enter your age (1-120): ";
        if (std::cin >> age && age >= 1 && age <= 120) {
            break;
        } else {
            std::cout << "Error! Please enter an integer between 1 and 120.\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    printProfile(name, city, age);

    return 0;
}
