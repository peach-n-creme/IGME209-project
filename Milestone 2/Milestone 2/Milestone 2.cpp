// Milestone 2.cpp : Defines the exported functions for the DLL.
//

#include <cstdlib>
#include <Stdlib.h>
#include <time.h>
#include "pch.h"
#include "framework.h"
#include "Milestone 2.h"


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

int startPosY = -1;
int startPosX = -1;
int endPosY = -1;
int endPosX = -1;

char* GetTeam()
{
    return (char*)team;
}

bool SetMaze(const int** data, int width, int height)
{
    mazeData = (int**)data;
    mazeWidth = width;
    mazeHeight = height;
}

int** GetMaze(int& width, int& height)
{
    width = mazeWidth;
    height = mazeHeight;
    return mazeData;
}

bool GetNextPosition(int& xpos, int& ypos)
{
    xpos = rand();
    ypos = rand();
}

bool SetStart(int xpos, int ypos)
{
    startPosX = xpos;
    startPosY = ypos;
}

bool GetStart(int& xpos, int& ypos)
{
    if (startPosX == -1 && startPosY == -1)
    {
        xpos = -1;
        ypos = -1;
    }
    else
    {
        xpos = startPosX;
        ypos = startPosY;
    }

}

bool SetEnd(int xpos, int ypos)
{
    endPosX = xpos;
    endPosY = ypos;
}

bool GetEnd(int& xpos, int& ypos)
{
    if (endPosX == -1 && endPosY == -1)
    {
        xpos = -1;
        ypos = -1;
    }
    else
    {
        xpos = endPosX;
        ypos = endPosY;
    }
}

bool Restart()
{

}

// This is the constructor of a class that has been exported.
CMilestone2::CMilestone2()
{
    return;
}
