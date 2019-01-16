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
#   File: etiris.pri
#
# Author: $author$
#   Date: 1/13/2019
#
# QtCreator .pri file for etiris executable etiris
########################################################################

########################################################################
# etiris

# etiris_exe TARGET
#
etiris_exe_TARGET = etiris

# etiris_exe INCLUDEPATH
#
etiris_exe_INCLUDEPATH += \
$${etiris_INCLUDEPATH} \

# etiris_exe DEFINES
#
etiris_exe_DEFINES += \
$${etiris_DEFINES} \

########################################################################
# etiris_exe OBJECTIVE_HEADERS
#
#etiris_exe_OBJECTIVE_HEADERS += \
#$${ETIRIS_SRC}/etiris/base/Base.hh \

# etiris_exe OBJECTIVE_SOURCES
#
#etiris_exe_OBJECTIVE_SOURCES += \
#$${ETIRIS_SRC}/etiris/base/Base.mm \

########################################################################
# etiris_exe HEADERS
#
#etiris_exe_HEADERS += \
#$${ETIRIS_SRC}/etiris/base/Base.hpp \

# etiris_exe SOURCES
#
#etiris_exe_SOURCES += \
#$${ETIRIS_SRC}/etiris/base/Base.cpp \

########################################################################
# etiris_exe FRAMEWORKS
#
etiris_exe_FRAMEWORKS += \
$${etiris_FRAMEWORKS} \

# etiris_exe LIBS
#
etiris_exe_LIBS += \
$${etiris_LIBS} \


