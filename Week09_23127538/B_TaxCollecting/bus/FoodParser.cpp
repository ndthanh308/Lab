#include "FoodParser.h"
using std::regex;
using std::smatch;
using std::invalid_argument;

string FoodParser::toString() const { return "FoodParser"; }

shared_ptr<Object> FoodParser::parse(const string& data) const
{
    // Pattern to match Food ID=A724, Area=78, ColdStorage=3000000
    regex pattern("Food ID=(.+?), Area=(\\d+), ColdStorage=(\\d+)"); // chat gpt has updated code for more flexible, we use (.+?) instead of (\\w+)
    smatch matches;

    if (regex_search(data, matches, pattern)) 
    {
        // Extract matched values
        string id = matches[1];
        int area = stoi(matches[2]);
        int otherFee = stoi(matches[3]);

        // Create and return a shared_ptr to Idea
        return make_shared<Food>(id, area, otherFee);
    } 
    else 
    {
        throw invalid_argument("Invalid data format: " + data);
    }
}