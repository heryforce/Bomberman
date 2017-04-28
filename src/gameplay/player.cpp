#include "player.hpp"
#include <iostream>
#include "bomb.hpp"

int	Player::getNb() const
{
  return _nb;
}

void	Player::setAmmo(bool ammo)
{
  _ammo = ammo;
}

bool	Player::getAmmo() const
{
  return _ammo;
}

sf::Sprite	Player::putBomb()
{
  std::cout << "dans player->putbomb()" << std::endl;
  _bomb.setPos(_spriteP.getPosition());
  _ammo = false;
  return (_bomb.getBomb());
}

sf::Sprite	Player::getP() const
{
  return _spriteP;
}

int	Player::getPv() const
{
  return _pv;
}

sf::Vector2f	Player::move(sf::Event event)
{
  if (_nb == 1)
    {
      switch(event.key.code)
	{
	case sf::Keyboard::Z:
	  if (_spriteP.getTexture() != &_textUp)
	    _spriteP.setTexture(_textUp);
	  if (_spriteP.getPosition().y > 8)
	    _spriteP.move(0, -9);
	  break;
	case sf::Keyboard::S:
	  if (_spriteP.getTexture() != &_textDown)
	    _spriteP.setTexture(_textDown);
	  if (_spriteP.getPosition().y < 468)
	    _spriteP.move(0, 9);
	  break;
	case sf::Keyboard::Q:
	  if (_spriteP.getTexture() != &_textLeft)
	    _spriteP.setTexture(_textLeft);
	  if (_spriteP.getPosition().x > 8)
	_spriteP.move(-9, 0);
	  break;
	case sf::Keyboard::D:
	  if (_spriteP.getTexture() != &_textRight)
	    _spriteP.setTexture(_textRight);
	  if (_spriteP.getPosition().x < 468)
	    _spriteP.move(9, 0);
	  break;
	default:
	  break;
	}
    }
  else if (_nb == 2)
    {
      switch(event.key.code)
	{
	case sf::Keyboard::Up:
	  if (_spriteP.getTexture() != &_textUp)
	    _spriteP.setTexture(_textUp);
	  if (_spriteP.getPosition().y > 8)
	    _spriteP.move(0, -9);
	  break;
	case sf::Keyboard::Down:
	  if (_spriteP.getTexture() != &_textDown)
	    _spriteP.setTexture(_textDown);
	  if (_spriteP.getPosition().y < 468)
	    _spriteP.move(0, 9);
	  break;
	case sf::Keyboard::Left:
	  if (_spriteP.getTexture() != &_textLeft)
	    _spriteP.setTexture(_textLeft);
	  if (_spriteP.getPosition().x > 8)
	_spriteP.move(-9, 0);
	  break;
	case sf::Keyboard::Right:
	  if (_spriteP.getTexture() != &_textRight)
	    _spriteP.setTexture(_textRight);
	  if (_spriteP.getPosition().x < 468)
	    _spriteP.move(9, 0);
	  break;
	default:
	  break;
	}
    }
  return _spriteP.getPosition();
}

Player::Player(int nb) : _nb(nb), _pv(2), _ammo(true)
{
  if (nb == 1)
    {
      if (!_textDown.loadFromFile("../../sprites/char/panda_front.png"))
	std::cout << "can't load the player " << _nb << std::endl;
      else if (!_textUp.loadFromFile("../../sprites/char/panda_back.png"))
	std::cout << "can't load the player " << _nb << std::endl;
      else if (!_textLeft.loadFromFile("../../sprites/char/panda_left.png"))
	std::cout << "can't load the player " << _nb << std::endl;
      else if (!_textRight.loadFromFile("../../sprites/char/panda_right.png"))
	std::cout << "can't load the player " << _nb << std::endl;
      else
	{
	  _spriteP.setTexture(_textDown);
	  _spriteP.setPosition(0, 0);
	}
    }
  else
    {
      if (!_textDown.loadFromFile("../../sprites/char/skel_front.png"))
	std::cout << "can't load the player " << _nb << std::endl;
      else if (!_textUp.loadFromFile("../../sprites/char/skel_back.png"))
	std::cout << "can't load the player " << _nb << std::endl;
      else if (!_textLeft.loadFromFile("../../sprites/char/skel_left.png"))
	std::cout << "can't load the player " << _nb << std::endl;
      else if (!_textRight.loadFromFile("../../sprites/char/skel_right.png"))
	std::cout << "can't load the player " << _nb << std::endl;
      else
	{
	  _spriteP.setTexture(_textUp);
	  _spriteP.setPosition(450, 450);
	}
    }
  _ammo = true;
}

Player::~Player()
{
  std::cout << "The player " << _nb << " is dead !" << std::endl;
}
