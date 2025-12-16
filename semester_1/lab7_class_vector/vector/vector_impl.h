#pragma once
#include <iostream>
#include <initializer_list>
class Vector {
    // your code goes here

private:
    int* data_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    
    Vector();
    explicit Vector(size_t size);
    Vector(std::initializer_list<int> list);
    Vector(const Vector& other);

    Vector& operator=(const Vector& other);

    ~Vector();

    void Swap(Vector& other);

    int& operator[](size_t index);
    const int& operator[](size_t index) const;

    int& At(size_t index);
    const int& At(size_t index) const;

    size_t Size() const;
    size_t Capacity() const;

    void PushBack(int value);
    void PopBack();
    void Clear();
    void Reserve(size_t new_capacity);

    friend std::ostream& operator<<(std::ostream& os, const Vector& vec);
};


