#include <cmath>
#include "vec3.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VEC
{
	//const double Rad_to_deg = 45.0 / atan(1.0);

	// public methods
	vec3::vec3() // default constructor
	{
		e[0] = e[1] = e[2] = 0.0;
	}

	vec3::vec3(double n1, double n2, double n3)
	{
		e[0] = n1;
		e[1] = n2;
		e[2] = n3;
	}

	vec3 vec3::operator+(const vec3 & b) const
	{
		return vec3(e[0] + b.e[0], e[1] + b.e[1], e[2] + b.e[2]);
	}

	vec3 vec3::operator-(const vec3 & b) const
	{
		return vec3(e[0] - b.e[0], e[1] - b.e[1], e[2] - b.e[2]);
	}

	vec3 vec3::operator*(const vec3 & b) const
	{
		return vec3(e[0] * b.e[0], e[1] * b.e[1], e[2] * b.e[2]);
	}

	vec3 vec3::operator*(double n) const
	{
		return vec3(e[0]*n, e[1]*n, e[2]*n );
	}
	
	vec3 vec3::operator/(double n) const
	{
		return vec3(e[0]/n, e[1]/n, e[2]/n );
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


	double vec3::dot(const vec3 & v1, const vec3 & v2)
	{
		return v1

