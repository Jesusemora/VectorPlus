#ifndef __VECTOR_PLUS_H_INCLUDED__
#define __VECTOR_PLUS_H_INCLUDED__

//#include "Math/MatrixTools.h"
#include <string>
#include <cmath>
#include <vector>

const double PI = 3.141592653589793;
const double radian = PI / 180;

/*template <typename T>
class Property {
public:
	virtual ~Property() {}
	virtual T& operator= (constT& f) { return value = f; }
	virtual const T& operator() () const { return value; }
	virtual explicit operator const T& () const { return value; }
	virtual T* operator->() { return &value; }
protected:
	T value;
};

class : public Property<float> {
	virtual float & operator = (const float &f) { return value = f;}
	virtual operator float const & () const { return value; }
} y;*/

/*class Test {
public:
	Property<int, Test> Number{this, &Test::setNumber, &Test::getNumber};
private:
	int itsNumber;
	void setNumber(int theNumber)
	{
		itsNumber = theNumber;
	}
	
	int getNumber() const
	{
		return itsNumber;
	}
};*/

/*
	+ - * / %
	+ - ++ --
	= += *= /= -= %=
	& | << >> ~ ^
	(->)
	New delete
	[]
	()
	& || !
	> < == <= >=
 */

class Vector4;
class Matrix4x4;

class Vector2
{
protected:
	float pos[2] = {0.0, 0.0};//replace with 4x4
	
	//get set x
public:
	//Property<float> x;
	
	//class : public Property<float> { friend class Owner; } x;
	//Owner() { x.value = 8; }
	
	float &x = this->pos[0];
	float &y = this->pos[1];
	
	Vector2(float posx, float posy)
	{
		x = posx;
		y = posy;
	}
	
	//OVERLOADING operator
	//VECTOR2
	Vector2 operator+(Vector2 const& obj)
	{
		Vector2 res(0, 0);
		res.x = this->x + obj.x;
		res.y = this->y + obj.y;
		return res;
	}
	
	Vector2 operator-(Vector2 const& obj)
	{
		Vector2 res(0, 0);
		res.x = this->x - obj.x;
		res.y = this->y - obj.y;
		return res;
	}
	
	Vector2& operator+=(const Vector2 & obj)
	{
		this->x += obj.x;
		this->y += obj.y;
	}
	
	Vector2& operator-=(const Vector2 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
	}
	
	//FLOAT VECTOR2
	Vector2 operator*(float const& obj)
	{
		Vector2 res(0, 0);
		res.x = this->x * obj;
		res.y = this->y * obj;
		return res;
	}
	
	Vector2 operator/(float const& obj)
	{
		Vector2 res(0, 0);
		res.x = this->x / obj;
		res.y = this->y / obj;
		return res;
	}
	
	Vector2 operator+(float const& obj)
	{
		Vector2 res(0, 0);
		res.x = this->x + obj;
		res.y = this->y + obj;
		return res;
	}
	
	Vector2 operator-(float const& obj)
	{
		Vector2 res(0, 0);
		res.x = this->x - obj;
		res.y = this->y - obj;
		return res;
	}
	
	//FLOAT
	Vector2 operator*=(float const& obj)
	{
		this->x *= obj;
		this->y *= obj;
	}
	
	Vector2 operator/=(float const& obj)
	{
		this->x /= obj;
		this->y /= obj;
	}
	
	//SPECIAL
	
