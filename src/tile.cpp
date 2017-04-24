#include "tile.hpp"
#include <iostream>

bool	Tile::getSolid() const
{
	return (_isSolid);
}

int		Tile::getPv() const
{
	return (_pv);
}

void	Tile::setPv(int pv)
{
	this->_pv = pv;
}

void	Tile::setSolid(bool solid)
{
	this->isSolid = solid;
}

Tile::Tile(std::string str) : _pv(1)
{
	if(!this->texture.loadFromFile("../sprites/map/tile.png"))
		std::cout << "the map couldn't be loaded" << std::endl;
}

Tile::~Tile(){}
