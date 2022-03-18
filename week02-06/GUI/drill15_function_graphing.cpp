#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
	const int xmax = 600;
    	const int ymax = 600;

    	const int x_orig = xmax/2;
    	const int y_orig = ymax/2;
    	const Point orig(x_orig,y_orig);

    	const int r_min = -10;
    	const int r_max = 11;

    	const int n_points = 400;

    	const int x_scale = 20;
    	const int y_scale = 20;
	
	Simple_window win{Point{100,100},600,600, "Function graphs"};
	
	Axis xa{Axis::x, Point{100,300},400,20,"1 == 20px"};
	xa.set_color(Color::red);
	win.attach(xa);
	
	Axis ya{Axis::y, Point{300,500},400,20,"1 == 20px"};
	ya.set_color(Color::red);
	win.attach(ya);
	
	Function s(one,r_min,r_max,orig,n_points,x_scale,y_scale);
	win.attach(s);
	
	Function s1(slope,r_min,r_max,orig,n_points,x_scale,y_scale);
	Text t(Point{x_orig,y_orig+5},"x/2");
	win.attach(s1);
	win.attach(t);
	
	Function s2(square,r_min,r_max,orig,n_points,x_scale,y_scale);
	win.attach(s2);
	
	Function s3(cos,r_min,r_max,orig,n_points,x_scale,y_scale);
	s3.set_color(Color::blue);
	win.attach(s3);
	
	Function s4(sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale);
	win.attach(s4);
	
	win.wait_for_button();
}

