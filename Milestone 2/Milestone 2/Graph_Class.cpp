#include "pch.h"
#include "Graph_Class.h"
#include "Vertex_Class.h"
#include <vector>
using namespace std;

Graph::Graph()
{
	width = 0;
	height = 0;
	data = NULL;
}

Graph::Graph(int mazeWidth, int mazeHeight, int** mazeData)
{
	width = mazeWidth;
	height = mazeHeight;
	data = mazeData;
	
}

void Graph::Arrange()
{
	for (int b = 0; b < height; b++)
	{
		vector<Vertex> vertexRow;


		for (int a = 0; a < width; a++)
		{
			if (data[a][b] == 0)
			{
				blankVertex = new Vertex(a, b, 1);
				vertexRow.push_back(*blankVertex);
			}
		}
		vertices.push_back(vertexRow);
	}
}