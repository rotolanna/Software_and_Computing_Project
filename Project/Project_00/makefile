# Makefile for the ROOT test programs.
# This Makefile shows nicely how to compile and link applications
# using the ROOT libraries on all supported platforms.
#
# Copyright (c) 2000 Rene Brun and Fons Rademakers
#
# Author: Fons Rademakers, 29/2/2000

CXX           =
ObjSuf        = o
SrcSuf        = cpp
ExeSuf        =
DllSuf        = so
OutPutOpt     = -o 

ROOTSYS      := $(shell root-config --prefix)
ROOTCFLAGS   := $(shell root-config --cflags)
ROOTLIBS     := $(shell root-config --libs)
ROOTGLIBS    := $(shell root-config --glibs)

# Linux with egcs, gcc 2.9x, gcc 3.x (>= RedHat 5.2)
CXX           = g++
CXXFLAGS      = -g -Wall -fPIC
LD            = g++
LDFLAGS       = -O -m64
SOFLAGS       = -shared -dynamiclib

CXXFLAGS     += $(ROOTCFLAGS) -I.
LIBS          = $(ROOTLIBS) $(SYSLIBS)
GLIBS         = $(ROOTGLIBS) $(SYSLIBS) -lMinuit


#------------------------------------------------------------------------------
SRC   = Evento.cpp Initialization.cpp AnaFOOTDict.cpp Booking.cpp Init_in_each_event.cpp Generation.cpp Analysis.cpp
OBJ   = Evento.o Initialization.o AnaFOOTDict.o Booking.o Init_in_each_event.o Generation.o
HEAD  = Evento.h Initialization.h Booking.h Init_in_each_event.h STRUCT.h constant.h Generation.h
#------------------------------------------------------------------------------

all:            Analysis

Analysis:  Analysis.o $(OBJ) $(HEAD) Analysis.h EventStruct.h Initialization.h Booking.h Init_in_each_event.h Generation.h 
	$(LD) $(LDFLAGS) Analysis.o $(OBJ) $(GLIBS) -o Analysis

AnaFOOTDict.cpp:  $(HEAD) EventStruct.h AnaFOOTLinkDef.h
		@echo "Generating dictionary $@..." 
		@$(ROOTSYS)/bin/rootcint -f AnaFOOTDict.cpp -c -p $(HEAD)

Evento.o:   Evento.cpp $(HEAD) Evento.h EventStruct.h
	    g++ -c Evento.cpp $(CXXFLAGS)

Initialization.o:  Initialization.cpp $(HEAD) Initialization.h Evento.h 
		g++ -c Initialization.cpp $(CXXFLAGS)

Booking.o:  Booking.cpp $(HEAD) Booking.h Initialization.h Init_in_each_event.h
		g++ -c Booking.cpp $(CXXFLAGS)

Init_in_each_event.o:  Init_in_each_event.cpp $(HEAD) Init_in_each_event.h Initialization.h STRUCT.h constant.h
		g++ -c Init_in_each_event.cpp $(CXXFLAGS)
		
Generation.o:   Generation.cpp $(HEAD) Generation.h Booking.h 
		g++ -c Generation.cpp $(CXXFLAGS)
		
clean:
	@rm -f $(OBJ) *o *Dict* Analysis


