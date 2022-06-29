//
// Created by Iluha on 28.06.2022.
//

#include "array.h"

array::array() {
    this->arr = nullptr;
    this->size = 0;
}

array::array(std::ifstream &fin) {
    fin >> this->size;

    this->arr = new int[this->size];

    for (int i = 0; i < this->size; i++)
        fin >> this->arr[i];

    for (int i = 0; i < this->size - 1; i++)
        for (int j = i + 1; j < this->size; j++)
            if (this->arr[i] > this->arr[j]) {
                int temp = this->arr[i];
                this->arr[i] = this->arr[j];
                this->arr[j] = temp;
            }
}

array::array(const array &other) {
    delete[] this->arr;

    this->size = other.size;
    this->arr = new int[this->size];

    for (int i = 0; i < this->size; i++)
        this->arr[i] = other.arr[i];
}

array::~array() {
    delete[] this->arr;
}

void array::shiftRight(int index) {
    if (this->arr != nullptr)
        for (int i = this->size; i > index; i--)
            this->arr[i] = this->arr[i - 1];
}

array& array::operator+(const array &other) {
    int* temp = this->arr;

    this->arr = new int[this->size + other.size];

    for (int i = 0; i < this->size; i++)
        this->arr[i] = temp[i];

    int count = this->size;
    this->size = this->size + other.size;

    for (int i = 0; i < other.size; i++) {
        bool check = false;

        for (int j = 0; j < count; j++) {
            if (this->arr[j] > other.arr[i]) {
                check = true;
                this->shiftRight(j);
                this->arr[j] = other.arr[i];
                break;
            }
        }

        if (!check) {
            this->arr[count++] = other.arr[i];
        } else {
            count++;
        }
    }

    return *this;
}

void array::print() {
    for (int i = 0; i < this->size; i++)
        std::cout << this->arr[i] << " ";
    std::cout << std::endl;
}