AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ 

bin_PROGRAMS = Logger.plg


Logger_plg_LDFLAGS = -shared -fPIC
Logger_plg_LDADD =

AM_CPPFLAGS = $(JSONCPP_CFLAGS)
AM_CPPFLAGS += -fPIC -g

Logger_plg_SOURCES = src/Logger.cpp \
				    src/Dbg.cpp \
				    ../../src/api/Plugin.cpp \
					../../src/api/CommunicativeObject.cpp

