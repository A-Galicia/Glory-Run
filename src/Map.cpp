#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>


Map::Map():
    totalTilesX(0), totalTilesY(0), totalTiles(0),tiles(nullptr)
{


}


void Map::Initilize()
{
}

void Map::Load(std::string filename)
{
    mapLoader.Load(filename, md);


    if (tileSheetTexture.loadFromFile(md.tileSheet)) {

        for (int i = 0; i < md.dataLength; i++) {
            mapSprites.push_back(sf::Sprite(tileSheetTexture));
        }

        totalTilesX = tileSheetTexture.getSize().x / md.tileWidth;
        totalTilesY = tileSheetTexture.getSize().y / md.tileHeight;
        std::cout << "World titleSheet loaded\n";

        totalTiles = totalTilesX * totalTilesY;

        tiles = new Tile[totalTiles];

        for (int y = 0; y < totalTilesY; y++) {
            for (int x = 0; x < totalTilesX ; x++) {

                int i = x + y * totalTilesX;

                tiles[i].id = i;
                tiles[i].position = sf::Vector2i( x * md.tileWidth, y * md.tileHeight );

            }

        }

    }
    else {
        std::cout << "World titleSheet failed to load\n";
    }

    for (int y = 0; y < md.mapHeight; y++) {
        for (int x = 0; x < md.mapWidth; x++) {
            int i = x + y * md.mapWidth;
            int index = md.data[i];
            mapSprites[i].setTexture(tileSheetTexture);
            mapSprites[i].setTextureRect(sf::IntRect(
                { tiles[index].position.x, tiles[index].position.y }, 
                { md.tileWidth, md.tileHeight }));

            mapSprites[i].setScale(sf::Vector2f(md.scaleX, md.scaleY));
            mapSprites[i].setPosition(sf::Vector2f(
                x * md.tileWidth * md.scaleX, 
                y * md.tileWidth * md.scaleY));
        }
    }
}

void Map::Update()
{
}

void Map::Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < md.dataLength; i++) {
        window.draw(mapSprites[i]);
    
    }
}

void MapLoader::Load(std::string filename, MapData& mapData)
{
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
                mapData.version = std::stoi(val);
                }
                if (var == "tileSheet") {
                    mapData.tileSheet = val;
                }             
                else if (var == "name") {
                    mapData.name = val;
                }
                else if (var == "mapWidth") {
                    mapData.mapWidth = std::stoi(val);
                }
                else if (var == "mapHeight") {
                    mapData.mapHeight = std::stoi(val);
                }
                else if (var == "tileWidth") {
                    mapData.tileWidth = std::stoi(val);
                }
                else if (var == "tileHeight") {
                    mapData.tileHeight = std::stoi(val);
                }
                else if (var == "scaleX") {
                    mapData.scaleX = std::stoi(val);
                }
                else if (var == "scaleY") {
                    mapData.scaleY = std::stoi(val);
                }
                else if (var == "dataLength") {
                    mapData.dataLength = std::stoi(val);
                }
                else if (var == "data") {

                    mapData.data = new int[mapData.dataLength];

                    int offset = 0;
                    for (int i = 0; i < mapData.dataLength; i++) {
                        int index = val.find(',', offset);
                        std::string subData = val.substr(offset, index - offset);
                        mapData.data[i] = std::stoi(subData);
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
