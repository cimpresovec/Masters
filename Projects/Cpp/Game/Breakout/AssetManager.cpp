#include "AssetManager.h"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
    for (auto &[key, val] : textures)
    {
        UnloadTexture(val);
    }
    for (auto &[key, val] : sounds)
    {
        UnloadSound(val);
    }
}

AssetManager &AssetManager::getInstance()
{
    static AssetManager instance;
    return instance;
}

void AssetManager::loadTexture(const std::string name, const std::string path)
{
    Image image = LoadImage(path.c_str());
    Texture2D texture = LoadTextureFromImage(image);
    textures.insert(std::pair<std::string, Texture2D>(name, texture));
    UnloadImage(image);
}

Texture2D &AssetManager::getTexture(const std::string name)
{
    return textures.at(name);
}

Rectangle AssetManager::getRectangle(const std::string name)
{
    return Rectangle{0, 0, textures.at(name).width, textures.at(name).height};
}

void AssetManager::loadSound(const std::string name, const std::string path)
{
    Sound sound = LoadSound(path.c_str());
    sounds.insert(std::pair<std::string, Sound>(name, sound));
}

Sound &AssetManager::getSound(const std::string name)
{
    return sounds.at(name);
}
