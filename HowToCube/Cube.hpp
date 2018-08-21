//
//  Cube.hpp
//  HowToCube
//
//  Created by Jack Zeligson on 7/13/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#ifndef Cube_hpp
#define Cube_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>

//enum for color variables
enum Color{white, blue, orange, green, red, yellow};

struct Corner{
    Color first;
    Color second;
    Color third;
};

class Cube{
public:
    Cube(); //Constructor
    
    //6 2D arrays representing the 6 faces of the cube
    std::vector<std::vector<Color>> whiteFace;
    std::vector<std::vector<Color>> blueFace;
    std::vector<std::vector<Color>> redFace;
    std::vector<std::vector<Color>> orangeFace;
    std::vector<std::vector<Color>> greenFace;
    std::vector<std::vector<Color>> yellowFace;
    
    void setEdges(); //After a rotation, redefine all of the edges
    void setCorners(); //After a rotation, redefine all of the corners
    
    //Two rotation functions
    void rotateFace(Color face, int dir);
    //void rotateFaceCounterClock(std::vector<std::vector<Color>> &face);
    
    //Gets the other 4 faces needed
    /*void getFaces(std::vector<std::vector<Color>> mainFace, std::vector<std::vector<Color>> &face1, std::vector<std::vector<Color>> &face2, std::vector<std::vector<Color>> &face3, std::vector<std::vector<Color>> &face4);*/
    
    void shuffle();
    
//private:
    //12 pairs representing the 12 edge pieces of the cube
    std::pair<Color,Color> WB;
    std::pair<Color,Color> WR;
    std::pair<Color,Color> WO;
    std::pair<Color,Color> WG;
    std::pair<Color,Color> BO;
    std::pair<Color,Color> OG;
    std::pair<Color,Color> GR;
    std::pair<Color,Color> RB;
    std::pair<Color,Color> YB;
    std::pair<Color,Color> YR;
    std::pair<Color,Color> YO;
    std::pair<Color,Color> YG;
    
    Corner WBO;
    Corner WOG;
    Corner WGR;
    Corner WRB;
    Corner YBR;
    Corner YRG;
    Corner YGO;
    Corner YOB;
};



#endif /* Cube_hpp */
