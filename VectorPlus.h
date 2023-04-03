#ifndef __VECTOR_PLUS_H_INCLUDED__
#define __VECTOR_PLUS_H_INCLUDED__

#include <SOIL/SOIL.h>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

const double PI = 3.141592653589793;
const double radian = PI / 180;
const double qadian = PI / 360;
const double HALFPI = radian * 90;
const float POINT_FIVE = 0.5;

const float TOLERANCE = 0.00001f;

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

class Sub3 {
	float &x;
	float &y;
	float &z;
	
	Sub3(float &posx, float &posy, float &posz) : x(posx), y(posy), z(posz)
	{
		
	}
};

class Vector2
{
protected:
	//get set x
public:
	float pos[2] = {0.0, 0.0};//replace with 4x4
	
	float &x = this->pos[0];
	float &y = this->pos[1];
	
	Vector2(float posx, float posy)
	{
		x = posx;
		y = posy;
	}
	
	Vector2()
	{
		
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
		return *this;
	}
	
	Vector2& operator-=(const Vector2 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		return *this;
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
		return *this;
	}
	
	Vector2 operator/=(float const& obj)
	{
		this->x /= obj;
		this->y /= obj;
		return *this;
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
	static Vector2 Lerp(Vector2 a, Vector2 b)
	{
		return (a + b) * POINT_FIVE;
	}
	
	static Vector2 Lerp(Vector2 a, Vector2 b, float c)
	{
		return (a + b) * c;
	}
	
	static Vector2 Slerp(Vector2 a, Vector2 b, float c)
	{
		return (a + b) * std::sin(HALFPI * c);
	}
	
	static Vector2 down;
	static Vector2 left;
	static Vector2 right;
	static Vector2 up;
	static Vector2 zero;
};

Vector2 Vector2::down = Vector2(0, -1);
Vector2 Vector2::left = Vector2(-1, 0);
Vector2 Vector2::right = Vector2(1, 0);
Vector2 Vector2::up = Vector2(0, 1);
Vector2 Vector2::zero = Vector2(0, 0);

class Vector3
{
protected:
	//get set x
public:
	float pos[3] = {0.0, 0.0, 0.0};//replace with 4x4
	
	float &x = this->pos[0];
	float &y = this->pos[1];
	float &z = this->pos[2];
	
	Vector3(float posx, float posy, float posz)
	{
		x = posx;
		y = posy;
		z = posz;
	}
	
	Vector3()
	{
		
	}
	
	Vector3(const Vector3 &why)
	{
		this->x = why.x;
		this->y = why.y;
		this->z = why.z;
	}
	
	Vector3(const Vector3 &vx, const Vector3 &vy, const Vector3 &vz)//TODO might have to move this down
	{
		*this = Vector3::Lerp(vx, vy);
		*this = Vector3::Lerp(*this, vz);
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
		return *this;
	}
	
	Vector3& operator-=(const Vector3 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		this->z -= obj.z;
		return *this;
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
		return *this;
	}
	
	Vector3 operator/=(float const& obj)
	{
		this->x /= obj;
		this->y /= obj;
		this->z /= obj;
		return *this;
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
		//return *this;
	}
	
	Vector3 operator=(const Vector2 & obj)
	{
		this->x = obj.x;
		this->y = obj.y;//how should this be handled?
		return *this;
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
		return (a.x == b.x && a.y == b.y && a.z == b.z);
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
	
	static Vector3 Cross(Vector3 a, Vector3 b)
	{
		return Vector3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}
	
	static Vector3 Lerp(Vector3 a, Vector3 b)
	{
		return (a + b) * POINT_FIVE;
	}
	
	static Vector3 Lerp(Vector3 a, Vector3 b, float c)
	{
		return (a + b) * c;
	}
	
	static Vector3 Lerp(Vector3 a, Vector3 b, Vector3 c)
	{
		return (a + b + c) / 3;//this or Lerp Lerp for float accuracy
	}
	
	static Vector3 Slerp(Vector3 a, Vector3 b, float c)
	{
		return (a + b) * std::sin(HALFPI * c);//this is just cosmetic, to get a smooth transition for camera or objects
	}
	
	//lerp
	//
	
	static Vector3 down;// = Vector3(0, -1, 0);
	static Vector3 left;// = Vector3(-1, 0, 0);
	static Vector3 right;// = Vector3(1, 0, 0);
	static Vector3 up;// = Vector3(0, 1, 0);
	static Vector3 forward;// = Vector3(0, 0, 1);
	static Vector3 back;// = Vector3(0, 0, -1);
	static Vector3 zero;// = Vector3(0, 0, 0);
};

Vector3 Vector3::zero = Vector3(0, 0, 0);//what a mouthfull
Vector3 Vector3::down = Vector3(0, -1, 0);
Vector3 Vector3::left = Vector3(-1, 0, 0);
Vector3 Vector3::right = Vector3(1, 0, 0);
Vector3 Vector3::up = Vector3(0, 1, 0);
Vector3 Vector3::forward = Vector3(0, 0, 1);
Vector3 Vector3::back = Vector3(0, 0, -1);

class Vector2Int {//for use in pathfinding
public:
	int pos[2] = {0, 0};
	
	int &x = this->pos[0]; 
	int &y = this->pos[1];
	
	Vector2Int(float posx, float posy)
	{
		this->x = std::round(posx);
		this->y = std::round(posy);
	}
	
	Vector2Int(int posx, int posy)
	{
		this->x = posx;
		this->y = posy;
	}
	
	Vector2Int()
	{
		
	}
	
	Vector2Int(const Vector2 &why)
	{
		this->x = std::round(why.x);
		this->y = std::round(why.y);
	}
	
	Vector2Int(const Vector3 &why)
	{
		this->x = std::round(why.x);
		this->y = std::round(why.y);
	}
	
	Vector2Int operator+(Vector2Int const& obj)
	{
		Vector2Int res(0, 0);
		res.x = this->x + obj.x;
		res.y = this->y + obj.y;
		return res;
	}
	
	Vector2Int operator-(Vector2Int const& obj)
	{
		Vector2Int res(0, 0);
		res.x = this->x - obj.x;
		res.y = this->y - obj.y;
		return res;
	}
	
