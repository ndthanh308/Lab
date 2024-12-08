#include "Factory.h"

string Factory::toString() const { return "Factory"; }

void Factory::registerServiceForNameAndType(string name, string type, shared_ptr<Object> o)
{
    servicesForNameAndType.insert({{name, type}, o});
}

shared_ptr<Object> Factory::getServiceForNameAndType(string name, string type)
{
    if(servicesForNameAndType.size() == 0)
    {
        _config();
    }
    return servicesForNameAndType[{name, type}];
}

void Factory::_config()
{
    // A project
    registerServiceForNameAndType("Idea", "parser", make_shared<IdeaParser>());
    registerServiceForNameAndType("Mvp", "parser", make_shared<MVPParser>());
}