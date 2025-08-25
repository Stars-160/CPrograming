#include <iostream>
#include <string>

int main (void) {
    int age = 20;
    double gpa = 3.5;
    char grade = 'A';
    std::string name = "mike"; // string requires <string> header)
    bool isActive = true;

    //scan for input
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::cout << "Enter your age and GPA: ";
    std::cin >> age >> gpa;


    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << grade << std::endl;


    return 0;
}