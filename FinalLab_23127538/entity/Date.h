#ifndef DATE_H
#define DATE_H

#include "Object.h"
#include <time.h>
#include <iomanip>

class Date : public Object
{
    private:
        int _day;
        int _month;
        int _year;
    
    public:
        // Constructors
        Date();
        Date(int day, int month, int year);

        // Getter methods
        int day() const;
        int month() const;
        int year() const;

        // Setter methods
        void setDay(int day);
        void setMonth(int month);
        void setYear(int year);
    public:
        string toString() const override;
};

#endif // DATE_H