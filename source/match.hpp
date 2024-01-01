# ifndef MATCH_HPP
# define MATCH_HPP


# include <raylib.h>
# include "state.hpp"
# include "sprite.hpp"


class Game;


class Match : public State
{
    private:
        Sprite coffee {"../resources/graphics/coffee.png"};
    public:
        Match(Game *game);
        ~Match();
        void check_events() override;
        void update() override;
        void draw() override;
};


#endif