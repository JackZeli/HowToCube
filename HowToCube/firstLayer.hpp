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

Corner locateCorner(Cube &cube, Color c1, Color c2, Color c3);

void makeFull(Cube &cube);

void makeCross(Cube &cube);

bool cornerEq(const Corner &c1, const Corner &c2);

int getNum(Cube &cube);

int getPlace(Cube &cube);

void crossTest(Cube &cube);

void daisyTest(Cube &cube);

void fullTest(Cube &cube);

#endif /* firstLayer_hpp */
