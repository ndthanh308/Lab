#ifndef BOOK_H
#define BOOK_H

#include "Object.h"


class Book : public Object
{
    private:
        string _title;
        float _price;
        string _link;
    
    public:
        // Constructors
        Book();
        Book(const string& title, float price, const string& link);

        // Getter methods
        string title() const;
        float price() const;
        string link() const;

        // Setter methods
        void setTitle(const string& title);
        void setPrice(float price);
        void setLink(const string& link);

        // Override toString method
        string toString() const override;

};

#endif // BOOK_H