#ifndef PANDA_HPP_
#define PANDA_HPP_

#include <SFML/Graphics.hpp>

class Panda
{
  int		_pv;
  sf::Texture	_textUp;
  sf::Texture	_textDown;
  sf::Texture	_textLeft;
  sf::Texture	_textRight;
  sf::Texture	_bomb;
  sf::Sprite	_spritePanda;
  sf::Sprite	_spriteBomb;
  
public:
  void		putBomb();
  sf::Sprite	getBomb() const;
  sf::Sprite	getPanda() const;
  int		getPv() const;
  sf::Vector2f	move(sf::Event);
  
  Panda();
  ~Panda();
};

#endif
