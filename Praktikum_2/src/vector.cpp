#include "vector.h"
#include <assert.h>
#include <math.h>

#define threshold 1e-6

Vector::Vector(float x, float y, float z)
{
	this->X = x;
	this->Y = y;
	this->Z = z;
}
Vector::Vector()
{
	
}

float Vector::dot(const Vector& v) const
{
	float sklrprdkt = this->X * v.X + this->Y * v.Y + this->Z * v.Z;
	return sklrprdkt;
}

Vector Vector::cross(const Vector& v) const
{
	Vector vector = Vector((this->Y * v.Z) - (this->Z * v.Y), (this->Z * v.X) - (this->X * v.Z), (this->X * v.Y) - (this->Y * v.X));
	std::cout << (this->Y * v.Z) - (this->Z * v.Y);
	return vector; 
}



Vector Vector::operator+(const Vector& v) const
{
	Vector vector = Vector(this->X + v.X, this->Y + v.Y, this->Z + v.Z);
	return vector;
}

Vector Vector::operator-(const Vector& v) const
{
	Vector vector = Vector(this->X - v.X, this->Y - v.Y, this->Z - v.Z);
	return vector;
}

Vector Vector::operator*(float c) const
{
	Vector vector = Vector(this->X * c, this->Y * c, this->Z * c);
	return vector;
}

Vector Vector::operator-() const
{
	Vector vector = Vector(-this->X, -this->Y, -this->Z);
	return vector; // dummy (remove)
}

Vector& Vector::operator+=(const Vector& v)
{
	this->X = this->X + v.X;
	this->Y = this->Y + v.Y;
	this->Z = this->Z + v.Z;
	return *this; // dummy (remove)
}



Vector& Vector::normalize()
{
	float factor = sqrt(pow(this->X, 2) + pow(this->Y, 2) + pow(this->Z, 2));
	this->X = this->X * 1/factor;
	this->Y = this->Y * 1/factor;
	this->Z = this->Z * 1/factor;
	return *this;
}

float Vector::length() const
{
	float factor = sqrt(lengthSquared());
	return factor; 
}

float Vector::lengthSquared() const
{
	return pow(this->X, 2) + pow(this->Y, 2) + pow(this->Z, 2);
}

Vector Vector::reflection( const Vector& normal) const
{
	Vector vector = Vector();
	vector.X = this->X - (2 * this->X * normal.X);
	vector.Y = this->Y - (2 * this->Y * normal.Y);
	vector.Z = this->Z - (2 * this->Z * normal.Z);
	return vector;
}

bool Vector::triangleIntersection( const Vector& d, const Vector& a, const Vector& b, const Vector& c, float& s) const
{
	//Strahlursprung = *this, Strahlrichtung = d, Vertizes des Dreiecks a b c
	//n = Oberflaechennormale
	Vector oberflaechennormale = (b - a).cross(c - a).normalize();
	
	// Ist d parallel zu der Ebene?
	if (fabs(d.dot(oberflaechennormale)) < threshold) {
		return false;
	}

	// Distanz zur Ebene vom Ursprung
	float distanz = oberflaechennormale.dot(b);

	//Schnittpunkt
	s = (distanz - (oberflaechennormale.dot(*this))) / oberflaechennormale.dot(d);

	//Strahl zeigt in andere Richtung
	if (s < 0) {
		return false;
	}

	Vector p = (*this) + (d * s);

	float abc = (((b - a).cross(c - a)).length()) / 2;
	float abp = (((b - a).cross(p - a)).length()) / 2;
	float acp = (((c - a).cross(p - a).length()) / 2);
	float bcp = (((c - b).cross(p - b).length()) / 2);

	if (abc + threshold >= abp + acp + bcp) {
		return true;
	}

	return false;
}
