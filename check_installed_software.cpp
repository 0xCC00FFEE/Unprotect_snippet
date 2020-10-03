#include <iostream>
#include <windows.h>


bool EnumInstalledSoftware(void)
{
    HKEY hUninstKey = NULL;
    HKEY hAppKey = NULL;
    WCHAR sAppKeyName[1024];
    WCHAR sSubKey[1024];
    WCHAR sDisplayName[1024];
    WCHAR *sRoot = L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall";
    long lResult = ERROR_SUCCESS;
    DWORD dwType = KEY_ALL_ACCESS;
    DWORD dwBufferSize = 0;

    if(RegOpenKeyExW(HKEY_LOCAL_MACHINE, sRoot, 0, KEY_READ, &hUninstKey) != ERROR_SUCCESS)
    {
        return false;
    }

    for(DWORD dwIndex = 0; lResult == ERROR_SUCCESS; dwIndex++)
    {
        dwBufferSize = sizeof(sAppKeyName);
        if((lResult = RegEnumKeyExW(hUninstKey, dwIndex, sAppKeyName,
            &dwBufferSize, NULL, NULL, NULL, NULL)) == ERROR_SUCCESS)
        {
            //printf(sSubKey, L"%s\\%s", sRoot, sAppKeyName);
            if(RegOpenKeyExW(HKEY_LOCAL_MACHINE, sSubKey, 0, KEY_READ, &hAppKey) != ERROR_SUCCESS)
            {
                RegCloseKey(hAppKey);
                RegCloseKey(hUninstKey);
                return false;
            }

            dwBufferSize = sizeof(sDisplayName);
            if(RegQueryValueExW(hAppKey, L"DisplayName", NULL,
                &dwType, (unsigned char*)sDisplayName, &dwBufferSize) == ERROR_SUCCESS)
            {
                wprintf(L"%s\n", sDisplayName);
            }

            RegCloseKey(hAppKey);
        }
    }

    RegCloseKey(hUninstKey);

    return true;
}
