#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    size_t dimensions;
    T* data;

public:
    Vector<T>(size_t dimensions) : dimensions(dimensions), data(new T[dimensions]())
    {}

    Vector<T>() : dimensions(0), data(nullptr)
    {}

    virtual ~Vector<T>() {
        if (data) delete[] data;
    }

    size_t size() const {
        return dimensions;
    }

    T& operator[](size_t index) { // a
        return data[index];
    }

    const T& operator[](size_t index) const { // a
        return data[index];
    }

    friend ostream& operator<< <>(ostream& os, const Vector<T>& x);

    Vector<T> operator+(const Vector<T>& other) const { // b
        if (this->dimensions != other.dimensions) {
            throw std::invalid_argument("Vectors must have the same dimensions for addition.");
        }

        Vector<T> result(this->dimensions);
        for (size_t i = 0; i < this->dimensions; ++i) {
            result[i] = this->data[i] + other.data[i];
        }
        return result;
    }

    Vector<T> operator-(const Vector<T>& other) const { // c
        if (this->dimensions != other.dimensions) {
            throw std::invalid_argument("Vectors must have the same dimensions for subtraction.");
        }

        Vector<T> result(this->dimensions);
        for (size_t i = 0; i < this->dimensions; ++i) {
            result[i] = this->data[i] - other.data[i];
        }
        return result;
    }

    bool operator==(const Vector<T>& other) const { // d
        if (this->dimensions != other.dimensions) {
            return false;
        }

        for (size_t i = 0; i < this->dimensions; ++i) {
            if (this->data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Vector<T>& other) const { // e
        return !(*this == other);
    }
};

template <typename T>
ostream& operator<<(ostream& os, const Vector<T>& x) {
    for (size_t i = 0; i < x.size(); i++) {
        os << x.data[i] << " ";
    }
    return os;
}
