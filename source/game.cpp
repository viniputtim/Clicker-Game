# include <string>
# include <raylib.h>
# include "game.hpp"


Game::Game()
{
    this->set_state("match");
}


Game::~Game()
{

}


void Game::run()
{
    while (!WindowShouldClose()) {
        this->check_events();
        this->update();
        this->draw();
    }
}


void Game::check_events()
{
    if (IsKeyPressed(KEY_TAB)) {
        this->show_fps = !this->show_fps;
    }

    this->state->check_events();
}


void Game::update()
{
    this->state->update();
}


void Game::draw()
{
    BeginDrawing();
    this->state->draw();
    if (this->show_fps) {
        std::string fps_str {std::to_string(GetFPS())};
        DrawFPS(0, 0);
    }
    EndDrawing();
}


void Game::set_state(std::string state_name) {
    this->state = this->states[state_name];
}