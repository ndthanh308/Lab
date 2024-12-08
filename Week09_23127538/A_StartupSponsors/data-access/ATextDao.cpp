#include "ATextDao.h"

string ATextDao::toString() const
{
    return "ATextDao";
}

vector<shared_ptr<Object>> ATextDao::getAll()
{
    vector<shared_ptr<Object>> startups;

    const string filename = "data/MayProposals.txt";

    ifstream ifs;
    ifs.open(filename, ios::in);

    if(!ifs.is_open())
    {
        cout << "Cannot open file " << filename << " !!!\n";
        return startups;
    }

    string line;
    while(getline(ifs, line))
    {
        // Idea: SuperTech, DevMonths=6
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
            shared_ptr<IStartup> startup = dynamic_pointer_cast<IStartup>(parser->parse(line));
            startups.push_back(startup);
        }   
    }

    ifs.close();
    return startups;
}

string ATextDao::_firstWord(string line)
{
    // Idea: SuperTech, DevMonths=6
    size_t colonPos = line.find_first_of(':');
    string firstWord = line.substr(0, colonPos);

    return firstWord;
}
