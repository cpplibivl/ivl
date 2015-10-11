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

#ifndef IVL_QT_GUI_WIDGETS_CHECK_BOX_HPP
#define IVL_QT_GUI_WIDGETS_CHECK_BOX_HPP

#include "../../core.hpp"
#include "../kernel/widget_base.hpp"
#include <QCheckBox>

namespace ivl {

//-----------------------------------------------------------------------------

namespace qt_details {

//-----------------------------------------------------------------------------

class _ivlqt_export_ check_box : public QCheckBox,
	public widget_base <check_box>,
	public method_binder <check_box, QCheckBox, QAbstractButton>
{
	Q_OBJECT
	typedef QCheckBox T;

private slots:

	// QWidget
	void customContextMenuRequested_(const QPoint& p) { custom_context_menu_requested(p); }

	// QAbstractButton
	void pressed_()             { pressed(); }
	void released_()            { released(); }
	void clicked_(bool checked) { clicked(checked); }
	void toggled_(bool checked) { toggled(checked); }

	// QCheckBox
	void stateChanged_(int s)   { state_changed(s); }

private:

	void init()
	{
		// QWidget
		#include "../kernel/widget_init.hpp"

		// QAbstractButton
		#include "abstract_button_init.hpp"

		// QCheckBox
		connect(this, SIGNAL(stateChanged(int)), SLOT(stateChanged_(int)));
	}

public:

//-----------------------------------------------------------------------------

	// QWidget
	#include "../kernel/widget_decl.hpp"

	// QAbstractButton
	#include "abstract_button_decl.hpp"

	// QCheckBox
	signal <void (int)> state_changed;

//-----------------------------------------------------------------------------

	explicit check_box(QWidget* parent = 0) :
		QCheckBox(parent) { init(); }

	explicit check_box(const QString& text, QWidget* parent = 0) :
		QCheckBox(text, parent) { init(); }

	explicit check_box(const QString& text, bool checked, QWidget* parent = 0) :
		QCheckBox(text, parent) { init(); setChecked(checked); }

};

//-----------------------------------------------------------------------------

}  // qt_details

using qt_details::check_box;

//-----------------------------------------------------------------------------

}  // namespace ivl

#endif  // IVL_QT_GUI_WIDGETS_CHECK_BOX_HPP
