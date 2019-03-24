#include "alert_dialog.h"

#include <iostream>
#include <stdexcept>

AlertDialog::AlertDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder)
: Gtk::MessageDialog(cobject),
  m_refBuilder(refBuilder),
  m_close_button(nullptr) {
    std::cerr << G_STRFUNC << std::endl;
    refBuilder->get_widget("CloseButton", m_close_button);
    if(!m_close_button)
        throw std::runtime_error("No \"CloseButton\" object in vlcass_server.glade");
    m_close_button->signal_clicked().connect(sigc::mem_fun(*this, &AlertDialog::on_close_cb));
}

AlertDialog* AlertDialog::create(Gtk::Window& parent, const Glib::ustring& message)
{
    std::cerr << G_STRFUNC << std::endl;
    auto refBuilder = Gtk::Builder::create_from_resource("/jp/co/alpha/vclass_server.glade");

    AlertDialog* alert_dialog = nullptr;
    refBuilder->get_widget_derived("AlertDialog", alert_dialog);
    if(!alert_dialog)
        throw std::runtime_error("No \"AlertDialog\" object in vclass_server.glade");

    alert_dialog->set_message(message);
    alert_dialog->set_transient_for(parent);

    return alert_dialog;
}

void AlertDialog::on_close_cb()
{
    close();
}