#ifndef ATEXTDAO_H
#define ATEXTDAO_H

#include "../../lib/data-access/IDao.h"
#include "../entity/Idea.h"
#include "../entity/MVP.h"
#include "../../lib/bus/IParsable.h"
#include "../bus/Factory.h"
#include <sstream>
#include <fstream>


using std::stringstream;
using std::ifstream;
using std::fstream;

class ATextDao : public IDao
{
    public:
        string toString() const override;
        vector<shared_ptr<Object>> getAll() override;

    private:
        string _firstWord(string line);
};


#endif // ATEXTDAO_H
