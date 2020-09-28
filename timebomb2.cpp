#include <Windows.h>
#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;

// Trigger the action ony on Monday
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[100];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer, sizeof(buffer), "%A", timeinfo);

    const char * str(buffer);

    if (str == "Monday")
    {
        cout << "Wait!" << endl;
        MessageBox(NULL, (LPSTR)str, (LPSTR)str, MB_OK);
    }
    else
    {
        cout << "Time of attack!" << endl;
        MessageBox(NULL, (LPSTR)str, (LPSTR)str, MB_OK);
    }
    return 0;
}
