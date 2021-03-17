#include "StaticObject.h"

StaticObject::StaticObject(int id, const char* name, int position): BaseObject(id, name, position) {

}
StaticObject::~StaticObject() {

}

void StaticObject::move() {
	printf_s("&s is static object and cannot be moved\n", m_name);
}


