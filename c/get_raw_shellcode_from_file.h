#pragma once
#include <stdio.h>
#include <stdlib.h>

char *get_raw_shellcode_from_file(const char *filename) {
	char *shellcode;
	size_t sz = 0;
	FILE *f = fopen(filename, "rb");
	if (f == NULL) {
		exit(1);
	}

	// get file size
	fseek(f, 0, SEEK_END);
	sz = ftell(f);
	fseek(f, 0, SEEK_SET);

	// get shellcode from file
	shellcode = (char *)malloc(sizeof(char) * sz + 1);
	fread(shellcode, sz, 1, f);
	fclose(f);
	return shellcode;
}
