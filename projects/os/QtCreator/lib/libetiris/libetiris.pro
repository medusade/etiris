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
#   File: libetiris.pro
#
# Author: $author$
#   Date: 1/13/2019
#
# QtCreator .pro file for etiris library libetiris
########################################################################
include(../../../../../build/QtCreator/etiris.pri)
include(../../../../QtCreator/etiris.pri)
include(../../etiris.pri)
include(../../../../QtCreator/lib/libetiris/libetiris.pri)

TARGET = $${libetiris_TARGET}
TEMPLATE = $${libetiris_TEMPLATE}
CONFIG += $${libetiris_CONFIG}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${libetiris_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${libetiris_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${libetiris_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${libetiris_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${libetiris_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${libetiris_SOURCES} \

########################################################################


