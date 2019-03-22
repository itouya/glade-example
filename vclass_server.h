#if !defined(VCLASS_SERVER_H)
#define VCLASS_SERVER_H

#include <gtkmm.h>

class MainWindow;

class VclassServer : public Gtk::Application {
    protected:
        VclassServer();

    public:
        static Glib::RefPtr<VclassServer> create();

    protected:
        void on_activate() override;

    private:
        MainWindow* create_main_window();
        void on_hide_window(Gtk::Window* window);
};

#endif // VCLASS_SERVER_H
