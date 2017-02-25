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
///   File: Connection.hpp
///
/// Author: $author$
///   Date: 2/24/2017
///////////////////////////////////////////////////////////////////////
#ifndef _ETIRIS_DB_ODBC_CONNECTION_HPP
#define _ETIRIS_DB_ODBC_CONNECTION_HPP

#include "etiris/db/odbc/Object.hpp"

namespace etiris {
namespace db {
namespace odbc {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Connection: public Object {
public:
    HDBC hdbc;
    HENV henv;
    BOOL disconnect;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Connection() {
        hdbc=SQL_NULL_HDBC;
        henv=SQL_NULL_HENV;
        disconnect=FALSE;
    }
    virtual ~Connection() {
        if (hdbc!=SQL_NULL_HDBC)
            Destroy();
    }
    operator HDBC() {
        return hdbc;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL Create(HENV henv) {
        retcode=SQL_SUCCESS;
        if (henv!=SQL_NULL_HENV)
        if (hdbc==SQL_NULL_HDBC) {
            LOG_DEBUG("SQLAllocConnect(henv,&hdbc)...");
            if ((retcode=SQLAllocConnect(henv,&hdbc))==SQL_SUCCESS) {
                this->henv=henv;
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLAllocConnect(henv,&hdbc)");
            }
        }
        return FALSE;
    }
    BOOL Destroy() {
        retcode=SQL_SUCCESS;
        if (hdbc!=SQL_NULL_HDBC) {
            LOG_DEBUG("SQLFreeConnect(hdbc)...");
            if ((retcode=SQLFreeConnect(hdbc))==SQL_SUCCESS) {
                hdbc=SQL_NULL_HDBC;
                henv=SQL_NULL_HENV;
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLFreeConnect(hdbc)");
            }
        }
        return FALSE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL SetConnectOption(UWORD option,UDWORD param) {
        retcode=SQL_SUCCESS;
        if (hdbc!=SQL_NULL_HDBC) {
            LOG_DEBUG("SQLSetConnectOption(hdbc,option,param)...");
            if ((retcode=SQLSetConnectOption(hdbc,option,param))==SQL_SUCCESS) {
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLSetConnectOption(hdbc,option,param)");
            }
        }
        return FALSE;
    }
    BOOL Connect
    (LPCSTR name=NULL,SWORD namelen=-1,
     LPCSTR user=NULL,SWORD userlen=-1,
     LPCSTR password=NULL,SWORD passwordlen=-1) {
        retcode=SQL_SUCCESS;
        namelen = (namelen>=0)?namelen:(name!=NULL)?strlen(name):0;
        userlen = (userlen>=0)?userlen:(user!=NULL)?strlen(user):0;
        passwordlen = (passwordlen>=0)?passwordlen:(password!=NULL)?strlen(password):0;
        if (!disconnect)
        if (hdbc!=SQL_NULL_HDBC) {
            LOG_DEBUG("SQLConnect(hdbc,(UCHAR*)name,namelen,UCHAR*)user,userlen,(UCHAR*)password,passwordlen)...");
            if ((retcode=SQLConnect
                (hdbc,(UCHAR*)name,namelen,
                 (UCHAR*)user,userlen,
                 (UCHAR*)password,passwordlen))==SQL_SUCCESS) {
                return disconnect=TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLConnect(hdbc,(UCHAR*)name,namelen,UCHAR*)user,userlen,(UCHAR*)password,passwordlen)");
            }
        }
        return FALSE;
    }
    BOOL Disconnect() {
        retcode=SQL_SUCCESS;
        if (disconnect)
        if (hdbc!=SQL_NULL_HDBC) {
            LOG_DEBUG("SQLDisconnect(hdbc)...");
            if ((retcode=SQLDisconnect(hdbc))==SQL_SUCCESS) {
                disconnect=FALSE;
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLDisconnect(hdbc)");
            }
        }
        return FALSE;
    }
};

} // namespace odbc
} // namespace db 
} // namespace etiris 

#endif // _ETIRIS_DB_ODBC_CONNECTION_HPP 
