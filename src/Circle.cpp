
#include "Circle.h"
#include <math.h>
#include <OpenGL/gl.h>
#include <iostream>

Circle::Circle ( const int center_pos_x, const int center_pos_y ) {

    this -> center_pos [ 0 ] = center_pos_x;
    this -> center_pos [ 1 ] = center_pos_y;

    this -> radius = 5;
    this -> show = false;

};

void Circle::draw () const {

    float angle = 0;
    const int & r = this -> radius;

    const std::array< int, 2 > pos ( this -> center_pos );

    glBegin ( GL_TRIANGLE_FAN );

        for ( ; angle < 360.0; ++ angle ) {

            glVertex2f ( r * cos ( angle ) + pos[ 0 ], r * sin ( angle ) + pos[ 1 ] );

        }

    glEnd ();

};

void Circle::setCenter ( const int pos_x, const int pos_y ) {

    this -> center_pos [ 0 ] = pos_x;
    this -> center_pos [ 1 ] = pos_y;

};