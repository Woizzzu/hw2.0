#include <algorithm>
#include <charconv>
#include <iostream>
#include <string>
#include <vector>

class Book {
private:
    std::string title_;
    int year_;

public:
    Book(const std::string& title, int year)
        : title_(title), year_(year) {}

    const std::string& getTitle() const {
        return title_;
    }

    int getYear() const {
        return year_;
    }
};

bool isBlank(const std::string& str) {
    return str.find_first_not_of(" \t\r\n") == std::string::npos;
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos) {
        return "";
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, last - first + 1);
}

bool parseStrictInt(const std::string& input, int& outValue) {
    std::string trimmed = trim(input);
    if (trimmed.empty()) {
        return false;
    }

    const char* begin = trimmed.data();
    const char* end = trimmed.data() + trimmed.size();
    auto [ptr, ec] = std::from_chars(begin, end, outValue);

    return ec == std::errc() && ptr == end;
}

void printMenu() {
    std::cout << "\n=== Book Catalog Menu ===\n";
    std::cout << "1. Add a book\n";
    std::cout << "2. Show all books\n";
    std::cout << "3. Sort by year (ascending)\n";
    std::cout << "4. Sort by year (descending)\n";
    std::cout << "5. Search by title substring\n";
    std::cout << "6. Count books published after a given year\n";
    std::cout << "0. Exit\n";
    std::cout << "Select an option: ";
}

bool addBook(std::vector<Book>& catalog) {
    std::string title;
    std::cout << "Enter book title: ";
    if (!std::getline(std::cin, title)) {
        return false;
    }

    if (isBlank(title)) {
        std::cout << "Error: Book title cannot be empty. Book was not added.\n";
        return true;
    }

    std::string yearInput;
    std::cout << "Enter publication year: ";
    if (!std::getline(std::cin, yearInput)) {
        return false;
    }

    int year = 0;
    if (!parseStrictInt(yearInput, year)) {
        std::cout << "Error: Invalid integer for year. Book was not added.\n";
        return true;
    }

    if (year <= 0) {
        std::cout << "Error: Publication year must be greater than 0. Book was not added.\n";
        return true;
    }

    catalog.emplace_back(trim(title), year);
    std::cout << "Book added successfully.\n";
    return true;
}

void showBooks(const std::vector<Book>& catalog) {
    if (catalog.empty()) {
        std::cout << "Catalog is empty. No books to display.\n";
        return;
    }

    std::cout << "\n--- Book Catalog ---\n";
    for (size_t i = 0; i < catalog.size(); ++i) {
        std::cout << (i + 1) << ". \"" << catalog[i].getTitle()
                  << "\" (" << catalog[i].getYear() << ")\n";
    }
}

void sortByYearAscending(std::vector<Book>& catalog) {
    if (catalog.empty()) {
        std::cout << "Catalog is empty. Nothing to sort.\n";
        return;
    }

    std::sort(catalog.begin(), catalog.end(), [](const Book& a, const Book& b) {
        return a.getYear() < b.getYear();
    });
    std::cout << "Catalog sorted by year (ascending).\n";
}

void sortByYearDescending(std::vector<Book>& catalog) {
    if (catalog.empty()) {
        std::cout << "Catalog is empty. Nothing to sort.\n";
        return;
    }

    std::sort(catalog.begin(), catalog.end(), [](const Book& a, const Book& b) {
        return a.getYear() > b.getYear();
    });
    std::cout << "Catalog sorted by year (descending).\n";
}

bool searchBooks(const std::vector<Book>& catalog) {
    if (catalog.empty()) {
        std::cout << "Catalog is empty. Nothing to search.\n";
        return true;
    }

    std::string query;
    std::cout << "Enter title or part of title to search: ";
    if (!std::getline(std::cin, query)) {
        return false;
    }

    if (isBlank(query)) {
        std::cout << "Error: Search query cannot be empty.\n";
        return true;
    }

    bool found = false;
    std::cout << "\n--- Search Results ---\n";
    for (size_t i = 0; i < catalog.size(); ++i) {
        if (catalog[i].getTitle().find(query) != std::string::npos) {
            std::cout << (i + 1) << ". \"" << catalog[i].getTitle()
                      << "\" (" << catalog[i].getYear() << ")\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "Nothing found.\n";
    }
    return true;
}

bool countBooksAfterYear(const std::vector<Book>& catalog) {
    if (catalog.empty()) {
        std::cout << "Catalog is empty. Count is 0.\n";
        return true;
    }

    std::string yearInput;
    std::cout << "Enter year Y: ";
    if (!std::getline(std::cin, yearInput)) {
        return false;
    }

    int targetYear = 0;
    if (!parseStrictInt(yearInput, targetYear)) {
        std::cout << "Error: Invalid integer for year.\n";
        return true;
    }

    auto count = std::count_if(catalog.begin(), catalog.end(), [targetYear](const Book& b) {
        return b.getYear() > targetYear;
    });

    std::cout << "Books published strictly after " << targetYear << ": " << count << "\n";
    return true;
}

int main() {
    std::vector<Book> catalog;
    std::string choiceInput;

    while (true) {
        printMenu();

        if (!std::getline(std::cin, choiceInput)) {
            std::cout << "\nEnd of input reached. Exiting program.\n";
            return 0;
        }

        int choice = -1;
        if (!parseStrictInt(choiceInput, choice)) {
            std::cout << "Error: Invalid menu command. Please enter a number from 0 to 6.\n";
            continue;
        }

        switch (choice) {
            case 1:
                if (!addBook(catalog)) {
                    std::cout << "\nEnd of input reached. Exiting program.\n";
                    return 0;
                }
                break;
            case 2:
                showBooks(catalog);
                break;
            case 3:
                sortByYearAscending(catalog);
                break;
            case 4:
                sortByYearDescending(catalog);
                break;
            case 5:
                if (!searchBooks(catalog)) {
                    std::cout << "\nEnd of input reached. Exiting program.\n";
                    return 0;
                }
                break;
            case 6:
                if (!countBooksAfterYear(catalog)) {
                    std::cout << "\nEnd of input reached. Exiting program.\n";
                    return 0;
                }
                break;
            case 0:
                std::cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                std::cout << "Error: Unknown command. Please choose between 0 and 6.\n";
                break;
        }
    }
}
