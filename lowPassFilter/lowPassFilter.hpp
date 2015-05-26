//
//  main.cpp
//  lowPassFilter
//
//  Created by Ying Zhan on 2/20/15.
//  Copyright (c) 2015 Ying Zhan. All rights reserved.
//

#include <iostream>
#include "circularBuffer.hpp"
using namespace std;

class lowPassFilter {
private:
    float g1;
    float g2;
    circularBuffer<float> lowPassBuffer;

public:
    lowPassFilter():lowPassBuffer(64){
        g1 = 1;
        g2 = 1;
    }
    
    
    float process(float sample){
        float lowPassSignal;
        lowPassBuffer.writeFunction(sample);
        lowPassSignal = lowPassBuffer.readFunction(-1);
        cout<<"low1 = "<<lowPassSignal<<'\n';
        cout<<"sampe = "<<sample<<'\n';
        lowPassSignal = g1*sample+g2*lowPassSignal;
        cout<<"low2 = "<<lowPassSignal<<'\n';
        lowPassBuffer.moveReadPtr();
        
        
        return lowPassSignal;
    }
//    float operator[] (int p){
//        return read(p);
//    }
    friend std::ostream& operator<<(std::ostream& outputStream, const lowPassFilter& x) {
        //print something
        return outputStream;
    }
};

