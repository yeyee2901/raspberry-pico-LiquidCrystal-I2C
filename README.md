## Modified Version of I2C LCD Demo
- Modified it so it automatically initialize the I2C bus using the default I2C0 pin.
- Now it supports 16x2 & 20x4 LCD type. Users don't need to worry which type they use.  
- You can use this project as a template too! Just clone it, modify CMakeLists.txt to suit your needs, or you
can just download the file (LiquidCrystal.c & LiquidCrystal.h)
&nbsp;  


- For 16x2 display the row limit is defined as:  
```c
lcd_set_cursor(1, column);
```
  

- For 20x4 display the row limit is defined as:
```c
lcd_set_cursor(3, column);
```


&nbsp;  
#### Note that the position uses ZERO INDEXING, meaning it starts from 0.
&nbsp;  

## How To Build This Project
By default, the official Raspberry Pi C/C++ SDK documentation should give the rough idea how to build most of the projects.

1. Start by creating a folder named "build" in the project root directory
2. Open CMakeLists.txt using your favorite text editor.
3. You can change the project name & binary output produced from compile time
   by changing the call to project()
```
project( yourProjectName )
```
4. Make sure that we call include to import all the SDK functionality BEFORE
   the project name declaration. And after the project declaration, we have to
   init the SDK. So it looks something like this:
```
include(
    "./pico_sdk_import.cmake" 
)
project( yourProjectName )
pico_sdk_init()
```
5. If those lines are OK, then you should be able to compile normally, and
   don't forget to add SDK libraries that you used if you add another library
   or modify it. You can change this from the target link libraries call.

6. Go to your "build" directory, open the terminal if you haven't already open
   it, and run:
```
cmake ..
make
```
CMake will create all the build infos & configuration. This is common
misconception for beginners, because CMake only create build config files for
the Make. The one that does the project compilation & building is Make. So in
this case, CMake will generate Makefile & all the necessary configuration
files for your particular project.
&nbsp;  
  
## Uploading to Raspberry Pi Pico
1. Hold the BOOTSEL button on the raspberry pi pico, then plug it to your PC.
2. It should appear as USB storage device, and it contains some text files.
   Ignore it.
3. Now, if you built your project successfully, it should create a file with
   .uf2 extension. This is the file that we will upload to the Pico.
4. Now, simply copy that .uf2 file to the Pico that's now acting like a USB
   storage device. After you copied it, the Pico should automatically restart
   and you should see your program running. Congratulations!

&nbsp;  
This step by steps also assumes that you satisfy the dependency requirement 
(arm-none-eabi-gcc, build-essentials, cmake, pico-sdk, etc).  
If your program is not running, please refer to official Raspberry-Pi Pico
official C/C++ SDK documentation. It also provides platform specific build
steps. This project has been tested & can be build perfectly fine on:
1. Linux Pop-OS 20.04 (x86 arch)
2. Raspberry Pi 4 model B (arm arch)
