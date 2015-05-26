//
//  main.cpp
//  circular_buffer
//
//  Created by Ying Zhan on 2/19/15.
//  Copyright (c) 2015 Ying Zhan. All rights reserved.
//

#include <iostream>
#include <cstddef>
using namespace std;

template<class T>
class circularBuffer {
private:
    int readPtr;
    int writePtr;
    size_t bufferSize; // size_t
    T* a; // circular buffer
    size_t wrapFunction(int position) { // this function makes sure that you can turn position within buffersize
         while (position < 0) {
             position = (size_t)position+ bufferSize;
         }
        return position%bufferSize;
    }
    
    
public:
    circularBuffer(size_t bufferSize) // constructor function
    : bufferSize(bufferSize), readPtr(0),writePtr(0){
        a=new T[bufferSize];
    
    }
    ~circularBuffer(){ //destructor function
        delete[] a;
    }
    circularBuffer& writeFunction(T const & sample) {
        a[wrapFunction(writePtr)] = sample;
        writePtr++;
        return *this; //this is the pointer point to itself(object of this class)
    }
    
    T readFunction(int offset) {
        float temp;
        temp = a[wrapFunction(readPtr+offset)];
        return temp;
    }
    
    circularBuffer& moveReadPtr(){
        readPtr++;
        return *this;
    }
   
};

//int main() {
//    float a[20]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//
//    circularBuffer<float> b(15);
//    for (int i = 0; i<25;i++) {
//        b.writeFunction(a[i]);
//        
//        std::cout<<b.readFunction(-5);
//        b.moveReadPtr();
//    }
//    
//}
