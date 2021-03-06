#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include "bomb.hpp"

class Player
{
  int		_nb;
  int		_pv;
  sf::Texture	_textUp;
  sf::Texture	_textDown;
  sf::Texture	_textLeft;
  sf::Texture	_textRight;
  sf::Sprite	_spriteP;
  Bomb		_bomb;
  bool		_ammo;
  bool		_touched;
  sf::FloatRect	_bound;

public:
  void		setTouched(bool);
  bool		getTouched() const;
  sf::FloatRect	getVBound() const;
  sf::FloatRect	getHBound() const;
  void		unsetEBound();
  void		setBound();
  sf::FloatRect	getBound() const;
  void		explosion(sf::RenderWindow *, sf::Vector2f, int);
  int		getNb() const;
  sf::Sprite	putBomb();
  void		setAmmo(bool);
  bool		getAmmo() const;
  sf::Sprite	getP() const;
  void		setPv();
  int		getPv() const;
  sf::Vector2f	move(sf::Event);
  
  Player(int);
  ~Player();
};

#endif
