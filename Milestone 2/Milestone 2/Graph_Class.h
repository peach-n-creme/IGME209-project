#pragma once
#include "pch.h"
#include "Graph_Class.h"
#include "Vertex_Class.h"
#include <vector>
#include <list>
class Graph
{
public:
	Graph();
	Graph(int mazeWidth, int mazeHeight, int** mazeData);
	
	void Arrange();
	void Pathfind(int startX, int startY, int endX, int endY);

	std::vector<vector<Vertex>> vertices;
	int height;
	int width;
	int** data;
	Vertex* blankVertex;
	int* adjacency;
};

