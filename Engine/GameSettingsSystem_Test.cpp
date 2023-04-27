// Copyright Syed Aman. All Rights Reserved.
#include "GameSettingsSystem.h"

#include "TestingFramework.h"

TEST(GameSettingsSystem, ReadsFromGameSettingsTxt)
{
    GameSettingsSystem gameSettingsSystem;
    gameSettingsSystem.ReadGameSettings();
}
