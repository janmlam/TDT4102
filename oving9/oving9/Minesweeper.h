#pragma once
#include<iostream>


struct Tile {
	//en rute er alltid lukket og ~mine, mm. annet er sagt.
	bool open = false;
	bool mine = false;
	bool flag = false;
	int numAdjMines = 0;
};

class Minesweeper {
private:
	int rader, kolonner, miner, aapne;
	Tile** tileset = nullptr;
	bool gameOver;

	void populateTilesetWithMines();
	void buildAdjacencyIndex(int row, int col);
	void clearTileCover() const;

public:
	//              kolonner     rader
	Minesweeper(int width, int height, int mines);
	~Minesweeper();

	bool isGameOver() const;

	bool isTileOpen(int row, int col) const;
	bool isTileMine(int row, int col) const;
	bool isTileFlagged(int row, int col) const;

	void openTile(int row, int col);
	void flagTile(int row, int col);
	int numAdjacentMines(int row, int col) const;

	int getRad() const;
	int getKol() const;

	void modeDebug();
	void dumpTile(int row, int col) const;

	// Vi slår av autogenerert kopikonstruktør og tilordningsoperator for å unngå feil
	Minesweeper(const Minesweeper &) = delete;
	Minesweeper &operator=(const Minesweeper &) = delete;
};