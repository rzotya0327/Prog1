// g++ lib_files/Graph.cpp lib_files/Window.cpp lib_files/GUI.cpp lib_files/Simple_window.cpp ch141.cpp `fltk-config --ldflags --use-images` -o a.out

#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"Ch14 - 1.feladat");

    Smiley s1(Point(600,400),150);
    win.attach(s1);
    s1.set_fill_color(Color::yellow);
    //win.wait_for_button();
    s1.set_color(Color::red);
    //win.wait_for_button();
    s1.move(-180,50);
    //win.wait_for_button();
    s1.set_radius(300);
    //win.wait_for_button();
    s1.set_style(Line_style(Line_style::solid,4));
    //win.wait_for_button();
/*
    Frowny f1(Point(150,150),100);
    win.attach(f1);
    //win.wait_for_button();

    Hat_smiley hs1(Point(900,400),175);
    win.attach(hs1);
    //win.wait_for_button();
    hs1.set_fill_color(Color::yellow);
    hs1.set_color(Color::dark_blue);
    hs1.set_style(Line_style(Line_style::solid,4));
    //win.wait_for_button();

    Hat_frowny hf1(Point(600,100),75);
    win.attach(hf1);
    //win.wait_for_button();
    hf1.move(50,50);
    hf1.set_style(Line_style(Line_style::solid,4));
    hf1.set_fill_color(Color::yellow);
    
    win.wait_for_button();*/
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
