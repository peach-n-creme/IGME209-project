#include "pch.h"
#include "Vertex_Class.h"

Vertex::Vertex()
{
	xPos = 0;
	yPos = 0;
	movementCost = 0;
	visited = false;
	parent = nullptr;
	localGoal = 0;
	globalGoal = 0;
}

Vertex::Vertex(int xpos, int ypos, int movecost)
{
	xPos = xpos;
	yPos = ypos;
	movementCost = movecost;
	visited = false;
	parent = nullptr;
	localGoal = 0;
	globalGoal = 0;
}