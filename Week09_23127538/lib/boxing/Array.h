#ifndef ARRAY_H
#define ARRAY_H

#include "../Object.h"
#include <stdexcept> // For out_of_range
#include <initializer_list> // For initializer list support

using std::initializer_list;

/// @brief DynamicArray - A dynamic array class for boxing a collection of elements.
template<typename T>
class Array : public Object
{
private:
    T* _data;          // Pointer to the dynamic array
    size_t _size;      // Current number of elements in the array
    size_t _capacity;  // Total capacity of the array

    /// @brief Resizes the internal storage to a new capacity.
    /// @param newCapacity The new capacity of the array.
    void resize(size_t newCapacity)
    {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < _size; ++i)
        {
            newData[i] = _data[i];
        }
        delete[] _data;
        _data = newData;
        _capacity = newCapacity;
    }

public:
    /// @brief Default constructor.
    Array() : _data(nullptr), _size(0), _capacity(0) {}

    /// @brief Constructor with initial size and default value.
    /// @param initialSize The initial number of elements in the array.
    /// @param defaultValue The default value for each element.
    Array(size_t initialSize, const T& defaultValue = T())
        : _data(new T[initialSize]), _size(initialSize), _capacity(initialSize)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _data[i] = defaultValue;
        }
    }

    /// @brief Constructor from an initializer list.
    /// @param list Initializer list of elements.
    Array(initializer_list<T> list)
        : _data(new T[list.size()]), _size(list.size()), _capacity(list.size())
    {
        size_t index = 0;
        for (const T& value : list)
        {
            _data[index++] = value;
        }
    }

    /// @brief Copy constructor.
    Array(const Array<T>& other)
        : _data(new T[other._capacity]), _size(other._size), _capacity(other._capacity)
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _data[i] = other._data[i];
        }
    }

    /// @brief Move constructor.
    Array(Array<T>&& other) noexcept
        : _data(other._data), _size(other._size), _capacity(other._capacity)
    {
        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    /// @brief Destructor.
    virtual ~Array()
    {
        if (_data != nullptr)
        {
            delete[] _data;
            // _size = 0;
            // _capacity = 0; this is not neccessary
        }
    }

    /// @brief Adds a new element to the end of the array.
    /// @param value The value to be added.
    void add(const T& value)
    {
        if (_size == _capacity)
        {
            resize(_capacity == 0 ? 1 : _capacity * 2);
        }
        _data[_size++] = value;
    }

    /// @brief Removes the last element of the array.
    void removeLast()
    {
        if (_size > 0)
        {
            --_size;
        }
    }

    /// @brief Access operator.
    /// @param index The index of the element.
    /// @return Reference to the element at the given index.
    /// @throws out_of_range If the index is out of bounds.
    T& operator[](size_t index)
    {
        if (index >= _size)
        {
            throw out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    /// @brief Const access operator.
    /// @param index The index of the element.
    /// @return Const reference to the element at the given index.
    /// @throws out_of_range If the index is out of bounds.
    const T& operator[](size_t index) const
    {
        if (index >= _size)
        {
            throw out_of_range("Index out of bounds");
        }
        return _data[index];
    }

    /// @brief Gets the current number of elements in the array.
    /// @return The size of the array.
    size_t getSize() const
    {
        return _size;
    }

    /// @brief Clears all elements in the array.
    void clear()
    {
        _size = 0;
    }

    /// @brief Gets the capacity of the array.
    /// @return The total capacity of the array.
    size_t getCapacity() const
    {
        return _capacity;
    }

    /// @brief Copy assignment operator.
    Array<T>& operator=(const Array<T>& other)
    {
        if (this != &other)
        {
            delete[] _data;
            _size = other._size;
            _capacity = other._capacity;
            _data = new T[_capacity];
            for (size_t i = 0; i < _size; ++i)
            {
                _data[i] = other._data[i];
            }
        }
        return *this;
    }

    /// @brief Move assignment operator.
    Array<T>& operator=(Array<T>&& other) noexcept
    {
        if (this != &other)
        {
            delete[] _data;
            _data = other._data;
            _size = other._size;
            _capacity = other._capacity;

            other._data = nullptr;
            other._size = 0;
            other._capacity = 0;
        }
        return *this;
    }
};

#endif // ARRAY_H
