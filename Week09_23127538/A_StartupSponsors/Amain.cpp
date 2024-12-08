#include "Amain.h"

int main()
{
    shared_ptr<IDao> dao = make_shared<ATextDao>();
    vector<shared_ptr<Object>> startups = dao->getAll();
    vector<string> headers = {"Rank", "Kind of startup", "Name of startup", "Information", "Budget"};
    vector<int> columnSizes = {4, 20, 20, 45, 23}; // we need to fit the size 
    const string intro = "Funding Plan for AlphaTech's Internal Startup Project\nMonth: May 2024";

    shared_ptr<ToTableConverter> converter = make_shared<StartupToTableConverter>(headers, columnSizes);
    sort(startups.begin(), startups.end(), compareByBudget);
    cout << converter->convert(startups, intro);


    return 0;
}

bool compareByBudget(const shared_ptr<Object>& a, const shared_ptr<Object>& b) 
{
    shared_ptr<IStartup> startupA = dynamic_pointer_cast<IStartup>(a);
    shared_ptr<IStartup> startupB = dynamic_pointer_cast<IStartup>(b);
    if (startupA && startupB) {
        return startupA->budget() < startupB->budget();
    }
    return false; // Handle invalid cast
}