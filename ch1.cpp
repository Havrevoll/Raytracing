#include <iostream>
#include <string>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

int main() 
{

	using namespace std;

	int nx; //= 200;
	int ny;// = 100;
	cout << "nx = ";
	cin >> nx;
	cout << "ny = ";
	cin >> ny;

	char filnamn[30] = "bilete.png";
	cout << "skriv filnamnet (inkl. png): ";
        cin >> filnamn;	


	cout << "filnamnet er " << filnamn << endl;

	int n = 3;

	unsigned char  data [nx*ny*n] = {};
	
	for (int j = ny-1; j >= 0; j--) {
		for (int i = 0; i<nx;i++) {
			float r = float(i) / float(nx);
			float g = float(j) / float(ny);
			float b = 0.2;
			int ir = int(255.99*r);
			int ig = int(255.99*g);
			int ib = int(255.99*b);

			int k = ( (ny-1) - j) * nx * n + i*n ; 
			data[ k  ] = ir;
			data[  k +1] = ig;
			data[  k +2] = ib;

			//std::cout << "j = " << j << ", i = " << i <<", k = " << k << std::endl; 
		}
	}
	
	stbi_write_png(filnamn, nx,ny, n, data, 0);



}
