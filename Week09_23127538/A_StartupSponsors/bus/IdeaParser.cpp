#include "IdeaParser.h"
using std::regex;

string IdeaParser::toString() const { return "IdeaParser"; }

shared_ptr<Object> IdeaParser::parse(const string& data) const
{
    // Pattern to match Idea: SuperTech, DevMonths=6
    regex pattern("Idea: (.+?), DevMonths=(\\d+)"); // chat gpt has updated code for more flexible, we use (.+?) instead of (\\w+)
    smatch matches;

    if (regex_search(data, matches, pattern)) 
    {
        // Extract matched values
        string name = matches[1];
        int devMonths = stoi(matches[2]);

        // Create and return a shared_ptr to Idea
        return make_shared<Idea>(name, devMonths);
    } 
    else 
    {
        throw invalid_argument("Invalid data format: " + data);
    }
}