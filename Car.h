#pragma once
#include "DynamicObject.h"
class Car :
    public DynamicObject
{
public:
    Car(int id, const char* name, int position);
    ~Car();
};

