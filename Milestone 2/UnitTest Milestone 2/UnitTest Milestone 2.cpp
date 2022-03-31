#include "pch.h"
#include "CppUnitTest.h"
#include <cstdlib>
#include <Stdlib.h>
#include <time.h>
#include <cstdio>

__declspec(dllimport) char* GetTeam();
__declspec(dllimport) bool SetMaze(const int** data, int width, int height);
__declspec(dllimport) int** GetMaze(int& width, int& height);
__declspec(dllimport) bool GetNextPosition(int& xpos, int& ypos);
__declspec(dllimport) bool SetStart(int xpos, int ypos);
__declspec(dllimport) bool GetStart(int& xpos, int& ypos);
__declspec(dllimport) bool SetEnd(int xpos, int ypos);
__declspec(dllimport) bool GetEnd(int& xpos, int& ypos);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMilestone2
{
	TEST_CLASS(UnitTestMilestone2)
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
