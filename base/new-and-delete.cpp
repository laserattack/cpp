#include <iostream>

using namespace std;

struct address {
    char* name;
    int number;
};

int main() {
    // Создание объекта на куче с помощью new
    try {
        // () инициализируют все поля значениями по умолчанию
        address* pa = new address();

        cout << pa->number << endl; // -> 0
        // Для удаления объектов используется оператор delete
        // Объект не будет удален пока не вызвано delete
        delete pa;
    } catch(const exception& e) {
        cerr << "Some exception: " << e.what() << endl;
    }

    // Создание массива на куче с помощью new
    try {
        int n = 10;
        // синтаксис new type[elemets number]
        // () инициализируют значением по умолчанию все элементы
        int* s = new int[n]();

        for (int i = 0; i < n; i++) {
            cout << s[i] << " "; // -> 0 0 0 0 0 0 0 0 0 0
        }
        cout << endl;

        // Для удаления массивов используется оператор delete[]
        delete[] s;
    } catch(const bad_alloc& e) {
        cerr << "Memory allocation error: " << e.what() << endl;
    }

    return 0;
}
