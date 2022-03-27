// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the MILESTONE2_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// MILESTONE2_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MILESTONE2_EXPORTS
#define MILESTONE2_API __declspec(dllexport)
#else
#define MILESTONE2_API __declspec(dllimport)
#endif

// This class is exported from the dll
class MILESTONE2_API CMilestone2 {
public:
	CMilestone2(void);
	// TODO: add your methods here.
};

extern MILESTONE2_API int nMilestone2;

MILESTONE2_API int fnMilestone2(void);

MILESTONE2_API char* GetTeam();

MILESTONE2_API bool SetMaze(const int** data, int width, int height);

MILESTONE2_API int** GetMaze(int& width, int& height);

MILESTONE2_API bool GetNextPosition(int& xpos, int& ypos);

MILESTONE2_API bool SetStart(int xpos, int ypos);

MILESTONE2_API bool GetStart(int& xpos, int& ypos);

MILESTONE2_API bool SetEnd(int xpos, int ypos);

MILESTONE2_API bool GetEnd(int& xpos, int& ypos);

MILESTONE2_API bool Restart();