	Vector2Int operator+(Vector2 const& obj)
	{
		Vector2Int res(0, 0);
		res.x = this->x + std::round(obj.x);
		res.y = this->y + std::round(obj.y);
		return res;
	}
	
	Vector2Int operator-(Vector2 const& obj)
	{
		Vector2Int res(0, 0);
		res.x = this->x - std::round(obj.x);
		res.y = this->y - std::round(obj.y);
		return res;
	}
	
	Vector2Int& operator+=(const Vector2Int & obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		return *this;
	}
	
	Vector2Int& operator-=(const Vector2Int & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		return *this;
	}
	
	Vector2Int& operator+=(const Vector2 & obj)
	{
		this->x += std::round(obj.x);
		this->y += std::round(obj.y);
		return *this;
	}
	
	Vector2Int& operator-=(const Vector2 & obj)
	{
		this->x -= std::round(obj.x);
		this->y -= std::round(obj.y);
		return *this;
	}
	
	//FLOAT VECTOR2
	Vector2Int operator*(float const& obj)
	{
		Vector2Int res(0, 0);
		res.x = std::round(this->x * obj);
		res.y = std::round(this->y * obj);
		return res;
	}
	
	Vector2Int operator*(double const& obj)
	{
		Vector2Int res(0, 0);
		res.x = std::round(this->x * obj);
		res.y = std::round(this->y * obj);
		return res;
	}
	
	Vector2Int operator*(int const& obj)
	{
		Vector2Int res(0, 0);
		res.x = this->x * obj;
		res.y = this->y * obj;
		return res;
	}
	
	Vector2Int operator/(float const& obj)
	{
		Vector2Int res(0, 0);
		res.x = std::round(this->x / obj);
		res.y = std::round(this->y / obj);
		return res;
	}
	
	Vector2Int operator/(int const& obj)
	{
		Vector2Int res(0, 0);
		res.x = this->x / obj;
		res.y = this->y / obj;
		return res;
	}
	
	Vector2Int operator+(float const& obj)
	{
		Vector2Int res(0, 0);
		res.x = std::round(this->x + obj);
		res.y = std::round(this->y + obj);
		return res;
	}
	
	Vector2Int operator+(int const& obj)
	{
		Vector2Int res(0, 0);
		res.x = this->x + obj;
		res.y = this->y + obj;
		return res;
	}
	
	Vector2Int operator-(float const& obj)
	{
		Vector2Int res(0, 0);
		res.x = std::round(this->x - obj);
		res.y = std::round(this->y - obj);
		return res;
	}
	
	Vector2Int operator-(int const& obj)
	{
		Vector2Int res(0, 0);
		res.x = this->x - obj;
		res.y = this->y - obj;
		return res;
	}
	
	//FLOAT
	Vector2Int operator*=(float const& obj)
	{
		this->x = std::round(this->x * obj);
		this->y = std::round(this->y * obj);
		return *this;
	}
	
	Vector2Int operator/=(float const& obj)
	{
		this->x = std::round(this->x / obj);
		this->y = std::round(this->y / obj);
		return *this;
	}
	
	Vector2Int operator*=(int const& obj)
	{
		this->x *= obj;
		this->y *= obj;
		return *this;
	}
	
	Vector2Int operator/=(int const& obj)
	{
		this->x /= obj;
		this->y /= obj;
		return *this;
	}
	
	//SPECIAL
	
	bool operator==(const Vector2Int & obj) const
	{
		return (this->x == obj.x && this->y == obj.y);
	}
	
	bool operator==(const Vector2 & obj) const
	{
		return (this->x == std::round(obj.x) && this->y == std::round(obj.y));
	}
	
	bool operator==(const Vector3 & obj) const
	{
		return (this->x == std::round(obj.x) && this->y == std::round(obj.y));
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
	
	/*void Normalize()//this is probably useless
	{
		float mag = this->sqrMagnitude();
		this->x = this->x / mag;
		this->y = this->y / mag;//found error : assigning float to int / conversion must be made but / values are unit so result will be 0 or 1 / completely useless
		//this->z = this->z / mag;
	}*/
	
	Vector2 normalized()//normalized vector useless //result is unit vector / fix: return Vector2 instead
	{
		Vector2 res(0, 0);
		float mag = this->sqrMagnitude();
		res.x = this->x / mag;//std::round(this->x / mag);
		res.y = this->y / mag;//std::round(this->y / mag);
		return res;
	}
	//operator float() const { return x.magnitude;}
	
	static bool Equals(Vector2Int &a, Vector2Int &b)
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
	static int fastDistance(Vector2Int a, Vector2Int b)
	{
		return std::abs((a.x + a.y) - (b.x + b.y));
	}
	
	static float Distance(Vector2Int a, Vector2Int b)
	{
		return static_cast<float>(std::sqrt(std::abs(a.Magnitude() - b.Magnitude())));
	}
	
	static int Dot(Vector2Int a, Vector2Int b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}
	//lerp
	//
	static Vector2Int Lerp(Vector2Int a, Vector2Int b)
	{
		return (a + b) * POINT_FIVE;
	}
	
	static Vector2Int Lerp(Vector2Int a, Vector2Int b, float c)
	{
		return (a + b) * c;
	}
	
};

class Nav_Node2D : public Vector2Int
{
public:
	std::vector<Nav_Node2D*> Children;
	bool visited = false;
	
	static bool compareInterval(std::pair<float, Nav_Node2D*> i1, std::pair<float, Nav_Node2D*> i2)
	{
		return i1.first < i2.first;
	}
	
	void OrderBySize(Vector2Int goal)
	{
		std::vector<std::pair<float, Nav_Node2D*>> Distances;
		if(!Children.empty())
		{
			for(auto &ch : Children)
			{
				Distances.push_back(std::make_pair(Vector2Int::Distance(*ch, goal), ch));
			}
			std::sort(Distances.begin(), Distances.end(), compareInterval);
			//sort
			
			Children.clear();
			for(auto x : Distances)
			{
				Children.push_back(x.second);//this will be a mess, there should be a way to optimize
			}
		}
	}
	
