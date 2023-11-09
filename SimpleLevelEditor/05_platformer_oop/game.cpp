#include "game.h"

void Game::init()
{
	// Create the window
	window_.create(sf::VideoMode(800, 600), "Platformer");
	window_.setVerticalSyncEnabled(false);
	window_.setFramerateLimit(100);

	// Create tile shape
	tile_shape_ = sf::RectangleShape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	tile_shape_.setFillColor(sf::Color(209, 147, 67));

	if(tile_texture.loadFromFile("data/sprites/tile_0042.png"))
	{
		tile_sprite.setTexture(tile_texture);
		tile_sprite.setScale(TILE_SIZE_PX / (float)tile_texture.getSize().x, TILE_SIZE_PX / (float)tile_texture.getSize().y);
	}else
	{
		__debugbreak();
	}

	//tile_shape_.setOutlineColor(sf::Color(245, 213, 127));
	//tile_shape_.setOutlineThickness(-2);

	// Create cursor shape
	cursor_shape_ = sf::RectangleShape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	cursor_shape_.setFillColor(sf::Color(209, 147, 67, 0));
	cursor_shape_.setOutlineColor(sf::Color(250, 250, 250));
	cursor_shape_.setOutlineThickness(-3);

	// Create debug limit shapes
	debug_limit_shape_vertical_ = sf::RectangleShape(sf::Vector2f(2, 10000));
	debug_limit_shape_vertical_.setOrigin(1, 0);
	debug_limit_shape_vertical_.setFillColor(sf::Color(255, 0, 255));
	debug_limit_shape_horizontal_ = sf::RectangleShape(sf::Vector2f(10000, 2));
	debug_limit_shape_horizontal_.setOrigin(0, 1);
	debug_limit_shape_horizontal_.setFillColor(sf::Color(255, 0, 255));

	// Create player shape
	player_origin_shape_ = sf::CircleShape(10);
	player_origin_shape_.setOrigin(10, 10);
	player_origin_shape_.setFillColor(sf::Color(180, 30, 30));
	player_origin_shape_.setOutlineColor(sf::Color(252, 100, 100));
	player_origin_shape_.setOutlineThickness(-2);

	player_box_shape_ = sf::RectangleShape(player_size);
	player_box_shape_.setOrigin(player_size.x / 2, player_size.y);
	player_box_shape_.setFillColor(sf::Color(210, 210, 210));


	hud_.Init();
	hud_.StartChrono();

}

void Game::update()
{
	float limit_x_low = -1000000000.f;
	float limit_x_high = 1000000000.f;
	float limit_y_low = -1000000000.f;
	float limit_y_high = 1000000000.f;

	hud_.UpdateChrono();
	frameStart = std::chrono::high_resolution_clock::now();

	hud_.Update();

	const sf::Vector2i player_coords = tilemap_.PosToCoords(player_pos_);
	constexpr int margin = 1;
	if (tilemap_.TileAt(player_coords + sf::Vector2i(1, 0))) {
		limit_x_high = (player_coords.x + 1) * TILE_SIZE_PX - margin;
	}
	if (tilemap_.TileAt(player_coords + sf::Vector2i(-1, 0))) {
		limit_x_low = (player_coords.x) * TILE_SIZE_PX + margin;
	}
	if (tilemap_.TileAt(player_coords + sf::Vector2i(0, 1))) {
		limit_y_high = (player_coords.y + 1) * TILE_SIZE_PX - margin;
	}
	if (tilemap_.TileAt(player_coords + sf::Vector2i(0, -1))) {
		limit_y_low = (player_coords.y) * TILE_SIZE_PX + margin;
	}

	// moving the player!
	sf::Vector2f delta(0, 0);
	const float kPlayerSpeed = 3;
	const float kJumpSpeed = -8;
	constexpr float kFallLimit = 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		delta += sf::Vector2f(-kPlayerSpeed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		delta += sf::Vector2f(kPlayerSpeed, 0);
	}
#if 0 // NOTE(seb): disabled vertical movement, but keeping as it's useful for testing. Could be useful for ladders as well.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		delta += sf::Vector2f(0, player_speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		delta += sf::Vector2f(0, -player_speed);
	}
