#ifndef _BASEOBJECT_H_
#define _BASEOBJECT_H_
#include <stdio.h>
class BaseObject
{
public:
	BaseObject(int id, const char* name, int position);
	~BaseObject();

	int getId() { return m_id; }
	const char* getName() { return m_name; }

	void printPosition();
	virtual void move();

protected:
	int m_id;
	const char* m_name;
	int m_position;

};

#endif // !_BASEOBJECT_H_