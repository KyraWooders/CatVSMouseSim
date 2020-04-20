#pragma once
#include "Behavior.h"

class EdgeBehavior : public Behavior
{
public:
	EdgeBehavior() {}
	virtual ~EdgeBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
};

