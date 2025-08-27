#include <iostream>

using namespace std;

struct address {
    char* name;
    long int number;
    char* street;
    char* town;
};

void init1() {
    address a;
    a.name = "John";
    a.number = 61;
}

void init2() {
    address a = {
        "John",
        61,
    };
}

int main() {

    return 0;
} 
