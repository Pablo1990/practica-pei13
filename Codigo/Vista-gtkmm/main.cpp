#include <iostream>
#include <gtkmm.h>
#include "Form.h"

using namespace std;
using namespace Gtk;

int main(int argc, char **argv) {

	Main kit(argc,argv);
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("GtkForm.glade");

	Form *frm = 0;
	builder->get_widget_derived("form", frm);
	kit.run(*frm);

	return 0;
}
