// g++ lib_files/Graph.cpp lib_files/Window.cpp lib_files/GUI.cpp lib_files/Simple_window.cpp ex137.cpp `fltk-config --ldflags --use-images` -o a.out

#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
try {
 using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"RGB chart");
    Vector_ref<Graph_lib::Rectangle> rects;

    for (int i1 = 0; i1<4; ++i1) {
        for (int i2 = 0; i2<4; ++i2) {
            for (int j = 0; j<16; ++j) {
                for (int k = 0; k<16; ++k) {
                    rects.push_back(new Graph_lib::Rectangle(Point(16*12*i1+12*k,16*12*i2+12*j),12,12));
                    rects[rects.size()-1].set_fill_color(fl_rgb_color(15*(4*i1+i2),15*j,15*k));
                    rects[rects.size()-1].set_color(Color(Color::black,Color::invisible));
                    win.attach(rects[rects.size()-1]);
                }
            }
        }
    }
    win.wait_for_button();

}

catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
