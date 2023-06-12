#pragma once

#include "Item.h"
#include "Source.h"
#include "Globals.h"

class Bomb : public Item {

	Source source;
	float hp;

public:

	Bomb();
	Bomb(Point center, float angleRad, Source source);

	Source& GetSource();
	float GetHP();

	bool operator==(const Bomb& b) const;

	void ReceiveDamage(float damage);
};

