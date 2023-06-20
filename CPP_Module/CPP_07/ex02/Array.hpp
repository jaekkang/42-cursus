#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array {
  private:
    T *_arr;
    unsigned int _size;

  public:
    Array() : _arr(nullptr), _size(0){};
    Array(unsigned int n) {
        this->_size = n;
        this->_arr = new T[n];
    };

    ~Array() {
        if (_arr)
            delete[] _arr;
    };

    Array(const Array &obj) {
        _size = obj._size;
        if (this->_arr)
            delete[] _arr;
        _arr = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _arr[i] = obj._arr[i];
        }
    };

    Array &operator=(const Array &obj) {
        if (this != &obj) {
            if (this->_arr)
                delete[] _arr;
            _size = obj._size;
            _arr = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _arr[i] = obj._arr[i];
            }
        }
        return (*this);
    };

    T &operator[](int i) {
        if (i < 0 || static_cast<unsigned int>(i) >= this->_size) {
            throw std::out_of_range("Index out of range");
        } else {
            return (this->_arr[i]);
        }
    }

    const T &operator[](int i) const {
        if (i < 0 || static_cast<unsigned int>(i) >= _size) {
            throw std::out_of_range("Index out of range");
        } else {
            return _arr[i];
        }
    }

    int size() { return (this->_size); }
};

#endif