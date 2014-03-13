lib_LTLIBRARIES             =   libotlib.la

SUBDIRS                     =   otprotob bigint irrxml lucre otext

########################## STANDARD FOLDERS #########################

opentxs_incdir              =   $(top_srcdir)/include
opentxs_srcdir              =   $(top_srcdir)/src

gmock_incdir                =   $(opentxs_incdir)/gmock
gmock_srcdir                =   $(opentxs_srcdir)/gmock
gtest_incdir                =   $(opentxs_incdir)/gtest
gtest_srcdir                =   $(opentxs_srcdir)/gtest
ot_incdir                   =   $(opentxs_incdir)/otd
ot_srcdir                   =   $(opentxs_srcdir)/otd
otapi_incdir                =   $(opentxs_incdir)/otapi
otapi_srcdir                =   $(opentxs_srcdir)/otapi
otapitest_incdir            =   $(opentxs_incdir)/otapitest
otapitest_srcdir            =   $(opentxs_srcdir)/otapitest
otlib_incdir                =   $(opentxs_incdir)/otlib
otlib_srcdir                =   $(opentxs_srcdir)/otlib
otmint_incdir               =   $(opentxs_incdir)/otmint
otmint_srcdir               =   $(opentxs_srcdir)/otmint
otserver_incdir             =   $(opentxs_incdir)/ots
otserver_srcdir             =   $(opentxs_srcdir)/ots

swig_dir                    =   $(top_srcdir)/swig

common_includes             =   -I$(otapi_incdir) \
                                -I$(otlib_incdir) \
                                -I$(opentxs_incdir)

common_libraries            =   $(otapi_srcdir)/libotapi.la \
                                $(otlib_incdir)/libotlib.la
                                        
######################## BUILD COMMANDS #############################


libotlib_la_SOURCES         =   $(otlib_sources) $(otlib_headers)

libotapi_la_CXXFLAGS        =   $(AM_CXXFLAGS) $(common_includes)

libotlib_la_LIBADD          =   bigint/libbigint.la \
                                irrxml/libirrxml.la \
                                lucre/liblucre.la \
                                otprotob/libotprotob.la \
                                otext/libotext.la \
                                $(DEPS_LIBS)

libotlib_la_DEPENDENCIES    =   bigint/libbigint.la \
                                irrxml/libirrxml.la \
                                lucre/liblucre.la \
                                otprotob/libotprotob.la \
                                otext/libotext.la

libotlib_la_LDFLAGS         =   --no-undefined


#### KEYRING Options

if KEYRING_WINDOWS
libot_la_CXXFLAGS          +=   -DOT_KEYRING_WINDOWS
endif

if KEYRING_MAC
libot_la_CXXFLAGS          +=   -DOT_KEYRING_MAC
endif

if KEYRING_GNOME
libot_la_CXXFLAGS          +=   -DOT_KEYRING_GNOME
endif

if KEYRING_KWALLET
libot_la_CXXFLAGS          +=   -DOT_KEYRING_KWALLET
endif

######################## DEPENDENCIES ###############################


