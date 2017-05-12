#include "bomb.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unistd.h>
#include <iostream>
#include <string>

sf::FloatRect	Bomb::getVBound() const
{
  return _vBound;
}

sf::FloatRect	Bomb::getHBound() const
{
  return _hBound;
}

void	Bomb::unsetBound()
{
  _hBound.left = 0;
  _hBound.top = 0;
  _hBound.width = 0;
  _hBound.height = 0;
  _vBound.left = 0;
  _vBound.top = 0;
  _vBound.width = 0;
  _vBound.height = 0;
}

void	Bomb::explosion(sf::Vector2f bombPos, sf::RenderWindow *window, int x)
{
  switch(x)
    {
    case 1:
      _exp.setTexture(_exp1);
      break;
    case 2:
      _exp.setTexture(_exp2);
      break;
    case 3:
      _exp.setTexture(_exp3);
      break;
    case 4:
      _exp.setTexture(_exp4);
      break;
    case 5:
      _exp.setTexture(_exp5);
      break;
    case 6:
      _exp.setTexture(_exp6);
      break;
    case 7:
      _exp.setTexture(_exp7);
      break;
    case 8:
      _exp.setTexture(_exp8);
      break;
    case 9:
      _exp.setTexture(_exp9);
      break;
    default:
      break;
    }
  int	i = 0;
  int	z = 0;

  _exp.setPosition(bombPos.x, bombPos.y);
  window->draw(_exp);
  while (i < 10)
    {
      z += 9;
      _exp.setPosition(bombPos.x + z , bombPos.y);
      window->draw(_exp);
      _exp.setPosition(bombPos.x - z , bombPos.y);
      window->draw(_exp);
      _exp.setPosition(bombPos.x , bombPos.y + z);
      window->draw(_exp);
      _exp.setPosition(bombPos.x , bombPos.y - z);
      window->draw(_exp);
      ++i;
    }
  sf::RectangleShape	shape;
  shape.setFillColor(sf::Color(100, 250, 50));
  shape.setPosition(bombPos.x - 90, bombPos.y);
  shape.setSize(sf::Vector2f(210, 28));
  
  sf::RectangleShape	shape2;
  shape2.setFillColor(sf::Color(100, 250, 50));
  shape2.setPosition(bombPos.x, bombPos.y - 90);
  shape2.setSize(sf::Vector2f(28, 210));
  if (x == 4)
    {
      _hBound.left = bombPos.x - 90;
      _hBound.top = bombPos.y;
      _hBound.width = 210;
      _hBound.height = 28;
      _vBound.left = bombPos.x;
      _vBound.top = bombPos.y - 90;
      _vBound.width = 28;
      _vBound.height = 210;
    }
  window->draw(shape);
  window->draw(shape2);
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
  else if (!_exp1.loadFromFile("../../sprites/fx/exp1.png"))
    std::cout << "can't load the bomb fx" << std::endl;
  else if (!_exp2.loadFromFile("../../sprites/fx/exp2.png"))
    std::cout << "can't load the bomb fx" << std::endl;
  else if (!_exp3.loadFromFile("../../sprites/fx/exp3.png"))
    std::cout << "can't load the bomb fx" << std::endl;
  else if (!_exp4.loadFromFile("../../sprites/fx/exp4.png"))
    std::cout << "can't load the bomb fx" << std::endl;
  else if (!_exp5.loadFromFile("../../sprites/fx/exp5.png"))
    std::cout << "can't load the bomb fx" << std::endl;
  else if (!_exp6.loadFromFile("../../sprites/fx/exp6.png"))
    std::cout << "can't load the bomb fx" << std::endl;
  else if (!_exp7.loadFromFile("../../sprites/fx/exp7.png"))
    std::cout << "can't load the bomb fx" << std::endl;
  else if (!_exp8.loadFromFile("../../sprites/fx/exp8.png"))
    std::cout << "can't load the bomb fx" << std::endl;
  else if (!_exp9.loadFromFile("../../sprites/fx/exp9.png"))
    std::cout << "can't load the bomb fx" << std::endl;
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
