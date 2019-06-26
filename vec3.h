#ifndef VEC3_H_
#define VEC3_H_
#include <iostream>
#include <cmath>

using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

// Burde eg bruka namespace?
//
//

class vec3
{
	public:
		float e[3];

		vec3() { e[0] = e[1] = e[2] = 0.0; }
		vec3(float n1, float n2, float n3) {
			e[0] = n1;
			e[1] = n2;
			e[2] = n3;
		}
		// ~vec3();
		float x() const {return e[0];}
		float y() const {return e[1];}
		float z() const {return e[2];}
		float r() const {return e[0];}
		float g() const {return e[1];}
		float b() const {return e[2];}



		const vec3 & operator+() const {return *this;}
		//vec3 operator+(const vec3 & b) const;
		//vec3 operator-(const vec3 & b) const;
		vec3 operator-() const { return vec3(-e[0],-e[1],-e[2]); }
		//vec3 operator*(const vec3 & b) const;//Burde ikkje dette vera prikkproduktet? Er det nokon gong aktuelt å elementvis multiplisera to vektorar?
		//vec3 operator*(float n) const;
		//vec3 operator/(float n) const;

		float operator[](int i) const { return e[i]; }
		float & operator[](int i) { return e[i]; }


		vec3 & operator+=(const vec3 & b);
		vec3 & operator-=(const vec3 & b);
		vec3 & operator*=(const vec3 & b);
		vec3 & operator/=(const vec3 & b);
		vec3 & operator*=(const float n);
		vec3 & operator/=(const float n);

		// Vektor-operasjonar som ikkje er så vanlege
		//float dot(const vec3 & v1, const vec3 & v2);
		//vec3 cross(const vec3 & v1, const vec3 & v2);

		void make_unit_vector();
		//vec3 unit(vec3 v);
		float length();
		float len() {return length(); }
		float squared_length() { return e[0]*e[0]+e[1]*e[1]+e[2]*e[2]; }


		//friend vec3 operator*(float n, const vec3 & a);
		//friend std::ostream & operator<<(std::ostream & os, const vec3 & v);
		//friend std::istream & operator>>(std::istream & is, const vec3 & v); 

};

// public methods

vec3 operator+(const vec3 & a, const vec3 & b) 
{
	return vec3(a.e[0] + b.e[0], a.e[1] + b.e[1], a.e[2] + b.e[2]);
}

vec3 operator-(const vec3 & a, const vec3 & b)
{
	return vec3(a.e[0] - b.e[0], a.e[1] - b.e[1], a.e[2] - b.e[2]);
}

vec3 operator*(const vec3 & a, const vec3 & b) 
{
	return vec3(a.e[0] * b.e[0], a.e[1] * b.e[1], a.e[2] * b.e[2]);
}

vec3 operator*(const vec3 & a, float n) 
{
	return vec3(a.e[0]*n, a.e[1]*n, a.e[2]*n );
}

vec3 operator*(float n, const vec3 & a)
{
	return vec3(a.e[0]*n, a.e[1]*n, a.e[2]*n );
}

vec3 operator/(const vec3 & a, float n)
{
	return vec3(a.e[0]/n, a.e[1]/n, a.e[2]/n );
}

vec3 & vec3::operator+=(const vec3 & b)
{
	e[0] += b.e[0];
	e[1] += b.e[1];
	e[2] += b.e[2];
	return *this;
}

vec3 & vec3::operator-=(const vec3 & b)
{
	e[0] -= b.e[0];
	e[1] -= b.e[1];
	e[2] -= b.e[2];
	return *this;
}

vec3 & vec3::operator*=(const vec3 & b)
{
	e[0] *= b.e[0];
	e[1] *= b.e[1];
	e[2] *= b.e[2];
	return *this;
}
vec3 & vec3::operator/=(const vec3 & b)
{
	e[0] /= b.e[0];
	e[1] /= b.e[1];
	e[2] /= b.e[2];
	return *this;
}

vec3 & vec3::operator*=(const float n)
{
	e[0] *= n;
	e[1] *= n;
	e[2] *= n;
	return *this;
}

vec3 & vec3::operator/=(const float n)
{
	e[0] /= n;
	e[1] /= n;
	e[2] /= n;
	return *this;
}


float dot(const vec3 & v1, const vec3 & v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] +v1.e[2] * v2.e[2] ;
}

vec3 cross(const vec3 & a, const vec3 & b)
{
	return vec3( (a.e[1] * b.e[2] - a.e[2] * b.e[1]), (a.e[2] * b.e[0] - a.e[0] * b.e[2]), (a.e[0] * b.e[1] - a.e[1] * b.e[0]));
}

void vec3::make_unit_vector()
{
	float k = 1.0 / ( sqrt(e[0]*e[0] + e[1] * e[1] + e[2]*e[2]) );
	e[0] *= k; e[1] *= k; e[2] *= k;
}


vec3 unit(vec3 v)
{
	return v / v.length();
}

vec3 unit_vector(vec3 v) { return unit(v);}

float vec3::length()
{
	return sqrt(e[0]*e[0] + e[1] * e[1] + e[2]*e[2]);
}

std::ostream & operator<<(std::ostream & os, const vec3 & v)
{
	os << v.e[0] << " " << v.e[1] << " " << v.e[2];
	return os;
}

std::istream & operator>>(std::istream & is, vec3 & v)
{
	is >> v.e[0] >> v.e[1] >> v.e[2];
	return is;
}



#endif


