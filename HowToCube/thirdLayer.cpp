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
    
    while(finalMove(cube) == white){
        Color c = checkForPattern(cube);
        if(finalMove(cube) == white){
            downright(cube, c);
        }
        else{
            break;
        }
    }
    //cout << "made it here" << endl;
    while(!isSolved(cube)){
        finalStep(cube);
    }
    cout << "SOLVED!!!" << endl;
}

Color checkForPattern(Cube &cube){
    int i = 0;
    while(i != 1){
        if(cube.blueFace[2][0] == cube.blueFace[2][2]){
            if(cube.blueFace[2][0] == blue){
                return green;
            }
            else{
                cube.rotateFace(yellow, 0);
            }
        }
        else if(cube.redFace[2][0] == cube.redFace[2][2]){
            if(cube.redFace[2][0] == red){
                return orange;
            }
            else{
                cube.rotateFace(yellow, 0);
            }
        }
        else if(cube.greenFace[2][0] == cube.greenFace[2][2]){
            if(cube.greenFace[2][0] == green){
                return blue;
            }
            else{
                cube.rotateFace(yellow, 0);
            }
        }
        else if(cube.orangeFace[2][0] == cube.orangeFace[2][2]){
            if(cube.orangeFace[2][0] == orange){
                return red;
            }
            else{
                cube.rotateFace(yellow, 0);
            }
        }
        else{
            return blue;
        }
    }
    return blue;
}

void downright(Cube &cube, Color c1){
    Color face1, face2, face3;
    if(c1 == blue){
        face1 = blue;
        face2 = red;
        face3 = green;
    }
    else if(c1 == red){
        face1 = red;
        face2 = green;
        face3 = orange;
    }
    else if(c1 == green){
        face1 = green;
        face2 = orange;
        face3 = blue;
    }
    else if(c1 == orange){
        face1 = orange;
        face2 = blue;
        face3 = red;
    }

    cube.rotateFace(face2, 1);
    cube.rotateFace(face1, 0);
    cube.rotateFace(face2, 1);
    cube.rotateFace(face3, 0);
    cube.rotateFace(face3, 0);
    cube.rotateFace(face2, 0);
    cube.rotateFace(face1, 1);
    cube.rotateFace(face2, 1);
    cube.rotateFace(face3, 0);
    cube.rotateFace(face3, 0);
    cube.rotateFace(face2, 1);
    cube.rotateFace(face2, 1);
}

Color finalMove(Cube &cube){
    if(cube.redFace[2][0] == red && cube.redFace[2][2] == red && cube.redFace[2][1] != red && cube.orangeFace[2][0] == orange && cube.orangeFace[2][2] == orange && cube.orangeFace[2][1] != orange && cube.greenFace[2][1] != green){
        return green;
    }
    else if(cube.greenFace[2][0] == green && cube.greenFace[2][2] == green && cube.greenFace[2][1] != green && cube.blueFace[2][0] == blue && cube.blueFace[2][2] == blue && cube.blueFace[2][1] != blue && cube.orangeFace[2][1] != orange){
        return orange;
    }
    else if(cube.redFace[2][0] == red && cube.redFace[2][2] == red && cube.redFace[2][1] != red && cube.orangeFace[2][0] == orange && cube.orangeFace[2][2] == orange && cube.orangeFace[2][1] != orange && cube.blueFace[2][1] != blue){
        return blue;
    }
    else if(cube.greenFace[2][0] == green && cube.greenFace[2][2] == green && cube.greenFace[2][1] != green && cube.blueFace[2][0] == blue && cube.blueFace[2][2] == blue && cube.blueFace[2][1] != blue && cube.redFace[2][1] != red){
        return red;
    }
    else{
        return white;
    }
}

void finalStep(Cube &cube){
    Color f1 = finalMove(cube);
    Color f2, f3;
    int dir = 0;
    if(f1 == blue){
        f2 = orange;
        f3 = red;
        if(cube.orangeFace[2][1] == blue){
            dir = 1;
        }
        else if(cube.redFace[2][1] == blue){
            dir = 0;
        }
    }
    else if(f1 == red){
        f2 = blue;
        f3 = green;
        if(cube.blueFace[2][1] == red){
            dir = 1;
        }
        else if(cube.greenFace[2][1] == red){
            dir = 0;
        }
    }
    else if(f1 == green){
        f2 = red;
        f3 = orange;
        if(cube.redFace[2][1] == green){
            dir = 1;
        }
        else if(cube.orangeFace[2][1] == green){
            dir = 0;
        }
    }
    else if(f1 == orange){
        f2 = green;
        f3 = blue;
        if(cube.greenFace[2][1] == orange){
            dir = 1;
        }
        else if(cube.blueFace[2][1] == orange){
            dir = 0;
        }
    }
    cube.rotateFace(f1, 0);
    cube.rotateFace(f1, 0);
    if(dir == 0){
        cube.rotateFace(yellow, 0);
    }
    else{
        cube.rotateFace(yellow, 1);
    }
    cube.rotateFace(f2, 0);
    cube.rotateFace(f3, 1);
    cube.rotateFace(f1, 0);
    cube.rotateFace(f1, 0);
    cube.rotateFace(f2, 1);
    cube.rotateFace(f3, 0);
    if(dir == 0){
        cube.rotateFace(yellow, 0);
    }
    else{
        cube.rotateFace(yellow, 1);
    }
    cube.rotateFace(f1, 0);
    cube.rotateFace(f1, 0);
}

bool isSolved(Cube &cube){
    vector<vector<Color>> wface (3, vector<Color> (3, white));
    vector<vector<Color>> bface (3, vector<Color> (3, blue));
    vector<vector<Color>> oface (3, vector<Color> (3, orange));
    vector<vector<Color>> gface (3, vector<Color> (3, green));
    vector<vector<Color>> rface (3, vector<Color> (3, red));
    vector<vector<Color>> yface (3, vector<Color> (3, yellow));
    
    if(cube.whiteFace != wface){
        return false;
    }
    else if(cube.blueFace != bface){
        return false;
    }
    else if(cube.orangeFace != oface){
        return false;
    }
    else if(cube.greenFace != gface){
        return false;
    }
    else if(cube.redFace != rface){
        return false;
    }
    else if(cube.yellowFace != yface){
        return false;
    }
    else{
        return true;
    }
}
