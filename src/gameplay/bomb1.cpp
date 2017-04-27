#include "bomb1.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unistd.h>
#include <iostream>

void	Bomb1::explosion(sf::Vector2f pos)
{
  sleep(1);
}

void	Bomb1::setPos(sf::Vector2f pos)
{
  _spriteBomb.setPosition(pos);
}

sf::Sprite	Bomb1::getBomb() const
{
  return _spriteBomb;
}

Bomb1::Bomb1()
{
  if (!_textBomb.loadFromFile("../../sprites/weapons/bomb32.png"))
    std::cout << "can't load the bomb" << std::endl;
  else
    _spriteBomb.setTexture(_textBomb);
}

Bomb1::Bomb1(const Bomb1 &obj)
{
  _textBomb = obj._textBomb;
  _spriteBomb = obj._spriteBomb;
}

Bomb1::~Bomb1(){}

Bomb1	&Bomb1::operator=(const Bomb1 &obj)
{
  _textBomb = obj._textBomb;
  _spriteBomb = obj._spriteBomb;
}
