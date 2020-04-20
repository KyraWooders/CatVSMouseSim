#include "EdgeBehavior.h"

void EdgeBehavior::update(Agent* agent, float deltaTime)
{
	float x = agent->getPosition().x + agent->getVelocity().x;
	float y = agent->getPosition().y + agent->getVelocity().y;

	Vector2 force = { 0.0f, 0.0f };

	//If out of bounds
	if (x < 0 || x > 1000 || y < 0 || y > 700) {
		//Get this agent's position
		Vector2 pos = agent->getPosition();
		//Target the center
		Vector2 targetPos = { 1600, 900 };

		//Calculate the vector describing the direction to the target and normalize it
		Vector2 direction = targetPos - pos;
		direction = direction.normalize();
		//Multiply the direction by the speed we want the agent to move
		force = direction * agent->getSpeed();
		//Subtract the agent's current velocity from the result to get the force we need to apply
		force = force - agent->getVelocity();
	}

	agent->addForce(force * deltaTime);
}