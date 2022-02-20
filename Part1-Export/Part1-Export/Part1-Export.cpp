// Part1-Export.cpp : Defines the exported functions for the DLL.
//

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

int startPosY;
int startPosX;
int endPosY;
int endPosX;

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
    return nullptr;
}

void GetNextPosition(int& xpos, int& ypos)
{
}

void SetStart(int xpos, int ypos)
{
    startPosX = xpos;
    startPosY = ypos;
}

void GetStart(int& xpos, int& ypos)
{
}

void SetEnd(int xpos, int ypos)
{
    endPosX = xpos;
    endPosY = ypos;
}

void GetEnd(int& xpos, int& ypos)
{
}

// This is the constructor of a class that has been exported.
CPart1Export::CPart1Export()
{
    return;
}
