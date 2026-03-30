#pragma once
#ifdef FRPROFILE_EXPORTS_DEF
#define FRPROFILE_UNITTEST_EXPORTS __declspec(dllexport)
#else
#define FRPROFILE_UNITTEST_EXPORTS __declspec(dllimport)
#endif
void FRPROFILE_UNITTEST_EXPORTS print5(int a);