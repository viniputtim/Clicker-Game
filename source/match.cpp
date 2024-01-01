# include <raylib.h>
# include "match.hpp"


class Game;


Match::Match(Game *game) : State(game)
{
    this->coffee.scale(0.5);
    this->coffee.set_center(GetScreenWidth() / 2, GetScreenHeight() / 2);
}


Match::~Match()
{

}


void Match::check_events()
{

}


void Match::update()
{

}


void Match::draw()
{
    ClearBackground(RAYWHITE);
    this->coffee.draw();
}