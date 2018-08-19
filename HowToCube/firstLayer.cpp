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

pair<Color, Color> locateEdge(Cube &cube, Color c1, Color c2){
    vector<pair<Color,Color>> edges;
    edges.push_back(cube.WB);
    edges.push_back(cube.WO);
    edges.push_back(cube.WG);
    edges.push_back(cube.WR);
    edges.push_back(cube.BO);
    edges.push_back(cube.OG);
    edges.push_back(cube.GR);
    edges.push_back(cube.RB);
    edges.push_back(cube.YB);
    edges.push_back(cube.YO);
    edges.push_back(cube.YG);
    edges.push_back(cube.YR);
    
    pair<Color, Color> grn;
    
    for(int i = 0; i < edges.size(); ++i){
        pair<Color, Color> curEdge = edges[i];
        if((curEdge.first == c1 && curEdge.second == c2) || (curEdge.first == c2 && curEdge.second == c1)){
            return curEdge;
        }
    }
    return grn;
}

Color getFace(pair<Color,Color> &edge){
    
       
    return green;
}

void makeCross(Cube &cube){
    int numWhite = 0;
    if(cube.yellowFace[0][1] == white){
        numWhite++;
    }
    if(cube.yellowFace[1][0] == white){
        numWhite++;
    }
    if(cube.yellowFace[1][2] == white){
        numWhite++;
    }
    if(cube.yellowFace[2][1] == white){
        numWhite++;
    }
    
    while(numWhite < 4){
        pair<Color,Color> edge = locateEdge(cube, white, blue);
        if(edge == cube.YB || edge == cube.YO || edge == cube.YG || edge == cube.YR){
            if(edge.first != white){
                
            }
        }
    }
    
    
    
}
