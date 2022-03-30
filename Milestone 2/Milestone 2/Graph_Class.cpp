#include "pch.h"
#include "Graph_Class.h"
#include "Vertex_Class.h"
#include <vector>
#include <list>
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
	Arrange();
}

void Graph::Arrange()
{
	//setting up vertex 2d matrix
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

	//setup adjacency matrix
	for (int b = 0; b < height; b++)
	{
		for (int a = 0; a < width; a++)
		{
			if (vertices[a][b].movementCost == 1)
			{
				if (vertices[a + 1][b].movementCost == 1)
				{
					adjacency[a, b] = 1;
				}
				else if (vertices[a - 1][b].movementCost == 1)
				{
					adjacency[a, b] = 1;
				}
				else if (vertices[a][b + 1].movementCost == 1)
				{
					adjacency[a, b] = 1;
				}
				else if (vertices[a][b - 1].movementCost == 1)
				{
					adjacency[a, b] = 1;
				}
			}
		}
	}
}

void Graph::Pathfind(int startX, int startY, int endX, int endY)
{
	for (int b = 0; b < height; b++)
	{
		for (int a = 0; a < height; a++)
		{
			vertices[a][b].visited = false;
			vertices[a][b].parent = nullptr;
		}
	}

	//starting conditions
	Vertex *current = &vertices[startX][startY];
	current->localGoal = 0;
	current->globalGoal = 0;
	Vertex* neighbourNode;

	//list for nodes not tested yet
	list<Vertex*> unTestedNodes;
	//list for neighboring nodes
	list<Vertex*> neighborNodes;
	int numNeighbors;
	unTestedNodes.push_back(current);

	//actual pathfinding loop
	while (!unTestedNodes.empty())
	{
		//sort untested nobes gy global goal, so lowest first (need to fix)
		unTestedNodes.sort();

		//front of listNotTestedNodes is potentially the lowest distance node. Our list may also contian nodes that have been visited, so ditch these
		while (!unTestedNodes.empty() && unTestedNodes.front()->visited)
		{
			unTestedNodes.pop_front();
		}

		//abort if there are no valid nodes left to test
		if (unTestedNodes.empty())
		{
			break;
		}

		current = unTestedNodes.front();
		current->visited = true;


		//check current node for negihbors
		if (vertices[current->xPos + 1][current->yPos].movementCost == 1)
		{
			unTestedNodes.push_back(&vertices[current->xPos + 1][current->yPos]);
		}
		else if (vertices[current->xPos - 1][current->yPos].movementCost == 1)
		{
			unTestedNodes.push_back(&vertices[current->xPos - 1][current->yPos]);
		}
		else if (vertices[current->xPos][current->yPos + 1].movementCost == 1)
		{
			unTestedNodes.push_back(&vertices[current->xPos][current->yPos + 1]);
		}
		else if (vertices[current->xPos][current->yPos - 1].movementCost == 1)
		{
			unTestedNodes.push_back(&vertices[current->xPos][current->yPos - 1]);
		}



		numNeighbors = neighborNodes.size();
		//check each of the node's neighbors
		for (int i = 0; i < numNeighbors; i++)
		{
			neighbourNode = neighborNodes.front();
			//if the neighbor is not visited, add it to the untested list
			if (neighbourNode->visited == false)
			{
				unTestedNodes.push_back(neighbourNode);
			}
			
			//find local goal
			float possibleLowestGoal = current->localGoal + neighbourNode->movementCost;

			//if the past is lower distance
			if (possibleLowestGoal < neighbourNode->localGoal)
			{
				neighbourNode->parent = current;
				neighbourNode->localGoal = possibleLowestGoal;
				neighbourNode->globalGoal;
			}
			//remove the neighbor node we looked at
			neighborNodes.pop_front();
		}
	}
}