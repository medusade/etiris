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
TARGET = odbcpp

########################################################################
INCLUDEPATH += \
$${ODBCpp_INCLUDEPATH} \

DEFINES += \
$${ODBCpp_DEFINES} \

########################################################################
HEADERS += \
$${NADIR_SRC}/nadir/console/logger.hpp \

SOURCES += \
$${NADIR_SRC}/nadir/console/logger.cpp \

########################################################################
HEADERS += \
$${ODBCPP_SRC}/etiris/db/odbc/Main.hpp \
$${ODBCPP_SRC}/etiris/db/odbc/Query.hpp \
$${ODBCPP_SRC}/etiris/db/odbc/Connection.hpp \
$${ODBCPP_SRC}/etiris/db/odbc/Environment.hpp \
$${ODBCPP_SRC}/etiris/db/odbc/Object.hpp \
$${ODBCPP_SRC}/etiris/db/ODBC.hpp \

SOURCES += \
$${ODBCPP_SRC}/etiris/db/odbc/Main.cpp \
$${ODBCPP_SRC}/etiris/db/odbc/Object.cpp \
$${ODBCPP_SRC}/etiris/db/odbc/Query.cpp \
$${ODBCPP_SRC}/etiris/db/odbc/Connection.cpp \
$${ODBCPP_SRC}/etiris/db/odbc/Environment.cpp \
$${ODBCPP_SRC}/etiris/db/ODBC.cpp \

########################################################################
HEADERS += \

SOURCES += \

########################################################################
LIBS += \
$${ODBCpp_LIBS} \
