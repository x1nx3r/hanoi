#include <iostream>
#include <stack>
#include <string>

// Define a struct
struct Student {
    std::string name;
    int age;
    std::string major;
};

int main() {
    // Create a stack of Student structs
    std::stack<Student> studentStack;

    // Push elements onto the stack
    studentStack.push({"Alice", 20, "Computer Science"});
    studentStack.push({"Bob", 22, "Mathematics"});
    studentStack.push({"Charlie", 21, "Physics"});

    // Access the top element of the stack
    std::cout << "Top element: " << studentStack.top().name << std::endl;

    // Pop an element from the stack
    studentStack.pop();

    // Display the updated top element
    std::cout << "Top element after pop: " << studentStack.top().name << std::endl;

    // Check if the stack is empty
    if (studentStack.empty()) {
        std::cout << "Stack is empty." << std::endl;
    } else {
        std::cout << "Stack is not empty." << std::endl;
    }

    // Display the size of the stack
    std::cout << "Stack size: " << studentStack.size() << std::endl;

    return 0;
}
