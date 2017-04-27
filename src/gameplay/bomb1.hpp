#ifndef BOMB1_HPP_
#define BOMB1_HPP_

#include <SFML/Graphics.hpp>

class	Bomb1
{
  sf::Texture	_textBomb;
  sf::Sprite	_spriteBomb;
  
public:
  sf::Sprite	getBomb() const;
  void		setPos(sf::Vector2f);
  void		explosion(sf::Vector2f);

  Bomb1();
  Bomb1(const Bomb1 &);
  ~Bomb1();
  Bomb1	&operator=(const Bomb1 &);
};

#endif
