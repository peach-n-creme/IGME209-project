// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MILESTONE3_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MILESTONE3_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#include <cstdlib>
#include <Stdlib.h>
#include <time.h>
#include <iostream>
#ifdef MILESTONE3_EXPORTS
#define MILESTONE3_API __declspec(dllexport)
#else
#define MILESTONE3_API __declspec(dllimport)
#endif

// This class is exported from the dll
class MILESTONE3_API CMilestone3 {
public:
	CMilestone3(void);
	// TODO: add your methods here.
};

extern MILESTONE3_API int nMilestone3;

MILESTONE3_API int fnMilestone2(void);

MILESTONE3_API char* GetTeam();

MILESTONE3_API bool SetMaze(const int** data, int width, int height);

MILESTONE3_API int** GetMaze(int& width, int& height);

MILESTONE3_API bool GetNextPosition(int& xpos, int& ypos);

MILESTONE3_API bool SetStart(int xpos, int ypos);

MILESTONE3_API bool GetStart(int& xpos, int& ypos);

MILESTONE3_API bool SetEnd(int xpos, int ypos);

MILESTONE3_API bool GetEnd(int& xpos, int& ypos);

MILESTONE3_API bool Restart();
