// g++ GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp ex1-9.cpp `fltk-config --ldflags --use-images` -o a.out

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <string>
#include <iostream>
#include <vector>

using namespace Graph_lib;

int main()
try {
		
		Point t1 (100,100);
		Simple_window win (t1, 600, 400, "Ch12 labor");
		win.wait_for_button(); 
		//következő állapotra megyünk

		//01
		
		Rectangle r{Point{50,50},50,25};
		r.set_color(Color::blue);
		win.attach(r);

		Polygon rect;
		rect.add(Point{125, 50});
		rect.add(Point{175, 50});
		rect.add(Point{175, 75});
		rect.add(Point{125, 75});
		rect.set_color(Color::red);
		win.attach(rect);

		win.set_label("Ch 12 1.feladat");

		win.wait_for_button();
	   

		//02
		Rectangle rt{Point{200, 50}, 100, 30};
		win.attach(rt);

		Text t {Point{205, 75}, "Howdy!"};  //szöveg a képernyőre
		t.set_font(Font::helvetica_bold); //betűtípus
		t.set_font_size(20);
		win.attach(t);

		win.set_label("2.feladat");
		win.wait_for_button();

		//03
		Text t2 {Point{50, 350}, "R"};
		t2.set_font(Font::courier);
		t2.set_font_size(150);

		Text t3 {Point{250, 350}, "Z"};
		t3.set_font(Font::courier);
		t3.set_font_size(150);

		t2.set_color(Color::blue);
		t3.set_color(Color::green);
		win.attach(t2);
		win.attach(t3);

		win.set_label("3. feladat");
		win.wait_for_button();

		//04
		Vector_ref<Rectangle> vr;
		int w = 50; //szorzásra a pontok elhelyezése miatt
		for(int row = 0; row < 3; ++row) { //sor
				for(int col = 0; col < 3; ++col){ //oszlop
				vr.push_back(new Rectangle{Point{350+ w*col, 200+w*row}, w, w}); //négyzetek kirajzolása, 350 200-től indulok és 50 szélés 50 magas lesz a négyzet

				int i = vr.size()-1; //a vektor utolsó eleme legyen mindig
				i % 2 == 00 //2-vel 0 maradékot képez
						? vr[i].set_fill_color(Color::red)	//párosok pirosak
						: vr[i].set_fill_color(Color::white); //páratlanok fehérek

				win.attach(vr[i]);
				}
		}

		win.set_label("4.feladat");
		win.wait_for_button();

		//05
		Rectangle huge {Point{150, 150}, x_max() * 2 / 3, y_max() * 3 / 4}; //kilóg a képernyőből
		huge.set_style(Line_style(Line_style::solid, 8));
		huge.set_color(Color::red);

		win.attach(huge);
		win.set_label("5. feladat");
		win.wait_for_button();

		//06
		Rectangle r2(Point(100,100), 1500, 800);
		win.attach(r2);
		win.set_label("6.feladat");
		win.wait_for_button();

		//07
		Line_style house_s(Line_style::solid,4);

		Rectangle h(Point(100,370), 550, 330);
		h.set_style(house_s);
		h.set_fill_color(Color::dark_red);
		win.attach(h);

		Rectangle door(Point(300,450), 150, 250);
		door.set_style(house_s);
		door.set_fill_color(Color::dark_green);
		win.attach(door);

		Rectangle win_1(Point(200,400), 60,85);
		win_1.set_style(house_s);
		win_1.set_fill_color(Color::cyan);
		win.attach(win_1);

		Rectangle win_2(Point(500,400), 60,85);
		win_2.set_style(house_s);
		win_2.set_fill_color(Color::cyan);
		win.attach(win_2);

		Polygon roof;
		roof.add(Point(70,370));
		roof.add(Point(420,270));
		roof.add(Point(790,370));
		roof.set_style(house_s);
		roof.set_fill_color(Color::dark_blue);
		win.attach(roof);

		Polygon chimney;
		chimney.add(Point(590,250));
		chimney.add(Point(620,250));
		chimney.add(Point(620,324));
		chimney.add(Point(590,316));
		chimney.set_style(house_s);
		chimney.set_fill_color(Color::dark_magenta);
		win.attach(chimney);

		win.set_label("7.feladat");
		win.wait_for_button();

		//08

		Line_style olympic_s(Line_style(Line_style::solid,40));

		Circle circle1(Point(300,300),220);
		circle1.set_style(olympic_s);
		circle1.set_color(Color::blue);
		win.attach(circle1);

		Circle circle2(Point(812,300),220);
		circle2.set_style(olympic_s);
		win.attach(circle2);

		Circle circle3(Point(1324,300),220);
		circle3.set_style(olympic_s);
		circle3.set_color(Color::red);
		win.attach(circle3);

		Circle circle4(Point(556,540),220);
		circle4.set_style(olympic_s);
		circle4.set_color(Color::yellow);
		win.attach(circle4);

		Circle circle5(Point(1068,540),220);
		circle5.set_style(olympic_s);
		circle5.set_color(Color::green);
		win.attach(circle5);

		win.set_label("8.feladat");
		win.wait_for_button();

		//09
		Image img(Point(60,60),"badge.jpg");
		win.attach(img);
		win.set_label("Foto");

		Text text(Point(70,300),"Foto");
		win.attach(text);

		win.set_label("9.feladat");
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
