########################################################################
# Copyright (c) 1988-2017 $organization$
#
# This software is provided by the author and contributors ``as is'' 
# and any express or implied warranties, including, but not limited to, 
# the implied warranties of merchantability and fitness for a particular 
# purpose are disclaimed. In no event shall the author or contributors 
# be liable for any direct, indirect, incidental, special, exemplary, 
# or consequential damages (including, but not limited to, procurement 
# of substitute goods or services; loss of use, data, or profits; or 
# business interruption) however caused and on any theory of liability, 
# whether in contract, strict liability, or tort (including negligence 
# or otherwise) arising in any way out of the use of this software, 
# even if advised of the possibility of such damage.
#
#   File: ODBCpp.pri
#
# Author: $author$
#   Date: 2/20/2017
########################################################################
ODBCPP_PKG = ../../../../..
ODBCPP_BLD = ../..

ODBCPP_PRJ = $${ODBCPP_PKG}
ODBCPP_BIN = $${ODBCPP_BLD}/bin
ODBCPP_LIB = $${ODBCPP_BLD}/lib
ODBCPP_SRC = $${ODBCPP_PKG}/src

CONFIG(debug, debug|release) {
BUILD_CONFIG = Debug
DEFINES += DEBUG_BUILD
} else {
BUILD_CONFIG = Release
DEFINES += RELEASE_BUILD
}

########################################################################
# nadir
NADIR_PKG = $${ODBCPP_PKG}/../nadir
NADIR_PRJ = $${NADIR_PKG}
NADIR_SRC = $${NADIR_PKG}/src

nadir_INCLUDEPATH += \
$${NADIR_SRC} \

nadir_DEFINES += \

nadir_LIBS += \

########################################################################
ODBCpp_INCLUDEPATH += \
$${ODBCPP_SRC} \
$${nadir_INCLUDEPATH} \

ODBCpp_DEFINES += \

########################################################################
ODBCpp_HEADERS += \

ODBCpp_SOURCES += \

########################################################################
ODBCpp_LIBS += \
-L$${ODBCPP_LIB}/libODBCpp \
-lodbcpp \
