#pragma once
#include <Windows.h>

void dll_injector(int pid, char *dll_path) {
	HANDLE h_process = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	LPVOID h_mem = VirtualAllocEx(h_process, 0, strlen(dll_path), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (h_mem == NULL) {
		exit(2);
	}
	WriteProcessMemory(h_process, h_mem, dll_path, strlen(dll_path), NULL);
	HMODULE h_kernel32 = GetModuleHandleA("kernel32.dll");
	FARPROC h_lib = GetProcAddress(h_kernel32, "LoadLibraryA");

	HANDLE h_rthread = CreateRemoteThread(h_process, NULL, 0, (LPTHREAD_START_ROUTINE)h_lib, h_mem, 0, NULL);
	if (h_rthread == NULL) {
		exit(3);
	}
	return;
}