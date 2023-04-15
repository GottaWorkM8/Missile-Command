#pragma once
class Propagation {

	int stages;

public:

	Propagation();
	Propagation(int stages);

	bool operator==(const Propagation& p) const;
};

