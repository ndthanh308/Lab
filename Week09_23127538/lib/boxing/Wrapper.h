#ifndef WRAPPER_H
#define WRAPPER_H

#include "../Object.h"

template <typename T>
class Wrapper : public Object
{
private:
    T value; // The encapsulated value

public:
    // Default constructor
    Wrapper() = default;

    // Constructor to initialize the value
    explicit Wrapper(const T& value) : value(value) {}

    // Getter for the value
    T getValue() const
    {
        return value;
    }

    // Setter for the value
    void setValue(const T& value)
    {
        this->value = value;
    }

    // Overloaded assignment operator
    Wrapper<T>& operator=(const T& value)
    {
        this->value = value;
        return *this;
    }

    // Virtual destructor
    virtual ~Wrapper() = default;
};

#endif // WRAPPER_H
