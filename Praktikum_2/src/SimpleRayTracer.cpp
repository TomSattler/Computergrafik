//
//  SimpleRayTracer.cpp
//  SimpleRayTracer
//
//  Created by Philipp Lensing on 03.09.14.
//  Copyright (c) 2014 Philipp Lensing. All rights reserved.
//

#include "SimpleRayTracer.h"
#include "rgbimage.h"
#include <stdio.h>
#include <math.h>


Camera::Camera( float zvalue, float planedist, float width, float height, unsigned int widthInPixel, unsigned int heightInPixel )
{
	this->zvalue = zvalue;
	this->planedist = planedist;
	this->widthInPixel = widthInPixel;
	this->heightInPixel = heightInPixel;
	this->height = height;
	this->width = width;
	this->pixelXSize = this->width / this->widthInPixel;
	this->pixelYSize = this->height / this->heightInPixel;
}

Vector Camera::generateRay( unsigned int x, unsigned int y) const
{
	float xInVector = this->pixelXSize * x - width * 0.5f;
	float yInVector = this->pixelYSize * -y - width * 0.5f;
	float zInVector = - this->planedist;
	Vector vector = Vector(xInVector, yInVector, zInVector);
	vector.normalize();
    return vector;
}

Vector Camera::Position() const
{
	return Vector(0,0,this->zvalue);
}

SimpleRayTracer::SimpleRayTracer(unsigned int MaxDepth)
{
	// TODO: Add your code
}


void SimpleRayTracer::traceScene( const Scene& SceneModel, RGBImage& Image)
{
	// TODO: Add your code
}

Color SimpleRayTracer::localIllumination( const Vector& Surface, const Vector& Eye, const Vector& N, const PointLight& Light, const Material& Mtrl )
{
	// TODO: Add your code
	return Color(); // dummy (remove)
}

Color SimpleRayTracer::trace( const Scene& SceneModel, const Vector& o, const Vector& d, int depth)
{
	// TODO: Add your code
	return Color(); // dummy (remove)
}

