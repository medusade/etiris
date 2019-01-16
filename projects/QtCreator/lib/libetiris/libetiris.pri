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
#   File: libetiris.pri
#
# Author: $author$
#   Date: 1/13/2019
#
# QtCreator .pri file for etiris library libetiris
########################################################################

########################################################################
# libetiris

# libetiris TARGET
#
libetiris_TARGET = etiris
libetiris_TEMPLATE = lib
libetiris_CONFIG += staticlib

# libetiris INCLUDEPATH
#
libetiris_INCLUDEPATH += \
$${etiris_INCLUDEPATH} \

# libetiris DEFINES
#
libetiris_DEFINES += \
$${etiris_DEFINES} \

########################################################################
# libetiris OBJECTIVE_HEADERS
#
#libetiris_OBJECTIVE_HEADERS += \
#$${ETIRIS_SRC}/etiris/base/Base.hh \

# libetiris OBJECTIVE_SOURCES
#
#libetiris_OBJECTIVE_SOURCES += \
#$${ETIRIS_SRC}/etiris/base/Base.mm \

########################################################################
# libetiris HEADERS
#
libetiris_HEADERS += \
$${ETIRIS_SRC}/etiris/base/Base.hpp \
$${ETIRIS_SRC}/etiris/io/Logger.hpp \

# libetiris SOURCES
#
libetiris_SOURCES += \
$${ETIRIS_SRC}/etiris/base/Base.cpp \
$${ETIRIS_SRC}/etiris/io/Logger.cpp \

########################################################################
