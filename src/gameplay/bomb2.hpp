#ifndef BOMB2_HPP_
#define BOMB2_HPP_

#include <SFML/Graphics.hpp>

class	Bomb2
{
  sf::Texture	_textBomb;
  sf::Sprite	_spriteBomb;
  
public:
  sf::Sprite	getBomb() const;
  void		setPos(sf::Vector2f);
  void		explosion(sf::Vector2f);

  Bomb2();
  Bomb2(const Bomb2 &);
  ~Bomb2();
  Bomb2	&operator=(const Bomb2 &);
};

#endif
