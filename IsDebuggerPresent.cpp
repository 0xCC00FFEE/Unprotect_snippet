#include <windows.h>
#include <stdio.h>

int main(int argc, char** argv)
{
	if (IsDebuggerPresent())
	{
            printf("Debugger detected!!\n");
	}
	else
	{
	    printf("No debugger detected!!\n");
	}
	system("pause");
	return 0;
}
