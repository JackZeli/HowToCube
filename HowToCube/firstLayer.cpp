//
//  firstLayer.cpp
//  HowToCube
//
//  Created by Jack Zeligson on 8/5/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#include "firstLayer.hpp"
#include "Cube.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void crossTest(Cube &cube){
    vector<string> colorTypes = {"white", "blue", "orange", "green", "red", "yellow"};
    
    if(cube.WB.first != white || cube.WB.second != blue){
        cout << "Wrong piece in the White-Blue edge, the piece that's there is " << colorTypes[cube.whiteFace[2][1]] << ", " << colorTypes[cube.blueFace[0][1]] << endl;
    }
    else if(cube.WO.first != white || cube.WO.second != orange){
        cout << "Wrong piece in the White-Orange edge, the piece that's there is " << colorTypes[cube.whiteFace[1][2]] << ", " << colorTypes[cube.orangeFace[0][1]] << endl;
    }
    else if(cube.WG.first != white || cube.WG.second != green){
        cout << "Wrong piece in the White-Green edge, the piece that's there is " << colorTypes[cube.whiteFace[0][1]] << ", " << colorTypes[cube.greenFace[0][1]] << endl;
    }
    else if(cube.WR.first != white || cube.WR.second != red){
        cout << "Wrong piece in the White-Red edge, the piece that's there is " << colorTypes[cube.whiteFace[1][0]] << ", " << colorTypes[cube.redFace[0][1]] << endl;
    }
    return;
}
