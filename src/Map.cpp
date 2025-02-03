#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>

Map::Map():
    tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0), totalTiles(0), mapWidth(3), mapHeight(2), tiles(nullptr), mapSprites{sf::Sprite(tileSheetTexture),sf::Sprite(tileSheetTexture), sf::Sprite(tileSheetTexture), sf::Sprite(tileSheetTexture),sf::Sprite(tileSheetTexture), sf::Sprite(tileSheetTexture)}
{


}


void Map::Initilize()
{
}

void Map::Load()
{

    if (tileSheetTexture.loadFromFile("assets/world/TileSheet.png")) {

        totalTilesX = tileSheetTexture.getSize().x / tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / tileHeight;
        std::cout << "World titleSheet loaded\n";

        totalTiles = totalTilesX * totalTilesY;

        tiles = new Tile[totalTiles];

        for (int y = 0; y < totalTilesY; y++) {
            for (int x = 0; x < totalTilesX ; x++) {

                int i = x + y * totalTilesX;

                tiles[i].id = i;
                tiles[i].position = sf::Vector2i( x * tileWidth, y * tileHeight );

            }

        }

    }
    else {
        std::cout << "World titleSheet failed to load\n";
    }

    for (int y = 0; y < mapHeight; y++) {
        for (int x = 0; x < mapWidth; x++) {
            int i = x + y * mapWidth;
            int index = mapNumbers[i];
            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(
                { tiles[index].position.x, tiles[index].position.y }, 
                { tileWidth, tileHeight }));

            mapSprites[i].setScale(sf::Vector2f(5, 5));
            mapSprites[i].setPosition(sf::Vector2f(
                x * tileWidth * mapSprites[i].getScale().x, 
                100+ y * tileWidth * mapSprites[i].getScale().y));
        }
    }
}

void Map::Update()
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < mapSize; i++) {
        window.draw(mapSprites[i]);
    
    }
}

void MapLoader::Load(std::string filename)
{
    MapData data;
    std::string line;
    std::ifstream file(filename);

    bool isMapValid = false;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            
            if (!isMapValid) {

                if (line == "[Map]") {
                    isMapValid = true;
                    continue;
                }
                else {
                    std::cout << "file is not vaid" << '\n';
                    break;
                }

            }

            if (isMapValid) {
                int count = line.find('=');
                std::string var = line.substr(0, count);
                std::string val = line.substr(count + 1, line.length() - count);

                if (var == "version") {
                data.version = std::stoi(val);
                }
                if (var == "tileSheet") {
                    data.tileSheet = val;
                }             
                else if (var == "name") {
                    data.name = val;
                }
                else if (var == "tileWidth") {
                    data.tileWidth = std::stoi(val);
                }
                else if (var == "tileHeight") {
                    data.tileHeight = std::stoi(val);
                }
                else if (var == "scaleX") {
                    data.scaleX = std::stoi(val);
                }
                else if (var == "scaleY") {
                    data.scaleY = std::stoi(val);
                }
                else if (var == "dataLength") {
                    data.dataLength = std::stoi(val);
                }
                else if (var == "data") {

                    data.data = new int[data.dataLength];

                    int offset = 0;
                    for (int i = 0; i < data.dataLength; i++) {
                        int index = val.find(',', offset);
                        std::string subData = val.substr(offset, index - offset);
                        data.data[i] = std::stoi(subData);
                        offset = index + 1;
                    }

                }
            }


        }


        file.close();
    }
    else {
        std::cout << "Unable to open" << filename << std::endl;
    }
}
