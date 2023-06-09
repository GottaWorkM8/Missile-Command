#pragma once

#include <list>
#include "Item.h"
#include "Bomb.h"
#include "Building.h"
#include "Timer.h"
#include "Source.h"

class Explosion : public Item {

	float radius;
	float damage;
	int stage;
	Timer stageTimer;
	Source source;
	bool launcherHit;
	std::list<Building> buildingsHit;
	std::list<Bomb> bombsHit;

public:

	Explosion();
	Explosion(Point center, float radius, Source source);

	void SetAngleRad(float& angleRad);
	void SetAngleDeg(float& angleDeg);
	float& GetRadius();
	void SetRadius(float& radius);
	float& GetDamage();
	int& GetStage();
	Timer& GetStageTimer();
	Source& GetSource();
	bool IsLauncherHit();
	void SetLauncherHit(bool launcherHit);
	std::list<Building>& GetBuildingsHit();
	void SetBuildingsHit(std::list<Building>& buildingsHit);
	std::list<Bomb>& GetBombsHit();
	void SetBombsHit(std::list<Bomb>& bombsHit);
	
	bool operator==(const Explosion& e) const;
};

