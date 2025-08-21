#include <iostream>

void ex_lambda() {
    const char* msg = "hello, sailor!";
    // & => всё из родительской области видимост 
    // захватывает по ссылке (reference)
    auto print = [&](int number) { 
        std::cout << number << msg << std::endl; 
    };
    print(10);
}

int main() {
    ex_lambda();
    return 0;
}
