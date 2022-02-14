/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;
	
	//WINDOW
	Point tl{100,100}; //top left
	Simple_window win {tl,600,400,"Canvas"}; //600*400, title: "Canvas"
	//Or Simple_window win {Point{100,100},600,400,"Canvas"};
	
	
	// AXIS x
	Axis xa{Axis::x, Point{20,300},280,10,"x axis"};
	//{kind of shape, starting point, pixels long, "notches", label}
	win.attach(xa);
	win.set_label("Canvas #2");
	
	// AXIS y
	Axis ya{Axis::y,Point{20,300},280,10,"y axis"}; // that's the same, but in vertically
	ya.set_color(Color::cyan); // color of axis
	ya.label.set_color(Color::dark_red); // color of axis' label
	win.attach(ya);
	win.set_label("Canvas #3");
	
	// Graphing a function
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	//It's plot sin() in the range (0:100) with (0,0) at (20,150)
	// using 1000 points, scale x values *50, scale y values *50
	win.attach(sine);
	win.set_label("Canvas #4");
	
	// POLIGONS
	sine.set_color(Color::blue);
	
	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200}); // three points of a triangle
	
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash); // the style of line (dash,dot, etc.)
	win.attach(poly);
	win.set_label("Canvas #5");
	
	// RECTANGLES
	Rectangle r{Point{200,200},100,50}; // top left corner,width, height
	win.attach(r);
	win.set_label("Canvas #6");
	
	// rectangle with polynoms (not a real rectangle)
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	win.attach(poly_rect);
	
	// if we add one more point, than that's no more a rectangle
	poly_rect.add(Point{50,75});
	
	// FILL
	r.set_fill_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
	
	// TEXT
	Text t{Point{150,150},"Hello, graphical world!"};
	win.attach(t);
	win.set_label("Canvas #8");
	
	t.set_font(Font::times_bold);
	t.set_font_size(20);
	win.set_label("Canvas #9");
	/*
	// IMAGES (commented, because I don't have the image.jpg
	Image ii{Point{100,50},"image.jpg"};
	win.attach(ii);
	win.set_label("Canvas #10");
	
	ii.move(100,200);
	win.set_label("Canvas #11");*/
	
	// And much more
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	//Image cal {Point{225,225},"snow_cpp.gif"}; (don't have the gif)
	//cal.set_mask(Point{40,40},200,150);
	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	//win.attach(cal);
	win.set_label("Canvas #12");
	
	
	
	
	
	win.wait_for_button(); //display
}
