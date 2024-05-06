-----------Ultimate Windows Utility---------------


-----------Install and prerequisites--------------

To run the code, a Windows 10 x64 version 22H2 is recommended. The Project was tested in this config on multiple machines and works as intended.
The application will most probably run on windows 11 but it is not guarateed. A 64 bit Operating system is a REQUIREMENT.

The Microsoft Visual C++ Redistributables are required, Visual Studio 2015, 2017, 2019, 2022.
Can be downloaded and installed using the following link https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170
Download both x86 and x64 versions.

It is recommended to build the project from scratch using the IDE Visual Studio 2022 or equivalent versions. To do this open the .sln file
in visual studio, ensure the project is unicode(usually default), make sure the project is compiled in release and x64. Then build the project
via the build tab. The project can be run in visual studio or ran as a standalone exe.

--------------Important File Locations--------------

The Project .sln (opened using Visual Studio)
UltimateWindowsUtility->imgui-master->examples->Final Project.sln

The Location of the .EXE file (ran as a standalone App)
