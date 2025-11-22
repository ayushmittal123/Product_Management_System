
#include <iostream>
#include <string>
#include <cctype>
#include <cstdint>
using namespace std;

// Macros for menu options
#define ADD_PRODUCT    1
#define LIST_PRODUCTS  2
#define SEARCH_PRODUCT 3
#define DELETE_PRODUCT 4
#define EXIT_MENU      5

// Constants for validation
constexpr int MIN_CHOICE = 1;
constexpr int MAX_CHOICE = 5;

bool isValidInteger(const string& input) {
    // Trim spaces
    size_t start = input.find_first_not_of(' ');
    size_t end = input.find_last_not_of(' ');
    if (start == string::npos) return false; // all spaces

    string trimmed = input.substr(start, end - start + 1);
    if (trimmed.empty()) return false;

    // Check sign
    int pos = 0;
    if (trimmed[0] == '-' || trimmed[0] == '+') {
        if (trimmed.size() == 1) return false; // only sign
        pos = 1;
    }

    // Check digits
    for (int i = pos; i < trimmed.size(); i++) {
        if (!isdigit(trimmed[i])) return false;
    }

    // Convert and validate range
    try {
        int value = stoi(trimmed);
        if (value < MIN_CHOICE || value > MAX_CHOICE) return false;
    } catch (...) {
        return false;
    }

    return true;
}

int main() {
    string userInput;
    uint8_t choice = 0;

    do {
        cout << "\n--- Product Menu ---\n";
        cout << ADD_PRODUCT    << ". Add Product\n";
        cout << LIST_PRODUCTS  << ". List Products\n";
        cout << SEARCH_PRODUCT << ". Search Product\n";
        cout << DELETE_PRODUCT << ". Delete Product\n";
        cout << EXIT_MENU      << ". Exit\n";
        cout << "Enter your choice: ";
        getline(cin, userInput);

        if (!isValidInteger(userInput)) {
            cout << "Input is invalid! Please enter an integer between "
                 << MIN_CHOICE << " and " << MAX_CHOICE << ".\n";
            continue;
        }

        choice = stoi(userInput);

        switch (choice) {
            case ADD_PRODUCT:    cout << "Add Product selected.\n"; break;
            case LIST_PRODUCTS:  cout << "List Products selected.\n"; break;
            case SEARCH_PRODUCT: cout << "Search Product selected.\n"; break;
            case DELETE_PRODUCT: cout << "Delete Product selected.\n"; break;
            case EXIT_MENU:      cout << "Exiting...\n"; break;
            default:             cout << "Invalid choice! Try again.\n";
        }
    } while (choice != EXIT_MENU);

    return 0;
}
