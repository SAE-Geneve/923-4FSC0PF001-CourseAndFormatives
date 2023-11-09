#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>

#include "tilemap.h"

bool Tilemap::InBounds(sf::Vector2i coords)
{
    return coords.x >= 0
        && coords.x < TILEMAP_WIDTH
        && coords.y >= 0
        && coords.y < TILEMAP_HEIGHT
    ;
}

void Tilemap::Save()
{
    FILE* f = fopen("level.data", "wb");
        fwrite(cells, sizeof(cells), 1, f);
        fclose(f);
}

void Tilemap::Load()
{
    FILE* f = fopen("level.data", "rb");
    if(f)
    {
	    fread(cells, sizeof(cells), 1, f);
        fclose(f);
    }
    
}

sf::Vector2i Tilemap::PosToCoords(sf::Vector2f world_position)
{
    sf::Vector2i coord;
    coord.x = std::floor(world_position.x / TILE_SIZE_PX);
    coord.y = std::floor(world_position.y / TILE_SIZE_PX);
    return coord;
}

bool Tilemap::TileAt(sf::Vector2i tile_coord)
{
    if (tile_coord.x < 0 || tile_coord.y < 0 || tile_coord.x >= TILEMAP_WIDTH || tile_coord.y >= TILEMAP_HEIGHT) {
        return true;
    }
    int index = tile_coord.y * TILEMAP_WIDTH + tile_coord.x;

    return cells[index] != (int)TileType::kNotile;

}
