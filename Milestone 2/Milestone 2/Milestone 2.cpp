// Milestone 2.cpp : Defines the exported functions for the DLL.
//

#include <cstdlib>
#include <Stdlib.h>
#include <time.h>
#include "pch.h"
#include "framework.h"
#include "Milestone 2.h"
#include "Graph_Class.h"
#include "Vertex_Class.h"


// This is an example of an exported variable
MILESTONE2_API int nMilestone2=0;

// This is an example of an exported function.
MILESTONE2_API int fnMilestone2(void)
{
    return 0;
}

//variables for the project
const char* team = "Shep and Evan";
int** mazeData;
int mazeWidth;
int mazeHeight;

int startPosY;
int startPosX;
int endPosY;
int endPosX;

Graph* mazeGraph;


char* GetTeam()
{
    return (char*)team;
}

bool SetMaze(const int** data, int width, int height)
{
    mazeData = (int**)data;
    mazeWidth = width;
    mazeHeight = height;

    if (mazeWidth > 0 && mazeHeight > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int** GetMaze(int& width, int& height)
{
    width = mazeWidth;
    height = mazeHeight;

    if (mazeWidth > 0 && mazeHeight > 0)
    {
        return nullptr;
    }
    else
    {
        mazeGraph = new Graph(mazeWidth, mazeHeight, mazeData, startPosX, startPosY, endPosX, endPosY);
        return mazeData;
    }
}

bool GetNextPosition(int& xpos, int& ypos)
{
    Vertex* current;
    current = mazeGraph->nextPosition();
    if(xpos < 0 || ypos < 0 || current == NULL)
    {
        return false;
    }
    else
    {
        xpos = current->xPos;
        ypos = current->yPos;
        return true;
    }
}

bool SetStart(int xpos, int ypos)
{
    startPosX = xpos;
    startPosY = ypos;

    if (startPosX == xpos && startPosY == ypos && startPosX >=0 && startPosY >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GetStart(int& xpos, int& ypos)
{
    if (startPosX == xpos && startPosY == ypos && startPosX >= 0 && startPosY >= 0)
    {
        xpos = startPosX;
        ypos = startPosY;
        return true;
    }
    else
    {
        return false;
    }

}

bool SetEnd(int xpos, int ypos)
{
    endPosX = xpos;
    endPosY = ypos;
    if (endPosX == xpos && endPosY == ypos && endPosX >= 0 && endPosY >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool GetEnd(int& xpos, int& ypos)
{
    if (endPosX == xpos && endPosY == ypos && endPosX >= 0 && endPosY >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Restart()
{
    return false;
}

// This is the constructor of a class that has been exported.
CMilestone2::CMilestone2()
{
    return;
}
