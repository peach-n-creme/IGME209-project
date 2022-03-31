#pragma once
#include "pch.h"
#include "Graph_Class.h"
#include "Vertex_Class.h"
#include <math.h>
#include <vector>
#include <list>
using namespace std;

class Graph
{
public:
	Graph();
	Graph(int mazeWidth, int mazeHeight, int** mazeData, int startPosX, int startPosY, int endPosX, int endPosY);
	
	void Arrange();
	void Pathfind(int startX, int startY, int endX, int endY);
	void makeList(int endX, int endY);
	Vertex* nextPosition();

	std::vector<vector<Vertex>> vertices;
	int height;
	int width;
	int** data;
	Vertex* blankVertex;
	int* adjacency;
	int startX;
	int startY;
	int endX;
	int endY;
	list<Vertex*> bestPath;
};
