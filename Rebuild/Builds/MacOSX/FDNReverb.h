//
//  FDNReverb.h
//  Reverb
//
//  Created by XinquanZhou on 5/29/15.
//
//

#ifndef Reverb_FDNReverb_h
#define Reverb_FDNReverb_h


#include "/Users/xinquanzhou/Workspace/Source/Eigen/Core"
#include "FilterBase.h"
#include "FDN.h"

class FDNReverb {
private:
    int _DLs_num, _fs;
    FDN * _FDN;
    LowPassFilter ** _LPfilters;
    AllPassFilter ** _APfilters;
    ToneCorrection * _TCfilter;
    Eigen::MatrixXf _FDN_in, _FDN_out;
    enum class Preprocess {"allpass", "tone correction"};
    
public:
    Preprocess Pretype;
    FDNReverb(int fs = 44100 , int delay_lines_num = 16, Preprocess Pretype = "tone correction"):_DLs_num(delay_lines_num), _fs(fs ), _FDN(new FDN(_DLs_num)), _LPfilters(new LowPassFilter[_DLs_num]), _FDN_in(1,_DLs_num), _FDN_out(1,_DLs_num), Pretype(Pretype){
        try {
            if (Pretype == "tone correction") {
                _TCfilter = new ToneCorrection();
                _APfilters = nullptr;
            }
            else{
                _APfilters = new AllPassFilter[3];
                _APfilters[0] = new AllPassFilter(347);
                _APfilters[1] = new AllPassFilter(113);
                _APfilters[2] = new AllPassFilter(37);
                _TCfilter = nullptr;
            }
            for (int i = 0 ; i < _DLs_num; i++) {
                _LPfilters = new LowPassFilter(_fs);
            }
            

        } catch () {
            throw;
        }
    }
    
    ~FDNReverb(){
        try {
            for (int i = 0 ; i < _DLs_num; i++) {
                delete _LPfilters[i];
            }
            delete _LPfilters;
            
            if (Pretype == "tone correction") {
                delete _TCfilter;
            }
            else{
                for (int i = 0 ; i < 3 ; i++) {
                    delete _APfilters[i];
                }
                delete _APfilters;
            }
            
            delete _FDN;
            
        } catch () {
            ;
        }
    }
    
    // set the t60 for reverb
    void setReverbTime(float timeInSecond, float q = 1.25/3){
        float t60 = timeInSecond;
        for (int i = 0 ; i < _DLs_num; i++) {
            float kp = [pow(10, -3 * FDN::coff[i]/ (_fs * t60) );
            float bp = 20 * log10(kp)* log(10) / 80 * ( 1- 1/(q*q));
            _LPfilters[i] -> SetParams(kp,bp);
        }
    }
            
    float ProcessBySample(float sample){
        float CurY = sample ;
        float tmp ;
        if(Pretype == "tone correction"){
            tmp = _TCfilter -> ProcessBySample(sample);
        }
        else {
            tmp = _APfilters[0]->ProcessBySample(sample);
            for(int i = 1 ; i < 3 ; i++){
                tmp = _APfilters[i]->ProcessBySample(tmp);
            }
        }
        _FDN_in.Constant(tmp);
        _FDN_out =  _FDN -> process(_FDN_in);
        for( int i = 0 ; i < _DLs_num; i++){
            
            CurY += _LPfilters[i] -> ProcessBySample(_FDN_out(0,i));
        }
        
        return CurY;
    }
    
    void ProcessByBuffer(float * input, float * output, int buffersize){
        for(int i = 0 ; i < buffersize ; i++){
            output[i] = ProcessBySample(input[i]);
        }
    }
    
            
            
            
};

#endif
