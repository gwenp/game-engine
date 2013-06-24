AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ 

bin_PROGRAMS = OutputApiHeader.plg

OutputApiHeader_plg_SOURCES = src/OutputApiHeader.cpp \
			    				../../src/api/Plugin.cpp \
								../../src/api/CommunicativeObject.cpp \
								${NULL}

OutputApiHeader_plg_LDFLAGS = -shared -fPIC
AM_CPPFLAGS = -fPIC -g
