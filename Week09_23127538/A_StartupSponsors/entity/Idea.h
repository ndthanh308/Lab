#ifndef IDEA_H
#define IDEA_H

#include "IStartup.h"
#include <string>
using namespace std;

class Idea : public IStartup
{
    private:
        const int _supportEachMonth = 2200; // Monthly support budget
        int _devMonths;                    // Number of development months

    public:
        // Constructors
        Idea();
        Idea(const string &name, int devMonths);

        // Getter and Setter for devMonths
        int devMonths() const;
        void setDevMonths(int devMonths);

        // Getter and Setter for name
        string name() const;
        void setName(const string &name);

        // Overridden methods
        string toString() const override;
        string info() const override;
        int budget() const override;
};

#endif // IDEA_H
