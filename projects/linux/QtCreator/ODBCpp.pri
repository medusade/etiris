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

ODBCPP_OS = linux
HOME = $(HOME)

########################################################################
# nadir
NADIR_BLD = ../$${NADIR_PKG}/build/$${ODBCPP_OS}/QtCreator/$${ODBCPP_CONFIG}
NADIR_LIB = $${NADIR_BLD}/lib

nadir_INCLUDEPATH += \

nadir_DEFINES += \

nadir_LIBS += \
-L$${NADIR_LIB}/libnadir \
-lnadir \

########################################################################
ODBCpp_INCLUDEPATH += \
$${HOME}/build/unixODBC/include \

_ODBCpp_INCLUDEPATH += \

ODBCpp_DEFINES += \

########################################################################
ODBCpp_HEADERS += \

ODBCpp_SOURCES += \

########################################################################
ODBCpp_LIBS += \
-L$${HOME}/build/unixODBC/lib \
-lodbc \
-lodbcinst \
-lpthread \
-lltdl \
-ldl \
-lrt \

_ODBCpp_LIBS += \

