#include <iostream>
#include <windows.h>

using namespace std;


BOOL FileExists(TCHAR* szPath)
{
	DWORD dwAttrib = GetFileAttributes(szPath);
	return (dwAttrib != INVALID_FILE_ATTRIBUTES) && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY);
}

// Check if file related to sandbox exist
int CheckFile()
{
    bool hAppend;
    LPSTR fname[] = {"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\agent.pyw",
                     "C:\\WINDOWS\\system32\\drivers\\vmmouse.sys",
                     "C:\\WINDOWS\\system32\\drivers\\vmhgfs.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxMouse.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxGuest.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxSF.sys",
                     "C:\\WINDOWS\\system32\\drivers\\VBoxVideo.sys",
                     "C:\\WINDOWS\\system32\\vboxdisp.dll",
                     "C:\\WINDOWS\\system32\\vboxhook.dll",
                     "C:\\WINDOWS\\system32\\vboxmrxnp.dll",
                     "C:\\WINDOWS\\system32\\vboxogl.dll",
                     "C:\\WINDOWS\\system32\\vboxoglarrayspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglcrutil.dll",
                     "C:\\WINDOWS\\system32\\vboxoglerrorspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglfeedbackspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglpackspu.dll",
                     "C:\\WINDOWS\\system32\\vboxoglpassthroughspu.dll",
                     "C:\\WINDOWS\\system32\\vboxservice.exe",
                     "C:\\WINDOWS\\system32\\vboxtray.exe",
                     "C:\\WINDOWS\\system32\\VBoxControl.exe",
                     // ADD YOUR FILE HERE!
                    };

    for (int i = 0; i < (sizeof(fname) / sizeof(LPSTR)); i++)
    {

        if (FileExists(fname[i]))
            cout << " [+] File exist: " << (fname[i]) << endl;
	else
            cout << " [-] File doesn't exist: " << (fname[i]) << endl;

    }

    return 0;
}


int main()
{
    CheckFile();
    return 0;
}
