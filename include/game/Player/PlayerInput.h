#pragma once

#include "al/input/JoyPadAccelPoseAnalyzer.h"

class PlayerInput {
    public:

    unsigned char padding_0[0x78];
    al::JoyPadAccelPoseAnalyzer *mJoyPadAccelPoseAnalyzer1;
    al::JoyPadAccelPoseAnalyzer *mJoyPadAccelPoseAnalyzer2;

};