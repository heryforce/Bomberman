#include "player1.hpp"
#include <iostream>
#include "bomb.hpp"

void	Player1::setAmmo(bool ammo)
{
  _ammo = ammo;
}

bool	Player1::getAmmo() const
{
  return _ammo;
}

sf::Sprite	Player1::putBomb()
{
  std::cout << "dans player->putbomb()" << std::endl;
  _bomb.setPos(_spriteP1.getPosition());
  _ammo = false;
  return (_bomb.getBomb());
}

sf::Sprite	Player1::getP1() const
{
  return _spriteP1;
}

int	Player1::getPv() const
{
  return _pv;
}

sf::Vector2f	Player1::move(sf::Event event)
{
  switch(event.key.code)
    {
    case sf::Keyboard::Up:
      if (_spriteP1.getTexture() != &_textUp)
	_spriteP1.setTexture(_textUp);
      if (_spriteP1.getPosition().y > 8)
	_spriteP1.move(0, -9);
      break;
    case sf::Keyboard::Down:
      if (_spriteP1.getTexture() != &_textDown)
	_spriteP1.setTexture(_textDown);
      if (_spriteP1.getPosition().y < 468)
	_spriteP1.move(0, 9);
      break;
    case sf::Keyboard::Left:
      if (_spriteP1.getTexture() != &_textLeft)
	_spriteP1.setTexture(_textLeft);
      if (_spriteP1.getPosition().x > 8)
	_spriteP1.move(-9, 0);
      break;
    case sf::Keyboard::Right:
      if (_spriteP1.getTexture() != &_textRight)
	_spriteP1.setTexture(_textRight);
      if (_spriteP1.getPosition().x < 468)
	_spriteP1.move(9, 0);
      break;
    default:
      break;
    }
  return _spriteP1.getPosition();
}

Player1::Player1() : _pv(2), _ammo(true)
{
  if (!_textDown.loadFromFile("../../sprites/char/panda_front.png"))
    std::cout << "can't load the player 1" << std::endl;
  else if (!_textUp.loadFromFile("../../sprites/char/panda_back.png"))
    std::cout << "can't load the player 1" << std::endl;
  else if (!_textLeft.loadFromFile("../../sprites/char/panda_left.png"))
    std::cout << "can't load the player 1" << std::endl;
  else if (!_textRight.loadFromFile("../../sprites/char/panda_right.png"))
    std::cout << "can't load the player1" << std::endl;
  else
    {
      _spriteP1.setTexture(_textDown);
      _spriteP1.setPosition(0, 0);
    }  
}

Player1::~Player1()
{
  std::cout << "The player 1 is dead !" << std::endl;
}
