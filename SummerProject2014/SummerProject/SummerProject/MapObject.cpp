#pragma once
#include "stdafx.h"
#include "MapObject.h"

MapObject::MapObject() : GameObject(){

}
MapObject::MapObject(sf::String name, int level, sf::Vector2f position, sf::Vector2f extention) : GameObject(name, level, position, extention){

}