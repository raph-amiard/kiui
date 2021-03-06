//  Copyright (c) 2015 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#ifndef MK_WCHECKBOX_H
#define MK_WCHECKBOX_H

/* mk */
#include <Ui/mkUiForward.h>
#include <Ui/Widget/mkWidget.h>

namespace mk
{
	class MK_UI_EXPORT WCheckbox : public Widget
	{
	public:
		WCheckbox(Form* form, Lref& value);

		void build();

		void updateChecked();

		bool leftClick(float xPos, float yPos);

	protected:
		Lref& mValue;
	};
}

#endif
