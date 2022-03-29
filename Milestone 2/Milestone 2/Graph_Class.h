#pragma once
class Graph
{
public:
	Graph();
	Graph(int mazeWidth, int mazeHeight);

	vector<Vertex> verticies;
	void Arrange();

	int height;
	int width;
};

