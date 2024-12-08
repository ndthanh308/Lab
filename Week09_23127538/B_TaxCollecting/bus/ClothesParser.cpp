#include "ClothesParser.h"

using std::regex;
using std::smatch;
using std::invalid_argument;

// Mvp: FutureCar, RunMonths=6, Marketing=3 
shared_ptr<Object> ClothesParser::parse(const string& data) const
{
    // Define the regex pattern Clothes ID=B419, Area=33
    regex pattern("Clothes ID=(.+?), Area=(\\d+)");
    smatch matches;

    // Check if the data matches the expected pattern
    if (regex_search(data, matches, pattern))
    {
        // Extract values
        string id = matches[1];
        int area = stoi(matches[2]);

        // Create and return a shared_ptr to MVP
        return make_shared<Clothes>(id, area);
    }
    else
    {
        throw invalid_argument("Invalid data format: " + data);
    }
}

// Returns a description of the parser
string ClothesParser::toString() const { return "ClothesParser"; }
