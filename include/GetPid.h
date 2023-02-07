#include <Windows.h>
#include <TlHelp32.h>
 
DWORD GetPId(WCHAR* szProcessName)
{
	HANDLE hProcessSnapShot = NULL;
	PROCESSENTRY32 pe32 = { 0 };
 
	hProcessSnapShot = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
 
	if (hProcessSnapShot == (HANDLE)-1) return NULL;
 
	pe32.dwSize = sizeof(PROCESSENTRY32);
 
	if (Process32First(hProcessSnapShot, &pe32))
	{
		do {
			if (!wcscmp(szProcessName, pe32.szExeFile)) return pe32.th32ProcessID;
		} while (Process32Next(hProcessSnapShot, &pe32));
	}
	else
		::CloseHandle(hProcessSnapShot);
 
	return NULL;
}