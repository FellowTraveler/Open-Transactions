lib_LTLIBRARIES             =   libotlib.la

SUBDIRS                     =   bigint irrxml lucre otext otprotob

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
                                libotlib.la
                                        
######################## BUILD COMMANDS #############################

libotlib_la_SOURCES         =   $(otlib_sources) $(otlib_headers)

libotlib_la_CXXFLAGS        =   $(AM_CXXFLAGS) $(common_includes)

libotlib_la_DEPENDENCIES    =   bigint/libbigint.la \
                                irrxml/libirrxml.la \
                                lucre/liblucre.la \
                                otext/libotext.la \
                                otprotob/libotprotob.la

libotlib_la_LIBADD          =   $(libotlib_la_DEPENDENCIES) \
                                $(DEPS_LIBS)

libotlib_la_LDFLAGS         =   -g --no-undefined


#### KEYRING Options

if KEYRING_WINDOWS
libotlib_la_CXXFLAGS       +=   -DOT_KEYRING_WINDOWS
endif

if KEYRING_MAC
libotlib_la_CXXFLAGS       +=   -DOT_KEYRING_MAC
endif

if KEYRING_GNOME
libotlib_la_CXXFLAGS       +=   -DOT_KEYRING_GNOME
endif

if KEYRING_KWALLET
libotlib_la_CXXFLAGS       +=   -DOT_KEYRING_KWALLET
endif

######################## DEPENDENCIES ###############################


otlib_sources               =   OTAccount.cpp \
                                OTAgreement.cpp \
                                OTASCIIArmor.cpp \
                                OTAssetContract.cpp \
                                OTAsymmetricKey.cpp \
                                OTBasket.cpp \
                                OTBylaw.cpp \
                                OTCachedKey.cpp \
                                OTCheque.cpp \
                                OTContract.cpp \
                                OTCredential.cpp \
                                OTCron.cpp \
                                OTCronItem.cpp \
                                OTCrypto.cpp \
                                OTData.cpp \
                                OTDataCheck.cpp \
                                OTDigitalCash.cpp \
                                OTEnvelope.cpp \
                                OTKeyring.cpp \
                                OTIdentifier.cpp \
                                OTInstrument.cpp \
                                OTItem.cpp \
                                OTLedger.cpp \
                                OTLog.cpp \
                                OTMarket.cpp \
                                OTMessage.cpp \
                                OTMessageBuffer.cpp \
                                OTMint.cpp \
                                OTOffer.cpp \
                                OTPassword.cpp \
                                OTPaths.cpp \
                                OTPayload.cpp \
                                OTPayment.cpp \
                                OTPaymentPlan.cpp \
                                OTPseudonym.cpp \
                                OTPurse.cpp \
                                OTScript.cpp \
                                OTScriptable.cpp \
                                OTServerContract.cpp \
                                OTSettings.cpp \
                                OTSignature.cpp \
                                OTSignedFile.cpp \
                                OTSmartContract.cpp \
                                OTStorage.cpp \
                                OTString.cpp \
                                OTStringXML.cpp \
                                OTSymmetricKey.cpp \
                                OTToken.cpp \
                                OTTrackable.cpp \
                                OTTrade.cpp \
                                OTTransaction.cpp \
                                OTTransactionType.cpp \
                                OTWallet.cpp

otlib_headers               =   $(otlib_incdir)/constants.h \
                                $(otlib_incdir)/fast_mutex.h \
                                $(otlib_incdir)/WinsockWrapper.h \
                                $(otlib_incdir)/tinythread.h \
                                $(otlib_incdir)/Timer.h \
                                $(otlib_headers_ext)

otlib_headers_ext           =   $(otlib_incdir)/ot_config.h \
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

containers_incdir           =   $(opentxs_incdir)/containers

containers_headers          =   $(containers_incdir)/containers.hpp \
                                $(containers_incdir)/containers_fixes.hpp \
                                $(containers_incdir)/copy_functors.hpp \
                                $(containers_incdir)/digraph.hpp \
                                $(containers_incdir)/digraph.tpp \
                                $(containers_incdir)/exceptions.hpp \
                                $(containers_incdir)/foursome.hpp \
                                $(containers_incdir)/foursome.tpp \
                                $(containers_incdir)/hash.hpp \
                                $(containers_incdir)/hash.tpp \
                                $(containers_incdir)/matrix.hpp \
                                $(containers_incdir)/matrix.tpp \
                                $(containers_incdir)/ntree.hpp \
                                $(containers_incdir)/ntree.tpp \
                                $(containers_incdir)/safe_iterator.hpp \
                                $(containers_incdir)/safe_iterator.tpp \
                                $(containers_incdir)/simple_ptr.hpp \
                                $(containers_incdir)/simple_ptr.tpp \
                                $(containers_incdir)/smart_ptr.hpp \
                                $(containers_incdir)/smart_ptr.tpp \
                                $(containers_incdir)/triple.hpp \
                                $(containers_incdir)/triple.tpp

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
