/* g++ ch16.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` */

#include "Lines_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
try {

	Lines_window win{Point{100, 100}, 1280, 720, "Lines"};
	
	return gui_main();
} catch (exception& e){
	cerr << e.what() << endl;
	return 1;
} catch (...){
	cerr << "Something went wrong!" << endl;
	return 2;
}