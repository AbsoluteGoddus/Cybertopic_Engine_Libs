#ifndef CYBERTOPIC_ENGINE_1_SCML_WINDOWINIT_H
#define CYBERTOPIC_ENGINE_1_SCML_WINDOWINIT_H

#include <iostream>
#include <cstring>

namespace scml
{
    namespace window
    {
        namespace low_lvl
        {

            #ifdef _WIN32
            #include <windows.h>
            #elif __linux__
                        #include <X11/Xlib.h>
            #elif __APPLE__
            #include <Carbon/Carbon.h>
            #endif

                        void open_window(const char* Title, int sizeX, int sizeY, int screenMode) {
                            // Define platform-specific variables
            #ifdef _WIN32
                            HWND hwnd;
                            DWORD dwStyle;
                            RECT rect;
                            rect.left = 0;
                            rect.top = 0;
                            rect.right = sizeX;
                            rect.bottom = sizeY;
            #elif __linux__
                            Display* display;
                Window root;
                Window window;
                XEvent event;
            #elif __APPLE__
                Rect rect;
                WindowRef window;
            #endif

                            // Initialize the platform-specific window
            #ifdef _WIN32
                            dwStyle = WS_OVERLAPPEDWINDOW;
                            AdjustWindowRect(&rect, dwStyle, FALSE);
                            hwnd = CreateWindowEx(0, TEXT("STATIC"), TEXT(Title), dwStyle,
                                                  CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left, rect.bottom - rect.top,
                                                  nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
                            if (!hwnd) {
                                std::cerr << "Window creation failed on Windows." << std::endl;
                                return;
                            }
            #elif __linux__
                            display = XOpenDisplay(nullptr);
                if (!display) {
                    std::cerr << "Could not open X display on Linux." << std::endl;
                    return;
                }

                root = DefaultRootWindow(display);
                window = XCreateSimpleWindow(display, root, 0, 0, sizeX, sizeY, 1, 0, 0);
                XSelectInput(display, window, StructureNotifyMask);
                XMapWindow(display, window);
                XFlush(display);
                while (true) {
                    XNextEvent(display, &event);
                    if (event.type == MapNotify)
                        break;
                }
            #elif __APPLE__
                rect.left = 0;
                rect.top = 0;
                rect.right = sizeX;
                rect.bottom = sizeY;
                CreateNewWindow(kDocumentWindowClass, kWindowStandardDocumentAttributes | kWindowLiveResizeAttribute,
                    &rect, &window);
                SetWindowTitleWithCFString(window, CFStringCreateWithCString(nullptr, Title, kCFStringEncodingUTF8));
                ShowWindow(window);
            #endif

                            // Main loop
                            while (true) {
            #ifdef _WIN32
                                MSG msg;
                                if (PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) {
                                    if (msg.message == WM_QUIT)
                                        break;
                                    TranslateMessage(&msg);
                                    DispatchMessage(&msg);
                                }
            #elif __linux__
                                XNextEvent(display, &event);
            #elif __APPLE__
                    EventRef event;
                    ReceiveNextEvent(0, nullptr, kDurationForever, true, &event);
                    if (event)
                        SendEventToEventTarget(event, GetWindowEventTarget(window));
            #endif
                                // Your rendering code here
                            }

                            // Cleanup and exit
            #ifdef _WIN32
                            DestroyWindow(hwnd);
            #elif __linux__
                            XDestroyWindow(display, window);
                XCloseDisplay(display);
            #elif __APPLE__
                DisposeWindow(window);
            #endif
                        }

                        int main() {
                            const char* Title = "My Window";
                            int sizeX = 800;
                            int sizeY = 600;
                            int screenMode = 2; // Change this value to select the desired screen mode

                            open_window(Title, sizeX, sizeY, screenMode);

                            return 0;
                        }

        }
    }
}

#endif //CYBERTOPIC_ENGINE_1_WINDOWINIT_H