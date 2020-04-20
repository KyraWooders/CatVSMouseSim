#pragma once
#include "Behavior.h"

class FleeBehavior : public Behavior
{
public:
	FleeBehavior() {}
	virtual ~FleeBehavior() {}

	//updates with the agent
	virtual void update(Agent* agent, float deltaTime);
	//the targent to run away from
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};

