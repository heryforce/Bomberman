#ifndef PLAYER1_HPP_
#define PLAYER1_HPP_

#include <SFML/Graphics.hpp>
#include "bomb.hpp"

class Player1
{
  int		_pv;
  sf::Texture	_textUp;
  sf::Texture	_textDown;
  sf::Texture	_textLeft;
  sf::Texture	_textRight;
  sf::Sprite	_spriteP1;
  Bomb		_bomb;
  bool		_ammo;
  
public:
  sf::Sprite	putBomb();
  void		setAmmo(bool);
  bool		getAmmo() const;
  sf::Sprite	getP1() const;
  int		getPv() const;
  sf::Vector2f	move(sf::Event);
  
  Player1();
  ~Player1();
};

#endif
