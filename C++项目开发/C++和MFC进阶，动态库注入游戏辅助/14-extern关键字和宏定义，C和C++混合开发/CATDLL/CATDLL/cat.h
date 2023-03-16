#pragma once

#ifdef DLL_EXPORT
	#define DLL_API __declspec(dllexport)
#else 
	#define DLL_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	/*__declspec(dllexport) int sum(int a, int b);*/
	DLL_API int sum(int a, int b);

#ifdef __cplusplus
}
#endif // __cplusplus