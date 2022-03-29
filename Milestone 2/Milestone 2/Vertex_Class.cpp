#include "pch.h"
#include "Vertex_Class.h"

Vertex::Vertex()
{
	xPos = 0;
	yPos = 0;
	movementCost = 0;
	visited = false;
}

Vertex::Vertex(int xpos, int ypos, int movecost)
{
	xPos = xpos;
	yPos = ypos;
	movementCost = movecost;
	visited = false;
}