	//static Vector2Int Directions[8];//try to use nodes in navmesh instead //reserve directions for Nav_NodeGrid ( * directions) and Nav_NodeTower ( + directions)
};

//Vector2Int Nav_Node2D::Directions[8] = {Vector2Int(1, 0), Vector2Int(1, 1), Vector2Int(0, 1), Vector2Int(-1, 1), Vector2Int(-1, 0), Vector2Int(-1, -1), Vector2Int(0, -1), Vector2Int(1, -1)};

class IVector4 {
public:
	float pos[4] = {0.0, 0.0, 0.0, 1.0};
	
	float &x = this->pos[0];
	float &y = this->pos[1];
	float &z = this->pos[2];
	float &w = this->pos[3];
	
	float Magnitude()
	{
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
	}
	
	float sqrMagnitude()
	{
		return static_cast<float>(std::sqrt(this->Magnitude()));//must be non negative
	}
	
	void QNormalize()
	{
		float mag2 = this->Magnitude();
		if(std::abs(mag2 - 1.0f) > TOLERANCE)
		{
			float mag = std::sqrt(mag2);
			this->w /= mag;
			this->x /= mag;
			this->y /= mag;
			this->z /= mag;
		}
	}
};

class Sub4 {
public:
	float &x;
	float &y;
	float &z;
	float &w;
	
	Sub4(float &posx, float &posy, float &posz, float &posw) : x(posx), y(posy), z(posz), w(posw)
	{
		
	}
	
	Sub4(float *obj) : x(obj[0]), y(obj[1]), z(obj[2]), w(obj[3])
	{
		
	}
	
	void operator=(const IVector4 & obj)
	{
		this->x = obj.x;
		this->y = obj.y;
		this->z = obj.z;
		this->w = obj.w;
	}
	
	void operator=(const float(&obj)[4])
	{
		this->x = obj[0];
		this->y = obj[1];
		this->z = obj[2];
		this->w = obj[3];
	}
	
	void operator=(const Sub4 & obj)
	{
		this->x = obj.x;
		this->y = obj.y;
		this->z = obj.z;
		this->w = obj.w;
	}
	
	void operator=(const Vector3 & obj)
	{
		this->x = obj.x;
		this->y = obj.y;
		this->z = obj.z;
	}
	
	Sub4 operator+=(const Sub4 & obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		this->z += obj.z;
		this->w += obj.w;
		return *this;
	}
	
	Sub4 operator-=(const Sub4 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		this->z -= obj.z;
		this->w -= obj.w;
		return *this;
	}
	
	bool operator==(const Sub4 & obj) const
	{
		return (this->x == obj.x && this->y == obj.y && this->z == obj.z && this->w == obj.w);
	}
};

class Vector4 : public IVector4
{
protected:
	//get set x
public:
	/*float pos[4] = {0.0, 0.0, 0.0, 1.0};
	
	float &x = this->pos[0];
	float &y = this->pos[1];
	float &z = this->pos[2];
	float &w = this->pos[3];*/
	
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
	
	/*float& operator[](int i)
	{
		if(i < 4 && i > -1)
		{
			return this->pos[i];
		}
		else
		{
			return this->pos[0];
		}
	}*/
	
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
		return *this;
	}
	
	Vector4& operator-=(const Vector4 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		this->z -= obj.z;
		this->w -= obj.w;
		return *this;
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
		return *this;
	}
	
	Vector4 operator/=(float const& obj)
	{
		this->x /= obj;
		this->y /= obj;
		this->z /= obj;
		this->w /= obj;
		return *this;
	}
	
	//SPECIAL
	
	bool operator==(const Vector4 & obj) const
	{
		return (this->x == obj.x && this->y == obj.y && this->z == obj.z && this->w == obj.w);
	}
	
	void operator=(const Vector4 & obj)
	{
		x = obj.x;
		y = obj.y;
		z = obj.z;
		w = obj.w;
	}
	
	void operator=(const float (&obj)[4])
	{
		x = obj[0];
		y = obj[1];
		z = obj[2];
		w = obj[3];
	}
	
	//return Vector4
	Vector4 operator=(const Vector3 & obj)
	{
		this->x = obj.x;
		this->y = obj.y;
		this->z = obj.z;
		//this->w = 1;
		return *this;
	}
	
	Vector4 operator=(const Sub4 & obj)
	{
		this->x = obj.x;
		this->y = obj.y;
		this->z = obj.z;
		this->w = obj.w;
		return *this;
	}
	
	//TODO remove // DEPRECATED //inefficient
	void toArray(float (&obj)[4])
	{
		obj[0] = this->x;
		obj[1] = this->y;
		obj[2] = this->z;
		obj[3] = this->w;
	}
	
	float* toArray()
	{
		return this->pos;
	}
	
	//INTERNAL FUNCTIONS
	/*float Magnitude()
	{
		return (this->x * this->x) + (this->y * this->y) + (this->z * this->z) + (this->w * this->w);
	}
	
	float sqrMagnitude()
	{
		return static_cast<float>(std::sqrt(this->Magnitude()));//must be non negative
	}*/
	
	void Normalize()
	{
		float mag = this->sqrMagnitude();
		this->x = this->x / mag;
		this->y = this->y / mag;
		this->z = this->z / mag;
		this->w = this->w / mag;
	}
	
	/*void QNormalize()
	{
		float mag2 = this->Magnitude();
		if(fabs(mag2 - 1.0f) > TOLERANCE)
		{
			float mag = std::sqrt(mag2);
			this->w /= mag;
			this->x /= mag;
			this->y /= mag;
			this->z /= mag;
		}
	}*/
	
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
	
	static float Dot(IVector4 a, IVector4 b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
	}
	
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
	
	/*static Vector4 Cross(Vector4 a, Vector4 b)
	{
		return Vector4(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
	}*/
};

class Quaternion : public IVector4
{
public:
	//initialize a Quaternion from euler angles
	Quaternion(Vector3 quato)//euler rotation
	{
		float qx = quato.x * qadian;// / 2;//if radian is pi/180 then remove /2
		float qy = quato.y * qadian;// / 2;
		float qz = quato.z * qadian;// / 2;
		
		float qsinx = std::sin(qx);
		float qcosx = std::cos(qx);
		
		float qsiny = std::sin(qy);
		float qcosy = std::cos(qy);
		
		float qsinz = std::sin(qz);
		float qcosz = std::cos(qz);
		
		float qcosXY = qcosx * qcosy;//can't make it more efficient than this
		//are these too many variables?
		
		this->x = qsinx * qcosy * qcosz;
		this->y = qcosx * qsiny * qcosz;
		this->z = qcosXY * qsinz;
		this->w = qcosXY * qcosz;
	}
	
