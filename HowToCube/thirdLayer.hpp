//
//  thirdLayer.hpp
//  HowToCube
//
//  Created by Jack Zeligson on 8/24/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#ifndef thirdLayer_hpp
#define thirdLayer_hpp

#include <stdio.h>
#include "Cube.hpp"

bool isNine(Cube &cube);

bool isCross(Cube &cube);

bool isTank(Cube &cube);

bool isFish(Cube &cube);

bool isFull(Cube &cube);

void doThird(Cube &cube);

void fururf(Cube &cube);

void uldlulld(Cube &cube);

void finalStep(Cube &cube);

void downright(Cube &cube, Color c1);

Color checkForPattern(Cube &cube);

Color finalMove(Cube &cube);

bool isSolved(Cube &cube);

#endif /* thirdLayer_hpp */
