//g++ lib_files/Graph.cpp lib_files/Window.cpp lib_files/GUI.cpp lib_files/Simple_window.cpp ex13.cpp `fltk-config --ldflags --use-images` -o a.out

#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;
    
    Point t1(200,50);
    Simple_window win(t1,1200,800,"Labor 3");
    
    //01
    Graph_lib::Arc arc1(Point(150,100), 100, 50, 45, 175);	//ahonnan kirajzolja, szélesség, magasság, szög1, szög2
    win.attach(arc1);
    arc1.set_color(Color::red);
    arc1.set_angle1(-15);
    arc1.set_angle2(270);
    arc1.set_angles(-175,-5);
    
    win.wait_for_button();
    
    Graph_lib::Arc arc2(Point(200,200),50,90,-175,-5);
    arc2.set_color(Color::green);
    arc2.set_fill_color(Color::blue);
    win.attach(arc2);
    win.wait_for_button();
    
    //02
    Box box1(Point(350,350), 100, 80);	//pont, szélesség, magasság
    box1.set_style(Line_style(Line_style::dashdot, 4));
    win.attach(box1);   
    win.wait_for_button();
    
    Box box2(Point(450, 350), 200, 100, 50);	//pont, szélesség, magasság, sugár
    box2.set_fill_color(Color::yellow);
    win.attach(box2);
    win.wait_for_button();
    
    //03
    Arrow arrow1(Point(100,500), Point(400,450));	//pont-pont
    win.attach(arrow1);
    Arrow arrow2(Point(300,300), Point(250,250));
    win.attach(arrow2);
    arrow2.set_color(Color::red);
    arrow2.set_fill_color(Color::green);
    arrow2.set_style(Line_style::dot);
    win.wait_for_button();    
         

} catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
} catch (...) {
    cerr << "exception\n";
    keep_window_open();
}
