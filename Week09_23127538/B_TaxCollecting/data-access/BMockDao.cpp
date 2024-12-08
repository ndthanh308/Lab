#include "BMockDao.h"

string BMockDao::toString() const
{
    return "BMockDao";
}

vector<shared_ptr<Object>> BMockDao::getAll()
{
    return {
        shared_ptr<IStall>(new Food("A724", 78, 3000000)),
        shared_ptr<IStall>(new Clothes("B419", 33)),
        shared_ptr<IStall>(new Jewelry("C682", 55, 7000000)),
        shared_ptr<IStall>(new Clothes("B331", 38)),
        shared_ptr<IStall>(new Food("A903", 60, 5000000)),
        };
}