	bool operator==(const Vector2 & obj) const
	{
		if(this->x == obj.x && this->y == obj.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//INTERNAL FUNCTIONS
	float Magnitude()
	{
		return (this->x * this->x) + (this->y * this->y);
	}
	
	float sqrMagnitude()
	{
		return static_cast<float>(std::sqrt(this->Magnitude()));//must be non negative
	}
	
	void Normalize()
	{
		float mag = this->sqrMagnitude();
		this->x = this->x / mag;
		this->y = this->y / mag;
		//this->z = this->z / mag;
	}
	
	Vector2 normalized()
	{
		Vector2 res(0, 0);
		float mag = this->sqrMagnitude();
		res.x = this->x / mag;
		res.y = this->y / mag;
		return res;
	}
	//operator float() const { return x.magnitude;}
	
	static bool Equals(Vector2 &a, Vector2 &b)
	{
		if(a.x == b.x && a.y == b.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//angle
	//clampmagnitude
	static float fastDistance(Vector2 a, Vector2 b)
	{
		return std::abs((a.x + a.y) - (b.x + b.y));
	}
	
	static float Distance(Vector2 a, Vector2 b)
	{
		return static_cast<float>(std::sqrt(std::abs(a.Magnitude() - b.Magnitude())));
	}
	
	static float Dot(Vector2 a, Vector2 b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}
	//lerp
	//
	
	//static properties
	static Vector2 down;// = Vector2(0, -1);
	static Vector2 left;// = Vector2(-1, 0);
	static Vector2 right;// = Vector2(1, 0);
	static Vector2 up;// = Vector2(0, 1);
	static Vector2 zero;// = Vector2(0, 0);
};

class Vector3
{
protected:
	float pos[3] = {0.0, 0.0, 0.0};//replace with 4x4
	
	//get set x
public:
	//Property<float> x;
	
	//class : public Property<float> { friend class Owner; } x;
	//Owner() { x.value = 8; }
	
	float &x = this->pos[0];
	float &y = this->pos[1];
	float &z = this->pos[2];
	
	Vector3(float posx, float posy, float posz)
	{
		x = posx;
		y = posy;
		z = posz;
	}
	
	//OVERLOADING operator
	//VECTOR3
	Vector3 operator+(Vector3 const& obj)
	{
		Vector3 res(0, 0, 0);
		res.x = this->x + obj.x;
		res.y = this->y + obj.y;
		res.z = this->z + obj.z;
		return res;
	}
	
	Vector3 operator-(Vector3 const& obj)
	{
		Vector3 res(0, 0, 0);
		res.x = this->x - obj.x;
		res.y = this->y - obj.y;
		res.z = this->z - obj.z;
		return res;
	}
	
	Vector3& operator+=(const Vector3 & obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		this->z += obj.z;
	}
	
	Vector3& operator-=(const Vector3 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		this->z -= obj.z;
	}
	
	//FLOAT VECTOR3
	Vector3 operator*(float const& obj)
	{
		Vector3 res(0, 0, 0);
		res.x = this->x * obj;
		res.y = this->y * obj;
		res.z = this->z * obj;
		return res;
	}
	
	Vector3 operator/(float const& obj)
	{
		Vector3 res(0, 0, 0);
		res.x = this->x / obj;
		res.y = this->y / obj;
		res.z = this->z / obj;
		return res;
	}
	
	Vector3 operator+(float const& obj)
	{
		Vector3 res(0, 0, 0);
		res.x = this->x + obj;
		res.y = this->y + obj;
		res.z = this->z + obj;
		return res;
	}
	
	Vector3 operator-(float const& obj)
	{
		Vector3 res(0, 0, 0);
		res.x = this->x - obj;
		res.y = this->y - obj;
		res.z = this->z - obj;
		return res;
	}
	
	//FLOAT
	Vector3 operator*=(float const& obj)
	{
		this->x *= obj;
		this->y *= obj;
		this->z *= obj;
	}
	
	Vector3 operator/=(float const& obj)
	{
		this->x /= obj;
		this->y /= obj;
		this->z /= obj;
	}
	
	//SPECIAL
	
	bool operator==(const Vector3 & obj) const
	{
		if(this->x == obj.x && this->y == obj.y && this->z == obj.z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void operator=(const Vector3 & obj)
	{
		x = obj.x;
		y = obj.y;
		z = obj.z;
	}
	
	//INTERNAL FUNCTIONS
	float Magnitude()
	{
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z);
	}
	
	float sqrMagnitude()
	{
		return static_cast<float>(std::sqrt(this->Magnitude()));//must be non negative
	}
	
	void Normalize()
	{
		float mag = this->sqrMagnitude();
		this->x = this->x / mag;
		this->y = this->y / mag;
		this->z = this->z / mag;
		//this->z = this->z / mag;
	}
	
	Vector3 normalized()
	{
		Vector3 res(0, 0, 0);
		float mag = this->sqrMagnitude();
		res.x = this->x / mag;
		res.y = this->y / mag;
		res.z = this->z / mag;
		return res;
	}
	//operator float() const { return x.magnitude;}
	
	static bool Equals(Vector3 a, Vector3 b)
	{
		if(a.x == b.x && a.y == b.y && a.z == b.z)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	//angle
	//clampmagnitude
	static float fastDistance(Vector3 a, Vector3 b)
	{
		return std::abs((a.x + a.y + a.z) - (b.x + b.y + b.z));
	}
	
	static float Distance(Vector3 a, Vector3 b)
	{
		return static_cast<float>(std::sqrt(std::abs(a.Magnitude() - b.Magnitude())));
	}
	
	static float Dot(Vector3 a, Vector3 b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	}
	//lerp
	//
	
	//static properties
	static Vector3 down;// = Vector3(0, -1, 0);
	static Vector3 left;// = Vector3(-1, 0, 0);
	static Vector3 right;// = Vector3(1, 0, 0);
	static Vector3 up;// = Vector3(0, 1, 0);
	static Vector3 forward;// = Vector3(0, 0, 1);
	static Vector3 back;// = Vector3(0, 0, -1);
	static Vector3 zero;// = Vector3(0, 0, 0);
};

class Vector4
{
protected:
	//get set x
public:
	float pos[4] = {0.0, 0.0, 0.0, 1.0};
	
	float &x = this->pos[0];
	float &y = this->pos[1];
	float &z = this->pos[2];
	float &w = this->pos[3];
	
	Vector4(float posx, float posy, float posz, float posw)
	{
		x = posx;
		y = posy;
		z = posz;
		w = posw;
	}
	
	Vector4()
	{
		
	}
	
	Vector4(float (&Matrix)[4])
	{
		x = Matrix[0];
		y = Matrix[1];
		z = Matrix[2];
		w = Matrix[3];
	}
	
	//OVERLOADING operator
	
	float& operator[](int i)
	{
		if(i < 4 && i > -1)
		{
			return this->pos[i];
		}
		else
		{
			return this->pos[0];
		}
	}
	
	//VECTOR4
	Vector4 operator+(Vector4 const& obj)
	{
		Vector4 res(0, 0, 0, 1);
		res.x = this->x + obj.x;
		res.y = this->y + obj.y;
		res.z = this->z + obj.z;
		res.w = this->w + obj.w;
		return res;
	}
	
	Vector4 operator-(Vector4 const& obj)
	{
		Vector4 res(0, 0, 0, 1);
		res.x = this->x - obj.x;
		res.y = this->y - obj.y;
		res.z = this->z - obj.z;
		res.w = this->w - obj.w;
		return res;
	}
	
	Vector4& operator+=(const Vector4 & obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		this->z += obj.z;
		this->w += obj.w;
	}
	
	Vector4& operator-=(const Vector4 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		this->z -= obj.z;
		this->w -= obj.w;
	}
	
	/*Vector4 operator*(Matrix4x4 const& obj)
	{
		Vector4 res;
		for(int j = 0; j < 4; j++)
		{
			res.pos[j] = 0;
			for(int k = 0; k < 4; k++)
			{
				res.pos[j] += (pos[k] * obj.pos[k][j]);
			}
		}
		return res;
	}*/
	
	//FLOAT VECTOR4
	Vector4 operator*(float const& obj)
	{
		Vector4 res(0, 0, 0, 1);
		res.x = this->x * obj;
		res.y = this->y * obj;
		res.z = this->z * obj;
		res.w = this->w * obj;
		return res;
	}
	
	Vector4 operator/(float const& obj)
	{
		Vector4 res(0, 0, 0, 1);
		res.x = this->x / obj;
		res.y = this->y / obj;
		res.z = this->z / obj;
		res.w = this->w / obj;
		return res;
	}
	
	Vector4 operator+(float const& obj)
	{
		Vector4 res(0, 0, 0, 1);
		res.x = this->x + obj;
		res.y = this->y + obj;
		res.z = this->z + obj;
		res.w = this->w + obj;
		return res;
	}
	
	Vector4 operator-(float const& obj)
	{
		Vector4 res(0, 0, 0, 1);
		res.x = this->x - obj;
		res.y = this->y - obj;
		res.z = this->z - obj;
		res.w = this->w - obj;
		return res;
	}
	
	//FLOAT
	Vector4 operator*=(float const& obj)
	{
		this->x *= obj;
		this->y *= obj;
		this->z *= obj;
		this->w *= obj;
	}
	
	Vector4 operator/=(float const& obj)
	{
		this->x /= obj;
		this->y /= obj;
		this->z /= obj;
		this->w /= obj;
	}
	
	//SPECIAL
	
	bool operator==(const Vector4 & obj) const
	{
		if(this->x == obj.x && this->y == obj.y && this->z == obj.z && this->w == obj.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void operator=(const Vector4 & obj)
	{
		x = obj.x;
		y = obj.y;
		z = obj.z;
		w = obj.w;
	}
	
	//this is genious
	void operator=(const float (&obj)[4])
	{
		x = obj[0];
		y = obj[1];
		z = obj[2];
		w = obj[3];
	}
	
	void toArray(float (&obj)[4])
	{
		obj[0] = this->x;
		obj[1] = this->y;
		obj[2] = this->z;
		obj[3] = this->w;
	}
	
	//INTERNAL FUNCTIONS
	float Magnitude()
	{
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
	}
	
	float sqrMagnitude()
	{
		return static_cast<float>(std::sqrt(this->Magnitude()));//must be non negative
	}
	
	void Normalize()
	{
		float mag = this->sqrMagnitude();
		this->x = this->x / mag;
		this->y = this->y / mag;
		this->z = this->z / mag;
		//this->z = this->z / mag;
	}
	
	Vector4 normalized()
	{
		Vector4 res(0, 0, 0, 1);
		float mag = this->sqrMagnitude();
		res.x = this->x / mag;
		res.y = this->y / mag;
		res.z = this->z / mag;
		res.w = this->w / mag;
		return res;
	}
	//operator float() const { return x.magnitude;}
	
	static bool Equals(Vector4 a, Vector4 b)
	{
		return a == b;
	}
	
	//angle
	//clampmagnitude
	static float fastDistance(Vector4 a, Vector3 b)
	{
		return std::abs((a.x + a.y + a.z + a.w) - (b.x + b.y + b.z + a.w));
	}
	
	static float Distance(Vector4 a, Vector4 b)
	{
		return static_cast<float>(std::sqrt(std::abs(a.Magnitude() - b.Magnitude())));
	}
	
	static float Dot(Vector4 a, Vector4 b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
	}
	
	/*static float Cross(Vector4 a, Vector4 b)
	{
		return Vector4(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}*/
};

class Matrix4x4
{
protected:
	//col row
public:
	Vector4 pos[4] = {Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0), Vector4(0, 0, 0, 1)};
	//pos = {Vector4(1, 0, 0, 0), Vector4(0, 1, 0, 0), Vector4(0, 0, 1, 0), Vector4(0, 0, 0, 1)};
	
	Vector4 &x = this->pos[0];
	Vector4 &y = this->pos[1];
	Vector4 &z = this->pos[2];
	Vector4 &w = this->pos[3];
	
	Matrix4x4(Vector4 matx, Vector4 maty, Vector4 matz, Vector4 matw)
	{
		x = matx;
		y = maty;
		z = matz;
		w = matw;
	}
	
	Matrix4x4(float (&Matrix)[4][4])
	{
		x = Matrix[0];
		y = Matrix[1];
		z = Matrix[2];
		w = Matrix[3];
	}
	
	Matrix4x4(float (&Matrixx)[4], float (&Matrixy)[4], float (&Matrixz)[4], float (&Matrixw)[4])
	{
		x = Matrixx;
		y = Matrixy;
		z = Matrixz;
		w = Matrixw;
	}
	
	Matrix4x4()
	{
		//identity matrix
		//x = Vector4();
	}
	
	//this does [][]
	Vector4 operator[](int i) const
	{
		if(i < 4 && i >= 0)
		{
			return this->pos[i];
		}
		else
		{
			return this->pos[0];
		}
	}
	
	Matrix4x4 operator+(Matrix4x4 const& obj)
	{
		Matrix4x4 res;
		res.x = this->x + obj.x;
		res.y = this->y + obj.y;
		res.z = this->z + obj.z;
		res.w = this->w + obj.w;
		return res;
	}
	
	Matrix4x4 operator-(Matrix4x4 const& obj)
	{
		Matrix4x4 res;
		res.x = this->x - obj.x;
		res.y = this->y - obj.y;
		res.z = this->z - obj.z;
		res.w = this->w - obj.w;
		return res;
	}
	
	Matrix4x4& operator+=(const Matrix4x4 & obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		this->z += obj.z;
		this->w += obj.w;
	}
	
	Matrix4x4& operator-=(const Matrix4x4 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		this->z -= obj.z;
		this->w -= obj.w;
	}
	
	//MATRIX OPERATIONS
	Matrix4x4 operator*(Matrix4x4 const& obj)
	{
		Matrix4x4 res;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				res.pos[i].pos[j] = 0;
				for(int k = 0; k < 4; k++)
				{
					res.pos[i].pos[j] += this->pos[i][k] * obj[k][j];
				}
			}
		}
		
		return res;
	}
	
	Vector4 operator*(Vector4 const& obj)
	{
		Vector4 res;
		for(int j = 0; j < 4; j++)
		{
			res.pos[j] = 0;
			for(int k = 0; k < 4; k++)
			{
				res.pos[j] += (obj.pos[k] * this->pos[k].pos[j]);
			}
		}
		return res;
	}
	
	bool operator==(const Matrix4x4 & obj) const
	{
		if(this->x == obj.x && this->y == obj.y && this->z == obj.z && this->w == obj.w)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	
	void operator=(const Matrix4x4 & obj)
	{
		x = obj.x;
		y = obj.y;
		z = obj.z;
		w = obj.w;
	}
	
	void operator=(const float (&obj)[4][4])
	{
		this->x.x = obj[0][0];
		this->x.y = obj[0][1];
		this->x.z = obj[0][2];
		this->x.w = obj[0][3];
		
		this->y.x = obj[1][0];
		this->y.y = obj[1][1];
		this->y.z = obj[1][2];
		this->y.w = obj[1][3];
		
		this->z.x = obj[2][0];
		this->z.y = obj[2][1];
		this->z.z = obj[2][2];
		this->z.w = obj[2][3];
		
		this->w.x = obj[3][0];
		this->w.y = obj[3][1];
		this->w.z = obj[3][2];
		this->w.w = obj[3][3];
	}
	
	static Matrix4x4 Euler(float phi, float theta, float psi)
	{
		/*phi *= PI;
		theta *= PI;
		psi *= PI;*/
		Matrix4x4 xRotation(Vector4(1, 0, 0, 0), Vector4(0, std::cos(phi), -std::sin(phi), 0), Vector4(0, std::sin(phi), std::cos(phi), 0), Vector4(0, 0, 0, 1));
		Matrix4x4 yRotation(Vector4(std::cos(theta), 0, std::sin(theta), 0), Vector4(0, 1, 0, 0), Vector4(-std::sin(theta), 0, std::cos(theta), 0), Vector4(0, 0, 0, 1));
		Matrix4x4 zRotation(Vector4(std::cos(psi), -std::sin(psi), 0, 0), Vector4(std::sin(psi), std::cos(psi), 0, 0), Vector4(0, 0, 1, 0), Vector4(0, 0, 0, 1));
		
		return zRotation * (xRotation * yRotation);
	}
	
	static Matrix4x4 EulerRotation(float phi, float theta, float psi)
	{
		return Matrix4x4::Euler(phi * PI, theta * PI, psi * PI);
	}
	
	static Matrix4x4 Translation(float mx, float my, float mz)
	{
		Matrix4x4 Trl;
		Trl.w.x += mx;
		Trl.w.y += my;
		Trl.w.z += mz;
		Trl.w.w = 1;
		return Trl;
	}
	
	static Matrix4x4 Translation(Vector3 &translation)
	{
		Matrix4x4 Trl;
		Trl.w.x += translation.x;
		Trl.w.y += translation.y;
		Trl.w.z += translation.z;
		Trl.w.w = 1;
		return Trl;
	}
	
	void Translate(float mx, float my, float mz)
	{
		this->x.w += mx;
		this->y.w += my;
		this->z.w += mz;
		//this->w.w = 1;//?
	}
	
	void Translate(const Vector3 &translation)
	{
		this->x.w += translation.x;
		this->y.w += translation.y;
		this->z.w += translation.z;
		//this->w.w = 1;//?
	}
	
	void toArray(float (&obj)[4][4])
	{
		obj[0][0] = this->x.x;
		obj[0][1] = this->x.y;
		obj[0][2] = this->x.z;
		obj[0][3] = this->x.w;
		
		obj[1][0] = this->y.x;
		obj[1][1] = this->y.y;
		obj[1][2] = this->y.z;
		obj[1][3] = this->y.w;
		
		obj[2][0] = this->z.x;
		obj[2][1] = this->z.y;
		obj[2][2] = this->z.z;
		obj[2][3] = this->z.w;
		
		obj[3][0] = this->w.x;
		obj[3][1] = this->w.y;
		obj[3][2] = this->w.z;
		obj[3][3] = this->w.w;
	}
	
	static Matrix4x4 Perspective(float FOV, float near, float far)
	{
		Matrix4x4 Mat;
		float persp = FOV * radian;
		float aspectRatio = 4.0 / 3.0;
		persp = 2.0f * atanf(tanf(persp * 0.5) / aspectRatio);
		
		float tangent = tanf(persp / 2.0f);
		float height = near * tangent;
		float width = height * aspectRatio;
		
		/*[a] [b] [c] [d] 	 [X] 	 ax + by + cz + dw
		* [e] [f] [g] [h] 	 [Y] 	 ex + fy + gz + hw
		* [i] [j] [k] [l] 	 [Z] 	 ix + jy + kz + lw
		* [m] [n] [o] [p] 	 [W] 	 mx + ny + oz + pw
		* 
		* C G
		*/
		//Matrix[0][0] = Matrix[][] * persp;
		//Matrix[1][1] = persp;
		//Matrix[2][1] = persp;
		//Xp = ()
		float right = width;
		float left = -width;
		float top = height;
		float bottom = -height;
		
		float Ax = (2 * near) / (right - left);
		float Cx = (right + left) / (right - left);
		float Fy = (2 * near) / (top - bottom);
		float Gz = (top + bottom) / (top - bottom);
		float Kz = -(far + near) / (far - near);
		float Lw = -(2 * far * near) / (far - near);
		Mat.x.x = Ax;
		Mat.z.x = Cx;
		Mat.y.y = Fy;
		Mat.z.y = Gz;
		Mat.z.z = Kz;
		Mat.w.z = Lw;
		Mat.z.w = -1;
		Mat.w.w = 0;
		return Mat;
	}
	
	static Matrix4x4 getIdentityMatrix()
	{
		Matrix4x4 mat;
		return mat;
	}
	
	/*~Matrix4x4()
	{
		delete pos;
	}*/
};

class Texture {
public:
	int width;
	int height;
	unsigned char* imageO;
	bool isAlpha = false;
// 	Texture(int sizex, int sizey, int mipmap)
// 	{
// 		
// 	}
	
	void createTex(char *filePath)
	{
		imageO = SOIL_load_image(filePath, &width, &height, 0, SOIL_LOAD_RGB);
		isAlpha = false;
	}
	
	void createTex(char *filePath, bool alpha)
	{
		imageO = SOIL_load_image(filePath, &width, &height, 0, SOIL_LOAD_RGBA);
		isAlpha = true;
	}
	
	void BindTexture(int id, GLuint *textureID)
	{
		if(imageO)
		{
			glActiveTexture(GL_TEXTURE0 + id);
			glBindTexture(GL_TEXTURE_2D, textureID[id]);
			
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this-> height, 0, GL_RGB, GL_UNSIGNED_BYTE, this->imageO);
			
			glGenerateMipmap(GL_TEXTURE_2D);
		}
	}
	
	~Texture()
	{
		free(imageO);
	}
};

class KX_Rotation {
public:
	float RMatrix[4][4];
	
	virtual void Rotate()
	{}
};

class Component {
	
};

class KX_Vgroup {
public:
	int vertexGroup;
	float weight;
};

class Mesh {
private:
public:
	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> uvs;
	std::vector<float> tangents;
	//std::vector<float> bitangents;
	std::vector<int> indices;
	int numverts;
	int numindices;
	std::string name;
	
	void calculateTangentTriangles(Vector3 edge1, Vector3 edge2, Vector2 deltaUV1, Vector2 deltaUV2)
	{
		float f = 1.0 / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
		
		Vector3 tangent = (edge1 * deltaUV2.y - edge2 * deltaUV1.y) * f;
		tangents.push_back(tangent.x);
		tangents.push_back(tangent.y);
		tangents.push_back(tangent.z);
		
		tangents.push_back(tangent.x);
		tangents.push_back(tangent.y);
		tangents.push_back(tangent.z);
		
		tangents.push_back(tangent.x);
		tangents.push_back(tangent.y);
		tangents.push_back(tangent.z);
		
		//bitangents.push_back(f * (-deltaUV2.x * edge1.x - deltaUV1.x * edge2.x));
		//bitangent1.push_back(f * (-deltaUV2.x * edge1.y - deltaUV1.x * edge2.y));
		//bitangent1.push_back(f * (-deltaUV2.x * edge1.z - deltaUV1.x * edge2.z));
	}
	
	void GetTangentsTriangles()
	{
		//to be used with non indexed meshes. bunch of triangles
		int iverts = 0;
		int iuvs = 0;
		
		for(int abc = 0; abc < vertices.size() / 3; abc+= 3)
		{
			Vector3 v0 = Vector3(this->vertices[iverts], this->vertices[iverts+1], this->vertices[iverts+2]);
			Vector3 v1 = Vector3(vertices[iverts+3], vertices[iverts+4], vertices[iverts+5]);
			Vector3 v2 = Vector3(vertices[iverts+6], vertices[iverts+7], vertices[iverts+8]);
			
			Vector2 uv0 = Vector2(std::abs(uvs[iuvs]), std::abs(uvs[iuvs+1]));
			Vector2 uv1 = Vector2(std::abs(uvs[iuvs+2]), std::abs(uvs[iuvs+3]));
			Vector2 uv2 = Vector2(std::abs(uvs[iuvs+4]), std::abs(uvs[iuvs+5]));
			
			calculateTangentTriangles(v1 - v0, v2 - v0, uv1 - uv0, uv2 - uv0);
			
			iverts += 9;
			iuvs += 6;
		}
	}
};

class RawMesh {
public:
	std::vector<Vector3> vertices;
	std::vector<Vector3> normals;
	std::vector<Vector2> uvs;
	std::vector<Vector3> tangents;
	std::vector<int> indices;
	int numverts;
	std::string name;
};

class UI_Transform
{
public:
	GLfloat posx;
	GLfloat posy;
	GLfloat pos2x;
	GLfloat pos2y;
};

#endif
