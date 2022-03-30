#pragma once
class Graph
{
public:
	Graph();
	Graph(int mazeWidth, int mazeHeight, int** mazeData);

	vector<Vertex> vertices;
	void Arrange();

	int height;
	int width;
	int** data;
	Vertex* blankVertex;
};

