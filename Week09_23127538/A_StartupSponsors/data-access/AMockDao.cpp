#include "AMockDao.h"

string AMockDao::toString() const
{
    return "AMockDao";
}

vector<shared_ptr<Object>> AMockDao::getAll()
{
    return {
        shared_ptr<IStartup>(new Idea("SuperTech", 6)),
        shared_ptr<IStartup>(new Idea("VirtualHouse", 7)),
        shared_ptr<IStartup>(new Idea("NightVision", 4)),
        shared_ptr<IStartup>(new MVP("FutureCar", 6, 3)),
        shared_ptr<IStartup>(new MVP("SmartKey", 4, 5)),
        };
    
}