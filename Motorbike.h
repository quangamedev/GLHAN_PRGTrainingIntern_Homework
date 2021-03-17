#pragma once
#include "DynamicObject.h"
class Motorbike :
    public DynamicObject
{
public:
    Motorbike(int id, const char* name, int position);
    ~Motorbike();
};

