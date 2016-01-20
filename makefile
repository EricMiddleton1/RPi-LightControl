CC=g++
LD=g++

CFLAGS=-std=c++0x -Wall

srcdir=source
VPATH=source

all: LightControl

LightControl: SPI.o LightControl.o Color.o LightStrip.o StripModes.o
		g++ $(CFLAGS) Color.o LightStrip.o StripModes.o SPI.o LightControl.o -o LightControl -lbcm2835

SPI.o: $(srcdir)/SPI.c
	g++ $(CFLAGS) -c $(srcdir)/SPI.c

LightControl.o: $(srcdir)/LightControl.cpp
	g++ $(CFLAGS) -c $(srcdir)/LightControl.cpp

LightStrip.o: $(srcdir)/LightStrip.cpp
	g++ $(CFLAGS) -c $(srcdir)/LightStrip.cpp

Color.o: $(srcdir)/Color.cpp
	g++ $(CFLAGS) -c $(srcdir)/Color.cpp

StripModes.o: $(srcdir)/StripModes.cpp
	g++ $(CFLAGS) -c $(srcdir)/StripModes.cpp

clean:
	rm *o LightControl
