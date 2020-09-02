#include <iostream>
#include<Windows.h>
#include<stdio.h>

using namespace std;


int reg_value_exist(HKEY hKey, char * regkey_s, char * value_s, char * lookup) {
	HKEY regkey;
	LONG ret;
	DWORD size;
	char value[1024];


	if (RegOpenKeyEx(hKey, regkey_s, 0, KEY_READ, &regkey))
    {
        if (RegQueryValueEx(regkey, value_s, NULL, NULL, (BYTE*)value, &size))
        {
            cout << " [-] Reg value doesn't exist: " << (regkey) << endl;
        }
        else
        {
            cout << " [*] Reg value exist: " << (value) << endl;
        }
	}

    else
    {
        if (RegQueryValueEx(regkey, value_s, NULL, NULL, (BYTE*)value, &size))
        {
            cout << " [-] Reg value doesn't exist: " << (regkey) << endl;
        }
        else
        {
            cout << " [*] Reg value exist: " << (value) << endl;
        }
    }
}

int RegistryArtifacts()
{
    HKEY hKey;

    // list of registry key related virutal machines
    LPCTSTR RegValuePath[] = { "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 0\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0",
                               "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 1\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0",
                               "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 2\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0",
                               "SOFTWARE\\VMware, Inc.\\VMware Tools",
                               "HARDWARE\\Description\\System",
                               "SOFTWARE\\Oracle\\VirtualBox Guest Additions",
                               "SYSTEM\\ControlSet001\\Services\\Disk\\Enum",
                               "HARDWARE\\ACPI\\DSDT\\VBOX__",
                               "HARDWARE\\ACPI\\FADT\\VBOX__",
                               "HARDWARE\\ACPI\\RSDT\\VBOX__",
                               "SYSTEM\\ControlSet001\\Services\\VBoxGuest",
                               "SYSTEM\\ControlSet001\\Services\\VBoxMouse",
                               "SYSTEM\\ControlSet001\\Services\\VBoxService",
                               "SYSTEM\\ControlSet001\\Services\\VBoxSF",
                               "SYSTEM\\ControlSet001\\Services\\VBoxVideo",
                               };


    for (int i = 0; i < (sizeof(RegValuePath) / sizeof(LPCWSTR)); i++)
    {

        if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, RegValuePath[i], 0, KEY_READ, &hKey))
        {
            cout << " [-] Reg key doesn't exist: " << (RegValuePath[i]) << endl;
        }
        else
        {
            cout << " [*] Reg key exist: " << (RegValuePath[i]) << endl;
        }

    }

    // Check for registry Value
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 0\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0", "Identifier", "VMware");
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 1\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0", "Identifier", "VMware");
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 2\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0", "Identifier", "VMware");
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 0\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0", "Identifier", "VBOX");
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\Description\\System", "SystemBiosVersion", "VBOX");
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\Description\\System", "VideoBiosVersion", "VIRTUALBOX");
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System", "SystemBiosDate", "06/23/99");
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\DEVICEMAP\\Scsi\\Scsi Port 0\\Scsi Bus 0\\Target Id 0\\Logical Unit Id 0", "Identifier", "QEMU");
    reg_value_exist(HKEY_LOCAL_MACHINE, "HARDWARE\\Description\\System", "SystemBiosVersion", "QEMU");
}

int main()
{
    RegistryArtifacts();
    return 0;
}
