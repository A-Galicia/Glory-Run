#pragma once
#include <SFML/Graphics.hpp>
struct Tile;

class Map
{
    Tile* tiles;

    int tileWidth;
    int tileHeight;
    int totalTiles;
    int totalTilesX;
    int totalTilesY;

    static const int mapSize = 6;
    int mapWidth;
    int mapHeight;
    int mapNumbers[mapSize] = {
        120, 121, 122,
        144, 145, 146
    };

public:
    sf::Texture tileSheetTexture = sf::Texture("assets/world/TileSheet.png");
    sf::Sprite mapSprites[mapSize];
    Map();
    void Initilize();
    void Load();
    void Update();
    void Draw(sf::RenderWindow& window);
};


struct Tile : private Map {
    int id = -1;
    sf::Vector2i position;

};

class MapLoader {
public:
    void Load(std::string filename);

};