//  Copyright (c) 2015 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#ifndef MK_UITYPES_H_INCLUDED
#define MK_UITYPES_H_INCLUDED

#include <Ui/Form/mkForm.h>
#include <Ui/Form/mkRootForm.h>
#include <Ui/Form/mkButton.h>
#include <Ui/Form/mkWidgets.h>

#include <Ui/Frame/mkFrame.h>
#include <Ui/Frame/mkInk.h>

#include <Ui/Widget/mkWidget.h>
#include <Ui/Widget/mkSheet.h>

#include <Ui/Scheme/mkWExpandbox.h>
#include <Ui/Scheme/mkWDropdown.h>
#include <Ui/Scheme/mkWTabber.h>
#include <Ui/Scheme/mkWTable.h>

#include <Ui/Frame/mkDimString.h>

#include <Ui/mkUiWindow.h>

namespace mk
{
	template <> inline Type* typecls<Dimension>() { return Typed<Sizing>::cls(); }
	template <> inline Type* typecls<Sizing>() { return Typed<Sizing>::cls(); }
	template <> inline Type* typecls<Pivot>() { return Typed<Pivot>::cls(); }
	template <> inline Type* typecls<Flow>() { return Typed<Sizing>::cls(); }
	template <> inline Type* typecls<Overflow>() { return Typed<Sizing>::cls(); }
	template <> inline Type* typecls<BoxLayer>() { return Typed<Sizing>::cls(); }
	template <> inline Type* typecls<Opacity>() { return Typed<Sizing>::cls(); }
	template <> inline Type* typecls<FrameType>() { return Typed<Sizing>::cls(); }

	template class MK_UI_EXPORT Typed<Dimension>;
	template class MK_UI_EXPORT Typed<Sizing>;
	template class MK_UI_EXPORT Typed<Pivot>;
	template class MK_UI_EXPORT Typed<Flow>;
	template class MK_UI_EXPORT Typed<Overflow>;
	template class MK_UI_EXPORT Typed<BoxLayer>;
	template class MK_UI_EXPORT Typed<Opacity>;
	template class MK_UI_EXPORT Typed<FrameType>;
}

#endif // MK_UITYPES_H_INCLUDED
