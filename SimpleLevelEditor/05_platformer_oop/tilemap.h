#pragma once

#include <SFML/Graphics.hpp>

#define TILEMAP_WIDTH 16
#define TILEMAP_HEIGHT 12
#define TILE_SIZE_PX 50



class Tilemap
{

public:
    enum class TileType
    {
        kNotile = 0,
        kYellow,
        kRed
    };

    int cells[TILEMAP_WIDTH * TILEMAP_HEIGHT] = {0}; // initialize a bool array with all zeroes (false).

    bool InBounds(sf::Vector2i coords);
    void Save();
    void Load();
    sf::Vector2i PosToCoords(sf::Vector2f world_position);
    bool TileAt(sf::Vector2i tile_coord);
};
