#include <iostream>
#include "ShapeContainer.h"
#include "Square.h"
#include "Circle.h"
#include "Triangle.h"

int main()
{
    ShapeContainer cont;
    Square sq1("square A",20),sq2("sqaure B", 15);
    Circle circ1("Small circle", 1);
    Triangle trig("Right triangle 1", 3,4,5);

    cont.addShape(sq1);
    cont.addShape(circ1);
    cont.addShape(sq2);
    cont.addShape(trig);

    cont.printPerimeters();
    cont.printShapes();
}