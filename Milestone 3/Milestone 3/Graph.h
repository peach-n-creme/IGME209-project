#pragma once
#include "Graph.h"
#include "Vertex_Class.h"
#include <math.h>
#include <vector>
#include <list>
#include <iostream>
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

	vector<vector<Vertex*>> vertices;
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
