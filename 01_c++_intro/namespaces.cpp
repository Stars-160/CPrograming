//Create Namespace
#include <iostream>

namespace first {
    int a = 5;

    void print() {
        std::cout << "first" << std::endl;
    }
}

namespace second {
    
    void print() {
        std::cout << "Second" << std::endl;
    }
}

int main(void) {
    first::print();
    second::print();

    return 0;
} 
