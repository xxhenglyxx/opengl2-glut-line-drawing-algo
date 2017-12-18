
#include "Line.h"

Line::Line () {

    this -> point1 = new int [ 2 ];
    this -> point1 [ 0 ] = 0;
    this -> point1 [ 1 ] = 0;
    this -> point2 = new int [ 2 ];
    this -> point2 [ 0 ] = 10;
    this -> point2 [ 1 ] = 10;

    this -> algorithm = 0;

};

Line::Line ( const int x1, const int y1, const int x2, const int y2 ) {

    this -> point1 = new int [ 2 ];
    this -> point1 [ 0 ] = x1;
    this -> point1 [ 1 ] = y1;
    this -> point2 = new int [ 2 ];
    this -> point2 [ 0 ] = x2;
    this -> point2 [ 1 ] = y2;
    
    this -> algorithm = 0;

};

Line::~Line () {

    delete[] point1;
    delete[] point2;

};

void Line::setInitialPoint ( const int x, const int y ) {

    this -> point1 [ 0 ] = x;
    this -> point1 [ 1 ] = y;

};

void Line::setFinalPoint ( const int x, const int y ) {

    this -> point2 [ 0 ] = x;
    this -> point2 [ 1 ] = y;

};

int Line::absoluteValue ( const int value ) {

    return ( value > 0 ? value : value * -1 );

};

void Line::setLineDrawAlgorithm ( const int algorithm ) {

    this -> algorithm = algorithm;

};

void Line::digitalDifferentialAnalyzer () {

    int x_differences = this -> point2 [ 0 ] - this -> point1 [ 1 ],
        y_differences = this -> point2 [ 1 ] - this -> point1 [ 1 ];

    int pixel_generate_steps =
        this -> absoluteValue ( x_differences ) > this -> absoluteValue ( y_differences ) ?
           this -> absoluteValue ( x_differences ) : this -> absoluteValue ( y_differences );

    float
        x_increment = x_differences / pixel_generate_steps * 1.0,
        y_increment = y_differences / pixel_generate_steps * 1.0;

    float
        x = this -> point1 [ 0 ] * 1.0,
        y = this -> point1 [ 1 ] * 1.0;

    int index = 0;

    for ( ; index <= pixel_generate_steps; ++ index ) {

        glBegin ( GL_POINTS );

            glColor3d ( 1.0, .0, .0 );

            glVertex2d ( x, y );

        glEnd ();

        x += x_increment;
        y += y_increment;

    }

};

void Line::draw () {

    const int & algo = this -> algorithm;

    if ( algo == 0 ) {

        this -> digitalDifferentialAnalyzer ();

    } else {

        this -> midpointAlgorithm ();

    }

};

void Line::midpointAlgorithm () {

    int x_differences = this -> point2 [ 0 ] - this -> point1 [ 1 ],
        y_differences = this -> point2 [ 1 ] - this -> point1 [ 1 ];

    int
        decision = y_differences - ( x_differences / 2 ),
        x = this -> point1 [ 0 ],
        y = this -> point1 [ 1 ];

    glBegin ( GL_POINTS );

        glVertex2d ( x, y );

    glEnd ();

    while ( x < this -> point2 [ 1 ] ) {

        ++x;

        if ( decision < 0 ) decision = decision + y_differences;

        else {

            decision += ( y_differences - x_differences );
            ++y;

        }
        
        glBegin ( GL_POINTS );

            glVertex2d ( x, y );

        glEnd ();

    }

};