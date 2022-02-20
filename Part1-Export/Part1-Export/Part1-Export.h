// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the PART1EXPORT_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// PART1EXPORT_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef PART1EXPORT_EXPORTS
#define PART1EXPORT_API __declspec(dllexport)
#else
#define PART1EXPORT_API __declspec(dllimport)
#endif

// This class is exported from the dll
class PART1EXPORT_API CPart1Export {
public:
	CPart1Export(void);
	// TODO: add your methods here.
};

extern PART1EXPORT_API int nPart1Export;

PART1EXPORT_API int fnPart1Export(void);

PART1EXPORT_API char* GetTeam();
