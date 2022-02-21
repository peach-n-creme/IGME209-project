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
		TEST_METHOD(GetTeam)
		{
			char* team = GetTeam();
			Assert::AreEqual("Shep and Evan", team);
		}

		TEST_METHOD(SetMaze)
		{
			Assert::AreEqual();
		}

		TEST_METHOD(GetMaze)
		{
			Assert::AreEqual();
		}

		TEST_METHOD(GetNextPosition)
		{
			Assert::AreEqual();
		}

		TEST_METHOD(SetStart)
		{
			Assert::AreEqual();
		}

		TEST_METHOD(GetStart)
		{
			Assert::AreEqual();
		}

		TEST_METHOD(SetEnd)
		{
			Assert::AreEqual();
		}

		TEST_METHOD(GetEnd)
		{
			Assert::AreEqual();
		}
	};
}
