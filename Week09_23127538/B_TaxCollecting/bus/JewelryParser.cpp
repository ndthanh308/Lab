#include "JewelryParser.h"

using std::regex;
using std::smatch;
using std::invalid_argument;

shared_ptr<Object> JewelryParser::parse(const string &data) const
{
    // Pattern to match Jewelry ID=C682, Area=55, SecurityFee=7000000
    regex pattern("Jewelry ID=(.+?), Area=(\\d+), SecurityFee=(\\d+)"); // chat gpt has updated code for more flexible, we use (.+?) instead of (\\w+)
    smatch matches;

    if (regex_search(data, matches, pattern)) 
    {
        // Extract matched values
        string id = matches[1];
        int area = stoi(matches[2]);
        int otherFee = stoi(matches[3]);

        // Create and return a shared_ptr to Idea
        return make_shared<Jewelry>(id, area, otherFee);
    } 
    else 
    {
        throw invalid_argument("Invalid data format: " + data);
    }
}

string JewelryParser::toString() const
{
    return "JewelryParser";
}
