// SummerProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Engine eng;
	eng.Initialize();
	eng.Run();
	eng.Cleanup();
	return 0;
}

