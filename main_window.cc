#include "main_window.h"

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder)
: Gtk::ApplicationWindow(cobject),
  m_refBuilder(refBuilder) {

}

MainWindow* MainWindow::create() {
    auto refBuilder = Gtk::Builder::create_from_resource("/jp/co/alpha/vclass_server.glade");

    MainWindow* window = nullptr;
    refBuilder->get_widget_derived("mainWindow", window);
    if(!window)
        throw std::runtime_error("No \"mainWindow\" object in vclass_server.glade");

    return window;
}