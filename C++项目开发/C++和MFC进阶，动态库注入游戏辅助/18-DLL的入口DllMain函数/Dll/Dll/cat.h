#pragma once

#define DLL_EXPORTS

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif // DLL_EXPORTS

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	DLL_API int Max(int a, int b);
	DLL_API int Min(int a, int b);

#ifdef __cplusplus
}
#endif // __cplusplus