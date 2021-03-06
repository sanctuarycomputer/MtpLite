# MtpLite

A handful of simple CLI utilities to loosely mimic POSIX's LibMTP, in a Windows environment.

MtpLite started life as [this](https://code.msdn.microsoft.com/windowsdesktop/Portable-Devices-COM-API-fd4a5f7d/) Microsoft Developer Network Example.

### Suppported Operating Systems:
- Windows Vista
- Windows 7
- Windows 8
- Windows 10

### Build using Command Prompt:
[Install Microsoft Visual Studio](https://www.visualstudio.com/downloads/)

1. Open the Command Prompt window and navigate to the `MtpLite.cpp` directory.

2. Type`msbuild MtpLite.sln`

### Build using Visual Studio:
[Install Microsoft Visual Studio](https://www.visualstudio.com/downloads/)

1. Open File Explorer and navigate to the `MtpLite.cpp` directory.

2. Double-click the icon for the `MtpLite.sln` file to open the file in Visual Studio.

3. In the Build menu, select Build Solution. The application will be built in the default \Debug or \Release directory.

### To run the build:
Note that this sample requires the Microsoft.VC90.CRT redistributable from Microsoft Visual Studio.

1. Connect a portable device.

2. Navigate to the directory that contains the new executable, using the command prompt or File Explorer.

3. Type `MtpLite.exe` at the command line, or double-click the icon for `MtpLite.exe` to launch it from File Explorer.
