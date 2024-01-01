# include <string>
# include <raylib.h>
# include "sprite.hpp"


Sprite::Sprite(std::string file_path)
{
    this->image = LoadImage(file_path.c_str());
    this->load_texture();
}


Sprite::~Sprite()
{
    
}


void Sprite::load_texture()
{
    this->texture = LoadTextureFromImage(this->image);
    this->width = this->texture.width;
    this->height = this->texture.height;
}


void Sprite::scale(float scale)
{
    float new_width {this->width * scale};
    float new_height {this->height * scale};
    ImageResize(&this->image, new_width, new_height);
    this->load_texture();
}


void Sprite::draw()
{
    DrawTexture(this->texture, this->x, this->y, WHITE);
}


bool Sprite::collide_point(float x, float y)
{
    bool collide_x {this->get_left() < x && this->get_right() > x};
    bool collide_y {this->get_top() < y && this->get_bottom() > y};

    return collide_x && collide_y;
}


bool Sprite::collide_point(Vector2 pos)
{
    bool collide_x {this->get_left() < pos.x && this->get_right() > pos.x};
    bool collide_y {this->get_top() < pos.y && this->get_bottom() > pos.y};

    return collide_x && collide_y;
}


void Sprite::set_x(float x)
{
    this->x = x;
}


void Sprite::set_y(float y)
{
    this->y = y;
}


void Sprite::set_left(float left)
{
    this->x = left;
}


void Sprite::set_top(float top)
{
    this->y = top;
}


void Sprite::set_centerx(float centerx)
{
    this->x = centerx - this->width / 2;
}


void Sprite::set_centery(float centery)
{
    this->y = centery - this->height / 2;
}


void Sprite::set_right(float right)
{
    this->x = right - this->width;
}


void Sprite::set_bottom(float bottom)
{
    this->y = bottom - this->height;
}


void Sprite::set_pos(float x, float y)
{
    this->set_x(x);
    this->set_y(y);
}


void Sprite::set_topleft(float left, float top)
{
    this->set_left(left);
    this->set_top(top);
}


void Sprite::set_midtop(float centerx, float top)
{
    this->set_centerx(centerx);
    this->set_top(top);
}


void Sprite::set_topright(float right, float top)
{
    this->set_right(right);
    this->set_top(top);
}


void Sprite::set_midleft(float left, float centery)
{
    this->set_left(left);
    this->set_centery(centery);
}


void Sprite::set_center(float centerx, float centery)
{
    this->set_centerx(centerx);
    this->set_centery(centery);
}


void Sprite::set_midright(float right, float centery)
{
    this->set_right(right);
    this->set_centery(centery);
}


void Sprite::set_bottomleft(float left, float bottom)
{
    this->set_left(left);
    this->set_bottom(bottom);
}


void Sprite::set_midbottom(float centerx, float bottom)
{
    this->set_centerx(centerx);
    this->set_bottom(bottom);
}


void Sprite::set_bottomright(float right, float bottom)
{
    this->set_right(right);
    this->set_bottom(bottom);
}


float Sprite::get_x()
{
    return this->x;
}


float Sprite::get_y()
{
    return this->y;
}


float Sprite::get_left()
{
    return this->x;
}


float Sprite::get_top()
{
    return this->y;
}


float Sprite::get_centerx()
{
    return this->x + this->width / 2;
}


float Sprite::get_centery()
{
    return this->y + this->height / 2;
}


float Sprite::get_right()
{
    return this->x + this->width;
}


float Sprite::get_bottom()
{
    return this->y + this->height;
}


Vector2 Sprite::get_pos()
{
    return {
        this->x,
        this->y
    };
}


Vector2 Sprite::get_topleft()
{
    return {
        this->get_left(),
        this->get_top()
    };
}


Vector2 Sprite::get_midtop()
{
    return {
        this->get_centerx(),
        this->get_top()
    };
}


Vector2 Sprite::get_topright()
{
    return {
        this->get_right(),
        this->get_top()
    };
}


Vector2 Sprite::get_midleft()
{
    return {
        this->get_left(),
        this->get_centery()
    };
}


Vector2 Sprite::get_center()
{
    return {
        this->get_centerx(),
        this->get_centery()
    };
}


Vector2 Sprite::get_midright()
{
    return {
        this->get_right(),
        this->get_centery()
    };
}


Vector2 Sprite::get_bottomleft()
{
    return {
        this->get_left(),
        this->get_bottom()
    };
}


Vector2 Sprite::get_midbottom()
{
    return {
        this->get_centerx(),
        this->get_bottom()
    };
}


Vector2 Sprite::get_bottomright()
{
    return {
        this->get_right(),
        this->get_bottom()
    };
}


float Sprite::get_width()
{
    return this->width;
}


float Sprite::get_height()
{
    return this->height;
}
