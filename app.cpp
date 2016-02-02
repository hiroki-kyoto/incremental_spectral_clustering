#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <dirent.h>
#include <errno.h>
#include <ctime>

#include "CImg.h"

using namespace cimg_library;
using namespace std;


// function declaration
// os help
int getdir(string dir, vector<string> &files);

// some settings
// mask field: [x-r,y-r]->[x+r,y+r]
const int r = 2; // radius of gradient mask
// sampling set: ratio*(2*r+1)^2
const int ratio = 1; // ratio of sampling

int main(int argc, char ** argv)
{
	CImg <unsigned char> im;
	vector<string> files;
	stringstream ss;
	string dir("pics/");
	if(getdir(dir, files))
		return -1;
	ss.str("");
	ss<<dir;
	ss<<files[0];
	
	im.assign(ss.str().c_str());
	
	int width = im.width();
	int height = im.height();
	int depth = im.depth();
	int channel = im.spectrum();
	unsigned char * data = im.data();

	cout<<"IMAGE INFORMATION:"<<endl;
	cout<<"WIDTH:"<<width<<endl;
	cout<<"HEIGHT:"<<height<<endl;
	cout<<"DEPTH:"<<depth<<endl;
	cout<<"CHANNEL:"<<channel<<endl;
	
	// process image
	// the pixel array:
	// R[height, width],G,B...

	srand((unsigned)time(NULL));
	int n = ratio*(2*r+1)*(2*r+1);

	for(int k=0; k<channel; k++)
	{
		int coff = k*width*height;
		for(int j=0; j<height; j++)
		{
			int hoff = j*width;
			for(int i=0; i<width; i++)
			{
				// sampling pairs of point
				int p=0;
				for(; p<n; p++)
				{
					int x1 = i+rand()%(2*r)-r;
					int y1 = j+rand()%(2*r)-r;

					int x2 = i+rand()%(2*r)-r;
					int y2 = j+rand()%(2*r)-r;
					
					if(x1=y1&&x2=y2)
					{
						p--;
						continue;
					}

					// do stats
					int s[2];
					int c[2];
					s = x1-x2;

				}	
			}
		}
	}
	
	im.display();
	
	// machine state recovery
	

	return 0;
}


// os tool
// only works in unix-like system
//
// struct dirent{
//	ino_t d_ino;//inode number
//	off_t d_off;//offset to next dirent
//	unsigned short d_reclen;//record length
//	unsigned char d_type;// file:8;dir:4
//	char d_name[256];//filename
// }
//
int getdir(string dir, vector<string> &files)
{
	DIR *dp;
	struct dirent *dirp;

	if((dp=opendir(dir.c_str())) == NULL)
	{
		cout<<"Error: failed to open "<<dir;
		cout<<endl;
		return errno;
	}

	while((dirp = readdir(dp)) != NULL)
	{
		if(dirp->d_type==8)
			files.push_back(string(dirp->d_name));
	}

	closedir(dp);

	return 0;
}



