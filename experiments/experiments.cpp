#include <iostream>
#include <thread>

using namespace std;

void unbuffered() {
    cerr << "UNBUFFERED" << endl;
    cerr << "some ";
    this_thread::sleep_for(chrono::seconds(2)); 
    cerr << "text" << endl; 
}

void buffered() {
    cerr << "BUFFERED" << endl;
    cout << "some ";
    this_thread::sleep_for(chrono::seconds(2)); 
    cout << "text" << endl; 
}

int main() {
    buffered();
    cout << endl;
    unbuffered();
}
