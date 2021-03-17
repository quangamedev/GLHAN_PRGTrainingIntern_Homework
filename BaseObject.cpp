#include "BaseObject.h"

BaseObject::BaseObject(int id, const char* name, int position) {
	m_id = id;
	m_name = name;
	m_position = position;
}
BaseObject::~BaseObject() {

}

void BaseObject::printPosition() {
	printf_s("The %s is at %d\n", m_name, m_position);
}

void BaseObject::move() {
	//order reversed for some reason
	printf_s("The %s moved from %d to %d\n",m_name, m_position++, m_position);
}