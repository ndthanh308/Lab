#include "BTextDao.h"

string BTextDao::toString() const
{
    return "BTextDao";
}

vector<shared_ptr<Object>> BTextDao::getAll()
{
    vector<shared_ptr<Object>> stalls;

    const string filename = "data/RentMay24.txt";

    ifstream ifs;
    ifs.open(filename, ios::in);

    if(!ifs.is_open())
    {
        cout << "Cannot open file " << filename << " !!!\n";
        return stalls;
    }

    string line;
    while(getline(ifs, line))
    {
        // Food ID=A724, Area=78, ColdStorage=3000000
        string name = _firstWord(line);
        const string type = "parser";

        shared_ptr<IParsable> parser = nullptr;
        auto service = Factory::getServiceForNameAndType(name, type);
        if (service)
        {
            parser = dynamic_pointer_cast<IParsable>(service); // Preferred way for `shared_ptr`
        }
        if(parser)
        {
            shared_ptr<IStall> stall = dynamic_pointer_cast<IStall>(parser->parse(line));
            stalls.push_back(stall);
        }   
    }

    ifs.close();
    return stalls;
}

string BTextDao::_firstWord(string line)
{
    // Food ID=A724, Area=78, ColdStorage=3000000
    size_t spacePos = line.find_first_of(' ');
    string firstWord = line.substr(0, spacePos);

    return firstWord;
}
