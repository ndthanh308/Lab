#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Object.h"
#include "Book.h"
#include "Date.h"
#include <sstream>
#include <memory>
#include <time.h>


using std::string;
using std::shared_ptr;
using std::make_shared;

class Employee : public Object
{
    private:
        string _name;
        string _email;
        Date _startDate;
        Book _book;
        
    public:
        // Constructors
        Employee();
        Employee(const string& name, const string& email, const Date& startDate, const Book& book);

        // Getter methods
        string name() const;
        string email() const;
        Date startDate() const;
        Book book() const;

        // Setter methods
        void setName(const string& name);
        void setEmail(const string& email);
        void setStartDate(const Date& startDate);
        void setBook(const Book& book);

    public:
        // Override toString method
        string toString() const override;

        float yearWork();
        string seniority();
        float percentOfSponsoring();
        float sponsorship();
};

#endif // EMPLOYEE_H