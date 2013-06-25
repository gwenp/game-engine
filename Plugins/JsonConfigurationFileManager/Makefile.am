AUTOMAKE_OPTIONS = subdir-objects

INCLUDES = -I../../src/ 

bin_PROGRAMS = JsonConfigurationFileManager.plg


JsonConfigurationFileManager_plg_LDFLAGS = -shared -fPIC
JsonConfigurationFileManager_plg_LDADD = $(JSONCPP_LIBS)

AM_CPPFLAGS = $(JSONCPP_CFLAGS)
AM_CPPFLAGS += -fPIC -g

JsonConfigurationFileManager_plg_SOURCES = src/JsonConfigurationFileManager.cpp \
											src/JsonConfiguration.cpp \
										    ../../src/api/Plugin.cpp \
											../../src/api/CommunicativeObject.cpp

