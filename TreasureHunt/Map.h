#pragma once

#include "Random.h"

#define WIDTH 5
#define HEIGHT 8

enum TreasureTile
{
    plateau = 0,
    coffre = 1,
    monstre = 2
};

static int cells[WIDTH * HEIGHT];

void initializeMap();
void drawPlayfield();
int validInput();
int input();
