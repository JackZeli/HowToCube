//
//  firstLayer.hpp
//  HowToCube
//
//  Created by Jack Zeligson on 8/5/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#ifndef firstLayer_hpp
#define firstLayer_hpp

#include <stdio.h>
#include "Cube.hpp"
#include <vector>


std::pair<Color, Color> locateEdge(Cube &cube, Color c1, Color c2);

void makeCross(Cube &cube);

void crossTest(Cube &cube);

#endif /* firstLayer_hpp */
