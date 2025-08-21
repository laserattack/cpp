#include <limits>
#include <iostream>

int main() {
    std::cout << std::numeric_limits<float>::max() << std::endl; // 3.40282e+38
    std::cout << std::numeric_limits<int>::max() << std::endl; // 2147483647
}
