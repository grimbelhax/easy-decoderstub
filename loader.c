#include <windows.h>
#include <stdio.h>

int main( int argc, char *argv[] )  
{

	FILE* hFile = NULL;
	DWORD dwFileSize = 0;

	hFile = fopen(argv[1], "rb");
	fseek(hFile, 0, SEEK_END);
	dwFileSize = ftell(hFile) + 1;
	fseek(hFile, 0, SEEK_SET);

	LPVOID addressPointer = VirtualAlloc(NULL, dwFileSize, 0x3000, 0x40);

	fread(addressPointer, dwFileSize, 1, hFile);	
	fclose(hFile);

	CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)addressPointer, NULL, 0, 0);
	Sleep(1000);
	return 0;
}
