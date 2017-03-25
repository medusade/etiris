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
    enum { DataSize = 1024 };

    main()
    : sourceChars("DataSource"),
      tableChars("DataTable"),
      selectChars("*"),
      whereChars(0),
      queryChars("select * from DataTable") {
    }

    const char *sourceChars, *tableChars, *selectChars, *whereChars, *queryChars;
    nadir::char_string queryString;

    Environment environment;
    Connection connection;
    Query query;

    char statement[DataSize];
    char error[DataSize];
    SWORD errorlen;
    SDWORD errornum;

    char label[DataSize];
    SWORD labellen;
    SDWORD numinfo;

    char data[DataSize];
    SDWORD datalen;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    BOOL Success(BOOL success) {
        if (!success) {
            if ((environment.Error(connection, query, statement, errornum, error, DataSize-1, errorlen))) {
                printf("...Error statement = \"%s\" error = \"%s\"\n", statement, error);
                LOG_ERROR("...Error statement = \"" << statement << "\" error = \"" << error << "\" where source = \"" << sourceChars << "\" table = \"" << tableChars << "\" query = \"" << queryChars << "\"");
            } else {
                LOG_ERROR("...failed on environment.Error(connection, query, statement, errornum, error, DataSize-1, errorlen) where source = \"" << sourceChars << "\" table = \"" << tableChars << "\" query = \"" << queryChars << "\"");
            }
        }
        return success;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run(int argc, char** argv, char **env) {
        int err = 1;

        if ((1 < argc) && (argv[1][0])) {
            sourceChars = argv[1];
            queryChars = 0;
        }

        if ((2 < argc) && (argv[2][0])) {
            tableChars = argv[2];
            queryChars = 0;
        }

        if ((3 < argc) && (argv[3][0])) {
            queryChars = argv[3];
        }

        if (!(queryChars)) {
            queryString.assignl("select ", selectChars, " from ", tableChars, NULL);
            if ((whereChars)) {
                queryString.appendl(" where ", whereChars, NULL);
            }
            queryChars = queryString.chars();
        }

        if ((environment.Create())) {

            if ((connection.Create(environment))) {

                connection.SetConnectOption(SQL_ACCESS_MODE,SQL_MODE_READ_WRITE);

                if (Success(connection.Connect(sourceChars))) {

                    if (Success(query.Create(connection))) {

                        err = run_query(argc, argv, env);
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

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_query(int argc, char** argv, char **env) {
        int err = 1;
        err = run_query_table(argc, argv, env);
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_query_table(int argc, char** argv, char **env) {
        int err = 1;
        UCHAR_array table((const UCHAR*)tableChars, chars_t::count(tableChars));
        if (Success(query.TableColumns(table.elements(), table.length()))) {
            err = run_query_results(argc, argv, env);
        }
        return err;
    }
    virtual int run_query_execute(int argc, char** argv, char **env) {
        int err = 1;
        if (Success(query.Execute(queryChars))) {
            err = run_query_results(argc, argv, env);
        }
        return err;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual int run_query_results(int argc, char** argv, char **env) {
        int err = 1;
        err = run_query_results_html(argc, argv, env);
        return err;
    }
    virtual int run_query_results_html(int argc, char** argv, char **env) {
        int err = 1;
        int i = 0, cols = 0;
        printf("<html><body><table border=\"1\">\n");
        if ((cols=query.Columns())>0) {

            printf("<tc>");
            for (i=1; i<=cols; i++) {
                if (query.ColumnInfo(i,SQL_COLUMN_LABEL,label,DataSize,labellen,numinfo)) {
                    printf("<td><b>");
                    printf("%s",label);
                    printf("</b></td>");
                }
            }
            printf("</tc>");
            printf("\n");

            while ((query.Fetch())) {
                printf("<tr>");
                for (i=1; i<=cols; i++) {
                    if (query.ColumnInfo(i,SQL_COLUMN_DISPLAY_SIZE,label,DataSize,labellen,numinfo)) {
                        printf("<td>");
                        if (0 < (numinfo)) {
                            memset(data, DataSize, 0);
                            if ((query.GetData(i,SQL_C_CHAR,data,DataSize-1,datalen))) {
                                printf("%s", data);
                            }
                        } else {
                            printf("...");
                        }
                        printf("</td>");
                    }
                }
                printf("</tr>");
                printf("\n");
            }
        }
        printf("</table></body></html>\n");
        return err;
    }
    virtual int run_query_results_text(int argc, char** argv, char **env) {
        int err = 1;
        int i = 0, cols = 0;

        if ((cols=query.Columns())>0) {

            for (i=1; i<=cols; i++) {
                if (query.ColumnInfo(i,SQL_COLUMN_LABEL,label,DataSize,labellen,numinfo)) {
                    printf("%s , ",label);
                }
            }
            printf("\n");

            while ((query.Fetch())) {
                for (i=1; i<=cols; i++) {
                    if (query.ColumnInfo(i,SQL_COLUMN_DISPLAY_SIZE,label,DataSize,labellen,numinfo)) {
                        if (0 < (numinfo)) {
                            memset(data, DataSize, 0);
                            if ((query.GetData(i,SQL_C_CHAR,data,DataSize-1,datalen))) {
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
        return err;
    }
};

} // namespace odbc
} // namespace db 
} // namespace etiris 

#endif // _ETIRIS_DB_ODBC_MAIN_HPP 
