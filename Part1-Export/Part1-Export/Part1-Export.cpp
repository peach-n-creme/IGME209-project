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

const char* team = "Shep and Evan";

char* GetTeam()
{
    return (char*)team;
}

// This is the constructor of a class that has been exported.
CPart1Export::CPart1Export()
{
    return;
}
