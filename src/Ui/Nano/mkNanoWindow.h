//  Copyright (c) 2015 Hugo Amiard hugo.amiard@laposte.net
//  This software is provided 'as-is' under the zlib License, see the LICENSE.txt file.
//  This notice and the license may not be removed or altered from any source distribution.

#ifndef MK_GORILLAWINDOW_H
#define MK_GORILLAWINDOW_H

/* mk Og */
#include <Ui/mkUiForward.h>
#include <Ui/Frame/mkInk.h>

#include <memory>

namespace mk
{
	class MK_UI_EXPORT NanoLayer : public InkLayer
	{
	public:
		NanoLayer(Frame* frame, NanoTarget* target, size_t index);
		~NanoLayer();

		NanoTarget* target() { return mTarget; }

		size_t index() { return mIndex; }
		bool visible() { return mVisible; }

		unique_ptr<Inkbox> inkbox(Frame* frame);

		void show();
		void hide();

		void moveToTop();
		void nanodraw();

		void draw(Frame* frame);

	protected:
		NanoTarget* mTarget;
		size_t mIndex;
		bool mVisible;
		Frame* mFrame;

		std::vector<Frame*> mOrdered;
	};

	class MK_UI_EXPORT NanoTarget : public InkTarget
	{
	public:
		NanoTarget(NanoWindow* window);

		NanoWindow* window() { return mWindow; }
		size_t zmax() { return mZMax; }

		unique_ptr<InkLayer> layer(Frame* frame, size_t z);

		void moveToTop(NanoLayer* layer);
		void nanodraw();

	protected:
		NanoWindow* mWindow;
		size_t mZMax;
		std::vector<std::vector<NanoLayer*>> mLayers;
	};

	class MK_UI_EXPORT NanoGl
	{
	public:
		virtual ~NanoGl() {}
	};

	class MK_UI_EXPORT NanoWindow : public InkWindow
	{
	public:
		NanoWindow(size_t width, size_t height, float pixelRatio, string ressourcePath);
		~NanoWindow();

		void nextFrame();

		InkTarget* screenTarget();

		string ressourcePath() { return mRessourcePath; }
		NVGcontext* ctx() { return mCtx; }
		
		static std::map<string, int> sImages;

	protected:
		size_t mWidth;
		size_t mHeight;
		float mPixelRatio;
		string mRessourcePath;
		unique_ptr<NanoGl> mNanoGl;

		NVGcontext* mCtx;
		unique_ptr<NanoTarget> mScreenTarget;
	};

}

#endif
