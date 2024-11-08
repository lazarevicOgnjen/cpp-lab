#include <iostream>
#include "Image.h"

Image::Image() {
    size = 0;
    location = nullptr;
    data = nullptr;
}

Image::Image(int size) {
    this->size = size;
    location = new char[size];
    data = new short*[size];
    for (int i = 0; i < size; i++) {
        data[i] = new short[size];
    }
}

Image::~Image() {
    delete[] location;
    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void Image::Invert() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; ++j) {
            data[i][j] = data[i][j] == 0 ? 1 : 0;
        }
    }
}

void Image::Load() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> data[i][j];
        }
    }
}

void Image::Print() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool Image::Crop(int newSize) {
    if (newSize > size) {
        return false;
    }

    auto **newData = new short*[newSize];
    for (int i = 0; i < newSize; i++) {
        newData[i] = new short[newSize];
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            newData[i][j] = data[i][j];
        }
    }

    for (int i = 0; i < size; i++) {
        delete[] data[i];
    }

    delete[] data;

    data = newData;
    size = newSize;

    return true;
}
