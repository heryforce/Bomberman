#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  sf::CircleShape circle(100.f);
  sf::CircleShape square(100, 4);
  sf::CircleShape triangle(100, 3);
  sf::CircleShape shape;

  circle.setFillColor(sf::Color::Green);
  square.setFillColor(sf::Color::Red);
  triangle.setFillColor(sf::Color::Yellow);
  if (!sf::Shader::isAvailable())
    std::cout << "Shaders unavailable" << std::endl;
  else
    std::cout << "YES MORRAY" << std::endl;
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      {
        shape = square;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      {
        shape = circle;
      }
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      {
        shape = triangle;
      }
    }
    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}
