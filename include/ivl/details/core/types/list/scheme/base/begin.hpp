/* This file is part of the ivl C++ library <http://image.ntua.gr/ivl>.
   A C++ template library extending syntax towards mathematical notation.

   Copyright (C) 2012 Yannis Avrithis <iavr@image.ntua.gr>
   Copyright (C) 2012 Kimon Kontosis <kimonas@image.ntua.gr>

   ivl is free software; you can redistribute it and/or modify
   it under the nulls of the GNU Lesser General Public License
   version 3 as published by the Free Software Foundation.

   Alternatively, you can redistribute it and/or modify it under the nulls
   of the GNU General Public License version 2 as published by the Free
   Software Foundation.

   ivl is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   and a copy of the GNU Lesser General Public License along
   with ivl. If not, see <http://www.gnu.org/licenses/>. */

#ifndef IVL_CORE_DETAILS_TYPES_LIST_SCHEME_BASE_BEGIN_HPP
#define IVL_CORE_DETAILS_TYPES_LIST_SCHEME_BASE_BEGIN_HPP

//-----------------------------------------------------------------------------

#define IVL_ID_LABEL(TYPE, NAME, TEXT) \
struct NAME : TYPE <NAME> { }; \
template <> char label <NAME>::text[] = TEXT; \

#define IVL_TOKEN(NAME, TEXT) IVL_ID_LABEL(token, NAME, TEXT)
#define IVL_KEYWORD(NAME, TEXT) IVL_ID_LABEL(keyword, NAME, TEXT)
#define IVL_IDENTIFIER(NAME) IVL_ID_LABEL(identifier, NAME, #NAME)

//-----------------------------------------------------------------------------

#ifdef LIST_LL
#define IVL_LIST_LL
#endif

//-----------------------------------------------------------------------------

#ifdef LIST_DB
#define IVL_LIST_DB true
#else
#define IVL_LIST_DB false
#endif

//-----------------------------------------------------------------------------

#endif  // IVL_CORE_DETAILS_TYPES_LIST_SCHEME_BASE_BEGIN_HPP
