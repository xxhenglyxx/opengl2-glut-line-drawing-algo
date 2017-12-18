
#define WIDTH 1000
#define HEIGHT 800

#include "Display.h"
#include "Circle.h"
#include <sstream>
#include "Line.h"

int drawing_type = 0, line_color = 0;
Display display ( 20, 20 );
Line line1;
Circle circle;

void render ();
void drawingOption ( int value );
void mainMenu ( int value );
void lineColor ( int value );

int main ( int args_len, char ** args_context ) {

    glutInit ( &args_len, args_context );
    glutInitDisplayMode ( GLUT_SINGLE );
    glutInitWindowSize ( WIDTH, HEIGHT );
    glutInitWindowPosition ( 100, 100 );
    glutCreateWindow ( "OpenGL Midpoint Algorithm Simulation" );

    display.setMaxDisplaySize ( 20, 20 );
    // display.setBackgroundColor ( .3, .5, .6 );
    display.setBackgroundColor ( .0, .0, .0 );

    // menus
    int drawing_option = glutCreateMenu ( drawingOption );

    glutAddMenuEntry ( "DDA Line", 0 );
    glutAddMenuEntry ( "Midpoint Line", 1 );
    glutAddMenuEntry ( "Circle", 2 );
    glutAddMenuEntry ( "Circle Midpoint", 3 );

    int line_color_option = glutCreateMenu ( lineColor );

    glutAddMenuEntry ( "Black", 0 );
    glutAddMenuEntry ( "Green", 1 );
    glutAddMenuEntry ( "Violet", 2 );

    int main_menu = glutCreateMenu ( mainMenu );
    glutAddSubMenu ( "Drawing", drawing_option );
    glutAddSubMenu ( "Line Color", line_color_option );
    glutAttachMenu ( GLUT_RIGHT_BUTTON );

    line1.setLineDrawAlgorithm ( 1 );

    glutDisplayFunc ( render );

    glutMainLoop ();

    return 0;

};

void drawingOption ( int value ) {

    drawing_type = value;

    std::string center_pos;
    std::string number = "";
    int pos_x = 0, pos_y = 0;

    std::cout << "Specify center x and y position respectively with space: ";

    std::cin.sync ();
    std::getline ( std::cin, center_pos );

    for ( char character : center_pos ) {

        if ( character != ' ' ) {

            number += character;

        } else {

            std::stringstream ( number ) >> pos_x;

            number = "";

        }

    }

    std::stringstream ( number ) >> pos_y;

    switch ( value ) {

        case 0: {

            circle.setCenter ( pos_x, pos_y );

            glutPostRedisplay ();

            break;

        }

        default: {

            std::cout << "default" << std::endl;

        }

    }

};

void lineColor ( int value ) {

    line_color = value;

};

void mainMenu ( int value ) {

    drawingOption ( value );

    lineColor ( value );

};

void render () {

    glClear ( GL_COLOR_BUFFER_BIT );

    // display.showGrid ();
    // display.showAxis ();

    circle.draw ();
    line1.draw ();

    glFlush ();

};