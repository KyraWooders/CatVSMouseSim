#pragma once
#include "Agent.h";

class Behavior
{
public:
	Behavior() {}
	virtual ~Behavior() {}

	//performs a behavior every time it update
	virtual void update(Agent* agent, float deltaTime) = 0;
};

