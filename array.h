//
// Created by Iluha on 28.06.2022.
//

#pragma once
#ifndef PROJECT14_ARRAY_H
#define PROJECT14_ARRAY_H

#include <iostream>
#include <fstream>

class array {
    int* arr;
    int size;
public:
    array();
    array(std::ifstream &fin);
    array(const array &other);
    ~array();

    void shiftRight(int index);
    array& operator+(const array &other);
    void print();
};


#endif //PROJECT14_ARRAY_H
