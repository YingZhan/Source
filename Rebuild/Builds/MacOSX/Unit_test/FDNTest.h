//
//  FDNTest.h
//  Reverb
//
//  Created by XinquanZhou on 6/3/15.
//
//

#ifndef Reverb_FDNTest_h
#define Reverb_FDNTest_h

//#include <algorithm>
//#include "gtest/gtest.h"
//#include "FileReader.h"
//#include "SignalGen.h"
//#include "/Users/xinquanzhou/Workspace/Source/Eigen/Core"
//#include "/Users/xinquanzhou/Workspace/Source/Eigen/Dense"
//
//
//
//struct MatrixBuffer{
//    int buffersize;
//    Eigen::MatrixXf * input, * output;
//    float * _input, * _output;
//    
//    MatrixBuffer():buffersize(512), input(new Eigen::MatrixXf[buffersize]), output(new Eigen::MatrixXf[buffersize]), _input(new float [buffersize]), _output(new float[buffersize]){
//        fill(_input_buffer,_input_buffer+buffersize,0.0);
//        for(int i = 0 ; i < buffersize; ++i){
//            input[i].resize(1,16);
//            output[i].resize(1,16);
//        }
//    }
//    ~MatrixBuffer(){
//        delete []_input;
//        delete []_output;
//        delete []input;
//        delete []output;
//    }
//    
//    void setMatrixBuffer(){
//        for(int i = 0 ; i < buffersize; i++){
//            input[i] = Eigen::MatrixXf::Ones(1,16) * _input[i];
//        }
//    }
//};
//
//TEST (FDNTest, DC)
//{
//    MatrixBuffer b;
//    
//    CSignalGen::generateDc(b._input_buffer,b.buffersize);
//    b.setMatrixBuffer();
//    FileReader f("Unit_test/FDNDC.txt");
//    f.split(' ');
//    FDN fdn;
//    for (int i = 0 ; i < b.buffersize; ++i) {
//        b.output[i] = fdn.process(b.input[i]);
//        ASSERT_NEAR(b.output[i],f.content[0], 0.001);
//    }
//}
//
//
//TEST (FDNTest, ArbTest)
//{
//    MatrixBuffer b;
//    CSignalGen::generateSine(b._input_buffer,1000,44100/4,b.buffersize);
//    b.setMatrixBuffer();
//    FileReader f("Unit_test/FDNSine.txt");
//    f.split(' ');
//    FDN fdn;
//    for (int i = 0 ; i < b.buffersize; ++i) {
//        b.output[i] = fdn.process(b.input[i]);
//        ASSERT_NEAR(b.output[i],f.content[0], 0.001);
//    }
//}


#endif
