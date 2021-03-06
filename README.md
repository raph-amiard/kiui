## Disclaimer
This is a very early work-in-progress and is provided with no guarantee whatsoever of usability or even compilability.
Everything, from the namespaces to the class interfaces should be expected to undergo complete modification in the coming weeks.
It is, as of now, completely undocumented apart from the present overview.

kiUi
====

kiUi is a lightweight auto-layout Ui library, abstracted out from any rendering or input code.

It is designed according to the following design goals :
- Separation of Ui appearance and logic
- Automatic layout as the norm, not the exception (as in HTML)
- Easy styling, separated from logic (as in CSS)
- Brevity and simplicity above everything else, especially in C++ code
- Good for both an editor Ui and a game Ui

![screenshot of the example window with a raw skin](kiui.png?raw=true)

Usage
====
```C++
UiWindow* uiwindow = new UiWindow();

Form* root = uiwindow->rootForm();
Window* window = root->makeappend<Window>("window", "Example window");

Expandbox* expandbox = window->makeappend<Expandbox>("expandbox", "Collapsable box");

Label* label = expandbox->makeappend<Label>("label", "kiUi says hello.");
Button* button = expand->makeappend<Button>("button", "Push me");
```

Nano
====

kiUi comes with a light renderer / input system based on NanoVG and GLFW to quickly bootstrap a prototype application in a few lines of code.

```C++
GlWindow* glwindow = new GlWindow(1200, 800, "mk UiEditApp");
glwindow->initContext();

UiWindow* uiwindow = glwindow->uiWindow();
bool pursue = true;
while(pursue)
    pursue = glwindow->renderFrame();
```

Skins
=====

kiUi was conceived so that each element can be styled in a way very similar to CSS

## License
The library is licensed under [zlib license](LICENSE.txt)

## Links
Uses [nanovg](https://github.com/memononen/nanovg) for vector rendering
Uses [glfw](https://github.com/glfw/glfw) for OpenGL context management