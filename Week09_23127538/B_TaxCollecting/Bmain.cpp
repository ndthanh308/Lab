#include "Bmain.h"

int main()
{
    shared_ptr<IDao> dao = make_shared<BTextDao>();
    vector<shared_ptr<Object>> stalls = dao->getAll();
    vector<string> headers = {"Rank", "ID", "Name of stall", "Area", "Fee / m2", "Premises rent", "Other fee", "Total fee"};
    vector<int> columnSizes = {4, 7, 15, 10, 10, 25, 15, 20};
    const string intro = "Report on Collecting Premises Rental Fees for Ben Thanh\nMonth: May 2024";

    shared_ptr<ToTableConverter> converter = make_shared<StallToTableConverter>(headers, columnSizes);
    sort(stalls.begin(), stalls.end(), compareByTotalFee);
    cout << converter->convert(stalls, intro);


    return 0;
}

bool compareByTotalFee(const shared_ptr<Object>& a, const shared_ptr<Object>& b) 
{
    shared_ptr<IStall> stallA = dynamic_pointer_cast<IStall>(a);
    shared_ptr<IStall> stallB = dynamic_pointer_cast<IStall>(b);
    if (stallA && stallB) {
        return stallA->totalFee() < stallB->totalFee();
    }
    return false; // Handle invalid cast
}