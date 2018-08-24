//
//  secondLayer.cpp
//  HowToCube
//
//  Created by Jack Zeligson on 8/23/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#include "secondLayer.hpp"
#include "Cube.hpp"
#include "firstLayer.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

void makeSecondLayer(Cube &cube){
    bool b1 = false, b2 = false, b3 = false, b4 = false;
    int dir = 0;
    while(b1 == false || b2 == false || b3 == false || b4 == false){
        pair<Color, Color> curEdge;
        pair<Color, Color> goalEdge;
        
        if(cube.BO.first == blue && cube.BO.second == orange){
            b1 = true;
        }
        if(cube.OG.first == orange && cube.OG.second == green){
            b2 = true;
        }
        if(cube.GR.first == green && cube.GR.second == red){
            b3 = true;
        }
        if(cube.RB.first == red && cube.RB.second == blue){
            b4 = true;
        }
        
        if(b1 == false){
            curEdge = locateEdge(cube, blue, orange);
            if(curEdge.second == blue){
                goalEdge = cube.YB;
                dir = 1;
            }
            else{
                goalEdge = cube.YO;
                dir = 0;
            }
        }
        else if(b2 == false){
            curEdge = locateEdge(cube, orange, green);
            if(curEdge.second == orange){
                goalEdge = cube.YO;
                dir = 1;
            }
            else{
                goalEdge = cube.YG;
                dir = 0;
            }
        }
        else if(b3 == false){
            curEdge = locateEdge(cube, green, red);
            if(curEdge.second == green){
                goalEdge = cube.YG;
                dir = 1;
            }
            else{
                goalEdge = cube.YR;
                dir = 0;
            }
        }
        else if(b4 == false){
            curEdge = locateEdge(cube, red, blue);
            if(curEdge.second == red){
                goalEdge = cube.YR;
                dir = 1;
            }
            else{
                goalEdge = cube.YB;
                dir = 0;
            }
        }
        
        if(b1 == false || b2 == false || b3 == false || b4 == false){
            if(curEdge == cube.YB || curEdge == cube.YO || curEdge == cube.YG || curEdge == cube.YR){
                if(curEdge != goalEdge){
                    cube.rotateFace(yellow, 0);
                }
                else{
                    if(dir == 0){
                        cube.rotateFace(yellow, 0);
                        cube.rotateFace(curEdge.first, 0);
                        cube.rotateFace(yellow, 1);
                        cube.rotateFace(curEdge.first, 1);
                        cube.rotateFace(yellow, 1);
                        cube.rotateFace(curEdge.second, 1);
                        cube.rotateFace(yellow, 0);
                        cube.rotateFace(curEdge.second, 0);
                    }
                    else{
                        cube.rotateFace(yellow, 1);
                        cube.rotateFace(curEdge.first, 1);
                        cube.rotateFace(yellow, 0);
                        cube.rotateFace(curEdge.first, 0);
                        cube.rotateFace(yellow, 0);
                        cube.rotateFace(curEdge.second, 0);
                        cube.rotateFace(yellow, 1);
                        cube.rotateFace(curEdge.second, 1);
                    }
                }
            }
            else{
                Color c1, c2;
                if(curEdge == cube.BO){
                    c1 = blue;
                    c2 = orange;
                }
                else if(curEdge == cube.OG){
                    c1 = orange;
                    c2 = green;
                }
                else if(curEdge == cube.GR){
                    c1 = green;
                    c2 = red;
                }
                else if(curEdge == cube.RB){
                    c1 = red;
                    c2 = blue;
                }
                cube.rotateFace(c1, 0);
                cube.rotateFace(yellow, 1);
                cube.rotateFace(c1, 1);
                cube.rotateFace(yellow, 1);
                cube.rotateFace(c2, 1);
                cube.rotateFace(yellow, 0);
                cube.rotateFace(c2, 0);
            }
        }
    }
}

void secondLayerTest(Cube &cube){
    if(cube.BO.first != blue || cube.BO.second != orange){
        cout << "Second layer failed" << endl;
    }
    else if(cube.OG.first != orange || cube.OG.second != green){
        cout << "Second layer failed" << endl;
    }
    else if(cube.GR.first != green || cube.GR.second != red){
        cout << "Second layer failed" << endl;
    }
    else if(cube.RB.first != red || cube.RB.second != blue){
        cout << "Second layer failed" << endl;
    }
    else{
        cout << "PASS!!!" << endl;
    }
}
