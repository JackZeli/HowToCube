//
//  thirdLayer.cpp
//  HowToCube
//
//  Created by Jack Zeligson on 8/24/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#include "thirdLayer.hpp"
#include "Cube.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool isNine(Cube &cube){
    if(cube.yellowFace[0][1] == yellow && cube.yellowFace[1][0] == yellow && !isCross(cube)){
        return true;
    }
    else if(cube.yellowFace[0][1] == yellow && cube.yellowFace[1][2] == yellow && !isCross(cube)){
        cube.rotateFace(yellow, 1);
        return true;
    }
    else if(cube.yellowFace[1][2] == yellow && cube.yellowFace[2][1] == yellow && !isCross(cube)){
        cube.rotateFace(yellow, 1);
        cube.rotateFace(yellow, 1);
        return true;
    }
    else if(cube.yellowFace[1][0] == yellow && cube.yellowFace[2][1] == yellow && !isCross(cube)){
        cube.rotateFace(yellow, 0);
        return true;
    }
    return false;
}

bool isCross(Cube &cube){
    if(cube.yellowFace[0][1] == yellow && cube.yellowFace[1][0] == yellow && cube.yellowFace[1][2] == yellow && cube.yellowFace[2][1] == yellow){
        return true;
    }
    return false;
}

bool isFish(Cube &cube){
    if(isCross(cube)){
        if(cube.yellowFace[2][0] == yellow && cube.yellowFace[0][0] != yellow && cube.yellowFace[2][2] != yellow){
            return true;
        }
        else if(cube.yellowFace[0][0] == yellow && cube.yellowFace[2][0] != yellow && cube.yellowFace[0][2] != yellow){
            cube.rotateFace(yellow, 1);
            return true;
        }
        else if(cube.yellowFace[0][2] == yellow && cube.yellowFace[0][0] != yellow && cube.yellowFace[2][2] != yellow){
            cube.rotateFace(yellow, 1);
            cube.rotateFace(yellow, 1);
            return true;
        }
        else if(cube.yellowFace[2][2] == yellow && cube.yellowFace[2][0] != yellow && cube.yellowFace[0][2] != yellow){
            cube.rotateFace(yellow, 0);
            return true;
        }
    }
    return false;
}

bool isTank(Cube &cube){
    if(isCross(cube)){
        if(cube.yellowFace[2][0] != yellow && cube.yellowFace[2][2] != yellow && cube.yellowFace[0][0] == yellow && cube.yellowFace[0][2] == yellow){
            return true;
        }
        else if(cube.yellowFace[2][0] == yellow && cube.yellowFace[2][2] != yellow && cube.yellowFace[0][0] == yellow && cube.yellowFace[0][2] != yellow){
            cube.rotateFace(yellow, 0);
            return true;
        }
        else if(cube.yellowFace[2][0] == yellow && cube.yellowFace[2][2] == yellow && cube.yellowFace[0][0] != yellow && cube.yellowFace[0][2] != yellow){
            cube.rotateFace(yellow, 0);
            cube.rotateFace(yellow, 0);
            return true;
        }
        else if(cube.yellowFace[2][0] != yellow && cube.yellowFace[2][2] == yellow && cube.yellowFace[0][0] != yellow && cube.yellowFace[0][2] == yellow){
            cube.rotateFace(yellow, 1);
            return true;
        }
    }
    return false;
}

bool isFull(Cube &cube){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(cube.yellowFace[i][j] != yellow){
                return false;
            }
        }
    }
    cout << "IS FULL!" << endl;
    return true;
}

void fururf(Cube &cube){
    cube.rotateFace(blue, 0);
    cube.rotateFace(yellow, 0);
    cube.rotateFace(red, 0);
    cube.rotateFace(yellow, 1);
    cube.rotateFace(red, 1);
    cube.rotateFace(blue, 1);
}

void uldlulld(Cube &cube){
    cube.rotateFace(red, 0);
    cube.rotateFace(yellow, 0);
    cube.rotateFace(red, 1);
    cube.rotateFace(yellow, 0);
    cube.rotateFace(red, 0);
    cube.rotateFace(yellow, 0);
    cube.rotateFace(yellow, 0);
    cube.rotateFace(red, 1);
}

void doThird(Cube &cube){
    while(!isFull(cube)){
        if(isNine(cube)){
            fururf(cube);
        }
        else if(isCross(cube) && !isFish(cube) && !isTank(cube)){
            uldlulld(cube);
        }
        else if(isFish(cube) && !isTank(cube)){
            uldlulld(cube);
        }
        else if(isTank(cube)){
            uldlulld(cube);
        }
        else{
            fururf(cube);
        }
    }
}

bool finalMove(Cube &cube){
    return false;
}
