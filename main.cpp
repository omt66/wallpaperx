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
#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 
#include <vector>
#include <csignal>
#include <cstdlib>
#include <unistd.h>
#include "wallpaperx.h"

using namespace std;

void showVersion() {
	cout << "wallpaperx version 1.0" << endl
        << "(c) 2005 omt66. All rights reserved." << endl;
		
 	exit(0);
}

void showUsage() {
	cout << "Usage is: Wallpaperx "  
        << "[options]  [imageFileName1 imageFileName2 ...]"
        << endl
        << "\t--help | -h | ? \tShow usage information" << endl
        << "\t--version | -v  \tShow version information" << endl << endl
        << "If no image filenames provided then default ones will be used" << endl
        << "\t1) ~/wallpapers/image1.png" << endl
        << "\t2) ~/wallpapers/image1.png" << endl
        << "\t   ..." << endl
        << "\t8) ~/wallpapers/image8.png" << endl
		<< endl;

	exit(0);
}

int main(int argc, char* argv[]) {
	vector<string> fileNames; 

	if (argc > 1) {
		string arg = argv[1];
		if (arg == "--help" ||
			arg == "-h" ||
			arg == "?") {

			showUsage();
		}
		else if (arg == "--version" ||
 				 arg == "-v") {

			showVersion();
		}
		
		// Get the file names from the command line
		for (int i=1;i < argc;i++) {
			cout << "i-> " << i << " -> " << argv[i] << endl;
			fileNames.push_back(argv[i]);
		}
	}
	else {
		// Default image file names (8 desktops assumed!)		
		fileNames.push_back("~/wallpapers/image1.jpg");
		fileNames.push_back("~/wallpapers/image2.jpg");
		fileNames.push_back("~/wallpapers/image3.jpg");
		fileNames.push_back("~/wallpapers/image4.jpg");
		fileNames.push_back("~/wallpapers/image5.jpg");
		fileNames.push_back("~/wallpapers/image6.jpg");
		fileNames.push_back("~/wallpapers/image7.jpg");
		fileNames.push_back("~/wallpapers/image8.jpg");
	}

    WallpaperX wx(fileNames);
    
	cout << "Thanks for using WallpaperX. Bye bye :)" << endl;

	return 0;
}
