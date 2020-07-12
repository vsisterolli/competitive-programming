/* PICK'S THEOREM: A = I + B/2 - 1
	A = POLYGON AREA
	I = LATTICE POINTS INSIDE THE POLYGON
	B = LATTICE POINTS INT THE FRONTIER OF THE POLYGON
*/

struct dot {
	long long x, y;
	dot() {};
	dot(long long x_, long long y_) : x(x_), y(y_) {};
	bool operator<(dot a){if(a.x == x) return(a.y > y); else return a.x > x;}
	dot operator-(dot a){return{x-a.x, y-a.y};}	
	dot operator+(dot a){return{x+a.x, y+a.y};}
	
	/*	dot;
		0 straight
		> 0 obtuse
		< 0 acute
	*/
	long long operator*(dot a){return{a.x*x+a.y*y};}
	
};

double sz(dot a, dot b) {
	return hypot(a.x-b.x, a.y-b.y);
}

long long cross(dot a, dot b) {
	/*
	cross product:
	X > 0 left
	X < 0 right
	X == 0 colinears
	*/
	return a.x*b.y - a.y*b.x;
}


// returns the area of a convex polygon
long long area(vector<dot> &v) {
	double area = 0.0;
	int last = v.size()-1;
	for(int i = 0; i < v.size(); i++) {
		area += cross(v[i], v[last]);
		last = i;
	}
	return abs(area) / 2;
}

double perimeter(vector<dot> &v) {
	
	double perim = 0.0;
	
	int last = v.size()-1;
	
	for(int i = 0; i < v.size(); i++) { 
		perim += sz(v[i], v[last]);
		last = i;
	}

	return perim;
	
}
