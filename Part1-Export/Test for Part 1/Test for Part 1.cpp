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

		TEST_METHOD(TestMethod1)
		{
			char* test = GetTeam();
			char* expected = "Shep and Evan";
			Assert::AreEqual(test, expected);
		}
	};
}
