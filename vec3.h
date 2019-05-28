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
		double e[3];

		vec3() { e[0] = e[1] = e[2] = 0.0; }
		vec3(double n1, double n2, double n3) {
			e[0] = n1;
			e[1] = n2;
			e[2] = n3;
		}
		// ~vec3();
		double x() const {return e[0];}
		double y() const {return e[1];}
		double z() const {return e[2];}
		double r() const {return e[0];}
		double g() const {return e[1];}
		double b() const {return e[2];}



		const vec3 & operator+() const {return *this;}
		//vec3 operator+(const vec3 & b) const;
		//vec3 operator-(const vec3 & b) const;
		vec3 operator-() const { return vec3(-e[0],-e[1],-e[2]); }
		//vec3 operator*(const vec3 & b) const;//Burde ikkje dette vera prikkproduktet? Er det nokon gong aktuelt å elementvis multiplisera to vektorar?
		//vec3 operator*(double n) const;
		//vec3 operator/(double n) const;

		double operator[](int i) const { return e[i]; }
		double & operator[](int i) { return e[i]; }


		vec3 & operator+=(const vec3 & b);
		vec3 & operator-=(const vec3 & b);
		vec3 & operator*=(const vec3 & b);
		vec3 & operator/=(const vec3 & b);
		vec3 & operator*=(const double n);
		vec3 & operator/=(const double n);

		// Vektor-operasjonar som ikkje er så vanlege
		//double dot(const vec3 & v1, const vec3 & v2);
		//vec3 cross(const vec3 & v1, const vec3 & v2);

		void make_unit_vector();
		//vec3 unit(vec3 v);
		double length();
		double len() {return length(); }


		//friend vec3 operator*(double n, const vec3 & a);
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

vec3 operator*(const vec3 & a, double n) 
{
	return vec3(a.e[0]*n, a.e[1]*n, a.e[2]*n );
}

vec3 operator*(double n, const vec3 & a)
{
	return vec3(a.e[0]*n, a.e[1]*n, a.e[2]*n );
}

vec3 operator/(const vec3 & a, double n)
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

vec3 & vec3::operator*=(const double n)
{
	e[0] *= n;
	e[1] *= n;
	e[2] *= n;
	return *this;
}

vec3 & vec3::operator/=(const double n)
{
	e[0] /= n;
	e[1] /= n;
	e[2] /= n;
	return *this;
}


double dot(const vec3 & v1, const vec3 & v2)
{
	return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] +v1.e[2] * v2.e[2] ;
}

vec3 cross(const vec3 & a, const vec3 & b)
{
	return vec3( (a.e[2] * b.e[3] - a.e[3] * b.e[2]), (a.e[3] * b.e[1] - a.e[1] * b.e[3]), (a.e[1] * b.e[2] - a.e[2] * b.e[1]));
}

void vec3::make_unit_vector()
{
	double k = 1.0 / ( sqrt(e[0]*e[0] + e[1] * e[1] + e[2]*e[2]) );
	e[0] *= k; e[1] *= k; e[2] *= k;
}

vec3 unit(vec3 v)
{
	return v / v.length();
}

double vec3::length()
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


