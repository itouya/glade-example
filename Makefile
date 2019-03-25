CC ?= gcc
CXX ?= g++
PROGRAM = vclass_server
CXXFILES = main.cc vclass_server.cc main_window.cc alert_dialog.cc layout_area.cc
BUILT_SRC = resources.c
OBJS = $(BUILT_SRC:.c=.o) $(CXXFILES:.cc=.o)
DEPDIR = .deps
CXXFLAGS = `pkg-config --cflags gtkmm-3.0` -std=c++11 -Wall -g
CFLAGS = `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtkmm-3.0`
GLIB_COMPILE_RESOURCES = $(shell pkg-config --variable=glib_compile_resources gio-2.0)
GLIB_COMPILE_SCHEMAS   = $(shell pkg-config --variable=glib_compile_schemas gio-2.0)

all: $(PROGRAM)

-include $(OBJS:%.o=$(DEPDIR)/%.Po)

#gschemas.compiled: org.gtkmm.myapp.gschema.xml
#	$(GLIB_COMPILE_SCHEMAS) --strict --dry-run --schema-file=$<
#	$(GLIB_COMPILE_SCHEMAS) .

resources.c: vclass.gresource.xml vclass_server.glade
	$(GLIB_COMPILE_RESOURCES) --target=$@ --sourcedir=. --generate-source $<

%.o: %.c
	@mkdir -p $(DEPDIR)
	$(CC) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $(CFLAGS) $<

%.o: %.cc
	@mkdir -p $(DEPDIR)
	$(CXX) -MT $@ -MD -MP -MF $(DEPDIR)/$*.Tpo -c -o $@ $(CXXFLAGS) $<
	@mv -f $(DEPDIR)/$*.Tpo $(DEPDIR)/$*.Po

$(PROGRAM): $(OBJS)
	$(CXX) -o $(PROGRAM) $(OBJS) $(LIBS)

clean:
	rm -f gschemas.compiled
	rm -f $(BUILT_SRC)
	rm -f $(OBJS)
	rm -f $(PROGRAM)
