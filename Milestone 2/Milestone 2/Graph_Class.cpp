#include "pch.h"
#include "Graph_Class.h"
#include "Vertex_Class.h"
#include <vector>
using namespace std;

Graph::Graph()
{
	vector<Vertex> verticies;
	width = 0;
	height = 0;
}

Graph::Graph(int mazeWidth, int mazeHeight)
{
	vector<Vertex> verticies;
	width = mazeWidth;
	height = mazeHeight;
	
}

void Graph::Arrange()
{
	for (int b = 0; b < height; b++)
	{
		for (int a = 0; a < width; a++)
		{

		}
	}
}