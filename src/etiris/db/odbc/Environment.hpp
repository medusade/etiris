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
///   File: Environment.hpp
///
/// Author: $author$
///   Date: 2/24/2017
///////////////////////////////////////////////////////////////////////
#ifndef _ETIRIS_DB_ODBC_ENVIRONMENT_HPP
#define _ETIRIS_DB_ODBC_ENVIRONMENT_HPP

#include "etiris/db/odbc/Object.hpp"

namespace etiris {
namespace db {
namespace odbc {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Environment: public Object {
public:
    HENV henv;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Environment() {
        henv = SQL_NULL_HENV;
    }
    virtual ~Environment() {
        if (henv != SQL_NULL_HENV)
            Destroy();
    }
    operator HENV() {
        return henv;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL Create() {
        retcode = SQL_SUCCESS;
        if (henv == SQL_NULL_HENV) {
            LOG_DEBUG("SQLAllocEnv(&henv)...");
            if ((retcode = SQLAllocEnv(&henv)) == SQL_SUCCESS) {
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLAllocEnv(&henv)");
            }
        }
        return FALSE;
    }
    BOOL Destroy() {
        retcode = SQL_SUCCESS;
        if (henv != SQL_NULL_HENV) {
            LOG_DEBUG("SQLFreeEnv(henv)...");
            if ((retcode=SQLFreeEnv(henv)) == SQL_SUCCESS) {
                henv=SQL_NULL_HENV;
                return TRUE;
            } else {
                LOG_ERROR("...fained " << retcode << " on SQLFreeEnv(henv)");
            }
        }
        return FALSE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL Error
    (HDBC hdbc,HSTMT hstmt,
     char *statement,SDWORD &errornum,
     char *error,SWORD errorsize,SWORD &errorlen) {
        retcode = SQL_SUCCESS;
        if (henv != SQL_NULL_HENV) {
            LOG_DEBUG("SQLError(henv,hdbc,hstmt,(UCHAR*)statement,&errornum,(UCHAR*)error,errorsize,&errorlen)...");
            if ((retcode = SQLError
                (henv,hdbc,hstmt,(UCHAR*)statement,
                 &errornum,(UCHAR*)error,errorsize,&errorlen)) == SQL_SUCCESS) {
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLError(henv,hdbc,hstmt,(UCHAR*)statement,&errornum,(UCHAR*)error,errorsize,&errorlen)");
            }
        }
        return FALSE;
    }
};

} // namespace odbc
} // namespace db 
} // namespace etiris 

#endif // _ETIRIS_DB_ODBC_ENVIRONMENT_HPP 