otlib_sources               =   $(otlib_srcdir)/OTAccount.cpp \
                                $(otlib_srcdir)/OTAgreement.cpp \
                                $(otlib_srcdir)/OTASCIIArmor.cpp \
                                $(otlib_srcdir)/OTAssetContract.cpp \
                                $(otlib_srcdir)/OTAsymmetricKey.cpp \
                                $(otlib_srcdir)/OTBasket.cpp \
                                $(otlib_srcdir)/OTBylaw.cpp \
                                $(otlib_srcdir)/OTCachedKey.cpp \
                                $(otlib_srcdir)/OTCheque.cpp \
                                $(otlib_srcdir)/OTContract.cpp \
                                $(otlib_srcdir)/OTCredential.cpp \
                                $(otlib_srcdir)/OTCron.cpp \
                                $(otlib_srcdir)/OTCronItem.cpp \
                                $(otlib_srcdir)/OTCrypto.cpp \
                                $(otlib_srcdir)/OTData.cpp \
                                $(otlib_srcdir)/OTDataCheck.cpp \
                                $(otlib_srcdir)/OTDigitalCash.cpp \
                                $(otlib_srcdir)/OTEnvelope.cpp \
                                $(otlib_srcdir)/OTKeyring.cpp \
                                $(otlib_srcdir)/OTIdentifier.cpp \
                                $(otlib_srcdir)/OTInstrument.cpp \
                                $(otlib_srcdir)/OTItem.cpp \
                                $(otlib_srcdir)/OTLedger.cpp \
                                $(otlib_srcdir)/OTLog.cpp \
                                $(otlib_srcdir)/OTMarket.cpp \
                                $(otlib_srcdir)/OTMessage.cpp \
                                $(otlib_srcdir)/OTMessageBuffer.cpp \
                                $(otlib_srcdir)/OTMint.cpp \
                                $(otlib_srcdir)/OTOffer.cpp \
                                $(otlib_srcdir)/OTPassword.cpp \
                                $(otlib_srcdir)/OTPaths.cpp \
                                $(otlib_srcdir)/OTPayload.cpp \
                                $(otlib_srcdir)/OTPayment.cpp \
                                $(otlib_srcdir)/OTPaymentPlan.cpp \
                                $(otlib_srcdir)/OTPseudonym.cpp \
                                $(otlib_srcdir)/OTPurse.cpp \
                                $(otlib_srcdir)/OTScript.cpp \
                                $(otlib_srcdir)/OTScriptable.cpp \
                                $(otlib_srcdir)/OTServerContract.cpp \
                                $(otlib_srcdir)/OTSettings.cpp \
                                $(otlib_srcdir)/OTSignature.cpp \
                                $(otlib_srcdir)/OTSignedFile.cpp \
                                $(otlib_srcdir)/OTSmartContract.cpp \
                                $(otlib_srcdir)/OTStorage.cpp \
                                $(otlib_srcdir)/OTString.cpp \
                                $(otlib_srcdir)/OTStringXML.cpp \
                                $(otlib_srcdir)/OTSymmetricKey.cpp \
                                $(otlib_srcdir)/OTToken.cpp \
                                $(otlib_srcdir)/OTTrackable.cpp \
                                $(otlib_srcdir)/OTTrade.cpp \
                                $(otlib_srcdir)/OTTransaction.cpp \
                                $(otlib_srcdir)/OTTransactionType.cpp \
                                $(otlib_srcdir)/OTWallet.cpp

otlib_headers               =   $(otlib_incdir)/constants.h \
                                $(otlib_incdir)/fast_mutex.h \
                                $(otlib_incdir)/WinsockWrapper.h \
                                $(otlib_incdir)/tinythread.h \
                                $(otlib_incdir)/Timer.h \
                                $(otlib_headers_ext)

