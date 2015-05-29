#ifndef __toneCorrection_HPP__
#define __toneCorrection_HPP__
//
//  main.cpp
//  toneCorrection
//
//  Created by Ying Zhan on 2/20/15.
//  Copyright (c) 2015 Ying Zhan. All rights reserved.
//

#include <iostream>
#include "circularBuffer.hpp"

using namespace std;

class toneCorrection {
private:
    int N;
    //circularBuffer<float> oldTemp;
    circularBuffer<float> xTemp;
    float a;
    float g;
    
    
    
    
public:
    toneCorrection():xTemp(100){
        a = 1.25/3;
        g = (1-a)/(1+a);

    }
    float process(float sample){
        //float process(float sample,int N){
        // oldTemp will keep 0 status until N>N1;
        //float newTemp;
        float toneCorrectionSignal;
        // oldTemp is circularBuffer used for store data
        xTemp.writeFunction(sample);
        
        //float old = oldTemp.readFunction(-N);
        //newTemp = sample-g*old;
        //allPassSignal = g*newTemp+old;
        /*
         std::cerr<<"-------------------------------\n";
         std::cerr<<xTemp.readFunction(-N);
         std::cerr<<"\n";
         std::cerr<<yTemp.readFunction(-N);
         std::cin.get();
         */
        //y(n) * (1-b) = x(n)-b*x(n-1);
        toneCorrectionSignal = (sample-g*xTemp.readFunction(-1))/(1-g);
        
        xTemp.moveReadPtr();
        // std::cout<<old<<'\n';
        return toneCorrectionSignal;
        
        
        
    }
};
#endif

