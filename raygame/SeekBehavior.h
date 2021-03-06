#pragma once
#include "Behavior.h"

class SeekBehavior : public Behavior
{
public:
	SeekBehavior() {}
	virtual ~SeekBehavior() {}

	//updates with the agent
	virtual void update(Agent* agent, float deltaTime);
	//the target to seek to
	void setTarget(Agent* agent) { m_target = agent; }

private:
	Agent* m_target = nullptr;
};

