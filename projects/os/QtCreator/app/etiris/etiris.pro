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
#   File: etiris.pro
#
# Author: $author$
#   Date: 1/13/2019
#
# QtCreator .pro file for etiris executable etiris
########################################################################
include(../../../../../build/QtCreator/etiris.pri)
include(../../../../QtCreator/etiris.pri)
include(../../etiris.pri)
include(../../../../QtCreator/app/etiris/etiris.pri)

TARGET = $${etiris_exe_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${etiris_exe_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${etiris_exe_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${etiris_exe_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${etiris_exe_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${etiris_exe_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${etiris_exe_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${etiris_exe_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${etiris_exe_LIBS} \
$${FRAMEWORKS} \


