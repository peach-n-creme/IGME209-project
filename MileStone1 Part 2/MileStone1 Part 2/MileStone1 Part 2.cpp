#include "pch.h"
#include "CppUnitTest.h"

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
		}
	};
}
