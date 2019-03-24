#include "main_window.h"
#include "alert_dialog.h"

#include <iostream>

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder)
: Gtk::ApplicationWindow(cobject),
  m_refBuilder(refBuilder),
  m_power_button(nullptr),
  m_quit_button(nullptr) {
    m_refBuilder->get_widget("PowerButton", m_power_button);
    if(!m_power_button)
        throw std::runtime_error("No \"PowerButton\" object in vclass_server.glade");
    m_power_button->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_power_cb));

    m_refBuilder->get_widget("QuitButton", m_quit_button);
    if(!m_quit_button)
        throw std::runtime_error("No \"QuitButton\" object in vclass_server.glade");
    m_quit_button->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_quit_cb));

}

MainWindow* MainWindow::create() {
    auto refBuilder = Gtk::Builder::create_from_resource("/jp/co/alpha/vclass_server.glade");

    MainWindow* window = nullptr;
    refBuilder->get_widget_derived("MainWindow", window);
    if(!window)
        throw std::runtime_error("No \"MainWindow\" object in vclass_server.glade");

    return window;
}

void MainWindow::on_power_cb()
{
    std::cerr << G_STRFUNC << std::endl;
    auto alert_dialog = AlertDialog::create(*this, "No selected computer(s).");
    alert_dialog->show_all();
}

void MainWindow::on_quit_cb()
{
    std::cerr << G_STRFUNC << std::endl;
    MainWindow::hide();
}