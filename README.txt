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
UltimateWindowsUtility->imgui-master->examples->example_win32_directx11->Release->example_win32_directx11.exe
if built in debug look in debug folder instead of release.

---------------Testing and Using The app-------------
When running the app you will be in the first Tab that removes temporary files. App Temp Files, Windows Temp Files, and Google Chrome Files.
Clicking each of these will remove the files. Unless its the Chrome button(which has exception handling) if you have an abnormal installation
of windows the application will close if the other locations cant be resolved after pressing the buttons.

Clicking the next tab at the top of the app will bring you to the resource monitor, press the button at the top of the tab "Retrieve Info"
to show the memory useage. Scroll down to view the storage information of your PC.

Click the Terminate Applications tab and click update Processes to view all processes on your PC, Use the search to search
for a process (case sensitive) Press terminate next to the process you wish to terminate to terminate the process.
Click "Update Processes" to update the list of processes.
-----------------FAQ---------------------
If you are getting errors for missing .dll, it means you are missing Microsoft Redistributes, download the ones mentioned above, if you still
get an error then download all the Redistributes in the Link, if that doesnt work install Visual Studio and compile from source.

If the application closes after you try removing, OS Temp Files or Application Temp files it means you are not on windows as a User account and the file paths cannot be resolved
or you have an abnormal installation of windows.

The .exe supplied in the submission was compiled for the authors PC, windows 10 22H2 x64, it will work if you have the same specs, if not then
compile from source.

 