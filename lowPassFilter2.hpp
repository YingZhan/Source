#ifndef __LOWPASSFILTER2_HPP__
#define __LOWPASSFILTER2_HPP__
////
////  main.cpp
////  lowPassFilter
////
////  Created by Ying Zhan on 2/20/15.
////  Copyright (c) 2015 Ying Zhan. All rights reserved.
////
//
//#include <iostream>
//#include "circularBuffer_test.hpp"
//using namespace std;
//
//class lowPassFilter {
//private:
//    float g1;
//    //float q;
//    float g2;
//    circularBuffer<float> lowPassBuffer;
//
//public:
//    lowPassFilter():lowPassBuffer(64){
//        g1 = 1;
//        g2 = 1;
////        for (int line = 0; line<16; line++) {
////            kp[line] = pow(10,-m[line]/fs);
////            bp[line] = 20* log10(kp[line])*log(10)/80*(1-1/(q*q));
////        };
//    }
//
//
//    float process(float sample){
//        float lowPassSignal;
//        lowPassBuffer.writeFunction(sample);
//        lowPassSignal = lowPassBuffer.readFunction(-1);
//        //cout<<"low1 = "<<lowPassSignal<<'\n';
//        //cout<<"sampe = "<<sample<<'\n';
//        lowPassSignal = g1*sample+g2*lowPassSignal;
//        //cout<<"low2 = "<<lowPassSignal<<'\n';
//        lowPassBuffer.moveReadPtr();
//
//
//        return lowPassSignal;
//    }
////    float operator[] (int p){
////        return read(p);
////    }
////    friend std::ostream& operator<<(std::ostream& outputStream, const lowPassFilter& x) {
////        //print something
////        return outputStream;
////    }
//};
//
//
//  main.cpp
//  lowPassFilter
//
//  Created by Ying Zhan on 2/20/15.
//  Copyright (c) 2015 Ying Zhan. All rights reserved.
//

////
////  main.cpp
////  lowPassFilter
////
////  Created by Ying Zhan on 2/20/15.
////  Copyright (c) 2015 Ying Zhan. All rights reserved.
////
//
//#include <iostream>
//#include "circularBuffer_test.hpp"
//using namespace std;
//
//class lowPassFilter {
//private:
//    float g1;
//    //float q;
//    float g2;
//    circularBuffer<float> lowPassBuffer;
//
//public:
//    lowPassFilter():lowPassBuffer(64){
//        g1 = 1;
//        g2 = 1;
////        for (int line = 0; line<16; line++) {
////            kp[line] = pow(10,-m[line]/fs);
////            bp[line] = 20* log10(kp[line])*log(10)/80*(1-1/(q*q));
////        };
//    }
//
//
//    float process(float sample){
//        float lowPassSignal;
//        lowPassBuffer.writeFunction(sample);
//        lowPassSignal = lowPassBuffer.readFunction(-1);
//        //cout<<"low1 = "<<lowPassSignal<<'\n';
//        //cout<<"sampe = "<<sample<<'\n';
//        lowPassSignal = g1*sample+g2*lowPassSignal;
//        //cout<<"low2 = "<<lowPassSignal<<'\n';
//        lowPassBuffer.moveReadPtr();
//
//
//        return lowPassSignal;
//    }
////    float operator[] (int p){
////        return read(p);
////    }
////    friend std::ostream& operator<<(std::ostream& outputStream, const lowPassFilter& x) {
////        //print something
////        return outputStream;
////    }
//};
//
//
//  main.cpp
//  lowPassFilter
//
//  Created by Ying Zhan on 2/20/15.
//  Copyright (c) 2015 Ying Zhan. All rights reserved.
//

#include <iostream>
#include "circularBuffer.hpp"
#include<math.h>
//#include<math.h>
using namespace std;
class lowPassFilter {
private:
    circularBuffer<float> lowPassBuffer;
    float fs;
    float kp;
    float bp;
    
 
 
    float lowPassSignal;
    float lowPassSignalOriginal;
    
public:
    lowPassFilter(float fs): fs(fs),lowPassBuffer(2){}
    lowPassFilter(float kp, float bp, float fs):lowPassBuffer(2),
    fs(fs), kp(kp), bp(bp){

    }
   
    lowPassFilter& setParam(float kp, float bp){
        this->kp= kp;
        this->bp= bp;
        return *this;
    }
    
    float process(float sample){
        
        //return sample;
        lowPassSignalOriginal = lowPassBuffer.readFunction(-1);
        //cout<<"low1 = "<<lowPassSignal<<'\n';
        //cout<<"sampe = "<<sample<<'\n';
        // y(n) = coeff1*sample+coeff2*y(n-1);
        //std::cout<<"kp = "<<kp<<std::endl;
        //std::cout<<"bp = "<<bp<<std::endl;
        lowPassSignal = (kp-kp*bp)*sample+bp*lowPassSignalOriginal;
        //lowPassSignal = coeff1*sample+coeff2*lowPassSignal;
        lowPassBuffer.writeFunction(lowPassSignal);
        //lowPassSignal = sample+lowPassSignal;
        //cout<<"low2 = "<<lowPassSignal<<'\n';
        lowPassBuffer.moveReadPtr();
        //std::cout<<"kp = "<<kp[delayLine]<<'\n';
        // std::cout<<"bp = "<< bp[delayLine];
        //std::cout<<"coeff1: "<< kp[delayLine]-kp[delayLine]*bp[delayLine]<<'\n';
        //std::cout<<"coeff2: "<< bp[delayLine]<<'\n';
        //cout<<"low2 = "<<lowPassSignal<<'\n';
        //std::cout<<"lowpass = "<<lowPassSignal<<'\n';
        
        
        return lowPassSignal;
    }
    //    float operator[] (int p){
    //        return read(p);
    //    }
    //    friend std::ostream& operator<<(std::ostream& outputStream, const lowPassFilter& x) {
    //        //print something
    //        return outputStream;
    //    }
};

#endif



