#ifndef AMOCKDAO_H
#define AMOCKDAO_H

#include "../../lib/data-access/IDao.h"
#include "../entity/Idea.h"
#include "../entity/MVP.h"

class AMockDao : public IDao
{
    public:
        string toString() const override;
        vector<shared_ptr<Object>> getAll() override;
};

#endif // AMOCKDAO_H
                    