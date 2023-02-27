#include "pch.h"
#include "framework.h"
#include "Cat.h"

BOOL MyCat::ImproveAccessPrivilege()
{
	HANDLE tokenHandle;
	LUID privilegeValue;

	if (!::OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &tokenHandle)) return FALSE;

	if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &privilegeValue))
	{
		::CloseHandle(tokenHandle);
		return FALSE;
	}

	TOKEN_PRIVILEGES privileges;
	privileges.PrivilegeCount = 1;
	privileges.Privileges[0].Luid = privilegeValue;
	privileges.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

	if (!::AdjustTokenPrivileges(tokenHandle, FALSE, &privileges, sizeof(privileges), NULL, NULL))
	{
		::CloseHandle(tokenHandle);
		return FALSE;
	}
	
	return TRUE;
}