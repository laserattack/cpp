#include <iostream>
#include <typeinfo>

using namespace std;

void references() {
    cout << endl << "REFERENCES" << endl;

    int a = 1337;
    int* a_ptr = &a;
    int& a_ref = a;
    
    cout << "a_ptr = " << a_ptr << endl;
    cout << "a_ref = " << a_ref << endl;
    cout << "*a_ptr = " << *a_ptr << endl;
    cout << "&a_ref = " << &a_ref << endl;
}

void arrays_and_ptrs() {
    
    std::cout << std::endl << "ARRAYS AND PTRS" << std::endl;

    // Массив - это сам объект данных (непрерывная область памяти, хранящая N элементов).
    // этот объект данных имеет размер равным сумме размеров всех элементов
    // Указатель - это адрес, по которому этот массив находится (его первый элемент).
    // во _всех выражениях_ имя массива преобразуется в указатель на массив (arr ==  &arr)

    int arr[] = {1,2,3,4};
    // неявное преобразование в адрес первого элемента
    std::cout << "arr = " << arr << std::endl; // 0x7ffdc3df7b70
    // явно берем адрес первого элемента
    std::cout << "&arr[0] = " << &arr[0] << std::endl; // 0x7ffdc3df7b70
    // а вот сам указатель на массив в прямой форме записи,
    // тип тут int(*)[4] (указатель на массив из 4 элементов)
    std::cout << "&arr = " << &arr << std::endl; // 0x7ffdc3df7b70

    // Обычный массив (переменная v имеет тип A4_i)
    int v[] = {1, 2, 3, 4};
    std::cout << "Type: " << typeid(v).name() << std::endl; // A4_i

    // Указатель на первый элемент массива (переменная имеет тип Pi)
    int* p1 = v; // неявное преобразование A4_i в Pi
    std::cout << "Type: " << typeid(p1).name() << std::endl; // Pi
    int* p2 = &v[0]; // тоже самое явно
    std::cout << "Type: " << typeid(p2).name() << std::endl; // Pi
    // т.е. `p1 = v` это синтаксический сахар для `p2 = &v[0]`

    // получить именно тот же тип можно так (через разыменование указателя на массив)
    int (*pp3)[4] = &v; // само pp3 имеет тип PA4_i (указатель на массив)
    std::cout << "Type: " << typeid(*pp3).name() << std::endl; // A4_i
}

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
    arrays_and_ptrs();
    references();
    return 0;
}
