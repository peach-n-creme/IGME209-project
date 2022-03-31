#include "pch.h"
#include "Graph_Class.h"
#include "Vertex_Class.h"
#include <math.h>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

Graph::Graph()
{
	//vertices;
	width = 0;
	height = 0;
	data = NULL;
	blankVertex = NULL;
	adjacency = NULL;
	startX = -1;
	startY = -1;
	endX = -1;
	endY = -1;
	//bestPath;
}

Graph::Graph(int mazeWidth, int mazeHeight, int** mazeData, int startPosX, int startPosY, int endPosX, int endPosY)
{
	width = mazeWidth;
	height = mazeHeight;
	data = mazeData;
	//vertices;
	//bestPath;
	Arrange();
	Pathfind(startPosX, startPosY, endPosX, endPosY);
	makeList(endPosX, endPosY);
}

void Graph::Arrange()
{
	//setting up vertex 2d matrix
	for (int b = 0; b < height; b++)
	{
		vector<Vertex*> vertexRow;


		for (int a = 0; a < width; a++)
		{
			if (data[a][b] == 0)
			{
				blankVertex = new Vertex(a, b, 1);
				vertexRow.push_back(blankVertex);
			}
		}
		vertices.push_back(vertexRow);
	}

	//setup adjacency matrix
	for (int b = 0; b < height; b++)
	{
		for (int a = 0; a < width; a++)
		{
			if (vertices[a][b]->movementCost == 1)
			{
				if (vertices[a + 1][b]->movementCost == 1)
				{
					adjacency[a, b] = 1;
				}
				else if (vertices[a - 1][b]->movementCost == 1)
				{
					adjacency[a, b] = 1;
				}
				else if (vertices[a][b + 1]->movementCost == 1)
				{
					adjacency[a, b] = 1;
				}
				else if (vertices[a][b - 1]->movementCost == 1)
				{
					adjacency[a, b] = 1;
				}
			}
		}
	}
}

void Graph::Pathfind(int startX, int startY, int endX, int endY)
{
	//find heuristic
	int heuristic = 0;

	if (startX > -1 && startY > -1 && endX > -1 && endY > -1)
	{
		heuristic = round(sqrt(pow(abs(startX - endX), 2) + pow(abs(startY - endY), 2)));
	}
	

	for (int b = 0; b < height; b++)
	{
		for (int a = 0; a < height; a++)
		{
			vertices[a][b]->visited = false;
			vertices[a][b]->parent = nullptr;
		}
	}


	//starting conditions
	Vertex *current = vertices[startX][startY];
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
		//might need sort, if so need to figure out how too

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


		//check current node for neighbors
		if (vertices[current->xPos + 1][current->yPos]->movementCost == 1)
		{
			neighborNodes.push_back(vertices[current->xPos + 1][current->yPos]);
		}
		else if (vertices[current->xPos - 1][current->yPos]->movementCost == 1)
		{
			neighborNodes.push_back(vertices[current->xPos - 1][current->yPos]);
		}
		else if (vertices[current->xPos][current->yPos + 1]->movementCost == 1)
		{
			neighborNodes.push_back(vertices[current->xPos][current->yPos + 1]);
		}
		else if (vertices[current->xPos][current->yPos - 1]->movementCost == 1)
		{
			neighborNodes.push_back(vertices[current->xPos][current->yPos - 1]);
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
				neighbourNode->globalGoal = possibleLowestGoal + heuristic;
			}
			//remove the neighbor node we looked at
			neighborNodes.pop_front();
		}
	}
}

void Graph::makeList(int endX, int endY)
{
	Vertex* current = vertices[endX][endY];
	while (current->parent != nullptr)
	{
		bestPath.push_front(current);
		current = current->parent;
	}
}

Vertex* Graph::nextPosition()
{
	Vertex* current;
	if(bestPath.empty())
	{
		return NULL;
	}
	else
	{
		current = bestPath.front();
		cout << current;
		bestPath.pop_front();
		return current;
	}
}