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


//TODO:2013: needs a lot of fixing
/**
 * \brief 1-dimensional %array of type T
 *
 * This class defines an simple one-dimensional %array.
 */
template <class T,
		 T V,
		 class DERIVED_INFO
	     >
class array<T, data::fixed_val_repeat<T, V, DERIVED_INFO> >
	:
	public array_common_base<
		array<T, data::fixed_val_repeat<T, V, DERIVED_INFO> > >
{

private:
	typedef array_common_base<array<T,
		data::fixed_val_repeat<T, V, DERIVED_INFO> > > common_base_class;

	size_t len;

public:
	typedef array this_type;

	typedef this_type this_array_type;

	typedef this_type array_type;

	typedef T elem_type;

	typedef typename common_base_class::base_class base_class;

	//! parameter of resize, in each class of the hierarchy
	typedef size_t size_type;

	//! difference type of iterators
	typedef ptrdiff_t diff_type;

	using base_class::derived;


	void resize(size_t len)
	{
		this->len = len;
	}
	void reset(size_t len)
	{
		this->len = len;
	}

	class const_iterator
	{
		size_t i;
	public:

		// iterator_traits
		typedef std::random_access_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef const value_type* pointer;
		typedef value_type reference;

		const_iterator() { }
		const_iterator(const const_iterator& it) : i(it.i) { }
		const_iterator(size_t i) : i(i) { }

		const_iterator& operator++() { ++i; return *this; }
		const_iterator& operator--() { --i; return *this; }

		const_iterator operator++(int) { return const_iterator(i++); }
		const_iterator operator--(int) { return const_iterator(i++); }

		// random access
		const_iterator operator +(const difference_type i) const
			{ return const_iterator(this->i + i); }
		const_iterator operator -(const difference_type i) const
			{ return const_iterator(this->i - i); }
		const_iterator& operator +=(const difference_type i)
			{ this->i += i; return *this; }
		const_iterator& operator -=(const difference_type i)
			{ this->i -= i; return *this; }

		ptrdiff_t operator-(const const_iterator& o) const
			{ return this->i - o.i; }

		const T operator *() const { return V; }

		const T* operator ->() const { return NULL; }

		const T operator [] (size_t j) const { return V; }

		const_iterator& operator=(const const_iterator& it)
			{ i = it.i; return *this; }

		bool operator==(const const_iterator& it) const { return i == it.i; }
		bool operator!=(const const_iterator& it) const { return i != it.i; }
		bool operator<(const const_iterator& it) const { return (i < it.i); }
		bool operator<=(const const_iterator& it) const { return (i <= it.i); }
		bool operator>(const const_iterator& it) const { return (i > it.i); }
		bool operator>=(const const_iterator& it) const { return (i >= it.i); }

	};

	typedef typename const_iterator::reference const_reference;
	typedef const_iterator best_iterator;
	typedef const_reference best_reference;

	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

	typedef ptrdiff_t iter_border_walker;

	const_iterator begin() const { return const_iterator(0); }
	const_iterator end() const { return const_iterator(len); }
	const_reverse_iterator rbegin() const { return const_iterator(len); }
	const_reverse_iterator rend() const { return const_iterator(0); }

/** @name Size functions
@{*/
	//TODO: explain this better.
	//! Get the length of the element sequence
	size_t length() const { return len; }
	//! Get the size of the array. generic-class function.
	size_type size() const { return length(); }
	//! Get the length of the element sequence
	size_t numel() const { return length(); }
/**@}*/

	iter_border_walker first_to_last() { return this->length() - 1; }
	iter_border_walker begin_to_end() { return this->length(); }

/** @name Element access
 *
 * Access a unique element by specifying the position
 *
@{*/
	//! Returns the const element found at position offset
	T operator[](size_t offset) const {
		CHECK(offset >= 0 && offset < length(), erange);
		return V;
	}
/**@}*/

/** @name Constructors
@{*/
	//! Default constructor
	array() : len(0) { }

	//! Construnct by defining an initial number of elements.
	explicit array(size_t count) : len(count) { }

	//! Construnct by defining an initial number of elements.
	explicit array(int count) : len(count) { }

	//! Construnct by defining an initial number of elements.
	explicit array(long int count) : len(count) { }

	//! This constructor should be unused but has to
	//! be defined for child compatibility.
	array(size_t count, const T& s) : len(count) { }

	//! This constructor should be unused but has to
	//! be defined for child compatibility.
	array(size_t count, const T *ptr) : len(count) { }

	/** \brief Construct array with 1 element */
	template <class J>
	array(const internal::reference_face<J>& s) : len(1) { }

	//! Copy-constructor
	array(const this_type& a) : len(a.len) { }

	//! This constructor should be unused but has to
	//! be defined for child compatibility.
	template <class S>
	array(const array<T, S>& a, size_t n) : len(n) { }

	//! This constructor should be unused but has to
	//! be defined for child compatibility.
	template <class S>
	array(const array<T, S>& a) : len(a.length()) { }

	//! This constructor should be unused but has to
	//! be defined for child compatibility.
	template <class J, class S>
	array(size_t count, const array<J, S>& a) : len(count) { }
	//TODO: ensure (in this but more importantly in other classes
	// that the same rule is applied to all (count, array) - (array, count) pairs.
	// i have in mind some rule that, in one case, the minimum (or maximum)
	// of array length, n is used. Ensure that this doesnt hold.

/**@}*/

	//! destructor
	~array() { }


/** @name Assignement Operators
@{*/

	//!Copy-Assign another array of identical type
	this_type& operator=(const this_type& o) { len = o.len; return *this; }
/**@}*/


};

