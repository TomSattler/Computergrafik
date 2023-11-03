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

Vector Camera::generateRay(unsigned int x, unsigned int y) const
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
    this -> maxDepth = MaxDepth;
}


void SimpleRayTracer::traceScene( const Scene& SceneModel, RGBImage& Image)
{
    //Image.height/width = h/w
    Camera camera = Camera(-8, 1, 1, 0.75, 640, 480);
    for(int y = 0; y < Image.height(); y++){
        for(int x = 0; x < Image.width(); x++){
            Image.setPixelColor(x, y, Color());
            Vector s = camera.generateRay(x, y);
            Image.setPixelColor(x, y, trace(SceneModel, camera.Position(), s, this -> maxDepth));
        }
    }
}

Color SimpleRayTracer::localIllumination( const Vector& Surface, const Vector& Eye, const Vector& N, const PointLight& Light, const Material& Mtrl )
{
    return Mtrl.getDiffuseCoeff(Surface);
}

Color SimpleRayTracer::trace( const Scene& SceneModel, const Vector& o, const Vector& d, int depth)
{
    float hittingPoint = 0;
    bool light;
    //Berechnung des Auftrittpunkts P auf dem Dreieck. -> normalvektor des Kamerapixels(generate ray) * hitting Point
    hittingPoint = nearestRectangel(SceneModel, o);
    if(hittingPoint!=0){
        d*hittingPoint;
        for(int i = 0; i < SceneModel.getLightCount(); i++){
            if()
        }
    }
    
    return Color();
}
float SimpleRayTracer::nearestRectangel(const Scene &SceneModel, const Vector &o, const Vector &d, float &hittingPoint){
    float temp = 0;
    for(int i = 0; i<SceneModel.getTriangleCount(); i++){
        temp = d.triangleIntersection(o, SceneModel.getTriangle(i).A,SceneModel.getTriangle(i).B,SceneModel.getTriangle(i).C, hittingPoint);
        if(temp<hittingPoint){
            hittingPoint = temp;
        }
    }
    return temp;
}

