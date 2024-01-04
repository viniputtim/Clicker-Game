# ifndef RECT_HPP
# define RECT_HPP

# include <raylib.h>


class Rect
{
    protected:
        float x;
        float y;
        float width;
        float height;

    public:
        Rect(float x, float y);
        Rect(float x, float y, float width, float height);
        ~Rect();
        float get_x();
        float get_y();
        float get_left();
        float get_top();
        float get_centerx();
        float get_centery();
        float get_right();
        float get_bottom();
        Vector2 get_pos();
        Vector2 get_topleft();
        Vector2 get_midtop();
        Vector2 get_topright();
        Vector2 get_midleft();
        Vector2 get_center();
        Vector2 get_midright();
        Vector2 get_bottomleft();
        Vector2 get_midbottom();
        Vector2 get_bottomright();
        float get_width();
        float get_height();
        void set_x(float x);
        void set_y(float y);
        void set_left(float left);
        void set_top(float top);
        void set_centerx(float centerx);
        void set_centery(float centery);
        void set_right(float right);
        void set_bottom(float bottom);
        void set_pos(float x, float y);
        void set_topleft(float left, float top);
        void set_midtop(float centerx, float top);
        void set_topright(float right, float top);
        void set_midleft(float left, float centery);
        void set_center(float centerx, float centery);
        void set_midright(float right, float centery);
        void set_bottomleft(float left, float bottom);
        void set_midbottom(float centerx, float bottom);
        void set_bottomright(float right, float bottom);
        bool collide_point(float x, float y);
        bool collide_point(Vector2 pos);
        bool collide_rect(float x, float y, float width, float height);
        bool collide_rect(Rectangle rectangle);
        bool collide_rect(Rect *rectangle);
};


# endif