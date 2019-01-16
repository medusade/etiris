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
///   File: Query.hpp
///
/// Author: $author$
///   Date: 2/24/2017
///////////////////////////////////////////////////////////////////////
#ifndef _ETIRIS_DB_ODBC_QUERY_HPP
#define _ETIRIS_DB_ODBC_QUERY_HPP

#include "etiris/db/odbc/Object.hpp"
#include "etiris/io/Logger.hpp"

namespace etiris {
namespace db {
namespace odbc {

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS Query: public Object {
public:
    HSTMT hstmt;
    HDBC hdbc;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    Query() {
        hstmt=SQL_NULL_HSTMT;
        hdbc=SQL_NULL_HDBC;
    }
    virtual ~Query() {
        if (hstmt!=SQL_NULL_HSTMT)
            Destroy();
    }
    operator HSTMT() {
        return hstmt;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL Create(HDBC hdbc) {
        retcode=SQL_SUCCESS;
        if (hstmt==SQL_NULL_HSTMT)
        if (hdbc!=SQL_NULL_HDBC) {
            LOG_DEBUG("SQLAllocStmt(hdbc,&hstmt)...");
            if ((retcode=SQLAllocStmt(hdbc,&hstmt))==SQL_SUCCESS) {
                this->hdbc=hdbc;
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLAllocStmt(hdbc,&hstmt)");
            }
        }
        return FALSE;
    }
    BOOL Destroy() {
        retcode=SQL_SUCCESS;
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLFreeStmt(hstmt,SQL_DROP)...");
            if ((retcode=SQLFreeStmt(hstmt,SQL_DROP))==SQL_SUCCESS) {
                hstmt=SQL_NULL_HSTMT;
                hdbc=SQL_NULL_HDBC;
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLFreeStmt(hstmt,SQL_DROP)");
            }
        }
        return FALSE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL Execute(const char *statement,int len=-1) {
        retcode=SQL_SUCCESS;
        if (statement!=NULL)
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLExecDirect(hstmt,(UCHAR*)statement,len)...");
            if ((retcode=SQLExecDirect
                (hstmt,(UCHAR*)statement,
                (len<0)?strlen(statement):len))==SQL_SUCCESS) {
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLExecDirect(hstmt,(UCHAR*)statement,len)");
            }
        }
        return FALSE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    LONG Columns() {
        SWORD cols = 0;
        retcode=SQL_SUCCESS;
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLNumResultCols(hstmt,&cols)...");
            if ((retcode=SQLNumResultCols(hstmt,&cols))==SQL_SUCCESS) {
                return cols;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLNumResultCols(hstmt,&cols)");
            }
        }
        return -1;
    }
    BOOL ColumnInfo
    (UWORD index,UWORD infotype,PTR info,
     SWORD infomax,SWORD &infosize,SDWORD &numinfo) {
        SQLLEN _numinfo = numinfo;
        retcode=SQL_SUCCESS;
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLColAttributes(hstmt,index,infotype,info,infomax,&infosize,&_numinfo)...");
            if ((retcode=SQLColAttributes
                (hstmt,index,infotype,info,
                 infomax,&infosize,&_numinfo))==SQL_SUCCESS) {
                numinfo = _numinfo;
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLColAttributes(hstmt,index,infotype,info,infomax,&infosize,&_numinfo)");
            }
        }
        return FALSE;
    }
    BOOL TableColumns
    (UCHAR* szTableName, USHORT cbTableName,
     UCHAR* szColumnName = NULL, USHORT cbColumnName = 0) {
        UCHAR* szCatalogName = NULL; USHORT cbCatalogName = 0;
        UCHAR* szSchemaName = NULL; USHORT cbSchemaName = 0;
        return Columns
        (szCatalogName, cbCatalogName, szSchemaName, cbSchemaName,
         szTableName, cbTableName, szColumnName, cbColumnName);
    }
    /*/
    SQLRETURN   SQLColumns
    (SQLHSTMT          hstmt,          //
     SQLCHAR     FAR   *szCatalogName, // catalog name result set qualifier
     SQLSMALLINT       cbCatalogName,  //
     SQLCHAR     FAR   *szSchemaName,  // schema name result set qualifier
     SQLSMALLINT       cbSchemaName,   //
     SQLCHAR     FAR   *szTableName,   // table name result set qualifier
     SQLSMALLINT       cbTableName,    //
     SQLCHAR     FAR   *szColumnName,  // column name result set qualifier
     SQLSMALLINT       cbColumnName);  //
    /*/
    BOOL Columns
    (UCHAR* szCatalogName, USHORT cbCatalogName,
     UCHAR* szSchemaName, USHORT cbSchemaName,
     UCHAR* szTableName, USHORT cbTableName,
     UCHAR* szColumnName, USHORT cbColumnName) {
        retcode = SQL_SUCCESS;
        if (hstmt != SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLColumns(hstmt, ...)...");
            if ((retcode = SQLColumns
                 (hstmt, szCatalogName, cbCatalogName, szSchemaName, cbSchemaName,
                  szTableName, cbTableName, szColumnName, cbColumnName)) == SQL_SUCCESS) {
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLColumns(hstmt, ...)");
            }
        }
        return FALSE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL GetData
    (UWORD index,UWORD datatype,PTR data,
     SDWORD datamax,SDWORD &datasize) {
        SQLLEN _datasize = datasize;
        retcode=SQL_SUCCESS;
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLGetData(hstmt,index,datatype,data,datamax,&_datasize)...");
            if ((retcode=SQLGetData
                (hstmt,index,datatype,data,
                 datamax,&_datasize))==SQL_SUCCESS) {
                datasize = _datasize;
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLGetData(hstmt,index,datatype,data,datamax,&_datasize)");
            }
        }
        return FALSE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL BindColumn
    (UWORD index,UWORD datatype,PTR data,
     SDWORD datamax,SDWORD &datasize) {
        SQLLEN _datasize = datasize;
        retcode=SQL_SUCCESS;
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLBindCol(hstmt,index,datatype,data,datamax,&_datasize)...");
            if ((retcode=SQLBindCol
                (hstmt,index,datatype,data,
                 datamax,&_datasize))==SQL_SUCCESS) {
                datasize = _datasize;
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLBindCol(hstmt,index,datatype,data,datamax,&_datasize)");
            }
        }
        return FALSE;
    }
    BOOL UnbindColumns() {
        retcode=SQL_SUCCESS;
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLFreeStmt(hstmt,SQL_UNBIND)...");
            if ((retcode=SQLFreeStmt(hstmt,SQL_UNBIND))==SQL_SUCCESS) {
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLFreeStmt(hstmt,SQL_UNBIND)");
            }
        }
        return FALSE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL Fetch() {
        retcode=SQL_SUCCESS;
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLFetch(hstmt)...");
            if ((retcode=SQLFetch(hstmt))==SQL_SUCCESS) {
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLFetch(hstmt)");
            }
        }
        return FALSE;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL SetPos(UWORD row,UWORD option=SQL_POSITION,UWORD lock=SQL_LOCK_NO_CHANGE) {
        retcode=SQL_SUCCESS;
        if (hstmt!=SQL_NULL_HSTMT) {
            LOG_DEBUG("SQLSetPos(hstmt,row,option,lock)...");
            if ((retcode=SQLSetPos(hstmt,row,option,lock))==SQL_SUCCESS) {
                return TRUE;
            } else {
                LOG_ERROR("...failed " << retcode << " on SQLSetPos(hstmt,row,option,lock)");
            }
        }
        return FALSE;
    }
};

} // namespace odbc
} // namespace db 
} // namespace etiris 

#endif // _ETIRIS_DB_ODBC_QUERY_HPP 