	Quaternion(float xr, float yr, float zr)
	{
		float qx = xr * qadian;// / 2;// * radian;
		float qy = yr * qadian;// / 2;// * radian;
		float qz = zr * qadian;// / 2;// * radian;
		
		float qsinx = std::sin(qx);
		float qcosx = std::cos(qx);
		
		float qsiny = std::sin(qy);
		float qcosy = std::cos(qy);
		
		float qsinz = std::sin(qz);
		float qcosz = std::cos(qz);
		
		float qcosXY = qcosx * qcosy;//can't make it more efficient than this
		//are these too many variables?
		
		this->x = qsinx * qcosy * qcosz;
		this->y = qcosx * qsiny * qcosz;
		this->z = qcosXY * qsinz;
		this->w = qcosXY * qcosz;
	}
	
	//initialize a Quaternion from Quaternion
	Quaternion(float j, float k, float i, float l)
	{
		this->x = j;
		this->y = k;
		this->z = i;
		this->w = l;
	}
	
	//initialize a Quaternion no parameters
	Quaternion()
	{
		
	}
	
	static float Dot(IVector4 a, IVector4 b)
	{
		return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
	}
	
	Quaternion operator*(const Quaternion & obj) const
	{
		return Quaternion(
			this->w * obj.x + this->x * obj.w + this->y * obj.z - this->z * obj.y, this->w * obj.y + this->y * obj.w + this->z * obj.x - this->x * obj.z, this->w * obj.z + this->z * obj.w + this->x * obj.y - this->y * obj.x, this->w * obj.w - this->x * obj.x - this->y * obj.y - this->z * obj.z);
	}
	
	Quaternion operator*=(const Quaternion & obj) const
	{
		//FIXME posible problem //TODO test
		this->x = this->w * obj.x + this->x * obj.w + this->y * obj.z - this->z * obj.y;
		this->y = this->w * obj.y + this->y * obj.w + this->z * obj.x - this->x * obj.z;
		this->z = this->w * obj.z + this->z * obj.w + this->x * obj.y - this->y * obj.x;
		this->w = this->w * obj.w - this->x * obj.x - this->y * obj.y - this->z * obj.z;
		return *this;
	}
	
	Quaternion inverse()//conjugate
	{
		Quaternion quato;
		//float mag = this->sqrMagnitude();
		quato.x = -this->x;
		quato.y = -this->y;
		quato.z = -this->z;
		quato.w = this->w;
		return quato;
	}
	
	bool operator==(const IVector4 & obj) const
	{
		return (std::abs(Quaternion::Dot(*this, obj) - 1.0) < 0.001);
	}
	
	Quaternion operator=(const Quaternion & obj)
	{
		this->x = obj.x;
		this->y = obj.y;
		this->z = obj.z;
		this->w = obj.w;
		return *this;
	}
	
	static Quaternion Slerp(Quaternion a, Quaternion b, double c)
	{
		Quaternion quato;
		double CHT = Quaternion::Dot(a, b);//a.w * b.w + a.x * b.x + a.y * b.y + a.z * b.z;
		if(std::abs(CHT) >= 1.0)//Quaternion s are equal
		{
			quato.w = a.w;
			quato.x = a.x;
			quato.y = a.y;
			quato.z = a.z;
			return quato;
		}
		double HT = std::acos(CHT);
		double SHT = std::sqrt(1.0 - CHT*CHT);
		if(std::fabs(SHT) < TOLERANCE)
		{
			quato.w = (a.w + b.w * POINT_FIVE);
			quato.x = (a.x + b.x * POINT_FIVE);
			quato.y = (a.y + b.y * POINT_FIVE);
			quato.z = (a.z + b.z * POINT_FIVE);
			return quato;
		}
		double rA = std::sin((1 - c) * HT) / SHT;
		double rB = std::sin(c * HT) / SHT;
		quato.w = a.w * rA + b.w * rB;
		quato.x = a.x * rA + b.x * rB;
		quato.y = a.y * rA + b.y * rB;
		quato.z = a.z * rA + b.z * rB;
		//return a * a.inverse * b * c;//(b * a.inverse()) * c * a;
		return quato;
	}
};

class Matrix4x4
{
protected:
	//col row
public:
	float pos[4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
	
	Sub4 x = Sub4(this->pos[0]);
	Sub4 y = Sub4(this->pos[1]);
	Sub4 z = Sub4(this->pos[2]);
	Sub4 w = Sub4(this->pos[3]);
	
	Matrix4x4(const Vector4 &matx, const  Vector4 &maty, const Vector4 &matz, const  Vector4 &matw)
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
	}
	
	Matrix4x4 operator+(Matrix4x4 const& obj)
	{
		Matrix4x4 res(this->pos);
		res.x += obj.x;
		res.y += obj.y;
		res.z += obj.z;
		res.w += obj.w;
		return res;
	}
	
	Matrix4x4 operator-(Matrix4x4 const& obj)
	{
		Matrix4x4 res(this->pos);
		res.x -= obj.x;
		res.y -= obj.y;
		res.z -= obj.z;
		res.w -= obj.w;
		return res;
	}
	
	Matrix4x4& operator+=(const Matrix4x4 & obj)
	{
		this->x += obj.x;
		this->y += obj.y;
		this->z += obj.z;
		this->w += obj.w;
		return *this;
	}
	
	Matrix4x4& operator-=(const Matrix4x4 & obj)
	{
		this->x -= obj.x;
		this->y -= obj.y;
		this->z -= obj.z;
		this->w -= obj.w;
		return *this;
	}
	
