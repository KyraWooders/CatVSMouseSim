#pragma once
#include "Behavior.h"
#include "Maze.h"

class ClosedMazeBehavior : public Behavior
{
public:
	ClosedMazeBehavior() {}
	virtual ~ClosedMazeBehavior() {}

	virtual void update(Agent* agent, float deltaTime);
};

