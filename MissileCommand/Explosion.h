#pragma once

#include <list>
#include "Item.h"
#include "Bomb.h"
#include "Building.h"
#include "Timer.h"
#include "Source.h"

class Explosion : public Item {

	float radius;
	int stage;
	Timer stageTimer;
	Source source;
	std::list<Bomb> bombsHit;
	std::list<Building> buildingsHit;
	bool launcherHit;

public:

	Explosion();
	Explosion(Point center, float radius, Source source);

	void SetAngleRad(float& angleRad);
	void SetAngleDeg(float& angleDeg);
	float& GetRadius();
	void SetRadius(float& radius);
	int& GetStage();
	Timer& GetStageTimer();
	Source& GetSource();
	std::list<Bomb>& GetBombsHit();
	void SetBombsHit(std::list<Bomb>& bombsHit);
	std::list<Building>& GetBuildingsHit();
	void SetBuildingsHit(std::list<Building>& buildingsHit);
	bool& IsLauncherHit();
	void SetLauncherHit(bool& launcherHit);
	
	bool operator==(const Explosion& e) const;
};