	//MATRIX OPERATIONS
	Matrix4x4 operator*(Matrix4x4 const& obj)
	{
		//TODO It might be more efficient to use individual variables to store values than an array and references, but this has to perform the calculations directly
		Matrix4x4 res;
		/*for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				res.pos[i][j] = 0;
				for(int k = 0; k < 4; k++)
				{
					res.pos[i][j] += this->pos[i][k] * obj.pos[k][j];
				}
			}
		}*/
		//TODO cuadruple check
		//(7 + (0)) calculations vs (12 + (16 * 4))
		res.x.x = this->x.x * obj.x.x + this->x.y * obj.y.x + this->x.z * obj.z.x + this->x.w * obj.w.x;
		res.x.y = this->x.x * obj.x.y + this->x.y * obj.y.y + this->x.z * obj.z.y + this->x.w * obj.w.y;
		res.x.z = this->x.x * obj.x.z + this->x.y * obj.y.z + this->x.z * obj.z.z + this->x.w * obj.w.z;
		res.x.w = this->x.x * obj.x.w + this->x.y * obj.y.w + this->x.z * obj.z.w + this->x.w * obj.w.w;
		
		res.y.x = this->y.x * obj.x.x + this->y.y * obj.y.x + this->y.z * obj.z.x + this->y.w * obj.w.x;
		res.y.y = this->y.x * obj.x.y + this->y.y * obj.y.y + this->y.z * obj.z.y + this->y.w * obj.w.y;
		res.y.z = this->y.x * obj.x.z + this->y.y * obj.y.z + this->y.z * obj.z.z + this->y.w * obj.w.z;
		res.y.w = this->y.x * obj.x.w + this->y.y * obj.y.w + this->y.z * obj.z.w + this->y.w * obj.w.w;
		
		res.z.x = this->z.x * obj.x.x + this->z.y * obj.y.x + this->z.z * obj.z.x + this->z.w * obj.w.x;
		res.z.y = this->z.x * obj.x.y + this->z.y * obj.y.y + this->z.z * obj.z.y + this->z.w * obj.w.y;
		res.z.z = this->z.x * obj.x.z + this->z.y * obj.y.z + this->z.z * obj.z.z + this->z.w * obj.w.z;
		res.z.w = this->z.x * obj.x.w + this->z.y * obj.y.w + this->z.z * obj.z.w + this->z.w * obj.w.w;
		
		res.w.x = this->w.x * obj.x.x + this->w.y * obj.y.x + this->w.z * obj.z.x + this->w.w * obj.w.x;
		res.w.y = this->w.x * obj.x.y + this->w.y * obj.y.y + this->w.z * obj.z.y + this->w.w * obj.w.y;
		res.w.z = this->w.x * obj.x.z + this->w.y * obj.y.z + this->w.z * obj.z.z + this->w.w * obj.w.z;
		res.w.w = this->w.x * obj.x.w + this->w.y * obj.y.w + this->w.z * obj.z.w + this->w.w * obj.w.w;
		
		return res;
	}
	
	Matrix4x4 operator*(float (&obj)[4][4])
	{
		Matrix4x4 res;
		/*for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				res.pos[i][j] = 0;
				for(int k = 0; k < 4; k++)
				{
					res.pos[i][j] += this->pos[i][k] * obj[k][j];
				}
			}
		}*/
		
		res.x.x = this->x.x * obj[0][0] + this->x.y * obj[1][0] + this->x.z * obj[2][0] + this->x.w * obj[3][0];
		res.x.y = this->x.x * obj[0][1] + this->x.y * obj[1][1] + this->x.z * obj[2][1] + this->x.w * obj[3][1];
		res.x.z = this->x.x * obj[0][2] + this->x.y * obj[1][2] + this->x.z * obj[2][2] + this->x.w * obj[3][2];
		res.x.w = this->x.x * obj[0][3] + this->x.y * obj[1][3] + this->x.z * obj[2][3] + this->x.w * obj[3][3];
		
		res.y.x = this->y.x * obj[0][0] + this->y.y * obj[1][0] + this->y.z * obj[2][0] + this->y.w * obj[3][0];
		res.y.y = this->y.x * obj[0][1] + this->y.y * obj[1][1] + this->y.z * obj[2][1] + this->y.w * obj[3][1];
		res.y.z = this->y.x * obj[0][2] + this->y.y * obj[1][2] + this->y.z * obj[2][2] + this->y.w * obj[3][2];
		res.y.w = this->y.x * obj[0][3] + this->y.y * obj[1][3] + this->y.z * obj[2][3] + this->y.w * obj[3][3];
		
		res.z.x = this->z.x * obj[0][0] + this->z.y * obj[1][0] + this->z.z * obj[2][0] + this->z.w * obj[3][0];
		res.z.y = this->z.x * obj[0][1] + this->z.y * obj[1][1] + this->z.z * obj[2][1] + this->z.w * obj[3][1];
		res.z.z = this->z.x * obj[0][2] + this->z.y * obj[1][2] + this->z.z * obj[2][2] + this->z.w * obj[3][2];
		res.z.w = this->z.x * obj[0][3] + this->z.y * obj[1][3] + this->z.z * obj[2][3] + this->z.w * obj[3][3];
		
		res.w.x = this->w.x * obj[0][0] + this->w.y * obj[1][0] + this->w.z * obj[2][0] + this->w.w * obj[3][0];
		res.w.y = this->w.x * obj[0][1] + this->w.y * obj[1][1] + this->w.z * obj[2][1] + this->w.w * obj[3][1];
		res.w.z = this->w.x * obj[0][2] + this->w.y * obj[1][2] + this->w.z * obj[2][2] + this->w.w * obj[3][2];
		res.w.w = this->w.x * obj[0][3] + this->w.y * obj[1][3] + this->w.z * obj[2][3] + this->w.w * obj[3][3];
		
		return res;
	}
	
