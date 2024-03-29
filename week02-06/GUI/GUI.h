#ifndef GUI_GUARD
#define GUI_GUARD

#include "Window.h"
#include "Graph.h"

namespace Graph_lib {

typedef void* Address;
typedef void(*Callback)(Address, Address);

template<class W> W& reference_to(Address pw)
{
    return *static_cast<W*>(pw);
}

class Widget {
public:
    Widget(Point xy, int w, int h, const string& s, Callback cb)
        : loc(xy), width(w), height(h), label(s), do_it(cb)
    {}

    virtual void move(int dx,int dy) { hide(); pw->position(loc.x+=dx, loc.y+=dy); show(); }
    virtual void hide() { pw->hide(); }
    virtual void show() { pw->show(); }
    virtual void attach(Window&) = 0;

    Point loc;
    int width;
    int height;
    string label;
    Callback do_it;

    virtual ~Widget() { }

protected:
    Window* own;
    Fl_Widget* pw;
private:
    Widget& operator=(const Widget&);
    Widget(const Widget&);
};

struct Button : Widget {
    Button(Point xy, int w, int h, const string& label, Callback cb)
        : Widget(xy,w,h,label,cb)
    {}

    void attach(Window&);
};

struct In_box : Widget {
    In_box(Point xy, int w, int h, const string& s)
        :Widget(xy,w,h,s,0) { }
    int get_int();
    string get_string();

    void attach(Window& win);
};

struct Out_box : Widget {
    Out_box(Point xy, int w, int h, const string& s)
        :Widget(xy,w,h,s,0) { }
    void put(int);
    void put(const string&);

    void attach(Window& win);
};

struct Menu : Widget {
    enum Kind { horizontal, vertical };
    Menu(Point xy, int w, int h, Kind kk, const string& label);

    Vector_ref<Button> selection;
    Kind k;
    int offset;
    int attach(Button& b);
    int attach(Button* p);

    void show()
    {
        for (unsigned int i = 0; i<selection.size(); ++i)
            selection[i].show();
    }
    void hide()
    {
        for (unsigned int i = 0; i<selection.size(); ++i) 
            selection[i].hide(); 
    }
    void move(int dx, int dy)
    {
        for (unsigned int i = 0; i<selection.size(); ++i) 
            selection[i].move(dx,dy);
    }

    void attach(Window& win)
    {
        for (int i=0; i<selection.size(); ++i) win.attach(selection[i]);
        own = &win;
    }
};
    
    class Lines_window : public Window
	{
	public:
		Lines_window(Point xy, int w, int h, const string& title);
		Open_polyline m_lines;

		Menu m_colourMenu;
		Button m_menuButton;

		Menu m_lsMenu;
		Button m_lsButton;

		void change(Color c) { m_lines.set_color(c); hideMenu(); redraw(); }
		void hideMenu() { m_colourMenu.hide(); m_menuButton.show(); }
		void hideLSmenu() { m_lsMenu.hide(); m_lsButton.show(); }

		void redPressed() { change(Color::red); }
		void bluePressed() { change(Color::blue); }
		void blackPressed() { change(Color::black); }
		void menuPressed() { m_menuButton.hide(); m_colourMenu.show(); }
		void lsMenuPressed() { m_lsButton.hide(); m_lsMenu.show(); }
		void changeStyle(Line_style ls) { m_lines.set_style(ls); hideLSmenu(); redraw(); }

		//callback functions
		static void cb_red(Address, Address addr) { reference_to<Lines_window>(addr).redPressed(); }
		static void cb_blue(Address, Address addr) { reference_to<Lines_window>(addr).bluePressed(); }
		static void cb_black(Address, Address addr) { reference_to<Lines_window>(addr).blackPressed(); }
		static void cb_menu(Address, Address addr) { reference_to<Lines_window>(addr).menuPressed(); }
		static void cb_lsMenu(Address, Address addr) { reference_to<Lines_window>(addr).lsMenuPressed(); }

	private:
		void next();
		void quit();

		Button m_nextButton;	//add (nextX, nextY) to lines
		Button m_quitButton;
		In_box m_nextX;
		In_box m_nextY;
		Out_box m_xyOut;
	};
}

#endif
