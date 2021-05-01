/*
    g++ ch13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main() {
	using namespace Graph_lib;

	//01
    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};

    //02
    Lines grid;
    int x_size = 800;
    int y_size = 800;
    for (int i = 100; i<=x_size; i+=100) {
    	grid.add(Point(i,0), Point(i,y_size));
    	grid.add(Point(0,i), Point(x_size,i));
    }

    //03
    Vector_ref<Rectangle> vr;
    for (int i = 0; i < 8; ++i) {
    	vr.push_back(new Rectangle(Point(i*100, i*100),101,101));	//add unnamed
    	vr[vr.size()-1].set_fill_color(Color::red);
    	win.attach(vr[vr.size()-1]);
    }

    //04
    Image pic1(Point(200,0), "badge.jpg");
    pic1.set_mask(Point{200,0},200,200);
	win.attach(pic1);
	Image pic2(Point(600,200), "badge.jpg");
    pic2.set_mask(Point{200,0},200,200);
	win.attach(pic2);
	Image pic3(Point(400,100), "badge.jpg");
    pic3.set_mask(Point{200,0},200,200);
	win.attach(pic3);
    win.wait_for_button();

    //05
    Image pic4(Point(0,0), "badge.jpg");
    pic4.set_mask(Point(110,70), 100,100);
    win.attach(pic4);
    win.wait_for_button();

    int cnt = 1;	//számláló inicializálása
    while (cnt <= 64) {	//ha kevesebb, mint 64, akkor next
    	win.wait_for_button();
    	if (cnt % 8 == 0)	//8 többszöröse, vissza 0-ba és lejjebbtolás cellemérettel (sor eleje), továbbá minden lépésben go jobbra
    		pic4.move(-800, 100);
    		pic4.move(100, 0);
    	cnt++;
    }

    win.attach(grid);
    win.wait_for_button();
}