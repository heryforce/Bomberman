#ifndef PLAYER2_HPP_
#define PLAYER2_HPP_

#include <SFML/Graphics.hpp>
#include "bomb2.hpp"

class Player2
{
  int		_pv;
  sf::Texture	_textUp;
  sf::Texture	_textDown;
  sf::Texture	_textLeft;
  sf::Texture	_textRight;
  sf::Sprite	_spriteP2;
  Bomb2		_bomb;
  bool		_ammo;
  
public:
  sf::Sprite	putBomb();
  void		setAmmo(bool);
  bool		getAmmo() const;
  sf::Sprite	getP2() const;
  int		getPv() const;
  sf::Vector2f	move(sf::Event);
  
  Player2();
  ~Player2();
};

#endif
