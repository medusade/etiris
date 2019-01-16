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
# build QtCreator .pri file for etiris
########################################################################
USER = jboyd
UNAME = $$system(uname)

contains(UNAME,Darwin) {
ETIRIS_OS = macosx
HOME = /Users/$${USER}
} else {
ETIRIS_OS = linux
HOME = /home/$${USER}
}

########################################################################
# odbcpp
#
# pkg-config --cflags --libs odbcpp
#

# build odbcpp INCLUDEPATH
#
build_odbcpp_INCLUDEPATH += \
$${HOME}/build/unixODBC/include \

# build odbcpp DEFINES
#
build_odbcpp_DEFINES += \

# build odbcpp FRAMEWORKS
#
build_odbcpp_FRAMEWORKS += \

# build odbcpp LIBS
#
build_odbcpp_LIBS += \
-L$${HOME}/build/unixODBC/lib \
-lodbc \
-lodbcinst \
-L${HOME}/build/libiconv \
-liconv \

########################################################################
# nadir
#
# pkg-config --cflags --libs nadir
#

# build nadir INCLUDEPATH
#
build_nadir_INCLUDEPATH += \

# build nadir DEFINES
#
build_nadir_DEFINES += \

# build nadir FRAMEWORKS
#
build_nadir_FRAMEWORKS += \

# build nadir LIBS
#
build_nadir_LIBS += \

########################################################################
# etiris

# build etiris INCLUDEPATH
#
build_etiris_INCLUDEPATH += \
$${build_nadir_INCLUDEPATH} \
$${build_odbcpp_INCLUDEPATH} \


# build etiris DEFINES
#
build_etiris_DEFINES += \
$${build_odbcpp_DEFINES} \
$${build_nadir_DEFINES} \


# build etiris FRAMEWORKS
#
build_etiris_FRAMEWORKS += \
$${build_nadir_FRAMEWORKS} \
$${build_odbcpp_FRAMEWORKS} \


# build etiris LIBS
#
build_etiris_LIBS += \
$${build_nadir_LIBS} \
$${build_odbcpp_LIBS} \

