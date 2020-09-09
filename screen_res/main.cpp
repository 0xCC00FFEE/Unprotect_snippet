#include "wtypes.h"
#include <iostream>
using namespace std;

/*
1024x768 can be used for automated Sandbox
800x600 can be used for automated Sandbox
640x480 can be used for automated Sandbox
1024x697
1280x800
1280x960
1680x1050
1916x1066
*/

void GetResolution(int& horiz, int& verti)
{
   RECT desktop;
   const HWND hDesktop = GetDesktopWindow();
   GetWindowRect(hDesktop, &desktop);
   horiz = desktop.right;
   verti = desktop.bottom;
}

int main()
{
   int horiz = 0;
   int verti = 0;
   GetResolution(horiz, verti);

   if(horiz < 1024)
   {
      cout << "[!] Looks like you run in a sandbox!"<< '\n';
   }

   cout << "[+] Screen resolution: "<< horiz << "x" << verti << '\n';
   return 0;
}
