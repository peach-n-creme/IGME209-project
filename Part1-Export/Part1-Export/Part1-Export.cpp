// Part1-Export.cpp : Defines the exported functions for the DLL.
//

#include <cstdlib>
#include "pch.h"
#include "framework.h"
#include "Part1-Export.h"


// This is an example of an exported variable
PART1EXPORT_API int nPart1Export=0;

// This is an example of an exported function.
PART1EXPORT_API int fnPart1Export(void)
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

void SetMaze(const int** data, int width, int height)
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

void GetNextPosition(int& xpos, int& ypos)
{
    xpos = rand();
    ypos = rand();
}

void SetStart(int xpos, int ypos)
{
    startPosX = xpos;
    startPosY = ypos;
}

void GetStart(int& xpos, int& ypos)
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

void SetEnd(int xpos, int ypos)
{
    xpos = rand();
    ypos = rand();
}

void GetEnd(int& xpos, int& ypos)
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

// This is the constructor of a class that has been exported.
CPart1Export::CPart1Export()
{
    return;
}
