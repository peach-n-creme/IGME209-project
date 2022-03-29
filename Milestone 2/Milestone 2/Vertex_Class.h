#pragma once

class Vertex {
public:
	Vertex();
	Vertex(int xpos, int ypos, int movecost);

	int xPos;
	int yPos;
	int movementCost;
	bool visited;
};
