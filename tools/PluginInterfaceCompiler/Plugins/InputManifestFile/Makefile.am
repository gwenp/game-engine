AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ 

bin_PROGRAMS = InputManifestFile.plg

InputManifestFile_plg_SOURCES = src/InputManifestFile.cpp \
								src/ManifestParser.cpp \
			    				../../src/api/Plugin.cpp \
								../../src/api/CommunicativeObject.cpp \
								${NULL}

InputManifestFile_plg_LDFLAGS = -shared -fPIC
AM_CPPFLAGS = -fPIC -g
