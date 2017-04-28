#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <SFML/Graphics.hpp>

class	Bomb
{
  sf::Texture	_textBomb;
  sf::Sprite	_spriteBomb;
  
public:
  sf::Sprite	getBomb() const;
  void		setPos(sf::Vector2f);
  void		explosion(sf::Vector2f);

  Bomb();
  Bomb(const Bomb &);
  ~Bomb();
  Bomb	&operator=(const Bomb &);
};

#endif
