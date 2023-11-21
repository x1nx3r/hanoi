#include <iostream>
#include <string>

int main() {
    std::string myString;

    // Prompt the user to enter a line
    std::cout << "Enter a line: ";
    
    // Use getline to read the entire line, including spaces
    std::getline(std::cin, myString);

    // Display the entered line
    std::cout << "You entered: " << myString << std::endl;

    return 0;
}