#endif

	// Cancel vertical velocity if grounded
	if (grounded) {
		player_vel_.y = 0;
	}

	// jumping
	bool jump_key_is_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	if (jump_key_is_down && grounded) {
		player_vel_.y = kJumpSpeed;
	}


	// Falling speed limit
	if (player_vel_.y > kFallLimit) {
		player_vel_.y = kFallLimit;
	}

	constexpr float kMinFallForce = 0.1f;
	constexpr float kMaxFallForce = 0.2f;
	// Gravity
	player_vel_.y += jump_key_is_down ? kMinFallForce : kMaxFallForce; // accel

	delta += sf::Vector2f(0, player_vel_.y);

	player_pos_ += delta;
	if (player_pos_.x >= limit_x_high - (player_size.x / 2)) {
		player_pos_.x = limit_x_high - (player_size.x / 2);
	}
	if (player_pos_.x <= limit_x_low + (player_size.x / 2)) {
		player_pos_.x = limit_x_low + (player_size.x / 2);
	}

	grounded = false;
	if (player_pos_.y >= limit_y_high) {
		player_pos_.y = limit_y_high;
		grounded = true;
	}

	if (player_pos_.y <= limit_y_low + player_size.y) {
		player_pos_.y = limit_y_low + player_size.y;
		player_vel_.y = 0;
	}

	// convert it to world coordinates
	sf::View newView = sf::View(sf::Vector2f(window_.getSize().x * 0.5f, window_.getSize().y * 0.5f), sf::Vector2f(window_.getSize().x, window_.getSize().y));
	window_.setView(newView);
	 
	// Determine tile coordinates that the mouse is hovering
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window_);
	sf::Vector2i mouseCoord_TilesRelative = sf::Vector2i(
		window_.mapPixelToCoords(mouse_pos, window_.getView()).x / TILE_SIZE_PX,
		window_.mapPixelToCoords(mouse_pos, window_.getView()).y / TILE_SIZE_PX
		);

	//sf::Vector2i mouse_tile_coord(mouse_pos.x / 50, mouse_pos.y / 50);
	//printf("Tiles Coord : %i,%i\n", mouseCoord_TilesRelative.x, mouseCoord_TilesRelative.y);

	// Editor interaction
	bool mouse_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool mouse_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	bool shift_down = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);

	if (mouse_left || mouse_right) {
		// Check the coordinates are inside our tilemap. Important! Otherwise we could write on unrelated memory and potentially corrupt or crash the program.
		if (tilemap_.InBounds(mouseCoord_TilesRelative)) {
			if(mouse_left)
			{
				if(shift_down)
					// Set the hovered tile to true or false depending on the pressed mouse button.
					tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::kRed;
				else
					// Set the hovered tile to true or false depending on the pressed mouse button.
					tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::kYellow;

			}else
			{
				tilemap_.cells[mouseCoord_TilesRelative.y * TILEMAP_WIDTH + mouseCoord_TilesRelative.x] = (int)Tilemap::TileType::kNotile;
			}
		}
	}

	// clear the window with black color
	window_.clear(sf::Color::Black);

	// draw the tilemap
	for (int y = 0; y < TILEMAP_HEIGHT; y++) {
		for (int x = 0; x < TILEMAP_WIDTH; x++) {

			tile_shape_.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
			tile_sprite.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);

			Tilemap::TileType tileType = (Tilemap::TileType)tilemap_.cells[x + y * TILEMAP_WIDTH];
			switch (tileType)
			{

			case Tilemap::TileType::kYellow:
				// draw tile shape at correct position
				tile_shape_.setFillColor(sf::Color(209, 147, 67));
				//window_.draw(tile_shape_);
				window_.draw(tile_sprite);
				break;

			case Tilemap::TileType::kRed:
				tile_shape_.setFillColor(sf::Color(209, 65, 34));
				window_.draw(tile_shape_);
				break;

			case Tilemap::TileType::kNotile:
			default:
				break;
			}

			//if ( ) {
			//    // draw tile shape at correct position
			//    tile_shape_.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
			//    window_.draw(tile_shape_);
			//} else {
			//    // draw nothing                    
			//}
		}
	}

	// Draw the HUD above everything else
	window_.draw(hud_);

	// Visualize limits
	debug_limit_shape_vertical_.setPosition(limit_x_high, 0);
	window_.draw(debug_limit_shape_vertical_);
	debug_limit_shape_vertical_.setPosition(limit_x_low, 0);
	window_.draw(debug_limit_shape_vertical_);
	debug_limit_shape_horizontal_.setPosition(0, limit_y_high);
	window_.draw(debug_limit_shape_horizontal_);
	debug_limit_shape_horizontal_.setPosition(0, limit_y_low);
	window_.draw(debug_limit_shape_horizontal_);

	// draw selection cursor
	cursor_shape_.setPosition(TILE_SIZE_PX * mouseCoord_TilesRelative.x, TILE_SIZE_PX * mouseCoord_TilesRelative.y);
	window_.draw(cursor_shape_);

	// draw player
	player_box_shape_.setPosition(player_pos_.x, player_pos_.y);
	window_.draw(player_box_shape_);
	player_origin_shape_.setFillColor(grounded ? sf::Color(255, 0, 0) : sf::Color(0, 255, 255));
	player_origin_shape_.setPosition(player_pos_.x, player_pos_.y);
	window_.draw(player_origin_shape_);


	// end the current frame
	window_.display();
}
