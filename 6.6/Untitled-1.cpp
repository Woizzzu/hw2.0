#include <iostream>
#include <string>

class Product {
private:
    std::string name_;
    double price_;
    int count_;

public:
    Product(const std::string& name, double price, int count)
        : name_(name), price_(price >= 0 ? price : 0.0), count_(count >= 0 ? count : 0) {}

    double total() const {
        return price_ * count_;
    }

    bool sell(int n) {
        if (n <= 0) {
            std::cout << "Error: quantity to sell must be positive.\n";
            return false;
        }
        if (n > count_) {
            std::cout << "Failed to sell " << n << " unit(s) of \"" << name_
                      << "\". Not enough stock (available: " << count_ << ").\n";
            return false;
        }
        count_ -= n;
        std::cout << "Sold " << n << " unit(s) of \"" << name_
                  << "\". Remaining stock: " << count_ << ".\n";
        return true;
    }

    void restock(int n) {
        if (n <= 0) {
            std::cout << "Error: restock quantity must be positive.\n";
            return;
        }
        count_ += n;
        std::cout << "Restocked " << n << " unit(s) of \"" << name_
                  << "\". Current stock: " << count_ << ".\n";
    }

    void printInfo() const {
        std::cout << "Product: " << name_
                  << " | Price: $" << price_
                  << " | Stock: " << count_
                  << " | Total value: $" << total() << "\n";
    }
};

int main() {
    Product laptop("Gaming Laptop", 1200.0, 5);

    std::cout << "--- Initial State ---\n";
    laptop.printInfo();

    std::cout << "\n--- Successful Sale ---\n";
    laptop.sell(3);
    laptop.printInfo();

    std::cout << "\n--- Failed Sale (Insufficient Stock) ---\n";
    laptop.sell(4);
    laptop.printInfo();

    std::cout << "\n--- Restock & Retry Sale ---\n";
    laptop.restock(5);
    laptop.sell(4);
    laptop.printInfo();

    return 0;
}