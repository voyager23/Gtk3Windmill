# Makefile for Gtk3Windmill

.PHONY : run

CC = g++
CFLAGS = -g -Wfatal-errors -std=c++14
CFLAGS += `pkg-config --cflags gtk+-3.0 gdk-3.0`

LIBS = `pkg-config --libs gtk+-3.0 gdk-3.0`

TARGET = gtk3windmill

OBJECTS = main.o utilities.o gtk3_data_set.o
HEADERS = windmill.h

OBJS = $(addprefix ../build/, $(OBJECTS) )
HDRS = $(addprefix ../include/, $(HEADERS))
VPATH = ../build ../include
OUT = ../build/$@

#-----------------------------------------------------------------------
	
$(TARGET) : $(OBJS) $(HDRS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o ../bin/$(TARGET)
	
../build/main.o : main.cxx ../include/windmill.h
	@$(CC) -c $(CFLAGS) $(LIBS) $< -o $(OUT)

../build/utilities.o : utilities.cxx ../include/windmill.h
	@$(CC) -c $(CFLAGS) $(LIBS) $< -o $(OUT)
	
../build/gtk3_data_set.o : gtk3_data_set.cxx ../include/windmill.h
	@$(CC) -c $(CFLAGS) $(LIBS) $< -o $(OUT)
