// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
#include <iostream>
using namespace std;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    cout << hModule << " " << ul_reason_for_call << " " << lpReserved << endl;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        cout << "DLL_PROCESS_ATTACH" << endl;
        break;
    case DLL_THREAD_ATTACH:
        cout << "DLL_THREAD_ATTACH" << endl;
        break;
    case DLL_THREAD_DETACH:
        cout << "DLL_THREAD_ATTACH" << endl;
        break;
    case DLL_PROCESS_DETACH:
        cout << "DLL_PROCESS_DETACH" << endl;
        break;
    }
    return TRUE;
}

