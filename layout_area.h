#if !defined(LAYOUT_AREA_H)
#define LAYOUT_AREA_H

#include <gtkmm.h>

class LayoutArea : public Gtk::DrawingArea
{
    public:
        LayoutArea(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refBuilder);
        static LayoutArea* create();

    protected:
        Glib::RefPtr<Gtk::Builder> m_refBuilder;
        bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
        bool on_timeout();

        double m_radius;
        double m_line_width;
};

#endif // LAYOUT_AREA_H
