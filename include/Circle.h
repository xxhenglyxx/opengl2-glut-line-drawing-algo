
#ifndef CIRCLE_H
#define CIRCLE_H

#include <array>
#include <vector>
#include <math.h>
#include <OpenGL/gl.h>
#include <iostream>

class Circle {

    private:

        std::array < int, 2 > center_pos;
        int radius;
        bool show;

    public:

        Circle ( const int center_pos_x = 0, const int center_pos_y = 0 );

        void draw () const;
        void setCenter ( const int pos_x, const int pos_y );

};

#endif