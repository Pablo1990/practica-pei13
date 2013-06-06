#include "Form.h"
#include "../Modelo/modeloRegistro.h"

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
    builder->get_widget("LbId", LbId);
    builder->get_widget("Acerca de", DiAcercaDe);

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

void Form::on_BtNuevoRegistro_clicked()
{
    BtNuevoRegistro->set_sensitive(false);
    BtGuardarRegistro->set_sensitive(true);
    BtBorrarRegistro->set_sensitive(false);
	EnNombre->set_text("");
	EnDireccion->set_text("");
	EnPoblacion->set_text("");
	EnCPostal->set_text("");
	EnTelefono->set_text("");
	EnMail->set_text("");
	BtGuardarFichero->set_sensitive(true);
   	BtModificar->set_sensitive(false);
    modificar=false;
    LbId->set_text(IntToUString(mr.GetNumRegistros()));
}

void Form::on_BtGuardarRegistro_clicked(){
    if(!modificar)
    {
        BtNuevoRegistro->set_sensitive(true);
        BtBorrarRegistro->set_sensitive(true);
        mr.CrearRegistro(Glib::locale_from_utf8(EnNombre->get_text()), Glib::locale_from_utf8(EnMail->get_text()), Glib::locale_from_utf8(EnPoblacion->get_text()), Glib::locale_from_utf8(EnCPostal->get_text()), Glib::locale_from_utf8(EnTelefono->get_text()), Glib::locale_from_utf8(EnDireccion->get_text()));
    }
    else
    {
        if(!modoBuscar)
        {
            mr.Modificar(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str()), Glib::locale_from_utf8(EnNombre->get_text()), Glib::locale_from_utf8(EnMail->get_text()), Glib::locale_from_utf8(EnPoblacion->get_text()), Glib::locale_from_utf8(EnCPostal->get_text()), Glib::locale_from_utf8(EnTelefono->get_text()), Glib::locale_from_utf8(EnDireccion->get_text()));
        }
        else
        {
            mr.Modificar(buscados[contadorBuscados]->getId(), Glib::locale_from_utf8(EnNombre->get_text()), Glib::locale_from_utf8(EnMail->get_text()), Glib::locale_from_utf8(EnPoblacion->get_text()), Glib::locale_from_utf8(EnCPostal->get_text()), Glib::locale_from_utf8(EnTelefono->get_text()), Glib::locale_from_utf8(EnDireccion->get_text()));
            buscados = mr.GetRegistrosBuscados();
        }
    }

    BtGuardarRegistro->set_sensitive(false);
    modificar = false;
    BtModificar->set_sensitive(true);
}

void Form::on_BtModificar_clicked(){
    modificar=true;
    BtGuardarRegistro->set_sensitive(true);
    BtModificar->set_sensitive(false);
}

