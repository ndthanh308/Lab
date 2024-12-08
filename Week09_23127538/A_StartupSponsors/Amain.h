#ifndef AMAIN_H
#define AMAIN_H

#include <algorithm>

#include "data-access/AMockDao.h"
#include "data-access/ATextDao.h"
#include "bus/IdeaParser.h"
#include "bus/MVPParser.h"
#include "entity/Idea.h"
#include "entity/MVP.h"
#include "bus/Factory.h"
#include "ui/StartupToTableConverter.h"


#include "data-access/AMockDao.cpp"
#include "data-access/ATextDao.cpp"
#include "bus/IdeaParser.cpp"
#include "bus/MVPParser.cpp"
#include "entity/Idea.cpp"
#include "entity/MVP.cpp"
#include "bus/Factory.cpp"
#include "ui/StartupToTableConverter.cpp"
#include "entity/IStartup.cpp"
#include "../lib/ui/IntToCurrency.cpp"
#include "../lib/ui/ToTableConverter.cpp"

#include <iostream>

using std::cout;
using std::cin;
using std::sort;


bool compareByBudget(const shared_ptr<Object>& a, const shared_ptr<Object>& b);
#endif // AMAIN_H