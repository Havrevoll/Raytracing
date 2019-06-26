// http://www.cplusplus.com/forum/articles/10627/

#include <iostream>
#include <cstddef>
#include <limits>
#include <random>



#include "sphere.h"
#include "hitablelist.h"
#include "camera.h"
#include "material.h"
#include "lambertian.h"
#include "metal.h"

// std::random_device rd;
std::default_random_engine generator;//( rd() );
std::uniform_real_distribution<float> distribution(0.0, 1.0);


vec3 random_in_unit_sphere() {
	vec3 p;
	do {
		p = 2.0*vec3(distribution(generator), distribution(generator), distribution(generator)) - vec3(1,1,1);
	} while (p.squared_length() >= 1.0);
	return p;
}	

vec3 reflect(const vec3 & v, const vec3 & n) {
	return v - 2*dot(v,n)*n;
}

vec3 color(const ray& r, hitable *world, int depth) {
	hit_record rec;
	if (world->hit(r, 0.001, std::numeric_limits<float>::max(), rec)) {
		ray scattered;
		vec3 attenuation;
		if (depth < 50 && rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {
			return attenuation*color(scattered, world, depth+1);
		}
		else {
			return vec3(0,0,0);
		}
	}
	else {
		vec3 unit_direction = unit_vector(r.direction());	
		float t = 0.5*(unit_direction.y() + 1.0);
		return (1.0 -t )*vec3(1.0, 1.0, 1.0) + t * vec3(.5, .7, 1.0);
	}
}

int main() {
	int nx = 800;
	int ny = 400;
	int ns = 100;
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
/*
	string filnamn = new string("test.png");
	cout << "Skriv filnamnet (inkl. png): ";
	cin << filnamn;

	unsigned char data [nx * ny * 3] = {};
*/

	hitable *list[4];
	list[0] = new sphere(vec3(0,0,-1), 0.5, new lambertian(vec3(.8, .3, .3)));
	list[1] = new sphere(vec3(0,-100.5,-1),100, new lambertian(vec3(.8, .8, .0)));
	list[2] = new sphere(vec3(1,0,-1), .5, new metal(vec3(.8, .6, .2)));
	list[3] = new sphere(vec3(-1,0,-1),.5, new metal(vec3(.8,.8,.8)));
	//list[2] = new sphere(vec3(0,1,-1), 0.5);
	hitable *world = new hitable_list(list,4);
	camera cam;

	for (int j= ny-1; j>=0; j--) {
		for (int i = 0; i < nx; i++) {
			vec3 col(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float u = float(i + distribution(generator)) / float(nx);
				float v = float(j + distribution(generator)) / float(ny);
				ray r = cam.get_ray(u, v);
				vec3 p = r.point_at_parameter(2.0);
				col += color(r, world, 0);
			}
			col /= float(ns);
			col = vec3( sqrt( col[0]), sqrt(col[1]), sqrt(col[2]) );
			int ir = int(255.99*col[0]);
			int ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			std::cout << ir << " " << ig << " " << ib << "\n";

		}
	}
	return 0;

}
