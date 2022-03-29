#pragma once

class Vertex {
public:
	Vertex(int xpos, int ypos, int movecost);

	int xPos;
	int yPos;
	int movementCost;
	bool visited;
};
