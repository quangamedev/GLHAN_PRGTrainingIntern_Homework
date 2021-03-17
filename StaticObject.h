#ifndef _STATICOBJECT_H_
#define _STATICOBJECT_H_
#include"BaseObject.h"

class StaticObject : public BaseObject
{
public:
    StaticObject(int id, const char* name, int position);
    ~StaticObject();
    void move();
};

#endif // !_STATICOBJECT_H_