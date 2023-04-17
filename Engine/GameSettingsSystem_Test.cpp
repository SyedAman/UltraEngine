#include "GameSettingsSystem.h"

#include <gtest/gtest.h>

TEST(GameSettingsSystem, ReadsFromGameSettingsTxt)
{
    GameSettingsSystem gameSettingsSystem;
    gameSettingsSystem.ReadGameSettings();
}
