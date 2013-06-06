#include "Form.h"

using namespace Gtk;

Form::Form(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
    Gtk::Window(cobject), builder(refGlade){

    builder->get_widget("BtNuevoRegistro", BtNuevoRegistro);
    builder->get_widget("BtGuardarRegistro", BtGuardarRegistro);
    builder->get_widget("BtModificar", BtModificar);
    builder->get_widget("BtBorrarRegistro", BtBorrarRegistro);
    builder->get_widget("BtPrevRegistro", BtPrevRegistro);
    builder->get_widget("BtNextRegistro", BtNextRegistro);
    builder->get_widget("BtGuardarFichero", BtGuardarFichero);
    builder->get_widget("BtCargarFichero", BtCargarFichero);
    builder->get_widget("BtAcercaDe", BtAcercaDe);
    builder->get_widget("BtBuscar", BtBuscar);
    builder->get_widget("ChMostrar", ChMostrar);
    builder->get_widget("EnNombre", EnNombre);
    builder->get_widget("EnDireccion", EnDireccion);
    builder->get_widget("EnPoblacion", EnPoblacion);
    builder->get_widget("EnCPostal", EnCPostal);
    builder->get_widget("EnTelefono", EnTelefono);
    builder->get_widget("EnMail", EnMail);
    builder->get_widget("EnBusqueda", EnBusqueda);

    BtNuevoRegistro->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtNuevoRegistro_clicked));
    BtGuardarRegistro->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtGuardarRegistro_clicked));
    BtModificar->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtModificar_clicked));
    BtBorrarRegistro->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtBorrarRegistro_clicked));
    BtPrevRegistro->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtPrevRegistro_clicked));
    BtNextRegistro->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtNextRegistro_clicked));
    BtGuardarFichero->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtGuardarFichero_clicked));
    ChMostrar->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_ChMostrar_clicked));
    BtBuscar->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtBuscar_clicked));
    BtAcercaDe->signal_clicked().connect(sigc::mem_fun(*this, &Form::on_BtAcercaDe_clicked));
    BtCargarFichero->signal_file_set().connect(sigc::mem_fun(*this, &Form::on_BtCargarFichero_file_set));
}

void Form::on_BtNuevoRegistro_clicked(){

	//String str;
    	//str.append(QString("%1").arg(mr.GetNumRegistros()));
    	//LbId->set_text(str);
	EnNombre->set_text("");
	EnDireccion->set_text("");
	EnPoblacion->set_text("");
	EnCPostal->set_text("");
	EnTelefono->set_text("");
	EnMail->set_text("");
	BtGuardarRegistro->set_sensitive(true);
   	BtModificar->set_sensitive(false);
}

void Form::on_BtGuardarRegistro_clicked(){

}

void Form::on_BtModificar_clicked(){
	
	//String str;
    	//str.append(QString("%1").arg(mr.GetNumRegistros()));
    	//LbId->set_text(str);
	EnNombre->set_text("");
	EnDireccion->set_text("");
	EnPoblacion->set_text("");
	EnCPostal->set_text("");
	EnTelefono->set_text("");
	EnMail->set_text("");

}

void Form::on_BtBorrarRegistro_clicked(){

}

void Form::on_BtPrevRegistro_clicked(){

}

void Form::on_BtNextRegistro_clicked(){

}

void Form::on_BtGuardarFichero_clicked(){

}

void Form::on_BtCargarFichero_file_set(){

}

void Form::on_BtAcercaDe_clicked(){

}

void Form::on_ChMostrar_clicked(){

}

void Form::on_BtBuscar_clicked(){

}

