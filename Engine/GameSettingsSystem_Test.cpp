// Copyright Syed Aman. All Rights Reserved.
#include "GameSettingsSystem.h"

#include <gtest/gtest.h>

TEST(GameSettingsSystem, ReadsFromGameSettingsTxt)
{
    GameSettingsSystem gameSettingsSystem;
    gameSettingsSystem.ReadGameSettings();
}
