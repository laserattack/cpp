#include <iostream>

enum keyword { ASM, AUTO, BREAK };

int main() {
    keyword k = AUTO;
    std::cout << k << std::endl;
    return 0;
}
