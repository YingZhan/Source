#ifndef __ALLPASSFILTER2_HPP__
#define __ALLPASSFILTER2_HPP__
//
//  main.cpp
//  allPassFilter
//
//  Created by Ying Zhan on 2/20/15.
//  Copyright (c) 2015 Ying Zhan. All rights reserved.
//

#include <iostream>
#include "circularBuffer.hpp"

using namespace std;

class allPassFilter {
private:
    int N;
    //circularBuffer<float> oldTemp;
    circularBuffer<float> xTemp;
    circularBuffer<float> yTemp;
    float g;
    
    
    
    
public:
    allPassFilter(int N):N(N),xTemp(N+100),yTemp(N+100){
        g = 0.55;
        
    }
    float process(float sample){
        //float process(float sample,int N){
        // oldTemp will keep 0 status until N>N1;
        //float newTemp;
        float allPassSignal;
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
        allPassSignal = -g*sample+xTemp.readFunction(-N)+g*yTemp.readFunction(-N);
        yTemp.writeFunction(allPassSignal);
        yTemp.moveReadPtr();
        xTemp.moveReadPtr();
        // std::cout<<old<<'\n';
        return allPassSignal;
        
        
        
    }
};
#endif

