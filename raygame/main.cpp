/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h" 
#include "AStarPathfinder.h"
#include "Agent.h"
#include "Behavior.h"
#include "SeekBehavior.h"
#include "FleeBehavior.h"
#include "BooleanDecision.h"
#include "WanderBehavior.h"
#include <iostream>

using namespace pathfinding;

enum tileType
{
	open,
	closed
};

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1000;
	int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	//Nodes
	Node* a = new Node();
	a->position = Vector2{ 0, 0 };

	Node* b = new Node();
	b->position = Vector2{ 2, 0 };

	Node* c = new Node();
	c->position = Vector2{ 2, 1 };

	Node* d = new Node();
	d->position = Vector2{ 2, 2 };

	Node* e = new Node();
	e->position = Vector2{ 1, 3 };

	Node* f = new Node();
	f->position = Vector2{ 0, 2 };

	//Edges
	a->connections.push_back(Edge{ b, 2 });
	a->connections.push_back(Edge{ f, 5 });

	b->connections.push_back(Edge{ c, 3 });

	c->connections.push_back(Edge{ a, 3 });
	c->connections.push_back(Edge{ d, 1 });

	d->connections.push_back(Edge{ e, 4 });
	d->connections.push_back(Edge{ f, 4 });

	f->connections.push_back(Edge{ e, 6 });

	std::vector<Node*> shortestPath = dijkstrasSearch(a, e);

	for (Node* node : shortestPath) {
		std::cout << node->gScore << std::endl;
	}

	FleeBehavior* flee = new FleeBehavior();
	SeekBehavior* seek = new SeekBehavior();
	WanderBehavior* wander = new WanderBehavior();

	Agent* mouse = new Agent();
	mouse->setPosition(Vector2{400.0f,400.0f});
	mouse->setColor(BLACK);
	mouse->setSize(Vector2{50,50});
	mouse->setSpeed(250.0f);
	mouse->addBehavior(wander);

	Agent* cat = new Agent();
	cat->setPosition(Vector2{300.0f,300.0f});
	cat->setColor(DARKGRAY);
	cat->setSize(Vector2{ 80,80 });
	cat->setSpeed(250.0f);
	cat->addBehavior(seek);

	flee->setTarget(cat);
	seek->setTarget(mouse);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		mouse->update(GetFrameTime());
		cat->update(GetFrameTime());
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		//Draw the tile map
		
		mouse->draw();
		cat->draw();

		////Draw the graph
		//drawGraph(a, { 200, 200 });

		////Draw the shortest path
		//for (Node* node : shortestPath) {
		//	drawNode(node, { 200, 200 }, true);
		//}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}