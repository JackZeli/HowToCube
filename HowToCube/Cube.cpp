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
#include <stdlib.h>
#include <time.h>
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
    
    setEdges();
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

void Cube::rotateFace(vector<vector<Color>> &face, int dir){
    vector<Color> v1 (3);
    vector<Color> v2 (3);
    vector<Color> v3 (3);
    vector<Color> v4 (3);
    if(face == whiteFace){
        v1[0] = blueFace[0][0];
        v1[1] = blueFace[0][1];
        v1[2] = blueFace[0][2];
        
        v2[0] = orangeFace[0][0];
        v2[1] = orangeFace[0][1];
        v2[2] = orangeFace[0][2];
        
        v3[0] = greenFace[0][0];
        v3[1] = greenFace[0][1];
        v3[2] = greenFace[0][2];
        
        v4[0] = redFace[0][0];
        v4[1] = redFace[0][1];
        v4[2] = redFace[0][2];

        if(dir == 0){ // clockwise
            blueFace[0][0] = v2[0];
            blueFace[0][1] = v2[1];
            blueFace[0][2] = v2[2];
        
            orangeFace[0][0] = v3[0];
            orangeFace[0][1] = v3[1];
            orangeFace[0][2] = v3[2];
        
            greenFace[0][0] = v4[0];
            greenFace[0][1] = v4[1];
            greenFace[0][2] = v4[2];
        
            redFace[0][0] = v1[0];
            redFace[0][1] = v1[1];
            redFace[0][2] = v1[2];
        }
        else{ // counter clockwise
            blueFace[0][0] = v4[0];
            blueFace[0][1] = v4[1];
            blueFace[0][2] = v4[2];
            
            orangeFace[0][0] = v1[0];
            orangeFace[0][1] = v1[1];
            orangeFace[0][2] = v1[2];
            
            greenFace[0][0] = v2[0];
            greenFace[0][1] = v2[1];
            greenFace[0][2] = v2[2];
            
            redFace[0][0] = v3[0];
            redFace[0][1] = v3[1];
            redFace[0][2] = v3[2];
        }
        
    }
    else if(face == blueFace){
        v1[0] = whiteFace[2][0];
        v1[1] = whiteFace[2][1];
        v1[2] = whiteFace[2][2];
        
        v2[0] = orangeFace[0][0];
        v2[1] = orangeFace[1][0];
        v2[2] = orangeFace[2][0];
        
        v3[0] = yellowFace[2][0];
        v3[1] = yellowFace[2][1];
        v3[2] = yellowFace[2][2];
        
        v4[0] = redFace[0][2];
        v4[1] = redFace[1][2];
        v4[2] = redFace[2][2];
        
        if(dir == 0){ //clockwise
            whiteFace[2][0] = v4[0];
            whiteFace[2][1] = v4[1];
            whiteFace[2][2] = v4[2];
            
            orangeFace[0][0] = v1[0];
            orangeFace[1][0] = v1[1];
            orangeFace[2][0] = v1[2];
            
            yellowFace[2][0] = v2[0];
            yellowFace[2][1] = v2[1];
            yellowFace[2][2] = v2[2];
            
            redFace[0][2] = v3[0];
            redFace[1][2] = v3[1];
            redFace[2][2] = v3[2];
        }
        else{ //counter clockwise
            whiteFace[2][0] = v2[0];
            whiteFace[2][1] = v2[1];
            whiteFace[2][2] = v2[2];
            
            orangeFace[0][0] = v3[0];
            orangeFace[1][0] = v3[1];
            orangeFace[2][0] = v3[2];
            
            yellowFace[2][0] = v4[0];
            yellowFace[2][1] = v4[1];
            yellowFace[2][2] = v4[2];
        
            redFace[0][2] = v1[0];
            redFace[1][2] = v1[1];
            redFace[2][2] = v1[2];
        }
    }
    else if(face == orangeFace){
        v1[0] = whiteFace[0][2];
        v1[1] = whiteFace[1][2];
        v1[2] = whiteFace[2][2];
        
        v2[0] = greenFace[0][0];
        v2[1] = greenFace[1][0];
        v2[2] = greenFace[2][0];
        
        v3[0] = yellowFace[0][0];
        v3[1] = yellowFace[1][0];
        v3[2] = yellowFace[2][0];
        
        v4[0] = blueFace[0][2];
        v4[1] = blueFace[1][2];
        v4[2] = blueFace[2][2];
        
        if(dir == 0){
            whiteFace[0][2] = v4[0];
            whiteFace[1][2] = v4[1];
            whiteFace[2][2] = v4[2];
        
            greenFace[0][0] = v1[0];
            greenFace[1][0] = v1[1];
            greenFace[2][0] = v1[2];
        
            yellowFace[0][0] = v2[0];
            yellowFace[1][0] = v2[1];
            yellowFace[2][0] = v2[2];
        
            blueFace[0][2] = v3[0];
            blueFace[1][2] = v3[1];
            blueFace[2][2] = v3[2];
        }
        else{
            whiteFace[0][2] = v2[0];
            whiteFace[1][2] = v2[1];
            whiteFace[2][2] = v2[2];
            
            greenFace[0][0] = v3[0];
            greenFace[1][0] = v3[1];
            greenFace[2][0] = v3[2];
            
            yellowFace[0][0] = v4[0];
            yellowFace[1][0] = v4[1];
            yellowFace[2][0] = v4[2];
            
            blueFace[0][2] = v1[0];
            blueFace[1][2] = v1[1];
            blueFace[2][2] = v1[2];
        }
    }
    else if(face == greenFace){
        v1[0] = whiteFace[0][0];
        v1[1] = whiteFace[0][1];
        v1[2] = whiteFace[0][2];
        
        v2[0] = redFace[0][0];
        v2[1] = redFace[1][0];
        v2[2] = redFace[2][0];
        
        v3[0] = yellowFace[0][0];
        v3[1] = yellowFace[0][1];
        v3[2] = yellowFace[0][2];
        
        v4[0] = orangeFace[0][2];
        v4[1] = orangeFace[1][2];
        v4[2] = orangeFace[2][2];
        
        if(dir == 0){
            whiteFace[0][0] = v4[0];
            whiteFace[0][1] = v4[1];
            whiteFace[0][2] = v4[2];
        
            redFace[0][0] = v1[0];
            redFace[1][0] = v1[1];
            redFace[2][0] = v1[2];
        
            yellowFace[0][0] = v2[0];
            yellowFace[0][1] = v2[1];
            yellowFace[0][2] = v2[2];
        
            orangeFace[0][2] = v3[0];
            orangeFace[1][2] = v3[1];
            orangeFace[2][2] = v3[2];
        }
        else{
            whiteFace[0][0] = v2[0];
            whiteFace[0][1] = v2[1];
            whiteFace[0][2] = v2[2];
            
            redFace[0][0] = v3[0];
            redFace[1][0] = v3[1];
            redFace[2][0] = v3[2];
            
            yellowFace[0][0] = v4[0];
            yellowFace[0][1] = v4[1];
            yellowFace[0][2] = v4[2];
            
            orangeFace[0][2] = v1[0];
            orangeFace[1][2] = v1[1];
            orangeFace[2][2] = v1[2];
        }
    }
    else if(face == redFace){
        v1[0] = whiteFace[0][0];
        v1[1] = whiteFace[1][0];
        v1[2] = whiteFace[2][0];
        
        v2[0] = blueFace[0][0];
        v2[1] = blueFace[1][0];
        v2[2] = blueFace[2][0];
        
        v3[0] = yellowFace[0][2];
        v3[1] = yellowFace[1][2];
        v3[2] = yellowFace[2][2];
        
        v4[0] = greenFace[0][2];
        v4[1] = greenFace[1][2];
        v4[2] = greenFace[2][2];
        
        if(dir == 0){
            whiteFace[0][0] = v4[0];
            whiteFace[1][0] = v4[1];
            whiteFace[2][0] = v4[2];
        
            blueFace[0][0] = v1[0];
            blueFace[1][0] = v1[1];
            blueFace[2][0] = v1[2];
        
            yellowFace[0][2] = v2[0];
            yellowFace[1][2] = v2[1];
            yellowFace[2][2] = v2[2];
        
            greenFace[0][2] = v3[0];
            greenFace[1][2] = v3[1];
            greenFace[2][2] = v3[2];
        }
        else{
            whiteFace[0][0] = v2[0];
            whiteFace[1][0] = v2[1];
            whiteFace[2][0] = v2[2];
            
            blueFace[0][0] = v3[0];
            blueFace[1][0] = v3[1];
            blueFace[2][0] = v3[2];
            
            yellowFace[0][2] = v4[0];
            yellowFace[1][2] = v4[1];
            yellowFace[2][2] = v4[2];
            
            greenFace[0][2] = v1[0];
            greenFace[1][2] = v1[1];
            greenFace[2][2] = v1[2];
        }
    }
    else if(face == yellowFace){
        v1[0] = blueFace[2][0];
        v1[1] = blueFace[2][1];
        v1[2] = blueFace[2][2];
        
        v2[0] = redFace[2][0];
        v2[1] = redFace[2][1];
        v2[2] = redFace[2][2];
        
        v3[0] = greenFace[2][0];
        v3[1] = greenFace[2][1];
        v3[2] = greenFace[2][2];
        
        v4[0] = orangeFace[2][0];
        v4[1] = orangeFace[2][1];
        v4[2] = orangeFace[2][2];
        
        if(dir == 0){
            blueFace[2][0] = v2[0];
            blueFace[2][1] = v2[1];
            blueFace[2][2] = v2[2];
            
            redFace[2][0] = v3[0];
            redFace[2][1] = v3[1];
            redFace[2][2] = v3[2];
            
            greenFace[2][0] = v4[0];
            greenFace[2][1] = v4[1];
            greenFace[2][2] = v4[2];

            orangeFace[2][0] = v1[0];
            orangeFace[2][1] = v1[1];
            orangeFace[2][2] = v1[2];
        }
        else{
            blueFace[2][0] = v4[0];
            blueFace[2][1] = v4[1];
            blueFace[2][2] = v4[2];
            
            redFace[2][0] = v1[0];
            redFace[2][1] = v1[1];
            redFace[2][2] = v1[2];
            
            greenFace[2][0] = v2[0];
            greenFace[2][1] = v2[1];
            greenFace[2][2] = v2[2];
            
            orangeFace[2][0] = v3[0];
            orangeFace[2][1] = v3[1];
            orangeFace[2][2] = v3[2];
        }
    }
    
    v1[0] = face[0][0];
    v1[1] = face[0][1];
    v1[2] = face[0][2];
    
    v2[0] = face[0][2];
    v2[1] = face[1][2];
    v2[2] = face[2][2];
    
    v3[0] = face[2][2];
    v3[1] = face[2][1];
    v3[2] = face[2][0];
    
    v4[0] = face[2][0];
    v4[1] = face[1][0];
    v4[2] = face[0][0];
    
    if(dir == 0){
        face[0][0] = v4[0];
        face[0][1] = v4[1];
        face[0][2] = v4[2];
        
        face[0][2] = v1[0];
        face[1][2] = v1[1];
        face[2][2] = v1[2];
        
        face[2][2] = v2[0];
        face[2][1] = v2[1];
        face[2][0] = v2[2];
        
        face[2][0] = v3[0];
        face[1][0] = v3[1];
        face[0][0] = v3[2];
    }
    else{
        face[0][0] = v2[0];
        face[0][1] = v2[1];
        face[0][2] = v2[2];
        
        face[0][2] = v3[0];
        face[1][2] = v3[1];
        face[2][2] = v3[2];
        
        face[2][2] = v4[0];
        face[2][1] = v4[1];
        face[2][0] = v4[2];
        
        face[2][0] = v1[0];
        face[1][0] = v1[1];
        face[0][0] = v1[2];
    }
    setEdges();
}

void Cube::shuffle(){
    srand(time(NULL));
    for(int i = 0; i < 100; ++i){
        int num = rand() % 6;
        int dir = rand() % 2;
        if(num == 0){
            rotateFace(whiteFace, dir);
        }
        else if(num == 1){
            rotateFace(blueFace, dir);
        }
        else if(num == 2){
            rotateFace(orangeFace, dir);
        }
        else if(num == 3){
            rotateFace(greenFace, dir);
        }
        else if(num == 4){
            rotateFace(redFace, dir);
        }
        else if(num == 5){
            rotateFace(yellowFace, dir);
        }
    }
}









