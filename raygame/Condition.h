#pragma once
#include "Agent.h"

class Condition
{
public:
	Condition() {}
	virtual ~Condition() {}

	//test decisions and transitions
	virtual bool test(Agent* agent) const = 0;
};