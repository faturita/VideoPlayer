# Video Player

This code shows how to set up an OpenCV Remote IP Camera Video Player based on FFMPEG libraries used to decode the streaming data.

Works for Windows on Visual Studio 2012.

OpenCV binary version: 

Additional Include Directory : C:\opencv\build\include

Additional Library Directories: C:\opencv\build\x64\vc11\lib

X) La cámara quedó configurada con RSTP habilitado, con M-JPEG como formato a 30 fps 640x352


*) Download autounzip OpenCV-3.0.0.exe, which contains precompiled binaries.
*) You now have an OpenCV folder.
*) OpenCV/build/include header includes.
*) OpenCV/build/x64 static and dynamic libraries.
*) Depending on which version of Visual Studio you have to link to the appropiate library according to
** vc8 = Visual Studio 2005 
** vc9 = Visual Studio 2008 
** vc10 = Visual Studio 2010 
** vc11 = Visual Studio 2012 
** vc12 = Visual Studio 2013 
** vc14 = Visual Studio 2015

The Microsoft C++ runtime dlls use a 2 or 3 digit code also based on the compiler version not the version of Visual Studio.
* MSVCP80.DLL is from Visual Studio 2005 
* MSVCP90.DLL is from Visual Studio 2008 
* MSVCP100.DLL is from Visual Studio 2010 
* MSVCP110.DLL is from Visual Studio 2012 
* MSVCP120.DLL is from Visual Studio 2013 
* MSVCP140.DLL is from Visual Studio 2015

*) OpenCV 3.0.0 is bundled for:
x86 - VC11 y VC12
x64 - VC11 y VC12 (Visual Studio 2012 and Visual Studio 2013)

*) You can use Visual Studio 2012 (VC11) with OpenCV
*) Create a New Empty Visual Studio project (console app)
*) Use the following testing code (move away the RTC _tmain)

 #include <opencv2/core.hpp>
 #include <opencv2/imgcodecs.hpp>
 #include <opencv2/highgui.hpp>
 #include <iostream>
 
 using namespace cv;
 using namespace std;
 
 int main( int argc, char** argv )
 {
    if( argc != 2)
    {
     cout <<" Usage: display_image ImageToLoadAndDisplay" << endl;
     return -1;
    }
    Mat image;
    image = imread(argv[1], IMREAD_COLOR); // Read the file
    if( image.empty() ) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl ;
        return -1;
    }
    namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
    imshow( "Display window", image ); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
 }
 

Include references and libraries
*) Project Properties
*) >>Configuration Manager, add new target x64.
*) >>Configuration Properties>>C/C++>>General, look for Additional Include Directories and add OpenCV\build\include
*) >>Configuration Properties>>Linker>>General, check Additional Library Directories and add OpenCV\build\x64\vc11\lib
*) >>Configuration Properties>>Linker>>Input, add Additional Dependencies, add libraries opencv_world300d.dll (add all that you need depending on which algorithms you are planning to use).
*) Finally, you should copy all the DLLs to the DEBUG directory where the executable is being generated and do the same for the RELEASE directory.  If you are ussing any extra OpenCV contrib you need to add the corresponding DLL files.

