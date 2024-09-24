#include <iostream>

#include "Unit.h"
#include "Achievements.h"

void Achievements::OnNotify(Unit* _unit, std::string _event)
{
	if ((_event == "UnitFalling") && (_unit->GetY() < 0))
	{
		UnlockAchievement("Died from Falling");
	}
}

void Achievements::UnlockAchievement(std::string _achievement)
{
	std::cout << "Achievement unlocked:" << _achievement << "!!\n";
}