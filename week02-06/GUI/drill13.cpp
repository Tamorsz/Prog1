/*
    g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{

	using namespace Graph_lib;	
	
	// Window
	Simple_window win{Point{100,50},800,1000,"drill #13"};
	
	// Grid
	int x_size = win.x_max();
	int y_size = 801;
	int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	for(int x=x_grid; x<x_size; x+=x_grid)
		grid.add(Point{x,0},Point{x,y_size});  //vretical lines
	for(int y=y_grid; y<y_size; y+=y_grid)
		grid.add(Point{0,y},Point{x_size,y});
	
	win.attach(grid);
	
	// Red diagonal(átló)
	
	Vector_ref<Rectangle> rect;
	for(int i=0;i<8;++i)
	{
		rect.push_back(new Rectangle{Point{i*100,i*100},100,100});
		rect[rect.size()-1].set_fill_color(Color::red);
		rect[rect.size()-1].set_color(Color::red);
		win.attach(rect[rect.size()-1]);
	}
	
	// Images
	Image im0{Point{0,200},"badge2.jpg"};
	win.attach(im0);	
	Image im1{Point{600,200},"badge2.jpg"};
	win.attach(im1);
	Image im2{Point{0,600},"badge2.jpg"};
	win.attach(im2);
	
	// Image moving
	Image im{Point{0,0},"badge3.jpg"};
	win.attach(im);
	
	int j = 0;
	
	while(win.wait_for_button())
	{
	im.move(100,100);
	++j;
	if(j==8) break;
	win.set_label("drill #13");
	}
}
