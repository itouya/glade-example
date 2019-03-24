#if !defined(MAIN_WINDOW_H)
#define MAIN_WINDOW_H

#include <gtkmm.h>

class MainWindow : public Gtk::ApplicationWindow {
    public:
        MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

        static MainWindow* create();

    protected:
        Glib::RefPtr<Gtk::Builder> m_refBuilder;
        Gtk::Button* m_power_button;
        Gtk::Button* m_quit_button;
        // signal handlers
        void on_power_cb();
        void on_quit_cb();
};

#endif // MAIN_WINDOW_H
