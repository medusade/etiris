########################################################################
# Copyright (c) 1988-2019 $organization$
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
#   File: odbcpp.pri
#
# Author: $author$
#   Date: 1/13/2019
#
# QtCreator .pri file for etiris executable odbcpp
########################################################################

########################################################################
# odbcpp

# odbcpp TARGET
#
odbcpp_TARGET = odbcpp

# odbcpp INCLUDEPATH
#
odbcpp_INCLUDEPATH += \
$${etiris_INCLUDEPATH} \

# odbcpp DEFINES
#
odbcpp_DEFINES += \
$${etiris_DEFINES} \

########################################################################
# odbcpp OBJECTIVE_HEADERS
#
#odbcpp_OBJECTIVE_HEADERS += \
#$${ETIRIS_SRC}/etiris/base/Base.hh \

# odbcpp OBJECTIVE_SOURCES
#
#odbcpp_OBJECTIVE_SOURCES += \
#$${ETIRIS_SRC}/etiris/base/Base.mm \

########################################################################
# odbcpp HEADERS
#
odbcpp_HEADERS += \
$${ETIRIS_SRC}/etiris/base/Base.hpp \
$${ETIRIS_SRC}/etiris/io/Logger.hpp \
$${ETIRIS_SRC}/etiris/db/odbc/Main.hpp \
$${ETIRIS_SRC}/etiris/db/odbc/Query.hpp \
$${ETIRIS_SRC}/etiris/db/odbc/Connection.hpp \
$${ETIRIS_SRC}/etiris/db/odbc/Environment.hpp \
$${ETIRIS_SRC}/etiris/db/odbc/Object.hpp \
$${ETIRIS_SRC}/etiris/db/ODBC.hpp \

# odbcpp SOURCES
#
_odbcpp_SOURCES += \

odbcpp_SOURCES += \
$${ETIRIS_SRC}/etiris/db/odbc/Main.cpp \
$${ETIRIS_SRC}/etiris/db/odbc/Object.cpp \
$${ETIRIS_SRC}/etiris/db/odbc/Query.cpp \
$${ETIRIS_SRC}/etiris/db/odbc/Connection.cpp \
$${ETIRIS_SRC}/etiris/db/odbc/Environment.cpp \
$${ETIRIS_SRC}/etiris/db/ODBC.cpp \

########################################################################
# odbcpp FRAMEWORKS
#
odbcpp_FRAMEWORKS += \
$${etiris_FRAMEWORKS} \

# odbcpp LIBS
#
odbcpp_LIBS += \
$${etiris_LIBS} \


