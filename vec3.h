#ifndef VEC3_H_
#define VEC3_H_
#include <iostream>
namespace VEC
{
	class vec3
	{
		private:
			double e[3];
		public:
			vec3();
			vec3(double n1, double n2, double n3);
			// ~vec3();
			double x() const {return e[0];}
			double y() const {return e[1];}
			double z() const {return e[2];}
			double r() const {return e[0];}
			double g() const {return e[1];}
			double b() const {return e[2];}



			vec3 & operator+() const {return *this;}
			vec3 operator+(const vec3 & b) const;
			vec3 operator-(const vec3 & b) const;
			vec3 operator-() const { return vec3(-e[0],-e[1],-e[2]); }
			vec3 operator*(const vec3 & b) const;//Burde ikkje dette vera prikkproduktet? Er det nokon gong aktuelt å elementvis multiplisera to vektorar?
			vec3 operator*(double n) const;
			vec3 operator/(double n) const;

			double operator[](int i) const { return e[i]; }
// skjønar ikkje heilt denne:			double & operator[](int i) { return e[i]; }


			vec3 & operator+=(const vec3 & b);
			vec3 & operator-=(const vec3 & b);
			vec3 & operator*=(const vec3 & b);
			vec3 & operator/=(const vec3 & b);
			vec3 & operator*=(const double n);
			vec3 & operator/=(const double n);

			// Vektor-operasjonar som ikkje er så vanlege
			double dot(const vec3 & v1, const vec3 & v2);
			vec3 cross(const vec3 & v1, const vec3 & v2);

			void make_unit_vector();
			vec3 unit(vec3 v);
			double length();
			double len() {return this.length() }


			friend vec3 operator*(double n, const vec3 & a);
			friend std::ostream & operator<<(std::ostream & os, const vec3 & v);
			friend std::istream & operator>>(std::istream & is, const vec3 & v); 

	};

} //end namespace VEC
#endif


