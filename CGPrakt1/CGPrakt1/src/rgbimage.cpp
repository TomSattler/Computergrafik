#include "rgbimage.h"
#include "color.h"
#include "assert.h"
#include "stdio.h"

RGBImage::RGBImage( unsigned int Width, unsigned int Height)
{
	this->m_Width = Width;
	this->m_Height = Height;
	this->m_Image = new Color[Width*Height];
}

RGBImage::~RGBImage()
{
	delete this->m_Image;
}

void RGBImage::setPixelColor( unsigned int x, unsigned int y, const Color& c)
{
	this->m_Image[y * this->m_Width + x] = c;

}

const Color& RGBImage::getPixelColor( unsigned int x, unsigned int y) const
{
	return this->m_Image[y * this->m_Width + x];
}

unsigned int RGBImage::width() const
{
	return this->m_Width;
}
unsigned int RGBImage::height() const
{
	return this->m_Height;
}

unsigned char RGBImage::convertColorChannel( float v)
{
	char c;
	if (v < 0.0f) {
		c = 0.0f;
		return c;
	}
	if (v > 1.0f) {
		c = 255.0f;
		return c;
	}
	c = v * 255.0f;
	return c;
}


bool RGBImage::saveToDisk( const char* Filename)
{
	FILE* file;
	errno_t err = fopen_s(&file, Filename, "wb");
	if (file == NULL) {
		return false;
	}
	int imgSize = 3 * m_Height * m_Width;
	int fileSize = 54 + imgSize;

	unsigned char bmpheader[54];
	for (int i = 0; i < sizeof(bmpheader); i++) {
		bmpheader[i] = 0;
	}
	bmpheader[0] = 'B';
	bmpheader[1] = 'M';
	//bfSize
	bmpheader[2] = (unsigned char)(fileSize);
	bmpheader[3] = (unsigned char)(fileSize >> 8);
	bmpheader[4] = (unsigned char)(fileSize >> 16);
	bmpheader[5] = (unsigned char)(fileSize >> 24);
	//bfOffBits / Infoheader + fileheader = size
	bmpheader[10] = 54;
	//Infoheader
	bmpheader[14] = 40;
	//Breite der BMP
	bmpheader[18] = (unsigned char)(this->m_Width);
	bmpheader[19] = (unsigned char)(this->m_Width >> 8);
	bmpheader[20] = (unsigned char)(this->m_Width >> 16);
	bmpheader[21] = (unsigned char)(this->m_Width >> 24);
	//Höhe der BMP
	bmpheader[22] = (unsigned char)(this->m_Height * -1);
	bmpheader[23] = (unsigned char)(this->m_Height * -1 >> 8);
	bmpheader[24] = (unsigned char)(this->m_Height * -1 >> 16);
	bmpheader[25] = (unsigned char)(this->m_Height * -1 >> 24);
	//anzahl an farbe planes
	bmpheader[26] = 1;
	//Color bit depth - 1,4,8,16,24,32
	bmpheader[28] = 24;
	//Size Image
	bmpheader[34] = (unsigned char)(imgSize);
	bmpheader[35] = (unsigned char)(imgSize >> 8);
	bmpheader[36] = (unsigned char)(imgSize >> 16);
	bmpheader[37] = (unsigned char)(imgSize >> 24);

	fwrite(bmpheader, 1, 54, file);

	for (int i = 0; i < m_Height * m_Width; i++) {
		unsigned char R = convertColorChannel(this->m_Image[i].R);
		unsigned char G = convertColorChannel(this->m_Image[i].G);
		unsigned char B = convertColorChannel(this->m_Image[i].B);
		fwrite(&B, 1, 1, file);
		fwrite(&G, 1, 1, file);
		fwrite(&R, 1, 1, file);
	}
	fclose(file);

	return true; 
}
