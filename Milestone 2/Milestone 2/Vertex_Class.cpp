#include "pch.h"
#include "Vertex_Class.h"

class Vertex {
public:
	int xPos;
	int yPos;
	int heuristic;
	int lowestCost;
	bool visited;
};