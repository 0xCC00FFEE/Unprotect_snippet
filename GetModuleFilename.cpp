#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

int main(int argc, char** argv)
{
    TCHAR szExeFileName[MAX_PATH];
    GetModuleFileName(NULL, szExeFileName, MAX_PATH);

    // full path
    cout << "[+] Fulle Path: " << szExeFileName << endl;

    //convert tchar to string
    std:string filename (szExeFileName);

    // Remove directory if present.
    const size_t last_slash_idx = filename.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        filename.erase(0, last_slash_idx + 1);
    }

    // Blacklist
    LPSTR fname[] = {"sample.exe",
                     "malware.exe",
                     // ADD YOUR FILE HERE!
                    };
    for (int i = 0; i < (sizeof(fname) / sizeof(LPSTR)); i++)
    {
        if ((fname[i] == filename ))
        {
            cout << " [!] Filename is blacklisted: " << (fname[i]) << endl;
            exit(0);
        }
    }
    return 0;
}
