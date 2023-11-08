#ifdef _WIN32
#define _CRT_SECURE_NO_DEPRECATE
#endif

#include <SFML/Graphics.hpp>
#include <iostream>
#include <unistd.h>
#include <stdio.h>

#define TILEMAP_WIDTH 16
#define TILEMAP_HEIGHT 12
#define TILE_SIZE_PX 50

// TODO: replace the bool array with a TileType array, and allow to place Start and End tiles.
// enum class TileType {
//     Empty = 0,
//     Wall,
//     Start,
//     End,
// };

static sf::Vector2f player_pos(700, 230);
static sf::Vector2f player_vel(0,0);
static bool grounded;
const sf::Vector2f player_size(20, 30);

static bool tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = {0}; // initialize a bool array with all zeroes (false).

bool in_bounds(sf::Vector2i coords)
{
    return coords.x >= 0
        && coords.x < TILEMAP_WIDTH
        && coords.y >= 0
        && coords.y < TILEMAP_HEIGHT
    ;
}

void save()
{
    FILE* f = fopen("level.data", "wb");
    fwrite(tilemap, sizeof(tilemap), 1, f);
    fclose(f);
}

void load()
{
    FILE* f = fopen("level.data", "rb");
    fread(tilemap, sizeof(tilemap), 1, f);
    fclose(f);
}

sf::Vector2i pos_to_coords(sf::Vector2f world_position)
{
    sf::Vector2i coord;
    coord.x = std::floor(world_position.x / TILE_SIZE_PX);
    coord.y = std::floor(world_position.y / TILE_SIZE_PX);
    return coord;
}

bool tile_at(sf::Vector2i tile_coord)
{
    if (tile_coord.x < 0 || tile_coord.y < 0 || tile_coord.x >= TILEMAP_WIDTH || tile_coord.y >= TILEMAP_HEIGHT) {
        return true;
    }
    int index = tile_coord.y * TILEMAP_WIDTH + tile_coord.x;
    return tilemap[index];
}

bool collision_check(sf::Vector2f position)
{
    sf::Vector2i coord;
    coord.x = position.x / TILE_SIZE_PX;
    coord.y = position.y / TILE_SIZE_PX;

    printf("position (%f, %f) -> coord (%i, %i)\n",  position.x, position.y, coord.x, coord.y);

    if (coord.x < 0 || coord.y < 0 || coord.x >= TILEMAP_WIDTH || coord.y >= TILEMAP_HEIGHT) {
        return true;
    }

    int index = coord.y * TILEMAP_WIDTH + coord.x;
    bool tile_solid = tilemap[index];

    return tile_solid;
}

/// @return true if moved fully, false if collided. 
// bool move_player(sf::Vector2f delta)
// {
//     sf::Vector2f old_pos = player_pos;
//     player_pos += delta;
//     if (collision_check(player_pos)) {
//         player_pos = old_pos;
//         return false;
//     }
//     return true;
// }

