#include "pch.h"
#include "CppUnitTest.h"
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

namespace TestforPart1
{
	TEST_CLASS(TestforPart1)
	{
	public:

		TEST_METHOD(TestGetTeam)
		{
			char* test = GetTeam();
			char* expected = "Shep and Evan";
			Assert::AreEqual(strcmp(test, expected), 0);
		}
		TEST_METHOD(TestSetandGetMaze)
		{
			int height = 4;
			int width = 4;
			int** maze = new int* [width];
			int value = 0;
			for (size_t i = 0; i < width; i++)
			{
				maze[i] = new int[height];
				for (size_t j = 0; j < height; j++)
				{
					maze[i][j] = value++;
				}
			}
			SetMaze((const int**)maze, width, height);

			Assert::IsTrue(GetMaze(width, height) == maze);
		}
		TEST_METHOD(TestGetNextPosition)
		{
			int xpos = -1;
			int ypos = -1;
			GetNextPosition(xpos, ypos);
			Assert::AreNotEqual(xpos, -1);
			Assert::AreNotEqual(ypos, -1);
		}
		TEST_METHOD(TestSetandGetStart)
		{
			int xpos = 4;
			int ypos = 4;
			int xpos2 = 3;
			int ypos2 = 3;
			SetStart(xpos, ypos);
			GetStart(xpos2, ypos2);
			Assert::AreEqual(xpos, xpos2);
			Assert::AreEqual(ypos, ypos2);
		}
		TEST_METHOD(TestSetandGetEnd)
		{
			int xpos = 4;
			int ypos = 4;
			int xpos2 = 3;
			int ypos2 = 3;
			SetEnd(xpos, ypos);
			GetEnd(xpos2, ypos2);
			Assert::AreEqual(xpos, xpos2);
			Assert::AreEqual(ypos, ypos2);
		}
	};
}
