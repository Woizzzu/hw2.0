#include <algorithm>
#include <iostream>
#include <limits>
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

void clearInputStream() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool isBlank(const std::string& str) {
    return str.find_first_not_of(" \t\r\n") == std::string::npos;
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

void addBook(std::vector<Book>& catalog) {
    std::string title;
    std::cout << "Enter book title: ";
    std::getline(std::cin, title);

    if (isBlank(title)) {
        std::cout << "Error: Book title cannot be empty. Book was not added.\n";
        return;
    }

    int year = 0;
    std::cout << "Enter publication year: ";
    if (!(std::cin >> year)) {
        std::cout << "Error: Invalid input for year. Book was not added.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    if (year <= 0) {
        std::cout << "Error: Publication year must be greater than 0. Book was not added.\n";
        return;
    }

    catalog.emplace_back(title, year);
    std::cout << "Book added successfully.\n";
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

void searchBooks(const std::vector<Book>& catalog) {
    if (catalog.empty()) {
        std::cout << "Catalog is empty. Nothing to search.\n";
        return;
    }

    std::string query;
    std::cout << "Enter title or part of title to search: ";
    std::getline(std::cin, query);

    if (isBlank(query)) {
        std::cout << "Error: Search query cannot be empty.\n";
        return;
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
}

void countBooksAfterYear(const std::vector<Book>& catalog) {
    if (catalog.empty()) {
        std::cout << "Catalog is empty. Count is 0.\n";
        return;
    }

    int targetYear = 0;
    std::cout << "Enter year Y: ";
    if (!(std::cin >> targetYear)) {
        std::cout << "Error: Invalid input for year.\n";
        clearInputStream();
        return;
    }
    clearInputStream();

    auto count = std::count_if(catalog.begin(), catalog.end(), [targetYear](const Book& b) {
        return b.getYear() > targetYear;
    });

    std::cout << "Books published strictly after " << targetYear << ": " << count << "\n";
}

int main() {
    std::vector<Book> catalog;
    int choice = -1;

    while (true) {
        printMenu();

        if (!(std::cin >> choice)) {
            std::cout << "Error: Invalid menu command. Please enter a number from 0 to 6.\n";
            clearInputStream();
            continue;
        }
        clearInputStream();

        switch (choice) {
            case 1:
                addBook(catalog);
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
                searchBooks(catalog);
                break;
            case 6:
                countBooksAfterYear(catalog);
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
