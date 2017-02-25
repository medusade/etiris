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
///   File: Main.hpp
///
/// Author: $author$
///   Date: 2/24/2017
///////////////////////////////////////////////////////////////////////
#ifndef _ETIRIS_DB_ODBC_MAIN_HPP
#define _ETIRIS_DB_ODBC_MAIN_HPP

#include "etiris/db/ODBC.hpp"
#include "nadir/console/getopt/main.hpp"

namespace etiris {
namespace db {
namespace odbc {

typedef nadir::console::getopt::main main_extends;
///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS main: public main_extends {
public:
    Environment environment;
    Connection connection;
    Query query;

    char statement[1024];
    char error[1024];
    SWORD errorlen;
    SDWORD errornum;

    char label[1024];
    SWORD labellen;
    SDWORD numinfo;

    char data[1024];
    SDWORD datalen;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL Success(BOOL success) {
        if (!success) {
            if ((environment.Error(connection, query, statement, errornum, error, 1023, errorlen))) {
                printf("Error statement = \"%s\" error = \"%s\"\n", statement, error);
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char **env) {
        const char *sourceChars = "DataSource",
                   *queryChars = "select * from DataTable";
        int err = 1;
        int i,cols;
        nadir::char_string q;

        if ((1 < argc) && (argv[1][0])) {
            sourceChars = argv[1];
            if (!((2 < argc) && (argv[2][0]))) {
                q.assign("select * from ");
                q.append(sourceChars);
                queryChars = q.chars();
            }
        }

        if ((2 < argc) && (argv[2][0])) {
            queryChars = argv[2];
        }

        if (environment.Create()) {

            if (connection.Create(environment)) {

                connection.SetConnectOption(SQL_ACCESS_MODE,SQL_MODE_READ_WRITE);

                if (connection.Connect(sourceChars)) {

                    if (query.Create(connection)) {

                        if (Success(query.Execute(queryChars))) {

                            if ((cols=query.Columns())>0) {

                                for (i=1; i<=cols; i++) {
                                    if (query.ColumnInfo(i,SQL_COLUMN_LABEL,label,1024,labellen,numinfo)) {
                                        printf("%s , ",label);
                                    }
                                }
                                printf("\n");

                                while ((query.Fetch())) {
                                    for (i=1; i<=cols; i++) {
                                        if (query.ColumnInfo(i,SQL_COLUMN_DISPLAY_SIZE,label,1024,labellen,numinfo)) {
                                            if (0 < (numinfo)) {
                                                memset(data, 1024, 0);
                                                if ((query.GetData(i,SQL_C_CHAR,data,1023,datalen))) {
                                                    printf("%s , ", data);
                                                }
                                            } else {
                                                printf("...");
                                            }
                                        }
                                    }
                                    printf("\n");
                                }
                            }
                        }
                        query.Destroy();
                    }
                    connection.Disconnect();
                }
                connection.Destroy();
            }
            environment.Destroy();
        }
        return err;
    }
};

} // namespace odbc
} // namespace db 
} // namespace etiris 

#endif // _ETIRIS_DB_ODBC_MAIN_HPP 