void Form::on_BtBorrarRegistro_clicked(){
    if(!modoBuscar)
    {
        if(mr.GetNumRegistros()>=1)
        {
            mr.Borrar(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str()));
            std::vector<std::string> ar;
            ar=mr.GetRegistro(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str()));

            if(ar[0]=="-1" && mr.GetNumRegistros()!=0)
            {
                ar = mr.GetRegistro(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str())-1);
                LbId->set_text(IntToUString(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str())-1));
                EnNombre->set_text(ar[0]);
                EnDireccion->set_text(ar[1]);
                EnPoblacion->set_text(ar[2]);
                EnCPostal->set_text(ar[3]);
                EnTelefono->set_text(ar[4]);
                EnMail->set_text(ar[5]);
            }
            else if(ar[0]!="-1" && mr.GetNumRegistros()!=0)
            {
                ar = mr.GetRegistro(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str()));
                LbId->set_text(IntToUString(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str())));
                EnNombre->set_text(ar[0]);
                EnDireccion->set_text(ar[1]);
                EnPoblacion->set_text(ar[2]);
                EnCPostal->set_text(ar[3]);
                EnTelefono->set_text(ar[4]);
                EnMail->set_text(ar[5]);
            }
            else if(mr.GetNumRegistros()==0)
            {
                EnNombre->set_text("");
                EnDireccion->set_text("");
                EnPoblacion->set_text("");
                EnCPostal->set_text("");
                EnTelefono->set_text("");
                EnMail->set_text("");
            }
        }
    }
    else
    {
        mr.Borrar(buscados[atoi(Glib::locale_from_utf8(LbId->get_text()).c_str())]->getId());
        buscados = mr.GetRegistrosBuscados();
        if(contadorBuscados>=buscados.size())
        {
            contadorBuscados--;
        }
        if(contadorBuscados<0)
        {
            contadorBuscados=0;
        }
        if(buscados.size()!=0)
        {
            EnNombre->set_text(buscados[contadorBuscados]->getNombre());
            EnDireccion->set_text(buscados[contadorBuscados]->getDireccion());
            EnPoblacion->set_text(buscados[contadorBuscados]->getPoblacion());
            EnCPostal->set_text(buscados[contadorBuscados]->getPostal());
            EnTelefono->set_text(buscados[contadorBuscados]->getTelefono());
            EnMail->set_text(buscados[contadorBuscados]->getMail());
            LbId->set_text(IntToUString(contadorBuscados));
        }
        else
        {
            LbId->set_text("0");
            EnNombre->set_text("");
            EnDireccion->set_text("");
            EnPoblacion->set_text("");
            EnCPostal->set_text("");
            EnTelefono->set_text("");
            EnMail->set_text("");
        } 
    }
}

void Form::on_BtPrevRegistro_clicked()
{
    if(!modoBuscar)
    {
        std::vector<std::string> ar=mr.GetRegistro(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str())-1);
        if(ar.size()==6)
        {
            EnNombre->set_text(ar[0]);
            EnDireccion->set_text(ar[1]);
            EnPoblacion->set_text(ar[2]);
            EnCPostal->set_text(ar[3]);
            EnTelefono->set_text(ar[4]);
            EnMail->set_text(ar[5]);
            LbId->set_text(IntToUString(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str())-1));
        }
        BtGuardarRegistro->set_sensitive(false);
        BtModificar->set_sensitive(true);
        BtNuevoRegistro->set_sensitive(true);
        BtGuardarRegistro->set_sensitive(false);
        BtBorrarRegistro->set_sensitive(true);
    }
    else
    {
        if(contadorBuscados>0)
        {
            contadorBuscados--;
            EnNombre->set_text(buscados[contadorBuscados]->getNombre());
            EnDireccion->set_text(buscados[contadorBuscados]->getDireccion());
            EnPoblacion->set_text(buscados[contadorBuscados]->getPoblacion());
            EnCPostal->set_text(buscados[contadorBuscados]->getPostal());
            EnTelefono->set_text(buscados[contadorBuscados]->getTelefono());
            EnMail->set_text(buscados[contadorBuscados]->getMail());
            LbId->set_text(IntToUString(contadorBuscados));
        }
    }
}

void Form::on_BtNextRegistro_clicked()
{
    if(!modoBuscar)
    {
        std::vector<std::string> ar=mr.GetRegistro(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str())+1);
        if(ar.size()==6)
        {
            EnNombre->set_text(ar[0]);
            EnDireccion->set_text(ar[1]);
            EnPoblacion->set_text(ar[2]);
            EnCPostal->set_text(ar[3]);
            EnTelefono->set_text(ar[4]);
            EnMail->set_text(ar[5]);
            LbId->set_text(IntToUString(atoi(Glib::locale_from_utf8(LbId->get_text()).c_str())+1));
        }
        if(modificar)
        {
            BtModificar->set_sensitive(true);
            BtGuardarRegistro->set_sensitive(false);
            BtNuevoRegistro->set_sensitive(true);
            BtGuardarRegistro->set_sensitive(false);
            BtBorrarRegistro->set_sensitive(true);
        }
    }
    else
    {
        if(contadorBuscados+1<buscados.size())
        {
            contadorBuscados++;
            EnNombre->set_text(buscados[contadorBuscados]->getNombre());
            EnDireccion->set_text(buscados[contadorBuscados]->getDireccion());
            EnPoblacion->set_text(buscados[contadorBuscados]->getPoblacion());
            EnCPostal->set_text(buscados[contadorBuscados]->getPostal());
            EnTelefono->set_text(buscados[contadorBuscados]->getTelefono());
            EnMail->set_text(buscados[contadorBuscados]->getMail());
            LbId->set_text(IntToUString(contadorBuscados));
        }
    }
}

