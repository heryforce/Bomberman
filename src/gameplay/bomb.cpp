#include "bomb.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <unistd.h>
#include <iostream>
#include <string>

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
  _exp.setPosition(bombPos.x + 9, bombPos.y);
  window->draw(_exp);
  _exp.setPosition(bombPos.x + 18, bombPos.y);
  window->draw(_exp);
  _exp.setPosition(bombPos.x + 27, bombPos.y);
  window->draw(_exp);
  _exp.setPosition(bombPos.x - 9, bombPos.y);
  window->draw(_exp);
  _exp.setPosition(bombPos.x - 18, bombPos.y);
  window->draw(_exp);
  _exp.setPosition(bombPos.x - 27, bombPos.y);
  window->draw(_exp);
  _exp.setPosition(bombPos.x, bombPos.y + 9);
  window->draw(_exp);
  _exp.setPosition(bombPos.x, bombPos.y + 18);
  window->draw(_exp);
  _exp.setPosition(bombPos.x, bombPos.y + 27);
  window->draw(_exp);
  _exp.setPosition(bombPos.x, bombPos.y - 9);
  window->draw(_exp);
  _exp.setPosition(bombPos.x, bombPos.y - 18);
  window->draw(_exp);
  _exp.setPosition(bombPos.x, bombPos.y - 27);
  window->draw(_exp);
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
