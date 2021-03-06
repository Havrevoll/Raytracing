#include <iostream>
#include "sphere.h"
#include "hitablelist.h"
#include <cstddef>
#include <limits>
#include <random>
#include "camera.h"

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

vec3 color(const ray& r, hitable *world) {
	hit_record rec;
	if (world->hit(r, 0.0, std::numeric_limits<float>::max(), rec)) {
		vec3 target = rec.p + rec.normal + random_in_unit_sphere();
		return 0.5* color( ray( rec.p, target-rec.p), world);
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

	hitable *list[3];
	list[0] = new sphere(vec3(0,0,-1), 0.5);
	list[1] = new sphere(vec3(0,-100.5,-1),100);
	list[2] = new sphere(vec3(1,0,-1), 0.5);
	hitable *world = new hitable_list(list,3);
	camera cam;

	for (int j= ny-1; j>=0; j--) {
		for (int i = 0; i < nx; i++) {
			vec3 col(0, 0, 0);
			for (int s = 0; s < ns; s++) {
				float u = float(i + distribution(generator)) / float(nx);
				float v = float(j + distribution(generator)) / float(ny);
				ray r = cam.get_ray(u, v);
				vec3 p = r.point_at_parameter(2.0);
				col += color(r, world);
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
