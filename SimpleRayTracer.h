//
//  SimpleRayTracer.h
//  SimpleRayTracer
//
//  Created by Philipp Lensing on 03.09.14.
//  Copyright (c) 2014 Philipp Lensing. All rights reserved.
//

#ifndef SimpleRayTracer_SimpleRayTracer_h
#define SimpleRayTracer_SimpleRayTracer_h

#include "CGUtilities.h"

class RGBImage;

class Camera
{
public:
    Camera(float zvalue, float planedist, float width, float height, unsigned int widthInPixel, unsigned int heightInPixel);
    Vector generateRay(unsigned int x, unsigned int y) const;
    Vector Position() const;
private:
    float zvalue;
    float planedist;
    float width;
    float height;
    float widthInPixel;
    float heightInPixel;
    float pixelXSize;
    float pixelYSize;
}
;

class SimpleRayTracer
{
public:
    SimpleRayTracer(unsigned int MaxDepth);
    void traceScene( const Scene& SceneModel, RGBImage& Image);
protected:
    Color trace( const Scene& SceneModel, const Vector& o, const Vector& d, int depth);
    Color localIllumination( const Vector& SurfacePoint, const Vector& Eye, const Vector& Normal, const PointLight& Light, const Material& Material );
    float nearestRectangel(const Scene& SceneModel, const Vector& o, const Vector& d, float &hittingPoint);
private:
    int maxDepth;
};


#endif
