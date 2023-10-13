#include "rgbimage.h"
#include "color.h"
#include "assert.h"

RGBImage::RGBImage( unsigned int Width, unsigned int Height)
{
    m_Width = Width;
    m_Height = Height;
}

RGBImage::~RGBImage()
{
    delete m_Image;
}

void RGBImage::setPixelColor( unsigned int x, unsigned int y, const Color& c)
{
	
}

const Color& RGBImage::getPixelColor( unsigned int x, unsigned int y) const
{
	// TODO: add your code
	return Color(); // dummy (remove)
}

unsigned int RGBImage::width() const
{
	// TODO: add your code
	return 0; // dummy (remove)
}
unsigned int RGBImage::height() const
{
	// TODO: add your code
	return 0; // dummy (remove)
}

unsigned char RGBImage::convertColorChannel( float v)
{
	// TODO: add your code
	return 0; // dummy (remove)
}


bool RGBImage::saveToDisk( const char* Filename)
{
	// TODO: add your code
	return false; // dummy (remove)
}
