
#ifndef DISPLAY_H
#define DISPLAY_H

#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <iostream>

class Display {

    private:

        float display_bg_color [ 3 ], grid_color [ 3 ], axis_color [ 3 ];
        int max_display_size, display_grid_unit, axis_grid_unit;

        int window_height, window_width;

        void labelAxisUnit (
            
            const char * text,
            const GLint pos_x,
            const GLint pos_y,
            const int size
        
        );

    public:

        Display ( const int window_width, const int window_height );

        void setBackgroundColor ( const float r, const float g, const float b );
        void setMaxDisplaySize ( const int width, const int height );
        void setGridUnit ( const int unit );
        void setAxisUnit ( const int unit );
        void setAxisColor ( const float r, const float g, const float b );
        void setGridColor ( const float r, const float g, const float b );

        void showGrid ();
        void showAxis ();

};

#endif