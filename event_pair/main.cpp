#define WIN32_LEAN_AND_MEAN
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "defs.h"


#pragma comment(lib,"ntdll.lib")
#pragma comment(lib,"psapi.lib")


void QueryProcessHeapMethod(void)
{
    PDEBUG_BUFFER buffer;
    buffer = RtlCreateQueryDebugBuffer(0,FALSE);
    RtlQueryProcessHeapInformation(buffer);

    if (buffer->RemoteSectionBase == (PVOID) 0x50000062){
        MessageBoxA(NULL,"Debugged","Warning",MB_OK);
    }
    else {
        MessageBoxA(NULL,"Not Debugged","Warning",MB_OK);
    }
    if (buffer->EventPairHandle == (PVOID) 0x00002b98) {
        MessageBoxA(NULL,"Debugged","Warning",MB_OK);
    }
    else {
        MessageBoxA(NULL,"Not Debugged","Warning",MB_OK);
        printf("EventPairHandle= %x",(int)buffer->EventPairHandle);
    }
}
int main()
{
    QueryProcessHeapMethod();
    return (EXIT_SUCCESS);
}
