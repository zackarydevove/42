#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array {
public:
    Array() : _array(NULL), _size(0) {}
    
    Array(unsigned int n) : _array(new T[n]()), _size(n) {}
    
    Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other._array[i];
    }
    
    ~Array() { delete[] _array; };
    
    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] _array;
            _array = new T[other._size];
            _size = other._size;
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        return *this;
    }
    
    T &operator[](unsigned int index) {
        if (index >= _size)
            throw std::out_of_range("Array index out of range");
        return _array[index];
    }
    
    unsigned int size() const {
        return _size;
    }
    
private:
    T *_array;
    unsigned int _size;
};

#endif