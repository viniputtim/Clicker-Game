# ifndef GAME_HPP
# define GAME_HPP

# include <memory>
# include <map>
# include <string>
# include "state.hpp"
# include "match.hpp"


class Game
{
    private:
        std::shared_ptr<State> state;
        std::map<std::string, std::shared_ptr<State>> states {
            {"match", std::make_shared<Match> (this)}
        };
        bool show_fps {false};

        void check_events();
        void update();
        void draw();
    protected:
    public:
        Game();
        ~Game();
        void run();
        void set_state(std::string state_name);
};


#endif