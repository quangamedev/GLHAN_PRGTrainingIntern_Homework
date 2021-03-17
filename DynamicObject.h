#ifndef _DYNAMICOBJECT_H
#define _DYNAMICOBJECT_H

#include "BaseObject.h"
class DynamicObject : public BaseObject
{
public:
	DynamicObject(int id, const char* name, int position);
	~DynamicObject();
};

#endif // !_DYNAMICOBJECT_H



