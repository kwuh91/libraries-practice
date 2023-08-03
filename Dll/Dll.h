#pragma once

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

extern "C" DLL_API void MergeDLL(double arr[], double aux[], int low, int mid, int high);

extern "C" DLL_API void mergesortDLL(double arr[], double aux[], int low, int high);
