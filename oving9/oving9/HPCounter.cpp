#include<iostream>

#include"minesweeper.h"
#include"hpcounter.h"

HPCounter::HPCounter(Minesweeper* __g) {
	gameobj = __g;
	bars = new Bar[(gameobj->getRad())*(gameobj->getKol())];


}

bool isTileLive(int index) {
	return false;
}