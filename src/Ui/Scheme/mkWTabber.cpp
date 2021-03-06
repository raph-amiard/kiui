//  Copyright (c) 2015 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#include <Ui/mkUiConfig.h>
#include <Ui/Scheme/mkWTabber.h>

#include <Ui/Form/mkForm.h>
#include <Ui/Form/mkWidgets.h>

#include <Ui/Frame/mkFrame.h>

using namespace std::placeholders;

namespace mk
{
	WTab::WTab(WButton* header, bool active)
		: Sheet("tab")
		, mHeader(header)
		, mActive(active)
	{}

	void WTab::build()
	{
		Sheet::build();
		if(!mActive)
			mFrame->hide();
		else
			mHeader->activate();
	}

	WTabber::WTabber(string cls, bool downtabs)
		: Sheet(cls)
		, mCurrentTab(nullptr)
		, mDownTabs(downtabs)
	{}

	WTabber::~WTabber()
	{}

	void WTabber::build()
	{
		Sheet::build();
		mHeaders = this->makeappend<Sheet>("headtabs");
		mTabs = this->makeappend<Sheet>("tabs");

		if(mDownTabs)
			mFrame->as<Stripe>()->move(0, 1);
		mHeaders->frame()->hide();
	}

	Widget* WTabber::vappend(unique_ptr<Widget> widget)
	{
		WButton* header = mHeaders->makeappend<WButton>(widget->name(), "tabheader", std::bind(&WTabber::headerClicked, this, _1));
		WTab* tab = mTabs->makeappend<WTab>(header, mCurrentTab == nullptr);

		if(!mCurrentTab)
			mCurrentTab = tab;
		else if(mTabs->contents()->size() == 2)
			mHeaders->frame()->show();

		return tab->append(std::move(widget));
	}

	unique_ptr<Widget> WTabber::vrelease(Widget* widget)
	{
		WTab* tab = widget->parent()->as<WTab>();

		if(tab == mCurrentTab)
			mCurrentTab = nullptr;

		unique_ptr<Widget> unique = widget->unbind();
		tab->header()->destroy();
		tab->destroy();

		if(mTabs->contents()->size() > 0)
			this->showTab(size_t(0));
		if(mTabs->contents()->size() == 1)
			mHeaders->frame()->hide();

		return unique;
	}

	void WTabber::headerClicked(WButton* header)
	{
		this->showTab(header->frame()->index());
	}

	void WTabber::showTab(WTab* tab)
	{
		if(mCurrentTab)
		{
			mCurrentTab->frame()->hide();
			mCurrentTab->header()->deactivate();
		}
		tab->frame()->show();
		tab->header()->activate();
		mCurrentTab = tab;
	}

	void WTabber::showTab(size_t index)
	{
		this->showTab(mTabs->contents()->at(index)->as<WTab>());
	}

	Tabber::Tabber()
		: Form("tabber", "", []() { return make_unique<WTabber>("tabber"); })
	{}
}
