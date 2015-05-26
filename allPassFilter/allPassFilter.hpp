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
    circularBuffer<float> oldTemp;
    float g;
    
   
    
    
public:
    allPassFilter(N) :oldTemp(N){
        g = 0.55;
        
    }
    float process(float sample,int N){
        // oldTemp will keep 0 status until N>N1;
        float newTemp;
        float allPassSignal;
         // oldTemp is circularBuffer used for store data
        oldTemp.writeFunction(sample);
        newTemp = sample+g*oldTemp.readFunction(-N);
        allPassSignal = -g*newTemp+oldTemp.readFunction(-N);
        oldTemp.moveReadPtr();
        return allPassSignal;
        
     
        
  }
};

int main()
    {
        int a[] = {1,2,3,4,5};
        allPassFilter b;
        for(int i = 0;i<5;i++) {
            b.process(a[i], 3);
            cout<<b.process(a[i], 3);
            
        }
    }