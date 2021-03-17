#ifndef _HOUSE_H_


#include "StaticObject.h"
class House :
    public StaticObject
{
public:
    House(int id, const char* name, int position);
    ~House();
};

#define _HOUSE_H_
#endif // !_HOUSE_H_