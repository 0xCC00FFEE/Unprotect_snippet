#include <iostream>
#include <windows.h>

int WINAPI WinMain ( HINSTANCE, HINSTANCE, LPSTR, int )
{
  char  ComputerName [MAX_COMPUTERNAME_LENGTH + 1];
  DWORD cbComputerName = sizeof ( ComputerName );
  if ( GetComputerName ( ComputerName, &cbComputerName ))
     { MessageBox ( NULL, ComputerName, "Computer Name:", MB_OK | MB_ICONINFORMATION ); } }

