#pragma once

#include "Random.h"

#define WIDTH 5
#define HEIGHT 8

enum TreasureTiles
{
    Empty = 0,
    Coffre = 1,
    Monstre = 2
};

extern int Cells[WIDTH * HEIGHT];

void InitializeMap();
void DrawPlayfield(bool debugMode = true);
int Input();
