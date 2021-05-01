/*
    g++ ch12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"	//window library elérése
#include "Graph.h"	//graphics library facilities

int main()
try {
    using namespace Graph_lib;

    //Point tl {100,100}; //az ablak bal felső sarka

    //ablak - képernyő koordináta, szélesség*magasság, címke
    Simple_window win {Point{100,100}, 600, 400, "My window"}; 
    win.wait_for_button();

    //x tengely - vízszintes tengely, kezdőpont, hosszúság, beosztás, címke
    Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};
    win.attach(xa);
    win.set_label("Canvas #2");
    win.wait_for_button();
    
    //y tengely
    Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);
	win.attach(ya);
    win.set_label("Canvas #3");
    win.wait_for_button();

    //szinuszgörbe - sin fv. ábrázolása 0-100 tartományban 20-150 ponttól, 1000 pont, x*50, y*50s
    Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
    win.attach(sine);
    win.set_label("Canvas #4");
    win.wait_for_button();

    sine.set_color(Color::blue);

    //sokszög - 3 pont --> 3szög
    Polygon poly;	//a kind of shape
    poly.add(Point{300,200}); 
	poly.add(Point{350,100});
	poly.add(Point{400,200});
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash); //szaggatott vonal
	win.attach(poly);
	win.set_label("Canvas #5");
	win.wait_for_button();

	//téglalap rectangle osztállyal
	Rectangle r {Point{200,200}, 100, 50};
	win.attach(r);
	win.set_label( "Canvas #6");
	win.wait_for_button();

	//téglalap polygonokkal
	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});
	win.attach(poly_rect);
	win.wait_for_button();

	//kitöltés
	r.set_fill_color(Color::yellow);	//a téglalap kitöltése
	poly.set_style(Line_style(Line_style::dash,4));
	poly_rect.set_style(Line_style(Line_style::dash ,2));
	poly_rect.set_fill_color(Color::green);
	win.set_label("Canvas #7");
	win.wait_for_button();

	//szöveg
	Text t {Point{150,150}, "Hello, graphical world!"};
	win.attach(t);
	win.set_label( "Canvas #8");
	win.wait_for_button();

	//szöveg stílus
	t.set_font(Font::times_bold); //times, félkövér
	t.set_font_size(20);
	win.set_label("Canvas #9");
	win.wait_for_button();

	//kép betöltése fájlból
	Image ii {Point{100,50},"badge.jpg"}; // 400*212-pixel jpg
	win.attach(ii);
	win.set_label(" Canvas #10");
	win.wait_for_button();

	//a kép mozgatása (ne zavarjon)
	ii.move(100,200);
	win.set_label("Canvas #11");
	win.wait_for_button();

	//kör, ellipszis, ellipszis közzépontja
	Circle c {Point(100,200),50};
	Ellipse e {Point(100,200), 75, 25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};
	
	//ostringstream - a méreteket megjelenítő szöveg formázása
	ostringstream oss;	//karaktereket tárol, ami ebbe van írva
	oss << "screen size : " << x_max() << "*" << y_max()	//a képernyő lekérdezése
	<< "; window size: " << win.x_max() << "*" << win. y_max();
	Text sizes {Point{100,20},oss.str()};	//str visszadja a fenti sort
	
	Image cal {Point{225,225},"badge.jpg"};
	cal.set_mask(Point{40,40},200,150);	//a kép középső részének megjelenítése
	
	win.attach(c);
	win.attach(m);
	//win.attach(e);
	win.attach(sizes);
	win.attach(cal);
	win.set_label("Canvas #12");
	win.wait_for_button();

}
catch(exception& e) {
	cerr << "exception" << e.what() << '\n';
	return 1;
}
catch(...) {
	cerr << "error\n";
	return 2;
}