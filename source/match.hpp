# ifndef MATCH_HPP
# define MATCH_HPP


# include "state.hpp"


class Game;


class Match : public State
{
    public:
        Match(Game *game);
        ~Match();
        void check_events() override;
        void update() override;
        void draw() override;
};


#endif