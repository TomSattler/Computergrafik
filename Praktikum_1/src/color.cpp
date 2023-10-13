#include "color.h"
#include <assert.h>

Color::Color()
{
    R = 0;
    G = 0;
    B = 0;
}

Color::Color( float r, float g, float b)
{
    R = r;
    G = g;
    B = b;
}

Color Color::operator*(const Color& c) const
{
    Color temp = Color();
    temp.R = R * c.R;
    temp.G = G*c.G;
    temp.B = B*c.B;
    return temp;
}

Color Color::operator*(const float Factor) const
{
    Color temp = Color();
    temp.R = R*Factor;
    temp.G = G*Factor;
    temp.B = B*Factor;
    return temp;
}

Color Color::operator+(const Color& c) const
{
    Color temp = Color();
    temp.R = R + c.R;
    temp.G = G + c.G;
    temp.B = B + c.B;
    return temp;
}

Color& Color::operator+=(const Color& c)
{
    Color temp = Color();
    temp.R = R + c.R;
    temp.G = G + c.G;
    temp.B = B + c.B;
    return temp;
}

