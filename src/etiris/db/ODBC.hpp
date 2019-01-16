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
///   File: ODBC.hpp
///
/// Author: $author$
///   Date: 2/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _ETIRIS_DB_ODBC_ODBC_HPP
#define _ETIRIS_DB_ODBC_ODBC_HPP

#if defined(NO_USE_NADIR_BASE)
#include "xos/base/platform_build.hpp"
#else // defined(NO_USE_NADIR_BASE)
#include "nadir/platform/platform_build.h"
#endif // defined(NO_USE_NADIR_BASE)

#if defined(WINDOWS)
#include "etiris/base/Base.hpp"
#endif // defined(WINDOWS)

#include <sql.h>
#include <sqlext.h>

#if !defined(WINDOWS)
#define BOOL ETIRIS_BOOL
#define WCHAR ETIRIS_WCHAR
#define ULONG ETIRIS_ULONG
#define PWSTR ETIRIS_PWSTR
#define PCWSTR ETIRIS_PCWSTR
#define LPWSTR ETIRIS_LPWSTR
#define LPCWSTR ETIRIS_LPCWSTR
#include "etiris/base/Base.hpp"
#undef WCHAR
#undef ULONG
#undef PWSTR
#undef PCWSTR
#undef LPWSTR
#undef LPCWSTR
#endif // !defined(WINDOWS)

#ifndef _ETIRIS_DB_ODBC_OBJECT_HPP
#include "etiris/db/odbc/Object.hpp"
#include "etiris/db/odbc/Environment.hpp"
#include "etiris/db/odbc/Connection.hpp"
#include "etiris/db/odbc/Query.hpp"
#endif // _ETIRIS_DB_ODBC_OBJECT_HPP

/*/
///////////////////////////////////////////////////////////////////////
You can use the following list of functions in Jet queries when Sandbox mode is enabled. Any functions that do not appear in the list are not available in Sandbox mode.
ABS	array	ASC	ASCB	ASCW	ATN
CBOOL	CBYTE	CCUR	CDATE	CDBL	choose
CHR	CHR$	CHRB	CHRB$	CHRW	CHRW$
CINT	CLNG	COS	CSNG	CSTR	CVAR
CvDate	CVErr	date	DATE$	DATEADD	dateDiff
datePart	DATESERIAL	DATEVALUE	day	DDB	error
error$	EXP	fix	format	format$	fv
hex	hex$	HOUR	IIF	IMEStatus	inStr
INT	IPMT	IRR	isDate	isEmpty	ISERROR
isNull	isNumeric	isObject	lCase	lCase$	LEFT
LEFT$	LEFTB	LEFTB$	LEN	LENB	LOG
lTrim	lTrim$	MID	MID$	MIDB	MIDB$
MINUTE	MIRR	MONTH	NOW	NPER	NPV
oct	oct$	partition	PMT	PPMT	PV
QBColor	RATE	RGB	RIGHT	RIGHT$	RIGHTB
RIGHTB$	rnd	round	rTrim	rTrim$	SECOND
sgn	SIN	SLN	space	space$	sqr
str	str$	strComp	strConv	string	string$
switch	SYD	TAN	TIME	TIME$	timer
timeSerial	TIMEVALUE	TRIM	TRIM$	typeName	uCase
uCase$	val	varType	WEEKDAY	YEAR
///////////////////////////////////////////////////////////////////////
/*/

namespace etiris {
namespace db {
namespace odbc {

typedef char_arrayt<CHAR> CHAR_array;
typedef char_arrayt<UCHAR> UCHAR_array;

} // namespace odbc
} // namespace db
} // namespace etiris

#endif // _ETIRIS_DB_ODBC_ODBC_HPP
