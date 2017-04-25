#include "bomb.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unistd.h>
#include <iostream>

void	Bomb::explosion(sf::Vector2f pos)
{
  sleep(1);
}

void	Bomb::setPos(sf::Vector2f pos)
{
  _spriteBomb.setPosition(pos);
}

sf::Sprite	Bomb::getBomb() const
{
  return _spriteBomb;
}

Bomb::Bomb()
{
  if (!_textBomb.loadFromFile("../../sprites/weapons/bomb32.png"))
    std::cout << "can't load the bomb" << std::endl;
  else
    _spriteBomb.setTexture(_textBomb);
}

Bomb::Bomb(const Bomb &obj)
{
  _textBomb = obj._textBomb;
  _spriteBomb = obj._spriteBomb;
}

Bomb::~Bomb(){}

Bomb	&Bomb::operator=(const Bomb &obj)
{
  _textBomb = obj._textBomb;
  _spriteBomb = obj._spriteBomb;
}
