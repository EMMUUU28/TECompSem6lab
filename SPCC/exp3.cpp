#include <iostream>
#include <string>

// Function prototypes
bool E(const std::string& input, size_t& cursor);

int main() {
    std::string input;
    std::cout << "Enter the string: ";
    std::cin >> input;

    size_t cursor = 0;

    // Call the starting non-terminal E
    if (E(input, cursor) && cursor == input.length()) {
        std::cout << "String is successfully parsed\n";
        return 0;
    } else {
        std::cout << "Error in parsing String\n";
        return 1;
    }
}

// Grammar rule: E -> E + E | a
bool E(const std::string& input, size_t& cursor) {
    size_t start = cursor;

    // Try matching the non-terminal E
    if (input[cursor] == 'a') {
        cursor++; // Move to the next character
        if (cursor == input.length()) {
            return true; // Reached the end of the string after parsing 'a'
        }
        // Continue parsing 'E' if the end of the string is not reached
        if (input[cursor] == '+') {
            cursor++; // Move to the next character
            if (E(input, cursor)) {
                return true;
            }
        }
        return true; // Successfully parsed 'a'
    } else if (E(input, cursor)) {
        if (cursor < input.length() && input[cursor] == '+') {
            cursor++; // Move to the next character
            if (E(input, cursor)) {
                return true;
            }
        }
    }

    // If neither 'a' nor E + E matches, backtrack
    cursor = start;
    return false;
}
