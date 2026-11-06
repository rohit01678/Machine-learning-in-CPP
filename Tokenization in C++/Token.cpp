#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[] = "Introduction to C++ Programming";
    char *ptr;
    ptr = strtok(str, " :.-");
    while (ptr != NULL) {
        cout << ptr << endl;
        ptr = strtok(NULL, " :.-");
    }

    return 0;
}