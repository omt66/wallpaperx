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
}

WallpaperX::~WallpaperX() {
    stop();    
}

void WallpaperX::stop() {
	mDone = true;
}

WallpaperX *WallpaperX::mInstance = NULL;


