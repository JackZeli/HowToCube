//
//  main.cpp
//  HowToCube
//
//  Created by Jack Zeligson on 7/9/18.
//  Copyright © 2018 Jack Zeligson. All rights reserved.
//

#include <iostream>
#include "Cube.hpp"
#include "firstLayer.hpp"
#include "secondLayer.hpp"
#include "thirdLayer.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    Cube rubiks;
    //rubiks.test();
    //for(int i = 0; i < 10; ++i){
        rubiks.shuffle();
        makeCross(rubiks);
        //daisyTest(rubiks);
        crossTest(rubiks);
        makeFull(rubiks);
        fullTest(rubiks);
        makeSecondLayer(rubiks);
        secondLayerTest(rubiks);
        doThird(rubiks);
        cout << endl;
    //}
    return 0;
}
