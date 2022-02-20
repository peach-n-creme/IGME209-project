#include "pch.h"
#include "CppUnitTest.h"
#include "Part1-Export.h"
#include <cstdlib>
#include <Stdlib.h>
#include <time.h>
#include <cstdio>

__declspec(dllimport) char* GetTeam();
__declspec(dllimport) void SetMaze(const int** data, int width, int height);
__declspec(dllimport) int** GetMaze(int& width, int& height);
__declspec(dllimport) void GetNextPosition(int& xpos, int& ypos);
__declspec(dllimport) void SetStart(int xpos, int ypos);
__declspec(dllimport) void GetStart(int& xpos, int& ypos);
__declspec(dllimport) void SetEnd(int xpos, int ypos);
__declspec(dllimport) void GetEnd(int& xpos, int& ypos);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MileStone1Part2
{
	TEST_CLASS(MileStone1Part2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int** mazeData[3][3];
			int height = 3;
			int width = 3;
			SetMaze((const int**)mazeData, 4, 4);
			GetMaze(height, width);
			printf("%d \n", height);
			printf("%d \n", width);
		}
	};
}
