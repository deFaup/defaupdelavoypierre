/* Includes */
#include <iostream>
#include "define.hpp"
#include "Background.h"

using namespace std;
using namespace render;

Background::Background(const state::GameState& state, const state::Map& map) : state(state), map(map)
{
	/* the background is initialized straight into the constructor */
	
	/* instantiation of a unique work surface */
	surface = make_unique<Surface>();
	
	/* get map dimensions */
	int width(0), height(0);
	map.get_dimensions(width, height);

	/* creating an empty background whose size == map's size*/
	tileset.push_back( make_shared<TileSet>(width, height, sf::Color::Black) );

	/* Linking our Surface texure to the background */
	surface->loadTexture(tileset[0]->getImage());

	/* Linking our Surface sprite to the Surface texture */
	surface->setSpriteTexture();

	/* loading the images to make the background */
	tileset.push_back(make_shared<TileSet>("res/textureciel.png"));
	tileset.push_back(make_shared<TileSet>("res/textureherbe.png"));
	tileset.push_back(make_shared<TileSet>("res/texturesol.png"));

	/* update the background to represent the state's map */
	update();
}

/* Update the background if the mask has changed */
void Background::update()
{
	/* get background */
	sf::Image& image = tileset[0]->getImage();

	/* get the mask of state's map */
	const vector<vector<int>>& mask(map.get_mask()); 
	
	/* get map dimensions */
	int width(0), height(0);
	map.get_dimensions(width, height);

	/* update the background to represent the state's map */
	sf::Image& ciel = tileset[1]->getImage();
	sf::Image& herbe = tileset[2]->getImage();
	sf::Image& sol = tileset[3]->getImage();

	for (int y = 0; y < height; y++) { //y == height
		for (int x = 0; x < width; x++) { // x== width
			if (mask[y][x] == 1) {
				image.setPixel(x, y, sol.getPixel(x, y));
			}
			else if (mask[y][x] == 2) {
				image.setPixel(x, y, herbe.getPixel(x, y));
			}
			else {
				image.setPixel(x, y, ciel.getPixel(x, y));
			}
		}
	}

	/* update the texture and thus the sprite as they are linked */
	surface->update(image);

}
