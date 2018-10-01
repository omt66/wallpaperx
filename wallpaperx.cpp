/**
 * Purpose: Change desktop background based on the current workspace.
 * 
 * Notes: 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the author be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose, 
 * including commercial applications, and to alter it and redistribute it 
 * freely, subject to the following restrictions:
 *     1. The origin of this software must not be misrepresented; 
 *        you must not claim that you wrote the original software. 
 *        If you use this software in a product, an acknowledgment 
 *        in the product documentation would be appreciated. 
 *     2. Altered source versions must be plainly marked as such, and 
 *        must not be misrepresented as being the original software.
 *     3. This notice cannot be removed, changed or altered from any source 
 *        code distribution.
 * 
 *     (c) 2005 omt66. All rights reserved.
 */
#include "wallpaperx.h"
    
WallpaperX::WallpaperX(vector<string> imageFileNames) {
  cout << "WallpaperX starting..." << endl;
  mDone = false;
  mInstance = this;
  mWallpaperImageFiles = imageFileNames;

  // Set the signal handlers: All we want is to stop the process properly!
	signal(SIGINT,  WallpaperX::stopProcess);
	signal(SIGABRT, WallpaperX::stopProcess);
	signal(SIGKILL, WallpaperX::stopProcess);
	signal(SIGTERM, WallpaperX::stopProcess);
}

WallpaperX::~WallpaperX() {
  stop();    
}

int WallpaperX::getCurrentDesktopNo() {
  ifstream myFile;	
  string   fileInfo;

  // Get the current desktop and write it to a temp file!
  // I'll be using xprop: Property displayer for X.
  system("xprop -root _NET_CURRENT_DESKTOP > temp.dat");

  myFile.open("./temp.dat");
  
  getline(myFile, fileInfo);

  myFile.close(); // Don't forget the close the file here!			

  istringstream strStream(fileInfo);

  // Parse the info and get the desktop number.
  string temp;   // Just a temp string
  int desktopNo; // Desktop number info
  
  // Output is something like this:
  // _NET_CURRENT_DESKTOP(CARDINAL) = 3
  // OK, let's try to parse it now!
  strStream >> temp >> temp >> desktopNo;

  return desktopNo;
}

void WallpaperX::setDesktopBackground(int desktopNo) {
  static int previousDesktopNo = -1;
  string commandStr;
  string fileName;

  if (desktopNo != previousDesktopNo) {	
    previousDesktopNo = desktopNo;

    // If we don't have image file for desktop then just return!
    if (mWallpaperImageFiles.size() <= desktopNo) {
        cout << "No Image for desktop: " << desktopNo << endl;	
        return;
    }
    fileName = mWallpaperImageFiles[desktopNo];
    cout << "Desktop Number is " << desktopNo << endl;		
    cout << "File Name: " << fileName << endl;
    
    // Set the proper image here
    // by using 'gconftool-2'
    // set the background image attribute to different filenames 
    // based on the current desktop information.
    commandStr = "gconftool-2 -s /desktop/gnome/background/picture_filename -t string ";
    //gsettings set org.gnome.desktop.background picture-uri file:///home/serrano/Pictures/y.jpg
  
    //commandStr = "gsettings set org.gnome.desktop.background picture-uri file://";
    commandStr = "gsettings set org.mate.background picture-filename ";
          
    commandStr += fileName;
    
    cout << "Command-> " << commandStr << endl;

    system(commandStr.c_str());
  }		
}

void WallpaperX::stopProcess(int sigNo) {
	mInstance->stop();
}

void WallpaperX::msleep(int sleepTime) {
  sleepTime *= 1000; // Now, sleep time is in microseconds.
  usleep(sleepTime);
}

void WallpaperX::start() {
  int sleepTime = 500;   // Sleep time in ms
  int currentDesktopNo;  // Current desktop number

  while (!mDone) {
    currentDesktopNo = getCurrentDesktopNo();		
    setDesktopBackground(currentDesktopNo);
    msleep(sleepTime);
  }
}

void WallpaperX::stop() {
  mDone = true;
}

WallpaperX *WallpaperX::mInstance = NULL;


