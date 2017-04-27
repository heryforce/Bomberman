#include "bomb2.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unistd.h>
#include <iostream>

void	Bomb2::explosion(sf::Vector2f pos)
{
  sleep(1);
}

void	Bomb2::setPos(sf::Vector2f pos)
{
  _spriteBomb.setPosition(pos);
}

sf::Sprite	Bomb2::getBomb() const
{
  return _spriteBomb;
}

Bomb2::Bomb2()
{
  if (!_textBomb.loadFromFile("../../sprites/weapons/_bomb32.png"))
    std::cout << "can't load the bomb2" << std::endl;
  else
    _spriteBomb.setTexture(_textBomb);
}

Bomb2::Bomb2(const Bomb2 &obj)
{
  _textBomb = obj._textBomb;
  _spriteBomb = obj._spriteBomb;
}

Bomb2::~Bomb2(){}

Bomb2	&Bomb2::operator=(const Bomb2 &obj)
{
  _textBomb = obj._textBomb;
  _spriteBomb = obj._spriteBomb;
}
