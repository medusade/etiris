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
///   File: Base.hpp
///
/// Author: $author$
///   Date: 2/20/2017
///////////////////////////////////////////////////////////////////////
#ifndef _ETIRIS_BASE_BASE_HPP
#define _ETIRIS_BASE_BASE_HPP

#if defined(NO_USE_NADIR_BASE)
#include "xos/base/base.hpp"
#include "xos/base/types.hpp"
#include "xos/base/array.hpp"
#include "xos/base/string.hpp"
#include "xos/base/to_string.hpp"

namespace etiris {

typedef xos::base::implement_base ImplementBase;
typedef xos::base::base Base;

typedef xos::base::chars_t chars_t;
typedef xos::base::tchars_t tchars_t;
typedef xos::base::wchars_t wchars_t;

typedef xos::base::char_array char_array;
typedef xos::base::tchar_array tchar_array;
typedef xos::base::wchar_array wchar_array;

typedef xos::base::string string;
typedef xos::base::tstring tstring;
typedef xos::base::wstring wstring;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <typename TChar, class TExtends = xos::base::stringt<TChar> >
class _EXPORT_CLASS char_stringt: public TExtends {
public:
    typedef TExtends Extends;
    typedef typename Extends::char_t char_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    char_stringt(const char* chars1, const char* chars, ...) {
        this->append(chars1);
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
    }
    char_stringt(const wchar_t* chars1, const wchar_t* chars, ...) {
        this->append(chars1);
        if ((chars)) {
            va_list va;
            va_start(va, chars);
            this->appendv(chars, va);
            va_end(va);
        }
    }
    char_stringt(const char* chars): Extends(chars) {
    }
    char_stringt(const wchar_t* chars): Extends(chars) {
    }
    char_stringt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef char_stringt<char> char_string;
typedef char_stringt<tchar_t> tchar_string;
typedef char_stringt<wchar_t> wchar_string;

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
template <typename TChar, class TExtends = xos::base::arrayt<TChar> >
class _EXPORT_CLASS char_arrayt: public TExtends {
public:
    typedef TExtends Extends;
    typedef typename Extends::what_t what_t;
    typedef typename Extends::size_t size_t;
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    char_arrayt(const what_t* what, size_t length) {
        this->append(what, length);
    }
    char_arrayt() {
    }
    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};

} // namespace etiris

#else // defined(NO_USE_NADIR_BASE)
#include "nadir/base/chars.hpp"
#include "nadir/base/array.hpp"
#include "nadir/io/logger.hpp"

namespace etiris {

typedef nadir::implement_base ImplementBase;
typedef nadir::base Base;

typedef nadir::chars_t chars_t;
typedef nadir::tchars_t tchars_t;
typedef nadir::wchars_t wchars_t;

typedef nadir::char_string string_t;
typedef nadir::tchar_string tstring_t;
typedef nadir::wchar_string wstring_t;

typedef nadir::char_array char_array;
typedef nadir::tchar_array tchar_array;
typedef nadir::wchar_array wchar_array;

} // namespace etiris
#endif // defined(NO_USE_NADIR_BASE)

#endif // _ETIRIS_BASE_BASE_HPP 
