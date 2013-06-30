#include "ImageLoader.hpp"

void ImageLoader::init()
{
	ilInit();
}

GLuint ImageLoader::loadBMP_custom(const char * imagepath)
{
	// Dbg::out("ImageLoader")<< "ImageLoader::loadBMP_custom " << imagepath << std::endl;

	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	unsigned char * data;

	// Open the file
	FILE * file = fopen(imagepath,"rb");
	if (!file)
	{
		printf("Image could not be opened\n");
		return 0;
	}
	if ( fread(header, 1, 54, file)!=54 )
	{ 
		// If not 54 bytes read : problem
    	printf("Not a correct BMP file\n");
    	return false;
	}
	if ( header[0]!='B' || header[1]!='M' )
	{
		printf("Not a correct BMP file\n");
    	return 0;
	}
	
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	// Some BMP files are misformatted, guess missing information
	if (imageSize==0)
		imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)
		dataPos=54; // The BMP header is done that way

	// Create a buffer
	data = new unsigned char [imageSize];
 
	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);
 
	//Everything is in memory now, the file can be closed
	fclose(file);

	// Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);
	 
	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);
	 
	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	return textureID;
}

GLuint ImageLoader::loadImage_devil(const char * imagepath)
{
	// Dbg::out("ImageLoader")<< "ImageLoader::loadImage_devil " << imagepath << std::endl;

	ILuint texid;
	GLuint image;
	ILboolean success;

	ilGenImages(1, &texid); // Generation of one image name
	ilBindImage(texid); // Binding of image name
	success = ilLoadImage((const ILstring)imagepath); // Loading of image "image.jpg"
	/*if (success) // If no error occured:
	{
		success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE); // Convert every colour component into	unsigned byte. If your image contains alpha channel you can replace IL_RGB with IL_RGBA
		if (!success)
		{
			// Error occured
			// SDL_Quit();
			return 0;
		}
		glGenTextures(1, &image); // Texture name generation
		glBindTexture(GL_TEXTURE_2D, image); // Binding of texture name
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // We will use linear interpolation for magnification filter
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); // We will use linear interpolation for minifying filter
		glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_BPP), ilGetInteger(IL_IMAGE_WIDTH),
		ilGetInteger(IL_IMAGE_HEIGHT), 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
		ilGetData()); // Texture specification
		return image;
	}
	else
	{
		// Error occured
		// SDL_Quit();
		return 0;
	}
	return 0;*/
}
