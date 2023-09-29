#include <iostream>
#include "scr/Cybertopic_Engine_Libs/CE_main.h"
#include <thread>
#include <chrono>

int main()
{
    scml::window::Window window(scml::window::DisplayTypes::Normal, "Example Game | CSS Entertainment");
    window.openWindow();
    scml::window::Window::backgroundBuffer buffer;

    struct player
    {
        cy::vector2<int> pos;
        cy::vector2<int> vel;
        scml::window::Window::backgroundBuffer buffer;

        void update()
        {
            if (pos.x >= 100)
            {
                pos.x = 0;
            }

            if (pos.y >= 100)
            {
                pos.y = 0;
            }

            buffer.clear();
            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < 100; ++j) {
                    cy::vector2<int> pixelPos = cy::vector2<int>(i + pos.x, j + pos.y);
                    if (pixelPos.x >= 0 && pixelPos.y >= 0)
                    {
                        buffer.add(cy::vector3<int>(255,0,0), pixelPos);
                    }
                }
            }
        }

    };

    player player;

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        if (scml::check_for::key(VK_ESCAPE))
        {
            window.close();
        }

        if (scml::check_for::key('I'))
        {

            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < 100; ++j) {
                    buffer.add(cy::vector3<int>(i,j,0), cy::vector2<int>(i,j));
                }
            }
        }

        if (scml::check_for::key('D'))
        {
            window.draw(buffer);
        }

        if (scml::check_for::key('J'))
        {
            for (int i = 0; i < 100; ++i) {
                for (int j = 0; j < 100; ++j) {
                    window.setPixel(cy::vector3<int>(i,j,255), cy::vector2<int>(i,j));
                }
            }
        }

        if (scml::check_for::key('K'))
        {
            window.setPixelL(cy::vector3<int>(122,122,122), cy::vector2<int>(0,0), cy::vector2<int>(100,100));
        }

    }
    return 0;
}
