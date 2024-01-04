# include <raylib.h>
# include "rect.hpp"


float Rect::get_x()
{
    return this->x;
}


float Rect::get_y()
{
    return this->y;
}


float Rect::get_left()
{
    return this->x;
}


float Rect::get_top()
{
    return this->y;
}


float Rect::get_centerx()
{
    return this->x + this->width / 2;
}


float Rect::get_centery()
{
    return this->y + this->height / 2;
}


float Rect::get_right()
{
    return this->x + this->width;
}


float Rect::get_bottom()
{
    return this->y + this->height;
}


Vector2 Rect::get_pos()
{
    return {
        this->x,
        this->y
    };
}


Vector2 Rect::get_topleft()
{
    return {
        this->get_left(),
        this->get_top()
    };
}


Vector2 Rect::get_midtop()
{
    return {
        this->get_centerx(),
        this->get_top()
    };
}


Vector2 Rect::get_topright()
{
    return {
        this->get_right(),
        this->get_top()
    };
}


Vector2 Rect::get_midleft()
{
    return {
        this->get_left(),
        this->get_centery()
    };
}


Vector2 Rect::get_center()
{
    return {
        this->get_centerx(),
        this->get_centery()
    };
}


Vector2 Rect::get_midright()
{
    return {
        this->get_right(),
        this->get_centery()
    };
}


Vector2 Rect::get_bottomleft()
{
    return {
        this->get_left(),
        this->get_bottom()
    };
}


Vector2 Rect::get_midbottom()
{
    return {
        this->get_centerx(),
        this->get_bottom()
    };
}


Vector2 Rect::get_bottomright()
{
    return {
        this->get_right(),
        this->get_bottom()
    };
}


float Rect::get_width()
{
    return this->width;
}


float Rect::get_height()
{
    return this->height;
}


void Rect::set_x(float x)
{
    this->x = x;
}


void Rect::set_y(float y)
{
    this->y = y;
}


void Rect::set_left(float left)
{
    this->x = left;
}


void Rect::set_top(float top)
{
    this->y = top;
}


void Rect::set_centerx(float centerx)
{
    this->x = centerx - this->width / 2;
}


void Rect::set_centery(float centery)
{
    this->y = centery - this->height / 2;
}


void Rect::set_right(float right)
{
    this->x = right - this->width;
}


void Rect::set_bottom(float bottom)
{
    this->y = bottom - this->height;
}


void Rect::set_pos(float x, float y)
{
    this->set_x(x);
    this->set_y(y);
}


void Rect::set_topleft(float left, float top)
{
    this->set_left(left);
    this->set_top(top);
}


void Rect::set_midtop(float centerx, float top)
{
    this->set_centerx(centerx);
    this->set_top(top);
}


void Rect::set_topright(float right, float top)
{
    this->set_right(right);
    this->set_top(top);
}


void Rect::set_midleft(float left, float centery)
{
    this->set_left(left);
    this->set_centery(centery);
}


void Rect::set_center(float centerx, float centery)
{
    this->set_centerx(centerx);
    this->set_centery(centery);
}


void Rect::set_midright(float right, float centery)
{
    this->set_right(right);
    this->set_centery(centery);
}


void Rect::set_bottomleft(float left, float bottom)
{
    this->set_left(left);
    this->set_bottom(bottom);
}


void Rect::set_midbottom(float centerx, float bottom)
{
    this->set_centerx(centerx);
    this->set_bottom(bottom);
}


void Rect::set_bottomright(float right, float bottom)
{
    this->set_right(right);
    this->set_bottom(bottom);
}


bool Rect::collide_point(float x, float y)
{
    bool collide_x {this->get_left() < x && this->get_right() > x};
    bool collide_y {this->get_top() < y && this->get_bottom() > y};

    return collide_x && collide_y;
}


bool Rect::collide_point(Vector2 pos)
{
    bool collide_x {this->get_left() < pos.x && this->get_right() > pos.x};
    bool collide_y {this->get_top() < pos.y && this->get_bottom() > pos.y};

    return collide_x && collide_y;
}


bool Rect::collide_rect(float x, float y, float width, float height)
{
    float right {x + width};
    float bottom {y + height};

    return (this->x > x && this->x < right ||
        this->get_right() < right && this->get_right() > x) &&
        (this->get_top() > y && this->get_top() < bottom ||
        this->get_bottom() < bottom && this->get_bottom() > y);
}


bool Rect::collide_rect(Rectangle rectangle)
{
    return this->collide_rect(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
}


bool Rect::collide_rect(Rect *rectangle)
{
    return this->collide_rect(
        rectangle->get_x(), rectangle->get_y(), rectangle->get_width(), rectangle->get_height()
    );
}