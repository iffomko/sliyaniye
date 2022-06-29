#include <iostream>
#include <fstream>
#include "array.h"

int main() {
    std::ifstream fin("C:\\project14\\input.txt");

    if (!fin) {
        std::cout << "Failed!\n";
    } else {
        array arr1(fin);
        array arr2(fin);
        arr1.print();
        arr2.print();
        arr1 = arr1 + arr2;
        arr1.print();

        fin.close();
    }

    return 0;
}