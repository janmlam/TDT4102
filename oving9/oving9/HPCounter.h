#pragma once

#include "minesweeper.h"

struct Bar {
	bool live;
	bool mine;
	bool flagg;
};

class HPCounter {
private:
	Minesweeper * gameobj = nullptr;
	Bar* bars = nullptr;

public:
	HPCounter(Minesweeper*);

	bool isTileLive(int index);
};