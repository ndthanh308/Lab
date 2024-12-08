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
    // B project
    registerServiceForNameAndType("Food", "parser", make_shared<FoodParser>());
    registerServiceForNameAndType("Clothes", "parser", make_shared<ClothesParser>());
    registerServiceForNameAndType("Jewelry", "parser", make_shared<JewelryParser>());
}