#include "vclass_server.h"
#include "main_window.h"
#include "layout_area.h"

#include <iostream>

VclassServer::VclassServer() {

}

Glib::RefPtr<VclassServer> VclassServer::create() {
    return Glib::RefPtr<VclassServer>(new VclassServer());
}

MainWindow* VclassServer::create_main_window() {
    auto main_window = MainWindow::create();
    add_window(*main_window);

    main_window->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this, &VclassServer::on_hide_window), main_window));
    return main_window;
}

void VclassServer::on_activate() {
    auto main_window = create_main_window();
    main_window->present();
}

void VclassServer::on_hide_window(Gtk::Window* window) {
    delete window;
}