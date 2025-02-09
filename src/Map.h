#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Map;
struct Tile;

struct MapData {
    std::string tileSheet = "";
    int version = 0;
    std::string name = "";

    int mapWidth = 0;
    int mapHeight = 0;

    int tileWidth = 0;
    int tileHeight = 0;

    int scaleX = 0;
    int scaleY = 0;

    int dataLength = 0;
    int* data = nullptr;
    
};

class MapLoader {
public:
    void Load(std::string filename, MapData& mapData);

};

class Map
{
    Tile* tiles;

    MapLoader mapLoader;
    MapData md;

    int totalTiles;
    int totalTilesX;
    int totalTilesY;

public:
    sf::Texture tileSheetTexture = sf::Texture("assets/world/TileSheet.png");

    std::vector<sf::Sprite> mapSprites;
    Map();
    void Initilize();
    void Load(std::string filename);
    void Update();
    void Draw(sf::RenderWindow& window);
};

struct Tile : private Map {
    int id = -1;
    sf::Vector2i position;

};