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

#ifndef IVL_CORE_DETAILS_MATRIX_BASED_HPP
#define IVL_CORE_DETAILS_MATRIX_BASED_HPP

namespace ivl {

namespace core_details {

template<class T>
struct matrix_based
{
	T t;
	typedef typename types::bare_type<T>::type B;
	typedef typename types::bare_type<T>::type base_class;
	typedef typename types::bare_type<T>::type::elem_type elem_type;
	matrix_based(const typename types::bare_type<T>::type& x) : t(x) { }

	typename types::bare_type<T>::type& base() { return t; }
	const typename types::bare_type<T>::type& base() const { return t; }

	// awful
	template<class U>
	typename B::create_new operator*(const U& u) const
	{
		return mtimes(t, u);
	}

	template<class U>
	matrix_based<typename B::create_new> operator*(const matrix_based<U>& u) const
	{
		return mtimes(t, u.t);
	}
	
	//
	//
	typename B::create_new operator!() const
	{
		return transpose(t);
	}
	
};

} /* namespace core_details */

} /* namespace ivl */

#endif // IVL_CORE_DETAILS_MATRIX_BASED_HPP
