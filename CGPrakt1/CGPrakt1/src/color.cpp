#include "color.h"
#include <assert.h>

Color::Color()
{
	this->R = 255.0f;
	this->G = 255.0f;
	this->B = 255.0f;
}

Color::Color( float r, float g, float b)
{
	if (r, g, b < 255.0f && r, g, b >0.0f) {
		this->R = r;
		this->G = g;
		this->B = b;
	}
	else {
		Color();
	}
}

Color Color::operator*(const Color& c) const
{	
	Color temp = Color();
	if (R * c.R > 255.0f) {
		temp.R = R * c.R;
	}
	else if (R * c.R < 0.0f) {
		temp.R = 0.0f;
	}
	else {
		temp.R = R * c.R;
	}
	if (G * c.G > 255.0f) {
		temp.G = G * c.G;
	}
	else if (G * c.G < 0.0f) {
		temp.G = 0.0f;
	}
	else {
		temp.G = G * c.G;
	}
	if (B * c.B > 255.0f) {
		temp.B = B * c.B;
	}
	else if (B * c.B < 0.0f) {
		temp.B = 0.0f;
	}
	else {
		temp.B = B * c.B;
	}
    return temp;
}

Color Color::operator*(const float Factor) const
{
	Color temp = Color();
	if (R * Factor > 255.0f) {
		temp.R = R * Factor;
	}
	else if (R * Factor < 0.0f) {
		temp.R = 0.0f;
	}
	else {
		temp.R = R * Factor;
	}
	if (G * Factor > 255.0f) {
		temp.G = G * Factor;
	}
	else if (G * Factor < 0.0f) {
		temp.G = 0.0f;
	}
	else {
		temp.G = G * Factor;
	}
	if (B * Factor > 255.0f) {
		temp.B = B * Factor;
	}
	else if (B * Factor < 0.0f) {
		temp.B = 0.0f;
	}
	else {
		temp.B = B * Factor;
	}
	return temp;
}

Color Color::operator+(const Color& c) const
{
	Color temp = Color();
	if (R + c.R > 255.0f) {
		temp.R = R + c.R;
	}
	else if (R + c.R < 0.0f) {
		temp.R = 0.0f;
	}
	else {
		temp.R = R + c.R;
	}
	if (G + c.G > 255.0f) {
		temp.G = G + c.G;
	}
	else if (G + c.G < 0.0f) {
		temp.G = 0.0f;
	}
	else {
		temp.G = G + c.G;
	}
	if (B + c.B > 255.0f) {
		temp.B = B + c.B;
	}
	else if (B + c.B < 0.0f) {
		temp.B = 0.0f;
	}
	else {
		temp.B = B + c.B;
	}
	return temp;
}

Color& Color::operator+=(const Color& c)
{
	if (R + c.R > 255.0f) {
		R = R + c.R;
	}
	else if (R + c.R < 0.0f) {
		R = 0.0f;
	}
	else {
		R = R + c.R;
	}
	if (G + c.G > 255.0f) {
		G = G + c.G;
	}
	else if (G + c.G < 0.0f) {
		G = 0.0f;
	}
	else {
		G = G + c.G;
	}
	if (B + c.B > 255.0f) {
		B = B + c.B;
	}
	else if (B + c.B < 0.0f) {
		B = 0.0f;
	}
	else {
		B = B + c.B;
	}
	return *this; // dummy (remove)
}