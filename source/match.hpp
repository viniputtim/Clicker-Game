# ifndef MATCH_HPP
# define MATCH_HPP


# include <raylib.h>
# include "state.hpp"
# include "sprite.hpp"


class Game;


class Match : public State
{
    private:
        int score {0};
        int score_font_size {40};
        int score_x {0};
        float score_y {0};
        Sprite coffee {"../resources/graphics/coffee.png"};
        Sprite coffee_chantilly {"../resources/graphics/coffee_chantilly.png"};
        Sprite chantilly {"../resources/graphics/chantilly.png"};
        Sprite auto_clicker {"../resources/graphics/auto_clicker.png"};
        Sprite mouse_power {"../resources/graphics/mouse_power.png"};
        int mouse_power_value {250};
        int chantilly_value {50};
        int auto_clicker_value {1000};
        int click_value {1};
        int chantily_passive {0};
        double chantilly_time {0};
        bool is_chantily_purchased {false};
        bool is_auto_clicker_purchased {false};
    public:
        Match(Game *game);
        ~Match();
        void check_events() override;
        void update() override;
        void draw() override;
};


#endif