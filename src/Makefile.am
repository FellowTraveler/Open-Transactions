bin_PROGRAMS            =   ot otserver createmint

SUBDIRS                 =   otlib otapi mtest gmock aotapitest

########################## STANDARD FOLDERS #########################

opentxs_incdir              =   $(top_srcdir)/include
opentxs_srcdir              =   $(top_srcdir)/src

gmock_incdir                =   $(opentxs_incdir)/gmock
gmock_srcdir                =   $(opentxs_srcdir)/gmock
gtest_incdir                =   $(opentxs_incdir)/gtest
gtest_srcdir                =   $(opentxs_srcdir)/gtest
ot_incdir                   =   $(opentxs_incdir)/ot
ot_srcdir                   =   $(opentxs_srcdir)/ot
otapi_incdir                =   $(opentxs_incdir)/otapi
otapi_srcdir                =   $(opentxs_srcdir)/otapi
otapitest_incdir            =   $(opentxs_incdir)/otapitest
otapitest_srcdir            =   $(opentxs_srcdir)/otapitest
otlib_incdir                =   $(opentxs_incdir)/otlib
otlib_srcdir                =   $(opentxs_srcdir)/otlib
otmint_incdir               =   $(opentxs_incdir)/otmint
otmint_srcdir               =   $(opentxs_srcdir)/otmint
otserver_incdir             =   $(opentxs_incdir)/otserver
otserver_srcdir             =   $(opentxs_srcdir)/otserver

swig_dir                    =   $(top_srcdir)/swig

common_includes             =   -I$(otapi_incdir) \
                                -I$(otlib_incdir) \
                                -I$(opentxs_incdir)

common_libraries            =   $(otapi_srcdir)/libotapi.la \
                                $(otlib_incdir)/libotlib.la
                                        
######################## BUILD COMMANDS #############################


#### OT

ot_SOURCES                  =   $(ot_sources) $(ot_headers)

ot_CXXFLAGS                 =   $(AM_CXXFLAGS) $(common_includes)

ot_LDADD                    =   $(common_libraries) $(DEPS_LIBS)
ot_DEPENDENCIES             =   $(common_libraries)


#### OT Server

otserver_SOURCES            =   $(otserver_sources) $(otserver_headers)

otserver_CXXFLAGS           =   $(AM_CXXFLAGS) \
                                -I$(otserver_incdir) \
                                $(common_includes)

otserver_LDADD              =   $(common_libraries) $(DEPS_LIBS)
otserver_DEPENDENCIES       =   $(common_libraries)


#### Createmint  (includes files from OT Server)

createmint_SOURCES          =   $(createmint_sources) $(otserver_sources) $(otserver_headers)

createmint_CXXFLAGS         =   $(AM_CXXFLAGS) \
                                -I$(otserver_incdir) \
                                $(common_includes)

createmint_LDADD            =   $(common_libraries) $(DEPS_LIBS)
createmint_DEPENDENCIES     =   $(common_libraries)


#### Transport ZMQ 'option'

if TRANSPORT_ZMQ
ot_CXXFLAGS                +=   -DOT_ZMQ_MODE
otserver_SOURCES           +=   ots/xmlrpcxx_server.cpp
otserver_CXXFLAGS          +=   -DOT_ZMQ_MODE
createmint_CXXFLAGS        +=   -DOT_ZMQ_MODE
endif

######################## DEPENDENCIES ###############################

#### OT

ot_sources                  =   $(ot_srcdir)/main.cpp

ot_headers                  =   $(otapi_incdir)/main.h             \
                                $(otapi_incdir)/OpenTransactions.h \
                                $(otapi_incdir)/OTAPI.h            \
                                $(otapi_incdir)/OT_ME.h            \
                                $(otapi_incdir)/ot_switch_me.hpp   \
                                $(otapi_incdir)/OTClient.h         \
                                $(otapi_incdir)/OTServerConnection.h

#### OT Server

otserver_sources            =   $(otserver_srcdir)/OTClientConnection.cpp  \
                                $(otserver_srcdir)/OTServer.cpp

otserver_headers            =   $(otserver_incdir)/main.h   \
                                $(otserver_incdir)/OTClientConnection.h \
                                $(otserver_incdir)/OTServer.h

#### OT Create Mint

createmint_sources          =   $(otmint_srcdir)/main.cpp
