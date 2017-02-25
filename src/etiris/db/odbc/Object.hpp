///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2017 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: Object.hpp
///
/// Author: $author$
///   Date: 2/24/2017
///////////////////////////////////////////////////////////////////////
#ifndef _ETIRIS_DB_ODBC_OBJECT_HPP
#define _ETIRIS_DB_ODBC_OBJECT_HPP

#include "etiris/db/ODBC.hpp"

namespace etiris {
namespace db {
namespace odbc {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Object {
public:
    RETCODE retcode;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Object() {
        retcode = SQL_SUCCESS;
    }
    virtual ~Object() {
    }
};

} // namespace odbc
} // namespace db 
} // namespace etiris 

#endif // _ETIRIS_DB_ODBC_OBJECT_HPP 
        