void Form::on_BtGuardarFichero_clicked()
{
    mr.EscribirFichero((char*)Glib::locale_from_utf8(BtCargarFichero->get_filename()).c_str());
    Gtk::MessageDialog dialog(*this, "Se ha guardado correctamente.");
    dialog.run();
}

void Form::on_BtCargarFichero_file_set(){

    if(mr.LeerFichero((char*)Glib::locale_from_utf8(BtCargarFichero->get_filename()).c_str()))
    {
        std::vector<std::string> ar;
        ar=mr.GetRegistro(0);
        EnNombre->set_text(ar[0]);
        EnDireccion->set_text(ar[1]);
        EnPoblacion->set_text(ar[2]);
        EnCPostal->set_text(ar[3]);
        EnTelefono->set_text(ar[4]);
        EnMail->set_text(ar[5]);
        BtModificar->set_sensitive(true);
        BtGuardarRegistro->set_sensitive(false);
        LbId->set_text("0");
    }
}

void Form::on_BtAcercaDe_clicked(){
    DiAcercaDe->show();
}

void Form::on_ChMostrar_clicked(){
    if(ChMostrar->get_active())
    {
        contadorBuscados=0;
        buscados = mr.GetRegistrosBuscados();
        if(buscados.size()==0)
        {
            Gtk::MessageDialog dialog(*this, "No se ha encontrado registros.");
            dialog.run();
            ChMostrar->set_active(false);
            BtNuevoRegistro->set_sensitive(true);
            modoBuscar=false;
        }
        else
        {
            BtNuevoRegistro->set_sensitive(false);
            modoBuscar=true;
            ChMostrar->set_active(true);
            EnNombre->set_text(buscados[0]->getNombre());
            EnDireccion->set_text(buscados[0]->getDireccion());
            EnPoblacion->set_text(buscados[0]->getPoblacion());
            EnCPostal->set_text(buscados[0]->getPostal());
            EnTelefono->set_text(buscados[0]->getTelefono());
            EnMail->set_text(buscados[0]->getMail());
            LbId->set_text(IntToUString(contadorBuscados));
        }
    }
    else
    {
        BtNuevoRegistro->set_sensitive(true);
        contadorBuscados=0;
        modoBuscar=false;
        std::vector<std::string> ar=mr.GetRegistro(0);
        EnNombre->set_text(ar[0]);
        EnDireccion->set_text(ar[1]);
        EnPoblacion->set_text(ar[2]);
        EnCPostal->set_text(ar[3]);
        EnTelefono->set_text(ar[4]);
        EnMail->set_text(ar[5]);
        BtModificar->set_sensitive(true);
        BtGuardarRegistro->set_sensitive(false);
        LbId->set_text("0");
    }
}

void Form::on_BtBuscar_clicked(){
    mr.Buscar(Glib::locale_from_utf8(EnBusqueda->get_text()));
    buscados.clear();
    buscados = mr.GetRegistrosBuscados();
    if(buscados.size()>0)
    {
        contadorBuscados=0;
        modoBuscar=true;
        ChMostrar->set_active(true);
        EnNombre->set_text(buscados[0]->getNombre());
        EnDireccion->set_text(buscados[0]->getDireccion());
        EnPoblacion->set_text(buscados[0]->getPoblacion());
        EnCPostal->set_text(buscados[0]->getPostal());
        EnTelefono->set_text(buscados[0]->getTelefono());
        EnMail->set_text(buscados[0]->getMail());
        LbId->set_text(IntToUString(contadorBuscados));
    }
    else
    {
        Gtk::MessageDialog dialog(*this, "No se ha encontrado registros.");
        dialog.run();
    }
}

Glib::ustring Form::IntToUString(int iVal)
{
    std::ostringstream ssIn;
    ssIn << iVal;
    Glib::ustring strOut = ssIn.str();

    return strOut;
}
