#include "al/util.hpp"
#include "game/Layouts/MapLayout.h"
#include "rs/util.hpp"
#include <fl/ui.h>
#include <fl/server.h>
#include <nn/init.h>
#include <mem.h>
#include "al/input/JoyPadAccelPoseAnalyzer.h"

void serverThreadFunc(void* args)
{
    smo::Server* server = (smo::Server*) args;
    nn::TimeSpan w = nn::TimeSpan::FromNanoSeconds(1000000);
    while (true)
    {
        server->handlePacket();
        nn::os::YieldThread();
        nn::os::SleepThread(w);
    }
}

void stageSceneControlHook() {
    __asm ("MOV X19, X0");

    StageScene* stageScene;
    __asm ("MOV %[result], X0" : [result] "=r" (stageScene));
    
    fl::PracticeUI::instance().update(*stageScene);

    al::PlayerHolder *pHolder = al::getScenePlayerHolder(stageScene);
    PlayerActorHakoniwa *player = al::tryGetPlayerActor(pHolder, 0);
    HackCap *cap = player->mHackCap;
    al::JoyPadAccelPoseAnalyzer *playerMotion = player->mPlayerInput->mJoyPadAccelPoseAnalyzer1;
    al::JoyPadAccelPoseAnalyzer *capMotion = cap->mPlayerInput->mJoyPadAccelPoseAnalyzer2;

//This is hacky but it works
    if (fl::PracticeUI::instance().doCRC && al::isPadHoldL(2) || al::isPadHoldR(2))
    {   
    capMotion->mSwingLeft = true;
    capMotion->mSwingRight = true;
    capMotion->mSwingAny = true;
    capMotion->mAccelCombinedVel = {0.0f, 1.0f};
    capMotion->mAccelLeftAccel = {0.0f, 1.0f};
    capMotion->mAccelRightAccel = {0.0f, 1.0f};
    capMotion->mAccelLeftVel = {0.0f, 1.0f};
    capMotion->mAccelRightVel = {0.0f, 1.0f};
    capMotion->mHistoryLeft.hist0 = 1.4f;
    capMotion->mHistoryRight.hist0 = 1.4f;
    capMotion->mHistoryLeft.hist1 = 0.5f;
    capMotion->mHistoryRight.hist1 = 0.5f;
    }

    #if(SMOVER==100)
    static bool init = false;
    if (!init)
    {
        smo::Server& server = smo::Server::instance();
        nn::os::ThreadType* thread = (nn::os::ThreadType*) nn::init::GetAllocator()->Allocate(sizeof(nn::os::ThreadType));
        const u32 stackSize = 0x5000;
        void* threadStack = aligned_alloc(0x1000, stackSize);
        nn::os::CreateThread(thread, serverThreadFunc, &server, threadStack, stackSize, 16, 0);
        nn::os::SetThreadName(thread, "UDP Thread");
        nn::os::StartThread(thread);
        init = true;
    }
    #endif

    __asm ("MOV X0, %[input]" : [input] "=r" (stageScene));
}

void setGotShineVar(GameDataHolderWriter writer, const ShineInfo* shineInfo)
{
    fl::PracticeUI& ui = fl::PracticeUI::instance();
    if (!ui.shineRefresh)
        writer.mGameDataFile->setGotShine(shineInfo);
}

bool isGotShineVar(GameDataHolderAccessor accessor, const ShineInfo* shineInfo)
{
    return fl::PracticeUI::instance().gotShineRefresh ? false : accessor.mGameDataFile->isGotShine(shineInfo);
}

bool isEnableCheckpointWarpVar(MapLayout* layout)
{
    return fl::PracticeUI::instance().alwaysWarp ? true : layout->isEnableCheckpointWarp();
}

bool isEnableSaveVar(StageScene* stageScene)
{
    return fl::PracticeUI::instance().disableAutoSave ? false : stageScene->isEnableSave();
}

bool isTriggerSnapShotModeVar(const al::IUseSceneObjHolder* objHolder)
{
    return showMenu ? false : rs::isTriggerSnapShotMode(objHolder);
}

bool isTriggerAmiiboModeVar(const al::IUseSceneObjHolder* objHolder)
{
    return showMenu ? false : rs::isTriggerAmiiboMode(objHolder);
}

bool fisModeDiverOrJungleGymRom()
{
    return fl::PracticeUI::instance().isModeDiverOrJungleGymRom;
}

bool fisModeDiverRom()
{
    return fl::PracticeUI::instance().isModeDiverRom;
}

bool fisModeJungleGymRom()
{
    return fl::PracticeUI::instance().isModeJungleGymRom;
}

bool fisModeE3LiveRom()
{
    return fl::PracticeUI::instance().isModeE3LiveRom;
}

bool fisModeE3MovieRom()
{
    return fl::PracticeUI::instance().isModeE3MovieRom;
}

bool fisModeEpdMovieRom()
{
    return fl::PracticeUI::instance().isModeEpdMovieRom;
}