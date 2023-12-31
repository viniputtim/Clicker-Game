# include <raylib.h>
# include "match.hpp"


class Game;


Match::Match(Game *game) : State(game)
{

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
    ClearBackground(YELLOW);
}