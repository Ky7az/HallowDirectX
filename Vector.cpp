#include "Vector.h"
using namespace std;

/* Vec2D */
Vec2D::Vec2D(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec2D::Vec2D(const Vec2D &v)
{
	this->x = v.x;
	this->y = v.y;
}

Vec2D::~Vec2D()
{
}

Vec2D& Vec2D::operator+= (const Vec2D &v)
{
	x += v.x;
	y += v.y;
	return *this;
}

Vec2D Vec2D::operator+ (const Vec2D &v) const
{
	Vec2D r = *this;
	r += v;
	return r;
}

Vec2D& Vec2D::operator-= (const Vec2D &v)
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vec2D Vec2D::operator- (const Vec2D &v) const
{
	Vec2D r = *this;
	r -= v;
	return r;
}

Vec2D& Vec2D::operator/= (const Vec2D &v)
{
	x /= v.x;
	y /= v.y;
	return *this;
}

Vec2D Vec2D::operator/ (const Vec2D &v) const
{
	Vec2D r = *this;
	r /= v;
	return r;
}

Vec2D& Vec2D::operator*= (const Vec2D &v)
{
	x *= v.x;
	y *= v.y;
	return *this;
}

Vec2D Vec2D::operator* (const Vec2D &v) const
{
	Vec2D r = *this;
	r *= v;
	return r;
}

float Vec2D::calc_dist(const Vec2D &v) const
{
	return sqrtf(pow(x - v.x, 2) + pow(y - v.y, 2));
}

/* Vec3D */
Vec3D::Vec3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3D::Vec3D(const Vec3D &v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

Vec3D::~Vec3D()
{
}

Vec3D& Vec3D::operator+= (const Vec3D &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vec3D Vec3D::operator+ (const Vec3D &v) const
{
	Vec3D r = *this; 
	r += v;
	return r;
}

Vec3D& Vec3D::operator-= (const Vec3D &v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vec3D Vec3D::operator- (const Vec3D &v) const
{
	Vec3D r = *this;
	r -= v;
	return r;
}

Vec3D& Vec3D::operator/= (const Vec3D &v)
{
	x /= v.x;
	y /= v.y;
	z /= v.z;
	return *this;
}

Vec3D Vec3D::operator/ (const Vec3D &v) const
{
	Vec3D r = *this;
	r /= v;
	return r;
}

Vec3D& Vec3D::operator*= (const Vec3D &v)
{
	x *= v.x;
	y *= v.y;
	z *= v.z;
	return *this;
}

Vec3D Vec3D::operator* (const Vec3D &v) const
{
	Vec3D r = *this;
	r *= v;
	return r;
}

float Vec3D::calc_dist(const Vec3D &v) const
{
	return sqrtf(pow(x - v.x, 2) + pow(y - v.y, 2) + pow(z - v.z, 2));
}