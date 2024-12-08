#ifndef BMAIN_H
#define BMAIN_H

#include <algorithm>


#include "data-access/BMockDao.h"
#include "data-access/BTextDao.h"
#include "bus/FoodParser.h"
#include "bus/JewelryParser.h"
#include "bus/ClothesParser.h"
#include "entity/Food.h"
#include "entity/Clothes.h"
#include "entity/Jewelry.h"
#include "bus/Factory.h"
#include "ui/StallToTableConverter.h"


#include "data-access/BMockDao.cpp"
#include "data-access/BTextDao.cpp"
#include "bus/FoodParser.cpp"
#include "bus/ClothesParser.cpp"
#include "bus/JewelryParser.cpp"
#include "entity/Food.cpp"
#include "entity/Clothes.cpp"
#include "entity/Jewelry.cpp"
#include "bus/Factory.cpp"
#include "ui/StallToTableConverter.cpp"
#include "entity/IStall.cpp"
#include "../lib/ui/IntToCurrency.cpp"
#include "../lib/ui/ToTableConverter.cpp"

#include <iostream>

using std::cout;
using std::cin;
using std::sort;


bool compareByTotalFee(const shared_ptr<Object>& a, const shared_ptr<Object>& b);
#endif // BMAIN_H