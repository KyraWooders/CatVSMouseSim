#pragma once
#include "Agent.h"

class Decision
{
public:
	//the ai make a decision
	virtual void makeDecision(Agent* agent, float deltaTime) = 0;
};