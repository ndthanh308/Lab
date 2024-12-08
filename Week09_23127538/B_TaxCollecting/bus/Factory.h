#ifndef FACTORY_H
#define FACTORY_H

#include "../../lib/Object.h"

#include "FoodParser.h"
#include "ClothesParser.h"
#include "JewelryParser.h"

#include <iostream>
#include <map>
#include <tuple>
#include <memory>
#include <utility>

using std::map;
using std::tuple;
using std::make_shared;
using std::make_tuple;
using std::shared_ptr;
using std::pair;
using std::get;

/// @brief  Factory class for A and B project
class Factory : public Object
{
    private:
        /// @brief config type need to create
        static void _config();

    public:
        /// @brief toString constact from Object
        /// @return string
        string toString() const override;

        /// @brief 
        inline static map<pair<string, string>, shared_ptr<Object>> servicesForNameAndType;
        static void registerServiceForNameAndType(string name, string type, shared_ptr<Object> o);
        static shared_ptr<Object> getServiceForNameAndType(string name, string type);
};

#endif // FACTORY_H