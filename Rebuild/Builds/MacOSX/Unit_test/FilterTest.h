//
//  FilterTest.h
//  Reverb
//
//  Created by XinquanZhou on 6/3/15.
//
//

#ifndef Reverb_FilterTest_h
#define Reverb_FilterTest_h


#include "gtest/gtest.h"
#include "SignalGen.h"
#include "FilterBase.h"
#include "FileReader.h"
#include <algorithm>


struct Buffer {
    Buffer():size(512),input_buffer(new float[size]), output_buffer(new float[size]){}
    ~Buffer(){
        delete input_buffer;
        delete output_buffer;
        input_buffer = 0;
        output_buffer = 0 ;
    }

    void setSize(int new_size){
        delete input_buffer;
        delete output_buffer;
        size = new_size;
        input_buffer = new float[size];
        output_buffer = new float[size];
    }
    int size;
    float * input_buffer, *output_buffer;
};

TEST (Unit_test, DC)
{
    Buffer b;
    CSignalGen::generateDc(b.input_buffer,b.size);
    FileReader f("Unit_test/DC.txt");
    f.split(' ');
    LowPassFilter lp(1,1);

    for (int i = 0 ; i < b.size; ++i) {
        b.output_buffer[i] = lp.ProcessBySample(b.input_buffer[i]);
        ASSERT_NEAR(b.output_buffer[i],f.content[0][i], 0.001);
    }

    AllPassFilter ap(100);

    for (int i = 0 ; i < b.size; ++i) {
        b.output_buffer[i] = lp.ProcessBySample(b.input_buffer[i]);
        ASSERT_NEAR(b.output_buffer[i],f.content[1][i], 0.001);
    }
    
    ToneCorrection tc;
    
    for (int i = 0 ; i < b.size; ++i) {
        b.output_buffer[i] = tc.ProcessBySample(b.input_buffer[i]);
        ASSERT_NEAR(b.output_buffer[i],f.content[2][i], 0.001);
    }

    
}

TEST (Unit_test, LP_Impulse)
{
    Buffer b;
    //CSignalGen::generateDc(b.input_buffer,b.size);
    fill(b.input_buffer,b.input_buffer+b.size,0.0);
    b.input_buffer[0] = 1.0;
    FileReader f("Unit_test/lp_impulse.txt");
    f.split(' ');
    LowPassFilter lp(1,1);

    for (int i = 0 ; i < b.size; ++i) {
        b.output_buffer[i] = lp.ProcessBySample(b.input_buffer[i]);
        ASSERT_NEAR(b.output_buffer[i],f.content[0][i], 0.001);
    }

    lp.SetParams(0.5, 0.5);

    for (int i = 0 ; i < b.size; ++i) {
        b.output_buffer[i] = lp.ProcessBySample(b.input_buffer[i]);
        ASSERT_NEAR(b.output_buffer[i],f.content[1][i], 0.001);
    }
}


TEST (Unit_test, AP_Impulse)
{
    Buffer b;
    //CSignalGen::generateDc(b.buffer,b.size);
    fill(b.input_buffer,b.input_buffer+b.size,0.0);
    b.input_buffer[0] = 1.0;
    FileReader f("Unit_test/ap_impulse.txt");
    f.split(' ');
    AllPassFilter ap(100);

    for (int i = 0 ; i < b.size; ++i) {
        b.output_buffer[i] = ap.ProcessBySample(b.input_buffer[i]);
        ASSERT_NEAR(b.output_buffer[i],f.content[0][i], 0.001);
    }


    for (int i = 0 ; i < b.size; ++i) {
        b.output_buffer[i] = ap.ProcessBySample(b.input_buffer[i]);
        ASSERT_NEAR(b.output_buffer[i],f.content[1][i], 0.001);
    }
}


TEST (Unit_test, TC_Impulse)
{
    Buffer b;
    //CSignalGen::generateDc(b.buffer,b.size);
    fill(b.input_buffer,b.input_buffer+b.size,0.0);
    b.input_buffer[0] = 1.0;
    FileReader f("Unit_test/tc_impulse.txt");
    f.split(' ');
    ToneCorrection tc;

    for (int i = 0 ; i < b.size; ++i) {
        b.output_buffer[i] = tc.ProcessBySample(b.input_buffer[i]);
        ASSERT_NEAR(b.output_buffer[i],f.content[0][i], 0.001);
    }

}


#endif