otlib_headers_ext           =   $(top_builddir)/include/otlib/ot_config.h \
                                $(otlib_incdir)/ExportWrapper.h \
                                $(otlib_incdir)/stacktrace.h \
                                $(otlib_incdir)/stdafx.h \
                                $(otlib_incdir)/OTAccount.h \
                                $(otlib_incdir)/OTAgreement.h \
                                $(otlib_incdir)/OTASCIIArmor.h \
                                $(otlib_incdir)/OTAssetContract.h \
                                $(otlib_incdir)/OTAsymmetricKey.h \
                                $(otlib_incdir)/OTBasket.h \
                                $(otlib_incdir)/OTBylaw.h \
                                $(otlib_incdir)/OTCachedKey.h \
                                $(otlib_incdir)/OTCheque.h \
                                $(otlib_incdir)/OTContract.h \
                                $(otlib_incdir)/OTCredential.h \
                                $(otlib_incdir)/OTCron.h \
                                $(otlib_incdir)/OTCronItem.h \
                                $(otlib_incdir)/OTCrypto.h \
                                $(otlib_incdir)/OTData.h \
                                $(otlib_incdir)/OTDataCheck.h \
                                $(otlib_incdir)/OTDigitalCash.h \
                                $(otlib_incdir)/OTEnvelope.h \
                                $(otlib_incdir)/OTKeyring.h \
                                $(otlib_incdir)/OTglobal.h \
                                $(otlib_incdir)/OTIdentifier.h \
                                $(otlib_incdir)/OTInstrument.h \
                                $(otlib_incdir)/OTItem.h \
                                $(otlib_incdir)/OTLedger.h \
                                $(otlib_incdir)/OTLib.h \
                                $(otlib_incdir)/OTLibPriv.h \
                                $(otlib_incdir)/OTLog.h \
                                $(otlib_incdir)/OTMarket.h \
                                $(otlib_incdir)/OTMessage.h \
                                $(otlib_incdir)/OTMessageBuffer.h \
                                $(otlib_incdir)/OTMint.h \
                                $(otlib_incdir)/OTOffer.h \
                                $(otlib_incdir)/OTPassword.h \
                                $(otlib_incdir)/OTPaths.h \
                                $(otlib_incdir)/OTPayload.h \
                                $(otlib_incdir)/OTPayment.h \
                                $(otlib_incdir)/OTPaymentPlan.h \
                                $(otlib_incdir)/OTPseudonym.h \
                                $(otlib_incdir)/OTPurse.h \
                                $(otlib_incdir)/OTScript.h \
                                $(otlib_incdir)/OTScriptable.h \
                                $(otlib_incdir)/OTServerContract.h \
                                $(otlib_incdir)/OTSettings.h \
                                $(otlib_incdir)/OTSignature.h \
                                $(otlib_incdir)/OTSignedFile.h \
                                $(otlib_incdir)/OTSmartContract.h \
                                $(otlib_incdir)/OTStorage.h \
                                $(otlib_incdir)/OTString.h \
                                $(otlib_incdir)/OTStringXML.h \
                                $(otlib_incdir)/OTSymmetricKey.h \
                                $(otlib_incdir)/OTToken.h \
                                $(otlib_incdir)/OTTrackable.h \
                                $(otlib_incdir)/OTTrade.h \
                                $(otlib_incdir)/OTTransaction.h \
                                $(otlib_incdir)/OTTransactionType.h \
                                $(otlib_incdir)/OTWallet.h

####   Containers

containers_headers_dir      =   $(opentxs_incdir)/containers

containers_headers          =   $(containers_incdir)/containers.hpp \
                                $(containers_headers_dir)/containers_fixes.hpp \
                                $(containers_headers_dir)/copy_functors.hpp \
                                $(containers_headers_dir)/digraph.hpp \
                                $(containers_headers_dir)/digraph.tpp \
                                $(containers_headers_dir)/exceptions.hpp \
                                $(containers_headers_dir)/foursome.hpp \
                                $(containers_headers_dir)/foursome.tpp \
                                $(containers_headers_dir)/hash.hpp \
                                $(containers_headers_dir)/hash.tpp \
                                $(containers_headers_dir)/matrix.hpp \
                                $(containers_headers_dir)/matrix.tpp \
                                $(containers_headers_dir)/ntree.hpp \
                                $(containers_headers_dir)/ntree.tpp \
                                $(containers_headers_dir)/safe_iterator.hpp \
                                $(containers_headers_dir)/safe_iterator.tpp \
                                $(containers_headers_dir)/simple_ptr.hpp \
                                $(containers_headers_dir)/simple_ptr.tpp \
                                $(containers_headers_dir)/smart_ptr.hpp \
                                $(containers_headers_dir)/smart_ptr.tpp \
                                $(containers_headers_dir)/triple.hpp \
                                $(containers_headers_dir)/triple.tpp

####    Global Headers for dist.

pkginclude_HEADERS          =   $(otlib_headers_ext)

## Extra to package containers headers

pkginclude_containersdir    =   $(pkgincludedir)/containers
pkginclude_containers_HEADERS   =   $(containers_headers)

## Extra to package simpleini headers

simpleini_headers_dir       =   $(top_srcdir)/include/simpleini

simpleini_headers           =   $(simpleini_headers_dir)/ConvertUTF.h \
                                $(simpleini_headers_dir)/SimpleIni.h
    
pkginclude_simpleinidir     =   $(pkgincludedir)/simpleini
pkginclude_simpleini_HEADERS    =   $(simpleini_headers)
