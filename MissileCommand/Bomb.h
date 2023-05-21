#pragma once

#include "Item.h"
#include "Source.h"

class Bomb : public Item {

	Source source;

public:

	Bomb();
	Bomb(Point center, float angleRad, Source source);

	Source& GetSource();
};

