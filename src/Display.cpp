
#include "Display.h"

Display::Display ( const int width, const int height ) {

    this -> window_height = height;
    this -> window_width = width;

    // getting small 20 grids
    this -> display_grid_unit = width / 20;

    // getting axis to be twice of smaller grid
    this -> axis_grid_unit = this -> display_grid_unit * 2;

    this -> display_bg_color [ 0 ] = 1.0;
    this -> display_bg_color [ 1 ] = 1.0;
    this -> display_bg_color [ 1 ] = 1.0;

    this -> grid_color [ 0 ] = 135 / 255.0;
    this -> grid_color [ 1 ] = 206 / 255.0;
    this -> grid_color [ 2 ] = 235 / 255.0;

    this -> axis_color [ 0 ] = 255 / 255.0;
    this -> axis_color [ 1 ] = 255 / 255.0;
    this -> axis_color [ 2 ] = 255 / 255.0;

};

void Display::setBackgroundColor ( const float r, const float g, const float b ) {

    const float opacity = 1.0;

    this -> display_bg_color [ 0 ] = r;
    this -> display_bg_color [ 1 ] = g;
    this -> display_bg_color [ 2 ] = b;

    glClearColor ( r, g, b, opacity );

};

void Display::setMaxDisplaySize ( const int width, const int height ) {

    glLoadIdentity ();
    gluOrtho2D ( - width, width, - height, height );

};

void Display::labelAxisUnit ( const char * text, const GLint pos_x, const GLint pos_y, const int size ) {

    glRasterPos2i ( pos_x, pos_y );

    for ( int index = 0; index < size; index ++ ) {

        glutBitmapCharacter ( GLUT_BITMAP_HELVETICA_12, text[ index ] );

    }

};

void Display::showGrid () {

    int unit_distance = 0;
    const int & unit = this -> display_grid_unit;
    float * color = this -> grid_color;

    while ( unit_distance < this -> window_width ) {

        glBegin ( GL_LINES );

            glColor3d ( color[ 0 ], color [ 1 ], color [ 2 ] );

            glVertex2f ( unit_distance, this -> window_height );
            glVertex2f ( unit_distance, - this -> window_height );

        glEnd ();

        glBegin ( GL_LINES );

            glColor3d ( color[ 0 ], color [ 1 ], color [ 2 ] );

            glVertex2f ( -unit_distance, this -> window_height );
            glVertex2f ( -unit_distance, - this -> window_height );

        glEnd ();

        unit_distance += unit;

    }

    unit_distance = 0;

    while ( unit_distance < this -> window_height ) {

        glBegin ( GL_LINES );

            glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

            glVertex2f ( this -> window_width, unit_distance );
            glVertex2f ( - this -> window_width, unit_distance );

        glEnd ();

        glBegin ( GL_LINES );

            glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

            glVertex2f ( this -> window_width, -unit_distance );
            glVertex2f ( - this -> window_width, -unit_distance );

        glEnd ();

        unit_distance += unit;

    }

};

void Display::showAxis () {

    int unit_distance = this -> axis_grid_unit;
    const int & unit = this -> axis_grid_unit;
    float * color = this -> axis_color;

    float text_distance_apart = unit * 50 / 100.0;

    glBegin ( GL_LINES );

        glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

        glVertex2f ( 0, this -> window_height );
        glVertex2f ( 0, - this -> window_height );

    glEnd ();

    glBegin ( GL_LINES );

        glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

        glVertex2f ( this -> window_width, 0 );
        glVertex2f ( - this -> window_width, 0 );

    glEnd ();

    while ( unit_distance < this -> window_width ) {

        const char * text = std::to_string ( unit_distance ).c_str ();
        const char * negate_text = std::to_string ( - unit_distance ).c_str ();

        this -> labelAxisUnit ( text, unit_distance, text_distance_apart, 3 );
        this -> labelAxisUnit ( negate_text, -unit_distance, - text_distance_apart * 2, 4 );

        unit_distance += unit;

    }

    this -> labelAxisUnit ( "X", this -> window_width - text_distance_apart, - text_distance_apart * 2, 1 );

    unit_distance = unit;

    while ( unit_distance < this -> window_height ) {

        const char * text = std::to_string ( unit_distance ).c_str ();
        const char * negate_text = std::to_string ( - unit_distance ).c_str ();

        glColor3d ( color [ 0 ], color [ 1 ], color [ 2 ] );

        this -> labelAxisUnit ( text, -text_distance_apart * 2, unit_distance, 3 );
        this -> labelAxisUnit ( negate_text, text_distance_apart, - unit_distance, 4 );
            
        unit_distance += unit;

    }

    this -> labelAxisUnit ( "Y", text_distance_apart, this -> window_height - text_distance_apart, 1 );

};