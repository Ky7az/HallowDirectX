#ifndef __VECTOR_H__
#define __VECTOR_H__

/** INCLUDES **/
#include <iostream>
#include <cmath>

/** DEFINES **/

/** CLASSES **/
/* Vec2D */
typedef struct {
	float x, y;
} vec2d;

class Vec2D
{
public:
	Vec2D(float x = 0.0f, float y = 0.0f);
	Vec2D(const Vec2D &v);
	~Vec2D();

	Vec2D& operator+= (const Vec2D &v);
	Vec2D operator+ (const Vec2D &v) const;
	Vec2D& operator-= (const Vec2D &v);
	Vec2D operator- (const Vec2D &v) const;
	Vec2D& operator/= (const Vec2D &v);
	Vec2D operator/ (const Vec2D &v) const;
	Vec2D& operator*= (const Vec2D &v);
	Vec2D operator* (const Vec2D &v) const;
	float calc_dist(const Vec2D &v) const;

	float x, y;
};

/* Vec3D */
typedef struct {
	float x, y, z;
} vec3d;

class Vec3D
{
public:
	Vec3D(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	Vec3D(const Vec3D &v);
	~Vec3D();

	Vec3D& operator+= (const Vec3D &v);
	Vec3D operator+ (const Vec3D &v) const;
	Vec3D& operator-= (const Vec3D &v);
	Vec3D operator- (const Vec3D &v) const;
	Vec3D& operator/= (const Vec3D &v);
	Vec3D operator/ (const Vec3D &v) const;
	Vec3D& operator*= (const Vec3D &v);
	Vec3D operator* (const Vec3D &v) const;
	float calc_dist(const Vec3D &v) const;

	float x, y, z;
};

#endif