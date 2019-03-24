#if !defined(ALERT_DIALOG_H)
#define ALERT_DIALOG_H

#include <gtkmm.h>

class AlertDialog : public Gtk::MessageDialog {
    public:
        AlertDialog(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);

        static AlertDialog* create(Gtk::Window& parent, const Glib::ustring& message);

    protected:
        Glib::RefPtr<Gtk::Builder> m_refBuilder;
        Gtk::Button* m_close_button;
        // signal handlers
        void on_close_cb();
};

#endif // ALERT_DIALOG_H
