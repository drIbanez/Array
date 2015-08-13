#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <initializer_list>
#include <stdexcept>

template <class T, size_t size>
class Array
{    
public:
    T array[size];
    ~Array();
    T operator[](T digital) const {
        if (digital >= size)
            throw std::invalid_argument ("Out of range");
        return array[digital];
    }
    T & operator[](T digital) {
        if (digital >= size)
            throw std::invalid_argument ("Out of range");
        return array[digital];
    }
    void Show();
};

template<typename T, size_t size>
Array<T, size>::~Array()
{
}

template<typename T, size_t size>
void Array<T, size>::Show()
{
    for (size_t i = 0; i < size; ++i)
        std::cout << array[i] << ' ';
}


#endif // ARRAY_H
