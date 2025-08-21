#include <iostream>

int foo(const char* arg) {
    return 1;
}

void function_pointers() {
    // указатель на функцию (старый метод)
    {
        int(*fp_old)(const char*) = foo; // явное указание типа
        std::cout << fp_old("123") << std::endl; // 1
    }
    // указатель на функцию (современный метод)
    {
        auto fp_new = foo; // компилятор сам выведет тип
        std::cout << fp_new("123") << std::endl; // 1
    }
}

void null() {
    // Всегда в качестве нулевого указателя надо использовать nullptr.
    // Это позволяет, например, перегружать функции как для указателей так и для
    // целых чисел. Передача NULL/0 приведет к ошибочному выбору версии int
    //
    // nullptr имеет тип std::nullptr_t
    std::cout << nullptr << std::endl; // nullptr
}

int main() {
    function_pointers();
    null();
    return 0;
}
