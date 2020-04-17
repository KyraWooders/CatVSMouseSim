#pragma once
#include "raylib.h"
#include <vector>

/*	Agent
The Agent class is our game object class. Agents can any
number of Behaviors and will execute each of them in the
order they were added. Behaviors may apply forces to an
Agent or change its speed or color.
 */

class Behavior;

class Agent
{
public:
	Agent() {}
	virtual ~Agent() {}

	//Update the agent and its behaviors
	virtual void update(float deltaTime);

	//Draw the agent
	virtual void draw();

	//Add a behavior to the agent
	void addBehavior(Behavior* behavior);

	//Add a force to the agent's velocity
	void addForce(Vector2 force);

	//Movement functions
	void setPosition(Vector2 position) { m_position = position; }
	Vector2 getPosition() { return m_position; }
	void setVelocity(Vector2 velocity) { m_velocity = velocity; }
	Vector2 getVelocity() { return m_velocity; }

	//Speed functions
	void setSpeed(float speed) { m_speed = speed; }
	float getSpeed() { return m_speed; }

	//Color functions
	void setColor(Color color) { m_color = color; }
	Color getColor() { return m_color; }

	//Size functions
	void setSize(Vector2 size) { m_size = size; }
	Vector2 getSize() { return m_size; }

protected:
	std::vector<Behavior*> m_behaviorList;

	Vector2 m_position = { 0.0f, 0.0f };
	Vector2 m_velocity = { 0.0f, 0.0f };
	Vector2 m_size = { 0.0f, 0.0f };

	float m_speed = 500.0f;
	Color m_color = MAROON;
};
