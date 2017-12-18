
#ifndef LINE_H
#define LINE_H

#include <OpenGL/gl.h>
#include <iostream>

class Line {

    private:

        int * point1, * point2;

        int algorithm;

        int absoluteValue ( const int value );

        void digitalDifferentialAnalyzer ();
        void midpointAlgorithm ();

    public:

        Line ();
        Line ( const int x1, const int y1, const int x2, const int y2 );
        ~Line ();

        void draw ();

        void setInitialPoint ( const int x, const int y );
        void setFinalPoint ( const int x, const int y );
        void setLineDrawAlgorithm ( const int algorithm );

};

#endif