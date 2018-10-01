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
#ifndef WALLPAPERX_H
#define WALLPAPERX_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <vector>
#include <csignal>
#include <cstdlib>
#include <unistd.h>

using namespace std;

class WallpaperX {
public:
    WallpaperX(vector<string> imageFileNames);  
    ~WallpaperX();
    void start();
    void stop();

private: 
    //--- Data Members ---
    bool mDone;
    vector<string> mWallpaperImageFiles;

    //--- Member Functions (Methods) ---
	int getCurrentDesktopNo();
	void setDesktopBackground(int desktopNo);
	void msleep(int sleepTime);
	static void stopProcess(int sigNo);
	static WallpaperX *mInstance;
};

#endif