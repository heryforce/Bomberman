#include "player2.hpp"
#include <iostream>
#include "bomb2.hpp"

void	Player2::setAmmo(bool ammo)
{
  _ammo = ammo;
}

bool	Player2::getAmmo() const
{
  return _ammo;
}

sf::Sprite	Player2::putBomb()
{
  std::cout << "dans player->putbomb()" << std::endl;
  _bomb.setPos(_spriteP2.getPosition());
  _ammo = false;
  return (_bomb.getBomb());
}

sf::Sprite	Player2::getP2() const
{
  return _spriteP2;
}

int	Player2::getPv() const
{
  return _pv;
}

sf::Vector2f	Player2::move(sf::Event event)
{
  switch(event.key.code)
    {
    case sf::Keyboard::Up:
      if (_spriteP2.getTexture() != &_textUp)
	_spriteP2.setTexture(_textUp);
      if (_spriteP2.getPosition().y > 8)
	_spriteP2.move(0, -9);
      break;
    case sf::Keyboard::Down:
      if (_spriteP2.getTexture() != &_textDown)
	_spriteP2.setTexture(_textDown);
      if (_spriteP2.getPosition().y < 468)
	_spriteP2.move(0, 9);
      break;
    case sf::Keyboard::Left:
      if (_spriteP2.getTexture() != &_textLeft)
	_spriteP2.setTexture(_textLeft);
      if (_spriteP2.getPosition().x > 8)
	_spriteP2.move(-9, 0);
      break;
    case sf::Keyboard::Right:
      if (_spriteP2.getTexture() != &_textRight)
	_spriteP2.setTexture(_textRight);
      if (_spriteP2.getPosition().x < 468)
	_spriteP2.move(9, 0);
      break;
    default:
      break;
    }
  return _spriteP2.getPosition();
}

Player2::Player2() : _pv(2), _ammo(true)
{
  if (!_textDown.loadFromFile("../../sprites/char/skel_front.png"))
    std::cout << "can't load the player 1" << std::endl;
  else if (!_textUp.loadFromFile("../../sprites/char/skel_back.png"))
    std::cout << "can't load the player 1" << std::endl;
  else if (!_textLeft.loadFromFile("../../sprites/char/skel_left.png"))
    std::cout << "can't load the player 1" << std::endl;
  else if (!_textRight.loadFromFile("../../sprites/char/skel_right.png"))
    std::cout << "can't load the player2" << std::endl;
  else
    {
      _spriteP2.setTexture(_textUp);
      _spriteP2.setPosition(300, 300);
      _ammo = true;
    }  
}

Player2::~Player2()
{
  std::cout << "The player 2 is dead !" << std::endl;
}
