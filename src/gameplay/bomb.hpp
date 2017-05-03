#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <SFML/Graphics.hpp>

class	Bomb
{
  sf::Texture	_exp1;
  sf::Texture	_exp2;
  sf::Texture	_exp3;
  sf::Texture	_exp4;
  sf::Texture	_exp5;
  sf::Texture	_exp6;
  sf::Texture	_exp7;
  sf::Texture	_exp8;
  sf::Texture	_exp9;
  sf::Texture	_textBomb;
  sf::Sprite	_exp;
  sf::Sprite	_spriteBomb;
  
public:
  sf::Sprite	getBomb() const;
  void		setPos(sf::Vector2f);
  void		explosion(sf::Vector2f, sf::RenderWindow *, int);

  Bomb();
  Bomb(const Bomb &);
  ~Bomb();
  Bomb	&operator=(const Bomb &);
};

#endif
