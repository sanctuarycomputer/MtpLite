# mtplite

A handful of simple

https://code.msdn.microsoft.com/windowsdesktop/Portable-Devices-COM-API-fd4a5f7d/

Suppported Operating Systems:
=============================
Windows Vista
Windows 7
Windows 8
Windows 10

To build the sample using the command prompt:
=============================================
Install Microsoft Visual Studio Developer Express
     1. Open the Command Prompt window and navigate to the WpdApiSample\cpp directory.
     2. Type msbuild WpdApiSample.sln.

To build the sample using Visual Studio:
===========================================================
     1. Open File Explorer and navigate to the WpdApiSample\cpp directory.
     2. Double-click the icon for the WpdApiSample.sln file to open the file in Visual Studio.
     3. In the Build menu, select Build Solution. The application will be built in the default \Debug or \Release directory.

To run the sample:# mtplite

A handful of simple CLI utilities to loosely mimic POSIX's LibMTP, in a Windows environment.

MtpLite started life as [this](https://code.msdn.microsoft.com/windowsdesktop/Portable-Devices-COM-API-fd4a5f7d/) Microsoft Developer Network Example.

### Suppported Operating Systems:
- Windows Vista
- Windows 7
- Windows 8
- Windows 10

### Build usingCommand Prompt:
Install Microsoft Visual Studio
     1. Open the Command Prompt window and navigate to the `MtpLite.cpp` directory.
     2. Type`msbuild MtpLite.sln`

### Build using Visual Studio:
Install Microsoft Visual Studio
     1. Open File Explorer and navigate to the `MtpLite.cpp` directory.
     2. Double-click the icon for the `MtpLite.sln` file to open the file in Visual Studio.
     3. In the Build menu, select Build Solution. The application will be built in the default \Debug or \Release directory.

### To run the build:
Note that this sample requires the Microsoft.VC90.CRT redistributable from Microsoft Visual Studio.
     1. Connect a portable device.
     2. Navigate to the directory that contains the new executable, using the command prompt or File Explorer.
     3. Type MtpLite.exe at the command line, or double-click the icon for MtpLite.exe to launch it from File Explorer.
=================
Note that this sample requires the Microsoft.VC90.CRT redistributable from Microsoft Visual Studio.
     1. Connect a portable device.
     2. Navigate to the directory that contains the new executable, using the command prompt or File Explorer.
     3. Type WpdApiSample.exe at the command line, or double-click the icon for WpdApiSample.exe to launch it from File Explorer.