	Matrix4x4 operator*=(const Matrix4x4 &obj)
	{
		Matrix4x4 res;
		/*for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				res.pos[i][j] = 0;
				for(int k = 0; k < 4; k++)
				{
					res.pos[i][j] += this->pos[i][k] * obj.pos[k][j];
				}
			}
		}*/
		
		res.x.x = this->x.x * obj.x.x + this->x.y * obj.y.x + this->x.z * obj.z.x + this->x.w * obj.w.x;
		res.x.y = this->x.x * obj.x.y + this->x.y * obj.y.y + this->x.z * obj.z.y + this->x.w * obj.w.y;
		res.x.z = this->x.x * obj.x.z + this->x.y * obj.y.z + this->x.z * obj.z.z + this->x.w * obj.w.z;
		res.x.w = this->x.x * obj.x.w + this->x.y * obj.y.w + this->x.z * obj.z.w + this->x.w * obj.w.w;
		
		res.y.x = this->y.x * obj.x.x + this->y.y * obj.y.x + this->y.z * obj.z.x + this->y.w * obj.w.x;
		res.y.y = this->y.x * obj.x.y + this->y.y * obj.y.y + this->y.z * obj.z.y + this->y.w * obj.w.y;
		res.y.z = this->y.x * obj.x.z + this->y.y * obj.y.z + this->y.z * obj.z.z + this->y.w * obj.w.z;
		res.y.w = this->y.x * obj.x.w + this->y.y * obj.y.w + this->y.z * obj.z.w + this->y.w * obj.w.w;
		
		res.z.x = this->z.x * obj.x.x + this->z.y * obj.y.x + this->z.z * obj.z.x + this->z.w * obj.w.x;
		res.z.y = this->z.x * obj.x.y + this->z.y * obj.y.y + this->z.z * obj.z.y + this->z.w * obj.w.y;
		res.z.z = this->z.x * obj.x.z + this->z.y * obj.y.z + this->z.z * obj.z.z + this->z.w * obj.w.z;
		res.z.w = this->z.x * obj.x.w + this->z.y * obj.y.w + this->z.z * obj.z.w + this->z.w * obj.w.w;
		
		res.w.x = this->w.x * obj.x.x + this->w.y * obj.y.x + this->w.z * obj.z.x + this->w.w * obj.w.x;
		res.w.y = this->w.x * obj.x.y + this->w.y * obj.y.y + this->w.z * obj.z.y + this->w.w * obj.w.y;
		res.w.z = this->w.x * obj.x.z + this->w.y * obj.y.z + this->w.z * obj.z.z + this->w.w * obj.w.z;
		res.w.w = this->w.x * obj.x.w + this->w.y * obj.y.w + this->w.z * obj.z.w + this->w.w * obj.w.w;
		
		this->x = res.x;
		this->y = res.y;
		this->z = res.z;
		this->w = res.w;
		return res;
	}
	
