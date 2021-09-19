//
// Created by SashaPaladin on 15.09.2021.
//

#ifndef FIGURE_H
#define FIGURE_H

#include <cstddef>
#include <iostream>
#include <vector>
#include "point.h"

class Figure {
public:
    virtual void Print(std::ostream& os) = 0;

    virtual double Area() = 0;

    virtual size_t VertexesNumbers() = 0;

    virtual  ~Figure() = default;
};


#endif //FIGURE_H
