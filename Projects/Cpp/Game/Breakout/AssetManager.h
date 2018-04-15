#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <raylib.h>
#include <map>

class AssetManager
{
    std::map<std::string, Texture2D> textures;
    std::map<std::string, Sound> sounds;
public:
    AssetManager();
    ~AssetManager();
    static AssetManager& getInstance();

    //Singleton - remove methods we don't want
    AssetManager(AssetManager const&) = delete;
    void operator=(AssetManager const&) = delete;

    void loadTexture(const std::string name, const std::string path);
    Texture2D& getTexture(const std::string name);
    Rectangle getRectangle(const std::string name);

    void loadSound(const std::string name, const std::string path);
    Sound& getSound(const std::string name);
};

#endif // ASSETMANAGER_H
