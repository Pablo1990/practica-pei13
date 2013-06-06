#include <gtkmm.h>

class Form : public Gtk::Window{
protected:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Button *BtNuevoRegistro;
    Gtk::Button *BtGuardarRegistro;
    Gtk::Button *BtModificar;
    Gtk::Button *BtBorrarRegistro;
    Gtk::Button *BtPrevRegistro;
    Gtk::Button *BtNextRegistro;
    Gtk::Button *BtGuardarFichero;
    Gtk::FileChooserButton *BtCargarFichero;
    Gtk::Button *BtBuscar;
    Gtk::Button *BtAcercaDe;
    Gtk::CheckButton *ChMostrar;
    Gtk::Entry *EnNombre;
    Gtk::Entry *EnDireccion;
    Gtk::Entry *EnPoblacion;
    Gtk::Entry *EnCPostal;
    Gtk::Entry *EnTelefono;
    Gtk::Entry *EnMail;
    Gtk::Entry *EnBusqueda;
    

public:
    Form(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);//constructor

protected:
    //signal handlers
    void on_BtNuevoRegistro_clicked();
    void on_BtGuardarRegistro_clicked();
    void on_BtModificar_clicked();
    void on_BtBorrarRegistro_clicked();
    void on_BtPrevRegistro_clicked();
    void on_BtNextRegistro_clicked();
    void on_BtGuardarFichero_clicked();
    void on_ChMostrar_clicked();
    void on_BtBuscar_clicked();
    void on_BtAcercaDe_clicked();
    void on_BtCargarFichero_file_set();
};
