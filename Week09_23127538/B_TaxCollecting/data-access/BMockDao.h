#ifndef BMOCKDAO_H
#define BMOCKDAO_H

#include "../../lib/data-access/IDao.h"
#include "../entity/Food.h"
#include "../entity/Clothes.h"
#include "../entity/Jewelry.h"

class BMockDao : public IDao
{
    public:
        string toString() const override;
        vector<shared_ptr<Object>> getAll() override;
};

#endif // BMOCKDAO_H
                    