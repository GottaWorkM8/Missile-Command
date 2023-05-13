#pragma once

#include "Item.h"

class Launcher : public Item {

	float hp;

public:

	Launcher();
	Launcher(Point center, float angleRad, float hp);

	float& GetHP();

	void SetAngle(float angleRad);
};

