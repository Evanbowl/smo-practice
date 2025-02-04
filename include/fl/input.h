#pragma once

#include "sead/math/seadVector.h"

class StageScene;

void inputShake(al::JoyPadAccelPoseAnalyzer *capMotion);
sead::Vector2f* fgetLeftStick(int port);
sead::Vector2f* fgetRightStick(int port);

bool fisPadTriggerA(int port);
bool fisPadTriggerB(int port);
bool fisPadTriggerX(int port);
bool fisPadTriggerY(int port);
bool fisPadTriggerL(int port);
bool fisPadTriggerR(int port);
bool fisPadTriggerZL(int port);
bool fisPadTriggerZR(int port);
bool fisPadTriggerPressLeftStick(int port);
bool fisPadTriggerPressRightStick(int port);
bool fisPadTriggerPlus(int port);
bool fisPadTriggerMinus(int port);
bool fisPadTriggerUp(int port);
bool fisPadTriggerRight(int port);
bool fisPadTriggerDown(int port);
bool fisPadTriggerLeft(int port);
bool fisPadHoldA(int port);
bool fisPadHoldB(int port);
bool fisPadHoldX(int port);
bool fisPadHoldY(int port);
bool fisPadHoldL(int port);
bool fisPadHoldR(int port);
bool fisPadHoldZL(int port);
bool fisPadHoldZR(int port);
bool fisPadHoldPressLeftStick(int port);
bool fisPadHoldPressRightStick(int port);
bool fisPadHoldPlus(int port);
bool fisPadHoldMinus(int port);
bool fisPadHoldUp(int port);
bool fisPadHoldRight(int port);
bool fisPadHoldDown(int port);
bool fisPadHoldLeft(int port);
bool fisPadReleaseA(int port);
bool fisPadReleaseB(int port);
bool fisPadReleaseX(int port);
bool fisPadReleaseY(int port);
bool fisPadReleaseL(int port);
bool fisPadReleaseR(int port);
bool fisPadReleaseZL(int port);
bool fisPadReleaseZR(int port);
bool fisPadReleasePressLeftStick(int port);
bool fisPadReleasePressRightStick(int port);
bool fisPadReleasePlus(int port);
bool fisPadReleaseMinus(int port);
bool fisPadReleaseUp(int port);
bool fisPadReleaseRight(int port);
bool fisPadReleaseDown(int port);
bool fisPadReleaseLeft(int port);