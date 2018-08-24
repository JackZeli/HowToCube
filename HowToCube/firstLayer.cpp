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

Corner locateCorner(Cube &cube, Color c1, Color c2, Color c3){
    vector<Corner> corners;
    corners.push_back(cube.WBO);
    corners.push_back(cube.WOG);
    corners.push_back(cube.WGR);
    corners.push_back(cube.WRB);
    corners.push_back(cube.YBR);
    corners.push_back(cube.YRG);
    corners.push_back(cube.YGO);
    corners.push_back(cube.YOB);
    
    for(int i = 0; i < corners.size(); ++i){
        Corner curCorner = corners[i];
        if(curCorner.first == c1 && curCorner.second == c2 && curCorner.third == c3){
            return curCorner;
        }
        else if(curCorner.first == c1 && curCorner.second == c3 && curCorner.third == c2){
            return curCorner;
        }
        else if(curCorner.first == c2 && curCorner.second == c1 && curCorner.third == c3){
            return curCorner;
        }
        else if(curCorner.first == c2 && curCorner.second == c3 && curCorner.third == c1){
            return curCorner;
        }
        else if(curCorner.first == c3 && curCorner.second == c1 && curCorner.third == c2){
            return curCorner;
        }
        else if(curCorner.first == c3 && curCorner.second == c2 && curCorner.third == c1){
            return curCorner;
        }
    }
    
    Corner corn;
    return corn;
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

bool cornerEq(const Corner &c1, const Corner &c2){
    if(c1.first == c2.first && c1.second == c2.second && c1.third == c2.third){
        return true;
    }
    else if(c1.first == c2.first && c1.second == c2.third && c1.third == c2.second){
        return true;
    }
    else if(c1.first == c2.second && c1.second == c2.first && c1.third == c2.second){
        return true;
    }
    else if(c1.first == c2.second && c1.second == c2.third && c1.third == c2.first){
        return true;
    }
    else if(c1.first == c2.third && c1.second == c2.first && c1.third == c2.second){
        return true;
    }
    else if(c1.first == c2.third && c1.second == c2.second && c1.third == c2.first){
        return true;
    }
    
    return false;
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

void fullTest(Cube &cube){
    int counter = 0;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            if(cube.whiteFace[i][j] == white){
                counter++;
            }
        }
    }
    if(counter == 9){
        cout << "Full test passed!" << endl;
    }
    else{
        cout << "Full test failed :(" << endl;
    }
    
    //cube.printCube();
}

int getPlace(Cube &cube){
    int val = 0;
    if(cube.whiteFace[0][0] == white){
        val++;
    }
    if(cube.whiteFace[2][0] == white){
        val++;
    }
    if(cube.whiteFace[0][2] == white){
        val++;
    }
    if(cube.whiteFace[2][2] == white){
        val++;
    }
    return val;
}

void makeFull(Cube &cube){
    int inPlace = 0;
    bool b1 = false, b2 = false, b3 = false, b4 = false;
    
    Corner curCorner;
    Corner goalCorner;
    Corner opCorner;
    Color c1, c2, c3;
   // cube.printCube();
    while(inPlace < 4){
   // cout << inPlace << " " << b1 << " " << b2 << " " << b3 << " " << b4 << endl;
        if(b1 == false){
            curCorner = locateCorner(cube, white, blue, orange);
            goalCorner = cube.WBO;
            c1 = white;
            c2 = blue;
            c3 = orange;
            opCorner = cube.YOB;
        }
        else if(b2 == false){
            curCorner = locateCorner(cube, white, orange, green);
            goalCorner = cube.WOG;
            c1 = white;
            c2 = orange;
            c3 = green;
            opCorner = cube.YGO;
        }
        else if(b3 == false){
            curCorner = locateCorner(cube, white, green, red);
            goalCorner = cube.WGR;
            c1 = white;
            c2 = green;
            c3 = red;
            opCorner = cube.YRG;
        }
        else if(b4 == false){
            curCorner = locateCorner(cube, white, red, blue);
            goalCorner = cube.WRB;
            c1 = white;
            c2 = red;
            c3 = blue;
            opCorner = cube.YBR;
        }
        
        if(goalCorner.first != c1 || goalCorner.second != c2 || goalCorner.third != c3){
            if(cornerEq(curCorner,cube.YBR) || cornerEq(curCorner,cube.YRG) || cornerEq(curCorner,cube.YGO) || cornerEq(curCorner,cube.YOB)){
                if(!cornerEq(curCorner, opCorner)){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    while(goalCorner.first != c1 || goalCorner.second != c2 || goalCorner.third != c3){
                        cube.rotateFace(c2, 0);
                        cube.rotateFace(yellow, 0);
                        cube.rotateFace(c2, 1);
                        cube.rotateFace(yellow, 1);
                        if(b1 == false){
                            goalCorner = cube.WBO;
                        }
                        else if(b2 == false){
                            goalCorner = cube.WOG;
                        }
                        else if(b3 == false){
                            goalCorner = cube.WGR;
                        }
                        else{
                            goalCorner = cube.WRB;
                        }
                    }
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
                    inPlace = getPlace(cube);
                }
            }
            else{
                Color c;
                if(cornerEq(curCorner,cube.WRB)){
                    c = red;
                }
                else if(cornerEq(curCorner,cube.WBO)){
                    c = blue;
                }
                else if(cornerEq(curCorner,cube.WOG)){
                    c = orange;
                }
                else if(cornerEq(curCorner,cube.WGR)){
                    c = green;
                }
                cube.rotateFace(c, 0);
                cube.rotateFace(yellow, 1);
                cube.rotateFace(c, 1);
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
}








