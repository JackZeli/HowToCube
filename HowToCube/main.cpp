//
//  main.cpp
//  HowToCube
//
//  Created by Jack Zeligson on 7/9/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#include <iostream>
#include "Cube.hpp"
#include "firstLayer.hpp"

int main(int argc, const char * argv[]) {
    Cube rubiks;
    rubiks.shuffle();
    crossTest(rubiks);
    return 0;
}
