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

#include <ivl/ivl>
#include "../list_begin.hpp"

//-----------------------------------------------------------------------------

int main()
{
	using namespace std;
	using namespace ivl;
	using namespace vocabulary;
	using namespace types::scheme;

	using ivl::types::_;

	cout << wrap << endl << title <<
		"null? - test whether a list is empty"
	<< endl;

	cout << endl <<
		syntax << "b = (null? l)" << body
		<< " returns true if list l is empty, and false otherwise. E.g."
	<< endl << indent << sample << endl;

//-----------------------------------------------------------------------------

	{
		cout << "(null? ()) = " << _<null, _<> > () << endl << endl;

		typedef _<a, b, c> l;

		cout << "l = " << l() << endl;
		cout << "(null? l) = " << _<null, l> () << endl;
	}

//-----------------------------------------------------------------------------

	cout << !indent << body << endl <<
		"The result is not defined if l is not a list:"
	<< endl << indent << sample << endl;

//-----------------------------------------------------------------------------

	{
		cout << "(null? spaghetti) = " << _<null, spaghetti> () << endl;
	}

//-----------------------------------------------------------------------------

	cout << !indent << body << endl <<
		"See also zero? atom? car, cdr, cons."
	<< endl << endl;
}

//-----------------------------------------------------------------------------

#include "../list_end.hpp"
