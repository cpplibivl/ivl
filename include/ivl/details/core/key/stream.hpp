/* This file is part of the ivl C++ library <http://image.ntua.gr/ivl>.
   A C++ template library extending syntax towards mathematical notation.

   Copyright (C) 2012 Yannis Avrithis <iavr@image.ntua.gr>
   Copyright (C) 2012 Kimon Kontosis <kimonas@image.ntua.gr>

   ivl is free software; you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License
   version 3 as published by the Free Software Foundation.

   Alternatively, you can redistribute it and/or modify it under the terms
   of the GNU General Public License version 2 as published by the Free
   Software Foundation.

   ivl is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
   See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   and a copy of the GNU Lesser General Public License along
   with ivl. If not, see <http://www.gnu.org/licenses/>. */

//-----------------------------------------------------------------------------

#ifndef IVL_CORE_DETAILS_KEY_STREAM_HPP
#define IVL_CORE_DETAILS_KEY_STREAM_HPP

//-----------------------------------------------------------------------------

namespace ivl {

//-----------------------------------------------------------------------------

namespace keys {
namespace details {

//-----------------------------------------------------------------------------

template <typename S, typename K, typename T>
typename enable_if <is_group <K>, S&>::type
inline operator<<(S& s, const mod <K, off <T> >& v)
{
	return +(+ivl::off)[s] << ~*v,  s;
}

//-----------------------------------------------------------------------------

using ivl::operator<<;

//-----------------------------------------------------------------------------

}  // namespace details
}  // namespace keys

//-----------------------------------------------------------------------------

}  // namespace ivl

//-----------------------------------------------------------------------------

#endif  // IVL_CORE_DETAILS_KEY_STREAM_HPP
