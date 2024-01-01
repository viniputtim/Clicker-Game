# include <string>
# include <raylib.h>
# include "match.hpp"


class Game;


Match::Match(Game *game) : State(game)
{
    this->coffee.scale(0.5);
    this->coffee.set_center(GetScreenWidth() / 2, GetScreenHeight() / 2);
    this->coffee_chantilly.scale(0.5);
    this->coffee_chantilly.set_center(GetScreenWidth() / 2, GetScreenHeight() / 2);
    this->mouse_power.scale(0.15);
    this->chantilly.scale(0.15);
    this->auto_clicker.scale(0.15);
    this->chantilly.set_bottom(GetScreenHeight());
    this->mouse_power.set_bottomleft(this->chantilly.get_right() + 1, this->chantilly.get_bottom());
    this->auto_clicker.set_bottomleft(this->mouse_power.get_right() + 1, this->mouse_power.get_bottom());
}


Match::~Match()
{

}


void Match::check_events()
{
    if (IsMouseButtonPressed(0) && this->coffee.collide_point(GetMousePosition())) {
        if (!this->is_auto_clicker_purchased) {
            this->score += this->click_value;
        }
    } else if(IsMouseButtonPressed(0) && this->mouse_power.collide_point(GetMousePosition())) {
        if (this->score >= this->mouse_power_value) {
            ++this->click_value;
            this->score -= this->mouse_power_value;
        }
    } else if (IsMouseButtonPressed(0) && this->chantilly.collide_point(GetMousePosition())) {
        if (this->score >= this->chantilly_value) {
            this->is_chantily_purchased = true;
            ++this->chantily_passive;
            this->score -= this->chantilly_value;
        }
    } else if (IsMouseButtonPressed(0) && this->auto_clicker.collide_point(GetMousePosition())) {
        if (this->score >= this->auto_clicker_value && !this->is_auto_clicker_purchased) {
            this->is_auto_clicker_purchased = true;
            this->score -= this->auto_clicker_value;
        }
    }

    if (IsMouseButtonDown(0) && this->coffee.collide_point(GetMousePosition()) && this->is_auto_clicker_purchased) {
        this->score += this->click_value;
    }
}


void Match::update()
{
    if (this->is_chantily_purchased) {
        if (GetTime() > this->chantilly_time) {
            this->score += this->chantily_passive;
            this->chantilly_time = GetTime() + 1;
        }
    }
}


void Match::draw()
{
    ClearBackground(RAYWHITE);

    if (this->is_chantily_purchased) {
        this->coffee_chantilly.draw();
    } else {
        this->coffee.draw();
    }

    this->mouse_power.draw();
    this->chantilly.draw();
    this->auto_clicker.draw();

    std::string mouse_power_value_str {"$ " + std::to_string(this->mouse_power_value)};
    DrawTextEx(GetFontDefault(), mouse_power_value_str.c_str(), this->mouse_power.get_pos(), this->value_font_size, 2, DARKGREEN);
    std::string chantilly_value_str {"$ " + std::to_string(this->chantilly_value)};
    DrawTextEx(GetFontDefault(), chantilly_value_str.c_str(), this->chantilly.get_pos(), this->value_font_size, 2, DARKGREEN);
    std::string auto_clicker_value_str {"$ " + std::to_string(this->auto_clicker_value)};
    DrawTextEx(GetFontDefault(), auto_clicker_value_str.c_str(), this->auto_clicker.get_pos(), this->value_font_size, 2, DARKGREEN);

    std::string score_str {std::to_string(this->score)};
    this->score_x = (GetScreenWidth() - MeasureText(score_str.c_str(), score_font_size)) / 2;
    DrawText(score_str.c_str(), this->score_x, this->score_y, this->score_font_size, BLACK);
}