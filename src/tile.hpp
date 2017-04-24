#ifndef TILE_HPP
#define TILE_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Tile : public sf::Texture
{
	int			_pv;
	bool		_isSolid;
	sf::Texture	texture;

public:
	int		getPv() const;
	bool	getSolid() const;
	void	setPv(int);
	void	setSolid(bool);

  Tile(std::string);
  ~Tile();
};

#endif
