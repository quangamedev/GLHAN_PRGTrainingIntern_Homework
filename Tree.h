#pragma once
#include "StaticObject.h"
class Tree :
    public StaticObject
{
public:
    Tree(int id, const char* name, int position);
    ~Tree();
};