	Vector4 operator*(Vector4 const& obj)
	{
		Vector4 res;
		/*for(int j = 0; j < 4; j++)
		{
			res.pos[j] = 0;
			for(int k = 0; k < 4; k++)
			{
				res.pos[j] += (obj.pos[k] * this->pos[k][j]);
			}
		}*/
		// 7 * 4 = 28 // 4 * 4 = 16 + (16 * 2) = 48
		
		res.x = this->x.x * obj.x + this->y.x * obj.y + this->z.x * obj.z + this->w.x * obj.w;
		res.y = this->x.y * obj.x + this->y.y * obj.y + this->z.y * obj.z + this->w.y * obj.w;
		res.z = this->x.z * obj.x + this->y.z * obj.y + this->z.z * obj.z + this->w.z * obj.w;
		res.w = this->x.w * obj.x + this->y.w * obj.y + this->z.w * obj.z + this->w.w * obj.w;
		
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
		this->x = obj[0];
		this->y = obj[1];
		this->z = obj[2];
		this->w = obj[3];
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
	
	static Matrix4x4 QuaternionRotation(IVector4 quato)
	{
		quato.QNormalize();
		//2 * ((quato.x * quato.x) + (quato.y * quato.y)) - 1
		//1 - ((2 * (quato.y * quato.y)) - (2 * (quato.z * quato.z)))
		Matrix4x4 qRotation(Vector4(
			2 * (quato.x * quato.x + quato.y * quato.y) - 1, 
			2 * (quato.y * quato.z - quato.x * quato.w),
			2 * (quato.y * quato.w + quato.x * quato.z), 0), 
							Vector4(
			2 * (quato.y * quato.z + quato.x * quato.w),
			2 * (quato.x * quato.x + quato.z * quato.z) - 1,
			2 * (quato.z * quato.w - quato.x * quato.y), 0), 
							Vector4(
			2 * (quato.y * quato.w - quato.x * quato.z),
			2 * (quato.z * quato.w + quato.x * quato.y), 
			2 * (quato.x * quato.x + quato.w * quato.w) - 1, 0), 
							Vector4(
			0, 
			0, 
			0, 
			1));
		return qRotation;
	}
	
	//initialize Matrix4x4 from Quaternion
	Matrix4x4(Quaternion quato)
	{
		*this = QuaternionRotation(quato);
	}
	
	static Matrix4x4 QuaternionRotation(float i, float j, float k, float L)
	{
		return QuaternionRotation(Vector4(i, j, k, L));
		/*Matrix4x4 qRotation(Vector4(
			2 * (i * i + j * j) - 1, 
			2 * (j * k - i * L),
			2 * (j * L + i * k), 0), 
							Vector4(
			2 * (j * k + i * L),
			2 * (i * i + k * k) - 1,
			2 * (k * L - i * j), 0), 
							Vector4(
			2 * (j * L - i * k),
			2 * (k * L + i * j), 
			2 * (i * i + L * L) - 1, 0), 
							Vector4(
			0, 
			0, 
			0, 
			1));
		return qRotation;*/
	}
	
	static Matrix4x4 QuaternionRotation(Vector3 quato)
	{
		return QuaternionRotation(Quaternion(quato));
	}
	static Matrix4x4 QuaternionRotation(float rx, float ry, float rz)
	{
		return QuaternionRotation(Vector3(rx, ry, rz));
	}
	
	//Euler 3 fields
	void Rotate(float &phi, float &theta, float &psi)
	{
		Matrix4x4 Yrotation = EulerRotation(phi, theta, psi);
		*this *= Yrotation;
	}
	
	void Rotate(Vector3 &AvadaKadabra)
	{
		Matrix4x4 Yrotation = EulerRotation(AvadaKadabra.x, AvadaKadabra.y, AvadaKadabra.z);
		*this *= Yrotation;
	}
	
	//Get translation
	static Matrix4x4 Translation(float mx, float my, float mz)
	{
		Matrix4x4 Trl;
		Trl.w.x += mx;
		Trl.w.y += my;
		Trl.w.z += mz;
		Trl.w.w = 1;
		return Trl;
	}
	
	static Matrix4x4 Translation(const Vector3 &translation)
	{
		Matrix4x4 Trl;
		Trl.w.x += translation.x;
		Trl.w.y += translation.y;
		Trl.w.z += translation.z;
		Trl.w.w = 1;
		return Trl;
	}
	
	//Get scale matrix
	static Matrix4x4 Scalation(const Vector3 &scalation)
	{
		Matrix4x4 Trl;
		Trl.x.x = scalation.x;
		Trl.y.y = scalation.y;
		Trl.z.z = scalation.z;
		return Trl;
	}
	
	static Matrix4x4 Scalation(const float &scalation)
	{
		Matrix4x4 Trl;
		Trl.x.x = scalation;
		Trl.y.y = scalation;
		Trl.z.z = scalation;
		return Trl;
	}
	
	static Matrix4x4 Scalation(float sx, float sy, float sz)
	{
		Matrix4x4 Trl;
		Trl.x.x = sx;
		Trl.y.y = sy;
		Trl.z.z = sz;
		return Trl;
	}
	
	//SCALE SHOULD BE DONE FIRST SO THIS IS USELESS
	//Scale with individual floats
	void Scale(float sx, float sy, float sz)
	{
		Matrix4x4 mat = Matrix4x4::Scalation(sx, sy, sz);
		*this *= mat;
	}
	
	//Scale with a vector
	void Scale(const Vector3 &scalation)
	{
		Matrix4x4 mat = Matrix4x4::Scalation(scalation);
		*this *= mat;
	}
	
	//Scale with a single float
	void Scale(const float &scalation)
	{
		Matrix4x4 mat = Matrix4x4::Scalation(scalation);
		*this *= mat;
	}
	
	//translate this matrix
	void Translate(float mx, float my, float mz)
	{
		Matrix4x4 mat = Matrix4x4::Translation(mx, my, mz);
		*this *= mat;
	}
	
	void Translate(const Vector3 &translation)
	{
		Matrix4x4 mat = Matrix4x4::Translation(translation);
		*this *= mat;
	}
	
	//Get 4x4 float array
	//AAAAHHHH there's no way to return an array from inside class without defining a new array of array //FIXED HAHA
	
	float* toArray()
	{
		return *this->pos;//EVERYTHING WORKS! IT'S AMAZING!
	}
	
	//get Perspective matrix
	static Matrix4x4 Perspective(float FOV, float near, float far)
	{
		Matrix4x4 Mat;
		float persp = FOV * radian;
		float aspectRatio = 4.0 / 3.0;
		persp = 2.0f * std::atan(std::tan(persp * POINT_FIVE) / aspectRatio);
		
		float tangent = std::tan(persp / 2.0f);
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
	
	//get identity matrix (default)
	static Matrix4x4 Identity;
	
	static Matrix4x4 LookAt(Vector3 position, Vector3 target, Vector3 upDirection)
	{
		Matrix4x4 lookMatrix;
		
		Vector3 Zdirection = (position - target).normalized();
		Vector3 rightV = Vector3::Cross(upDirection, Zdirection);
		Vector3 upV = Vector3::Cross(Zdirection, rightV);
		
		lookMatrix.x = rightV;
		lookMatrix.y = upV;
		lookMatrix.z = Zdirection;
		lookMatrix *= Matrix4x4::Translation(position);
		
		return lookMatrix;
	}
	
	static Vector4 Direction(float (&Mat)[4][4])
	{
		//get direction from Matrix4x4
		Matrix4x4 Irotation(Mat);
		Vector4 res(0, 0, 1, 1);
		//Z positive
		return (Irotation * res);
	}
};

Matrix4x4 Matrix4x4::Identity = Matrix4x4();

class KX_Rotation {
public:
	float RMatrix[4][4];
};

//template <typename T>;
class Component {
	
};

class KX_Vgroup {
public:
	int vertexGroup;
	float weight;
};

class TriNormal {
public:
	int indices[3] = {0, 1, 2};
	Vector3 normal;
	
	TriNormal()
	{
		
	}
	
	TriNormal(const int &x, const int &y, const int &z, const Vector3 &v0) : normal(v0)
	{
		this->indices[0] = x;
		this->indices[1] = y;
		this->indices[2] = z;
	}
};

class Mesh {
private:
public:
	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> uvs;
	std::vector<float> tangents;
	//std::vector<float> bitangents;
	std::vector<GLuint> indices;
	int numverts = 0;
	int numindices = 0;
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
	
	void calculateTangents(std::vector<Vector3> &uTangents, Vector3 edge1, Vector3 edge2, Vector2 deltaUV1, Vector2 deltaUV2)
	{
		float f = 1.0f / (deltaUV1.x * deltaUV2.y - deltaUV2.x * deltaUV1.y);
		
		Vector3 tangent = Vector3((edge1.x * deltaUV2.y - edge2.x * deltaUV1.y) * f, (edge1.y * deltaUV2.y - edge2.y * deltaUV1.y) * f, (edge1.z * deltaUV2.y - edge2.z * deltaUV1.y) * f);
		
		uTangents.push_back(tangent);
		uTangents.push_back(tangent);
		uTangents.push_back(tangent);
	}
	
	void GetTangents()
	{
		//std::cout << "debug" << std::endl;
		std::vector<Vector3> uTangents;
		
		for(int abc = 0; abc < this->numindices; abc+= 3)
		{
			Vector3 v0(this->vertices[this->indices[abc] * 3], this->vertices[this->indices[abc] * 3 + 1], this->vertices[this->indices[abc] * 3 + 2]);
			Vector3 v1(this->vertices[this->indices[abc + 1] * 3], this->vertices[this->indices[abc + 1] * 3 + 1], this->vertices[this->indices[abc + 1] * 3 + 2]);
			Vector3 v2(this->vertices[this->indices[abc + 2] * 3], this->vertices[this->indices[abc + 2] * 3 + 1], this->vertices[this->indices[abc + 2] * 3 + 2]);
			
			Vector2 uv0(this->uvs[this->indices[abc] * 2], this->uvs[this->indices[abc] * 2 + 1]);
			Vector2 uv1(this->uvs[this->indices[abc + 1] * 2], this->uvs[this->indices[abc + 1] * 2 + 1]);
			Vector2 uv2(this->uvs[this->indices[abc + 2] * 2], this->uvs[this->indices[abc + 2] * 2 + 1]);
			
			calculateTangents(uTangents, v1 - v0, v2 - v0, uv1 - uv0, uv2 - uv0);
		}
		
		std::vector<Vector3> nTangents(this->vertices.size() / 3);
		for(int ahc = 0; ahc < uTangents.size(); ahc++)
		{
			if(nTangents[this->indices[ahc]] == Vector3::zero)//not assigned
			{
				nTangents[this->indices[ahc]] = Vector3(uTangents[ahc]);
			}
			else
			{
				nTangents[this->indices[ahc]] = Vector3::Lerp(nTangents[this->indices[ahc]], uTangents[ahc]);//mix lerp average blend
			}
		}
		
		for(Vector3 aec : nTangents)
		{
			this->tangents.push_back(aec.x);
			this->tangents.push_back(aec.y);
			this->tangents.push_back(aec.z);
		}
		
		//std::cout << "uTangents " << uTangents.size() << " nTangents " << nTangents.size() << " " << this->debug() << std::endl;
	}
	
	void RecalculateNormals()
	{
		//first clear normals
		this->normals.clear();
		//this->normals = std::vector<float>(this->vertices.size());//assign zero //hopefully
		CalculateNormals();
	}
	
	void CalculateNormals()
	{
		std::vector<TriNormal> tempNormals;
		for(int abc = 0; abc < this->numindices; abc+= 3)
		{
			Vector3 v0(this->vertices[this->indices[abc] * 3], this->vertices[this->indices[abc] * 3 + 1], this->vertices[this->indices[abc] * 3 + 2]);
			Vector3 v1(this->vertices[this->indices[abc + 1] * 3], this->vertices[this->indices[abc + 1] * 3 + 1], this->vertices[this->indices[abc + 1] * 3 + 2]);
			Vector3 v2(this->vertices[this->indices[abc + 2] * 3], this->vertices[this->indices[abc + 2] * 3 + 1], this->vertices[this->indices[abc + 2] * 3 + 2]);
			
			tempNormals.push_back(TriNormal(this->indices[abc], this->indices[abc + 1], this->indices[abc + 2], Vector3::Cross(v1 - v0, v2 - v0)));
		}
		
		std::vector<Vector3> nNormals(this->vertices.size() / 3);
		
		for(int aec = 0; aec < tempNormals.size(); aec++)
		{
			if(nNormals[tempNormals[aec].indices[0]] == Vector3::zero)
			{
				nNormals[tempNormals[aec].indices[0]] = tempNormals[aec].normal;
			}
			else
			{
				nNormals[tempNormals[aec].indices[0]] = Vector3::Lerp(nNormals[tempNormals[aec].indices[0]], tempNormals[aec].normal);
			}
			
			if(nNormals[tempNormals[aec].indices[1]] == Vector3::zero)
			{
				nNormals[tempNormals[aec].indices[1]] = tempNormals[aec].normal;
			}
			else
			{
				nNormals[tempNormals[aec].indices[1]] = Vector3::Lerp(nNormals[tempNormals[aec].indices[1]], tempNormals[aec].normal);
			}
			
			if(nNormals[tempNormals[aec].indices[2]] == Vector3::zero)
			{
				nNormals[tempNormals[aec].indices[2]] = tempNormals[aec].normal;
			}
			else
			{
				nNormals[tempNormals[aec].indices[2]] = Vector3::Lerp(nNormals[tempNormals[aec].indices[2]], tempNormals[aec].normal);
			}
		}
		
		for(auto &ch : nNormals)
		{
			this->normals.push_back(ch.x);
			this->normals.push_back(ch.y);
			this->normals.push_back(ch.z);
		}
	}
	
	std::string debug()
	{
		/*for(int aec : this->indices)
		{
			std::cout << aec << " ";
		}*/
		return std::to_string(vertices.size()) + " " + std::to_string(normals.size()) + " " + std::to_string(uvs.size()) + " " + std::to_string(tangents.size()) + " " + std::to_string(indices.size());
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

//TODO Incomplete
//TODO Test
class Terrain2D : public Mesh{
private:
	//this in constructor
	void GenerateTerrain()
	{
		//generate vertices uvs
		for(int x = 0; x < voxelwidth+1; x++)
		{
			for(int y = 0; y < voxelheight+1; y++)
			{
				this->vertices.push_back(x);
				this->vertices.push_back(y);
				this->vertices.push_back(0);
				this->uvs.push_back(x);
				this->uvs.push_back(y);
			}
		}
		
		int shix = voxelwidth + 1;
		//int shiy = voxelheight + 1;
		int ab1 = 0;
		int ae1 = 0;
		int v0 = 0;
		int v1 = 0;
		int v2 = 0;
		int v3 = 0;
		int shi1 = 0;
		int shi2 = 0;
		
		for(int abc = 0; abc < voxelwidth; abc++)
		{
			ab1 = abc + 1;
			for(int aec = 0; aec < voxelheight; aec++)
			{
				ae1 = aec + 1;
				shi1 = aec * shix;
				shi2 = ae1 * shix;
				v0 = abc + (shi1);
				v1 = ab1 + (shi1);
				v2 = abc + (shi2);
				v3 = ab1 + (shi2);
				this->indices.push_back(v0);
				this->indices.push_back(v3);
				this->indices.push_back(v2);
				this->indices.push_back(v0);
				this->indices.push_back(v1);
				this->indices.push_back(v3);//hope this works
				//FIXME this still doesn't work
			}
		}
		RecalculateNormals();
		GetTangents();
	}
	
public:
	//immutable Mesh preserves the same number of everything at all times
	//only positions are changed
	//render using dynamic or static opengl array
	
	int *VoxelData;
	
	unsigned int voxelwidth;
	unsigned int voxelheight;
	
	Terrain2D(unsigned int wid, unsigned int hei)
	{
		voxelwidth = wid;
		voxelheight = hei;
		
		this->numverts = (wid + 1) * (hei + 1);
		this->numindices = wid * hei * 6;
		
		VoxelData = new int[wid * hei];
		
		GenerateTerrain();
	}
	
	void EditHeight(const unsigned int &x, const unsigned int &y, const float &h)
	{
		if(x < voxelwidth && y < voxelheight)
		{
			this->vertices[((x + (y * voxelwidth) + 1) * 3) - 1] = h;
		}
	}
	
	void EditHeight(const unsigned int &p, const float &h)
	{
		if(p < this->vertices.size())
		{
			this->vertices[p] = h;
		}
	}
	
	~Terrain2D()
	{
		delete[] VoxelData;
	}
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
