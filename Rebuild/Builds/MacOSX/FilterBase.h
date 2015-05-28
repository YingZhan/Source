//
//  FilterBase.h
//  Reverb
//
//  Created by XinquanZhou on 5/27/15.
//
//

#ifndef Reverb_FilterBase_h
#define Reverb_FilterBase_h

#include"RingBuffer.h"

class FilterBase {
protected:
    int _delay_line;
    RingBuffer<float> _xdelay,_ydelay;
    FilterType();
public:
    enum class FilterType {"FIR", "IIR"};
    FilterType Type;
    FilterBase(int delay_line, FilterType f = "IIR") :_delay_line(delay_line),_xdelay(_delay_line + 1), _ydelay(_delay_line + 1), Type(f) {}
    
    virtual  ~FilterBase(){}
    
    virtual float ProcessBySample(float sample) = 0 {
    }
    
    virtual void ProcessByBuffer = 0 (float * input, float * output, int buffersize){
        
    }
    
};


class LowPassFilter: public FilterBase{
private:
    float _kp, _bp;
    LowPassFilter();
public:
    LowPassFilter(int delay_line = 2, float kp, float bp): FilterBase(delay_line), _kp(kp), _bp(bp){}
    ~LowPassFilter(){}
    
    void SetParams(float kp, float bp){
        _kp = kp;
        _bp = bp;
    }
    
    virtual float ProcessBySample(float sample){
        _ydelay.setReadOffset(-1);
        PreY = _ydelay.get();
        float CurY = (_kp - _kp * _bp) * sample + _bp * PreY;
        _ydelay.push(CurY);
        return CurY;
    }
    
    virtual void ProcessByBuffer(float * input, float * output, int buffersize){
        for (int i = 0 ; i < buffersize; ++i) {
            output[i] = ProcessBySample(input[i]);
        }
    }
};

#endif
