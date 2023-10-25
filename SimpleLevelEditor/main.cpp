#include <SFML/Graphics.hpp>
#include <ios>
#include <iostream>
#include <unistd.h>

#define TILEMAP_WIDTH 10
#define TILEMAP_HEIGHT 8
#define TILE_SIZE_PX 50

int main()
{
    // initialize a bool array with all zeroes (false).
    bool tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = {0};

    // set some tiles for testing purposes
    tilemap[0] = true; // top left
    tilemap[TILEMAP_WIDTH-1] = true; // top right
    tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT-1] = true; // bottom right
    {
        int x = 3;
        int y = 2;
        tilemap[TILEMAP_WIDTH*y + x] = true;
    }

    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // Determine tile coordinates that the mouse is hovering
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        sf::Vector2i mouse_tile_coord(mouse_pos.x / 50, mouse_pos.y / 50);
        //printf("%i,%i\n", mouse_tile_coord.x, mouse_tile_coord.y);

        // Editor interaction
        bool mouse_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
        bool mouse_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);
        if (mouse_left || mouse_right) {
            // Check the coordinates are inside our tilemap. Important! Otherwise we could write on unrelated memory and potentially corrupt or crash the program.
            if (mouse_tile_coord.x < 0 || mouse_tile_coord.x >= TILEMAP_WIDTH || mouse_tile_coord.y < 0 || mouse_tile_coord.y >= TILEMAP_HEIGHT) {
                printf("Out of bounds\n");
            } else {
                // Set the hovered tile to true or false depending on the pressed mouse button.
                tilemap[mouse_tile_coord.y * TILEMAP_WIDTH + mouse_tile_coord.x] = mouse_left;
            }
        }

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
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

        // draw selection cursor
        cursor_shape.setPosition(TILE_SIZE_PX * mouse_tile_coord.x, TILE_SIZE_PX * mouse_tile_coord.y);
        window.draw(cursor_shape);        
        
        // end the current frame
        window.display();
    }

    return 0;
}