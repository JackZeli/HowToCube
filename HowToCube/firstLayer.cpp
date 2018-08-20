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
    else{
        cout << "Cross test passed!" << endl;
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

int getNum(Cube &cube){
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
    return numWhite;
}

void daisyTest(Cube &cube){
    if(cube.yellowFace[0][1] == white && cube.yellowFace[1][0] == white && cube.yellowFace[1][2] == white && cube.yellowFace[2][1] == white){
        cout << "Daisy test passed!" << endl;
    }
}

void makeCross(Cube &cube){
    int numWhite = getNum(cube);
    bool b1 = false, b2 = false, b3 = false, b4 = false;
    
    while(numWhite < 4){
        pair<Color,Color> edge;
        if(b1 == false){
            edge = locateEdge(cube, white, blue);
        }
        else if(b2 == false){
            edge = locateEdge(cube, white, orange);
        }
        else if(b3 == false){
            edge = locateEdge(cube, white, green);
        }
        else if(b4 == false){
            edge = locateEdge(cube, white, red);
        }
        
        if(edge == cube.YB || edge == cube.YO || edge == cube.YG || edge == cube.YR){
            if(edge.first != white){
                if(edge == cube.YB){
                    cube.rotateFace(blue, 0);
                }
                else if(edge == cube.YO){
                    cube.rotateFace(orange, 0);
                }
                else if(edge == cube.YG){
                    cube.rotateFace(green, 0);
                }
                else{
                    cube.rotateFace(red, 0);
                }
            }
            else{
                if(b1 == false){
                    b1 = true;
                }
                else if(b2 == false){
                    b2 = true;
                }
                else if(b3 == false){
                    b3 = true;
                }
                else if(b4 == false){
                    b4 = true;
                }
            }
        }
        else if(edge == cube.WB || edge == cube.WO || edge == cube.WG || edge == cube.WR){
            if(edge == cube.WB){
                if(cube.YB.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(blue, 0);
                }
            }
            else if(edge == cube.WO){
                if(cube.YO.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(orange, 0);
                }
            }
            else if(edge == cube.WG){
                if(cube.YG.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(green, 0);
                }
            }
            else if(edge == cube.WR){
                if(cube.YR.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(red, 0);
                }
            }
        }
        else if(edge == cube.BO){
            if(edge.first == white){
                if(cube.YO.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(orange, 1);
                }
            }
            else{
                if(cube.YB.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(blue, 0);
                }
            }
        }
        else if(edge == cube.OG){
            if(edge.first == white){
                if(cube.YG.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(green, 1);
                }
            }
            else{
                if(cube.YO.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(orange, 0);
                }
            }
        }
        else if(edge == cube.GR){
            if(edge.first == white){
                if(cube.YR.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(red, 1);
                }
            }
            else{
                if(cube.YG.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(green, 0);
                }
                numWhite = getNum(cube);
            }
        }
        else if(edge == cube.RB){
            if(edge.first == white){
                if(cube.YB.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(blue, 1);
                }
            }
            else{
                if(cube.YR.first == white){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    cube.rotateFace(red, 0);
                }
            }
        }
        numWhite = getNum(cube);
    }
    
    pair<Color,Color> p1 = {white, blue};
    while(cube.YB != p1){
        cube.rotateFace(yellow, 0);
    }
    cube.rotateFace(blue, 0);
    cube.rotateFace(blue, 0);
    
    p1 = {white, orange};
    while(cube.YO != p1){
        cube.rotateFace(yellow, 0);
    }
    cube.rotateFace(orange, 0);
    cube.rotateFace(orange, 0);
    
    p1 = {white, green};
    while(cube.YG != p1){
        cube.rotateFace(yellow, 0);
    }
    cube.rotateFace(green, 0);
    cube.rotateFace(green, 0);
    
    p1 = {white, red};
    while(cube.YR != p1){
        cube.rotateFace(yellow, 0);
    }
    cube.rotateFace(red, 0);
    cube.rotateFace(red, 0);
    
}
