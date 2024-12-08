#ifndef MVP_H
#define MVP_H

#include "IStartup.h"
#include <string>
using namespace std;

class MVP : public IStartup
{
    private:
        const int _supportEachMonthForRun = 930;       // Monthly support for running
        const int _supportEachMonthForMarketing = 500; // Monthly support for marketing
        int _runMonths;                                // Number of months for running
        int _marketingMonths;                          // Number of months for marketing

    public:
        // Constructors
        MVP();
        MVP(const string &name, int runMonths, int marketingMonths);

        // Getter and Setter for runMonths
        int runMonths() const;
        void setRunMonths(int runMonths);

        // Getter and Setter for marketingMonths
        int marketingMonths() const;
        void setMarketingMonths(int marketingMonths);

        // Getter and Setter for name
        string name() const;
        void setName(const string &name);

        // Overridden methods
        string toString() const override;
        string info() const override;
        int budget() const override;
};

#endif // MVP_H
