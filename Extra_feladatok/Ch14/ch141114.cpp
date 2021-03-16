// g++ lib_files/Graph.cpp lib_files/Window.cpp lib_files/GUI.cpp lib_files/Simple_window.cpp ch141114.cpp `fltk-config --ldflags --use-images` -o a.out

#include "./lib_files/Simple_window.h"
#include "./lib_files/Graph.h"

int main()
try {
    using namespace Graph_lib;

    Point tl(200,50);
    Simple_window win(tl,1200,800,"My window");

    Binary_tree bt(Point(600,50),6,"");
    win.attach(bt);
    win.wait_for_button();

    bt.move(50,50);
    win.wait_for_button();
    bt.move(-50,-50);
    win.wait_for_button();

    win.detach(bt);

    Binary_tree_squares bts(Point(600,50),6,"");
    win.attach(bts);
    win.wait_for_button();

    win.detach(bts);

    Binary_tree bt2(Point(600,50),6,"ad");
    win.attach(bt2);
    win.wait_for_button();

    win.detach(bt2);

    Binary_tree bt3(Point(600,50),6,"au");
    win.attach(bt3);
    win.wait_for_button();

    bt3.set_node_label("l","Root");
    bt3.set_node_label("lr","lr");
    bt3.set_node_label("lrl","lrl");
    bt3.set_node_label("lrlr","lrlr");
    bt3.set_node_label("lrlrl","lrlrl");
    bt3.set_node_label("lrlrlr","lrlrlr");
    //bt3.set_node_label("","");
    //bt3.set_node_label("x","x");
    //bt3.set_node_label("lrlx","lrlx");
    //bt3.set_node_label("lrlrlrl","lrlrlrl");
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