int main()
{
    // set some tiles for testing purposes
    tilemap[0] = true; // top left
    tilemap[TILEMAP_WIDTH-1] = true; // top right
    tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT-1] = true; // bottom right
    {
        int x = 3;
        int y = 2;
        tilemap[TILEMAP_WIDTH*y + x] = true;
    }

    load();

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setVerticalSyncEnabled(true);

    // Create tile shape
    sf::RectangleShape tile_shape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
    tile_shape.setFillColor(sf::Color(209, 147, 67));
    tile_shape.setOutlineColor(sf::Color(245, 213, 127));
    tile_shape.setOutlineThickness(-2);

    // Create cursor shape
    sf::RectangleShape cursor_shape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
    cursor_shape.setFillColor(sf::Color(209, 147, 67, 0));
    cursor_shape.setOutlineColor(sf::Color(250, 250, 250));
    cursor_shape.setOutlineThickness(-3);

    // Create debug limit shapes
    sf::RectangleShape debug_limit_shape_vertical(sf::Vector2f(2, 10000));
    debug_limit_shape_vertical.setOrigin(1, 0);
    debug_limit_shape_vertical.setFillColor(sf::Color(255, 0, 255));
    sf::RectangleShape debug_limit_shape_horizontal(sf::Vector2f(10000, 2));
    debug_limit_shape_horizontal.setOrigin(0, 1);
    debug_limit_shape_horizontal.setFillColor(sf::Color(255, 0, 255));


    // Create player shape
    sf::CircleShape player_origin_shape(10);
    player_origin_shape.setOrigin(10,10);
    player_origin_shape.setFillColor(sf::Color(180, 30, 30));
    player_origin_shape.setOutlineColor(sf::Color(252, 100, 100));
    player_origin_shape.setOutlineThickness(-2);

    sf::RectangleShape player_box_shape(player_size);
    player_box_shape.setOrigin(player_size.x/2,player_size.y);
    player_box_shape.setFillColor(sf::Color(210, 210, 210));

    // run the program as long as the window is open
    while (window.isOpen())
    {
        

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::F5) {
                    save();
                }
                if (event.key.code == sf::Keyboard::F9) {
                    load();
                }
            }
        }


        float limit_x_low = -1000000000.f;
        float limit_x_high = 1000000000.f;
        float limit_y_low = -1000000000.f;
        float limit_y_high = 1000000000.f;

        sf::Vector2i player_coords = pos_to_coords(player_pos);
        const int margin = 1;
        if (tile_at(player_coords + sf::Vector2i(1,0))) {
            limit_x_high = (player_coords.x + 1) * TILE_SIZE_PX - margin;
        }
        if (tile_at(player_coords + sf::Vector2i(-1,0))) {
            limit_x_low = (player_coords.x) * TILE_SIZE_PX + margin;
        }
        if (tile_at(player_coords + sf::Vector2i(0,1))) {
            limit_y_high = (player_coords.y + 1) * TILE_SIZE_PX - margin;
        }
        if (tile_at(player_coords + sf::Vector2i(0,-1))) {
            limit_y_low = (player_coords.y) * TILE_SIZE_PX + margin;
        }

        // moving the player!
        sf::Vector2f delta(0,0);
        const float player_speed = 5;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            delta += sf::Vector2f(-player_speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            delta += sf::Vector2f(player_speed, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            delta += sf::Vector2f(0, player_speed);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            delta += sf::Vector2f(0, -player_speed);
        }

        // Cancel vertical velocity if grounded
        if (grounded) {
            player_vel.y = 0;
        }

        // jumping
        bool jump_key_is_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
        if (jump_key_is_down && grounded) {
            player_vel.y = -10;
        }

        // Falling speed limit
        if (player_vel.y > 7) {
            player_vel.y = 7;
        }

        // Gravity
        player_vel.y += jump_key_is_down ? 0.3f : 0.6f; // accel
        
        delta += sf::Vector2f(0, player_vel.y);

        player_pos += delta;
        if (player_pos.x >= limit_x_high - (player_size.x/2)) {
            player_pos.x = limit_x_high - (player_size.x/2);
        }
        if (player_pos.x <= limit_x_low + (player_size.x/2)) {
            player_pos.x = limit_x_low + (player_size.x/2);
        }
        grounded = false;
        if (player_pos.y >= limit_y_high) {
            player_pos.y = limit_y_high;
            grounded = true;
        }
        if (player_pos.y <= limit_y_low + player_size.y) {
            player_pos.y = limit_y_low + player_size.y;
            player_vel.y = 0;
        }

        // Determine tile coordinates that the mouse is hovering
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2i mouse_tile_coord(mouse_pos.x / 50, mouse_pos.y / 50);
        //printf("%i,%i\n", mouse_tile_coord.x, mouse_tile_coord.y);

        // Editor interaction
        bool mouse_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        bool mouse_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);
        if (mouse_left || mouse_right) {
            // Check the coordinates are inside our tilemap. Important! Otherwise we could write on unrelated memory and potentially corrupt or crash the program.
            if (in_bounds(mouse_tile_coord)) {
                // Set the hovered tile to true or false depending on the pressed mouse button.
                tilemap[mouse_tile_coord.y * TILEMAP_WIDTH + mouse_tile_coord.x] = mouse_left;
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw the tilemap
        for (int y = 0; y < TILEMAP_HEIGHT; y++) {
            for (int x = 0; x < TILEMAP_WIDTH; x++) {
                if (tilemap[x+y*TILEMAP_WIDTH]) {
                    // draw tile shape at correct position
                    tile_shape.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
                    window.draw(tile_shape);
                } else {
                    // draw nothing                    
                }
            }
        }

        // Visualize limits
        debug_limit_shape_vertical.setPosition(limit_x_high, 0);
        window.draw(debug_limit_shape_vertical);
        debug_limit_shape_vertical.setPosition(limit_x_low, 0);
        window.draw(debug_limit_shape_vertical);
        debug_limit_shape_horizontal.setPosition(0, limit_y_high);
        window.draw(debug_limit_shape_horizontal);
        debug_limit_shape_horizontal.setPosition(0, limit_y_low);
        window.draw(debug_limit_shape_horizontal);

        // draw selection cursor
        cursor_shape.setPosition(TILE_SIZE_PX * mouse_tile_coord.x, TILE_SIZE_PX * mouse_tile_coord.y);
        window.draw(cursor_shape);        

        // draw player
        player_box_shape.setPosition(player_pos.x, player_pos.y);
        window.draw(player_box_shape);
        player_origin_shape.setFillColor(grounded ? sf::Color(255, 0, 0) : sf::Color(0, 255, 255));
        player_origin_shape.setPosition(player_pos.x, player_pos.y);
        window.draw(player_origin_shape);
        

        // end the current frame
        window.display();
    }

    return 0;
}