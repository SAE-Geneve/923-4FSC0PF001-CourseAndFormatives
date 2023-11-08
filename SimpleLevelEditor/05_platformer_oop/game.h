#pragma once

#include "tilemap.h"
#include <SFML/Graphics.hpp>

class Game
{
    public:
    Tilemap tilemap_;
    sf::Vector2f player_pos_ = sf::Vector2f(700, 230);
    sf::Vector2f player_vel_ = sf::Vector2f(0,0);
    bool grounded;
    sf::Vector2f player_size = sf::Vector2f(20, 30);
    sf::RenderWindow window_;

    sf::RectangleShape tile_shape_;
    sf::RectangleShape cursor_shape_;
    sf::RectangleShape debug_limit_shape_vertical_;
    sf::RectangleShape debug_limit_shape_horizontal_;
    sf::CircleShape player_origin_shape_;
    sf::RectangleShape player_box_shape_;

    void init();

    void update();
};

