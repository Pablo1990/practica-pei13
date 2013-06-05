/*#include <iostream>
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
}*/

#include "Form.h"
#include <iostream>



int main (int argc, char **argv)
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "pei.gestorDatos");

  //Load the Glade file and instiate its widgets:
  Glib::RefPtr<Gtk::Builder> refBuilder = Gtk::Builder::create();
  try
  {
    refBuilder->add_from_file("GtkForm.glade");
  }
  catch(const Glib::FileError& ex)
  {
    std::cerr << "FileError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Glib::MarkupError& ex)
  {
    std::cerr << "MarkupError: " << ex.what() << std::endl;
    return 1;
  }
  catch(const Gtk::BuilderError& ex)
  {
    std::cerr << "BuilderError: " << ex.what() << std::endl;
    return 1;
  }

  //Get the GtkBuilder-instantiated dialog::
  Form* frm = 0;
  //Cuando busque el widget comprobara que el tipo del puntero pDialog es un DerivedDialog derivado de Dialog
  refBuilder->get_widget_derived("form", frm);
  if(frm)
  {
    //Start:
    app->run(*frm);
  }

  delete frm;

  return 0;
}
