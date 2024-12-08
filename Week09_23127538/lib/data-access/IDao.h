#ifndef IDAO_H
#define IDAO_H

#include "../Object.h"
#include <vector>
#include <memory>



using std::vector;
using std::shared_ptr;
using std::make_shared;
class IDao : public Object
{
    public:
        virtual vector<shared_ptr<Object>> getAll() = 0;
};

#endif // IDAO