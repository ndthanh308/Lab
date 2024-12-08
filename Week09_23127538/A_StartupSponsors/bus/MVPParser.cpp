#include "MVPParser.h"

using namespace std;

// Mvp: FutureCar, RunMonths=6, Marketing=3 
shared_ptr<Object> MVPParser::parse(const string& data) const
{
    // Define the regex pattern
    regex pattern("Mvp: (.+?), RunMonths=(\\d+), Marketing=(\\d+)");
    smatch matches;

    // Check if the data matches the expected pattern
    if (regex_search(data, matches, pattern))
    {
        // Extract values
        string name = matches[1];
        int runMonths = stoi(matches[2]);
        int marketingMonths = stoi(matches[3]);

        // Create and return a shared_ptr to MVP
        return make_shared<MVP>(name, runMonths, marketingMonths);
    }
    else
    {
        throw invalid_argument("Invalid data format: " + data);
    }
}

// Returns a description of the parser
string MVPParser::toString() const { return "MVPParser"; }
