#include <stdio.h>
#include <Windows.h>

int main()
{
	SetLastError(0);
	// Send string to the debugger
	
  OutputDebugStringA("Hello friend");
	
  if (GetLastError() != 0)
	{
		printf("Debugger detected!!\n");
	}
  system("pause");
	return 0;
}
