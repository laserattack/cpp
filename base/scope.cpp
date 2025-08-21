#include <iostream>

// Имя называется глобальным, если оно объявлено
// вне функций, классов и пространств имен
int x = 3;

int uninitialized_global_num;

int main() {
    int x = 1;
    // теперь x, которое = 3, скрыто
    std::cout << x << std::endl; // 1
    // доступ к скрытому глобальному имени
    // осуществляется с помощью операции :: 
    // (операция разрешения области видимости)
    std::cout << ::x << std::endl; // 3
    
    int uninitialized_local_num;
    std::cout << "uninitialized_global_num = " << uninitialized_global_num << std::endl // 0 
              << "uninitialized_local_num = " << uninitialized_local_num << std::endl;  // мусор
}
