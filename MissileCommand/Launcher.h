#pragma once

#include "Item.h"
#include "Globals.h"

/// <summary>description</summary>
class Launcher : public Item {

	float hp;
	bool destroyed;

public:

	Launcher();
	Launcher(Point center);

	float& GetHP();
	bool IsDestroyed();
	void SetDestroyed(bool destroyed);

	void SetAngle(float angleRad);
	void ReceiveDamage(float damage);
};

