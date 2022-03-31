// Milestone 2.cpp : Defines the exported functions for the DLL.
//

#include <cstdlib>
#include <Stdlib.h>
#include <time.h>
#include <iostream>
#include "pch.h"
#include "framework.h"
#include "Milestone 2.h"
#include "Graph_Class.h"
#include "Vertex_Class.h"
using namespace std;


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

Graph* mazeGraph = NULL;

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
        cout << "setmaze worked\n";
        return true;
    }
    else
    {
        cout << "setmaze failed\n";
        return false;
    }
}

int** GetMaze(int& width, int& height)
{
    width = mazeWidth;
    height = mazeHeight;

    if (mazeWidth > 0 && mazeHeight > 0)
    {
        cout << "getmaze worked\n";
        return mazeData;
    }
    else
    {
        cout << "getmaze failed\n";
        return nullptr;
    }
}

bool GetNextPosition(int& xpos, int& ypos)
{
    if (mazeGraph == NULL)
    {
        mazeGraph = new Graph(mazeWidth, mazeHeight, mazeData, startPosX, startPosY, endPosX, endPosY);
    }
    Vertex* current;
    current = mazeGraph->nextPosition();
    if(xpos < 0 || ypos < 0 || current == NULL)
    {
        cout << "getnextposition failed\n";
        return false;
    }
    else
    {
        cout << "getnextposition worked\n";
        xpos = current->xPos;
        ypos = current->yPos;
        return true;
    }
}

bool SetStart(int xpos, int ypos)
{
    startPosX = xpos;
    startPosY = ypos;

    if (startPosX == xpos && startPosY == ypos && startPosX >= 0 && startPosY >= 0)
    {
        cout << "setstart worked\n";
        return true;
    }
    else
    {
        cout << "setstart failed\n";
        return false;
    }
}

bool GetStart(int& xpos, int& ypos)
{
    xpos = startPosX;
    ypos = startPosY;
    if (startPosX == xpos && startPosY == ypos && startPosX >= 0 && startPosY >= 0)
    {
        cout << "getstart worked\n";
        return true;
    }
    else
    {
        cout << "getstart failed\n";
        return false;
    }

}

bool SetEnd(int xpos, int ypos)
{
    endPosX = xpos;
    endPosY = ypos;
    if (endPosX == xpos && endPosY == ypos && endPosX >= 0 && endPosY >= 0)
    {
        cout << "setend worked\n";
        return true;
    }
    else
    {
        cout << "setend failed\n";
        return false;
    }
}

bool GetEnd(int& xpos, int& ypos)
{
    xpos = endPosX;
    ypos = endPosY;
    if (endPosX == xpos && endPosY == ypos && endPosX >= 0 && endPosY >= 0)
    {
        cout << "getend worked\n";
        return true;
    }
    else
    {
        cout << "getend failed\n";
        return false;
    }
}

bool Restart()
{
    mazeGraph = new Graph(mazeWidth, mazeHeight, mazeData, startPosX, startPosY, endPosX, endPosY);
    return true;
}

// This is the constructor of a class that has been exported.
CMilestone2::CMilestone2()
{
    return;
}
