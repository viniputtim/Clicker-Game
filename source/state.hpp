# ifndef STATE_HPP
# define STATE_HPP


class Game;


class State
{
    protected:
        Game * game;

    public:
        State(Game *game) : game(game) {};
        ~State() {};
        virtual void check_events() {};
        virtual void update() {};
        virtual void draw() {};
};


#endif