#include <iostream>
#include <string>

using namespace std;
struct identity {
    string name;
    int age;
    float height;
};

int main() {
    identity person1 = {"John Doe", 30, 175.5};

    // Print the struct members
    cout << "Name: " << person1.name << std::endl;
    cout << "Age: " << person1.age << std::endl;
    cout << "Height: " << person1.height << std::endl;

    return 0;
}
