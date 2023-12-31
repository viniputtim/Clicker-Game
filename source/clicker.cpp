# include <raylib.h>
# include "game.hpp"


int main(int argc, char *argv[])
{
    InitAudioDevice();
    SetMasterVolume(0.5);
    InitWindow(0, 0 ,"Clicker Game");
    ToggleFullscreen();
    Game game;
    game.run();
    CloseAudioDevice();
    CloseWindow();

    return 0;
}