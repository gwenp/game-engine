#ifndef IMAGELOADER_HPP
#define IMAGELOADER_HPP

#include <iostream>
#include <stdio.h>
#include <fstream>
#include <GL/gl.h>                         // Header File For The OpenGL32 Library
#include <GL/glu.h>                            // Header File For The GLu32 Library
#include <IL/il.h> 

class ImageLoader
{
public:
	static void init();
	
	static GLuint loadBMP_custom(const char * imagepath);
	static GLuint loadImage_devil(const char * imagepath);
};

#endif /* IMAGELOADER_HPP */