#pragma once
#include "pch.h"
#include "Vertex_Class.h"

class Vertex {
public:
	Vertex();
	Vertex(int xpos, int ypos, int movecost);

	int xPos;
	int yPos;
	int movementCost;
	bool visited;
	Vertex* parent;
	int localGoal;
	int globalGoal;
};
