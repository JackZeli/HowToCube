//
//  Cube.cpp
//  HowToCube
//
//  Created by Jack Zeligson on 7/13/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#include "Cube.hpp"
#include <vector>
#include <string>
using namespace std;

Cube::Cube(){
    vector<vector<Color>> wface (3, vector<Color> (3, white));
    vector<vector<Color>> bface (3, vector<Color> (3, blue));
    vector<vector<Color>> oface (3, vector<Color> (3, orange));
    vector<vector<Color>> gface (3, vector<Color> (3, green));
    vector<vector<Color>> rface (3, vector<Color> (3, red));
    vector<vector<Color>> yface (3, vector<Color> (3, yellow));
    
    whiteFace = wface;
    blueFace = bface;
    orangeFace = oface;
    greenFace = gface;
    redFace = rface;
    yellowFace = yface;
}

void Cube::setEdges(){
    WB.first = whiteFace[2][1];
    WB.second = blueFace[0][1];
    
    WO.first = whiteFace[1][2];
    WO.second = orangeFace[0][1];
    
    WG.first = whiteFace[0][1];
    WG.second = greenFace[0][1];
    
    WR.first = whiteFace[1][0];
    WR.second = redFace[0][1];
    
    BO.first = blueFace[1][2];
    BO.second = orangeFace[1][0];
    
    OG.first = orangeFace[1][2];
    OG.second = greenFace[1][0];
    
    GR.first = greenFace[1][2];
    GR.second = redFace[1][0];
    
    RB.first = redFace[1][2];
    RB.second = blueFace[1][0];
    
    YB.first = yellowFace[2][1];
    YB.second = blueFace[2][1];
    
    YR.first = yellowFace[1][2];
    YR.second = redFace[2][1];
    
    YG.first = yellowFace[0][1];
    YG.second = greenFace[2][1];
    
    YO.first = yellowFace[1][0];
    YO.second = orangeFace[2][1];
}
