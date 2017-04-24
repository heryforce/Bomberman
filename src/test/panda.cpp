#include "panda.hpp"
#include <iostream>

void		Panda::putBomb()
{
  _spriteBomb.setPosition(_spritePanda.getPosition());
}

sf::Sprite	Panda::getBomb() const
{
  return _spriteBomb;
}

sf::Sprite	Panda::getPanda() const
{
  return _spritePanda;
}

int	Panda::getPv() const
{
  return _pv;
}

sf::Vector2f	Panda::move(sf::Event event)
{
  switch(event.key.code)
    {
    case sf::Keyboard::Up:
      if (_spritePanda.getTexture() != &_textUp)
	_spritePanda.setTexture(_textUp);
      if (_spritePanda.getPosition().y > 8)
	_spritePanda.move(0, -9);
      break;
    case sf::Keyboard::Down:
      if (_spritePanda.getTexture() != &_textDown)
	_spritePanda.setTexture(_textDown);
      if (_spritePanda.getPosition().y < 468)
	_spritePanda.move(0, 9);
      break;
    case sf::Keyboard::Left:
            if (_spritePanda.getTexture() != &_textLeft)
	_spritePanda.setTexture(_textLeft);
      if (_spritePanda.getPosition().x > 8)
	_spritePanda.move(-9, 0);
      break;
    case sf::Keyboard::Right:
      if (_spritePanda.getTexture() != &_textRight)
	_spritePanda.setTexture(_textRight);
      if (_spritePanda.getPosition().x < 468)
	_spritePanda.move(9, 0);
      break;
    default:
      break;
    }
  return _spritePanda.getPosition();
}

Panda::Panda() : _pv(2)
{
  if (!_textDown.loadFromFile("../../sprites/char/panda_front.png"))
    std::cout << "can't load the panda" << std::endl;
  else if (!_textUp.loadFromFile("../../sprites/char/panda_back.png"))
    std::cout << "can't load the panda" << std::endl;
  else if (!_textLeft.loadFromFile("../../sprites/char/panda_left.png"))
    std::cout << "can't load the panda" << std::endl;
  else if (!_textRight.loadFromFile("../../sprites/char/panda_right.png"))
    std::cout << "can't load the panda" << std::endl;
  else if (!_bomb.loadFromFile("../../sprites/weapons/bomb32.png"))
    std::cout << "can't load the bomb" << std::endl;
  else
    {
      _spriteBomb.setTexture(_bomb);
      _spritePanda.setTexture(_textDown);
      _spritePanda.setPosition(0, 0);
    }
  
}

Panda::~Panda(){}
