#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>


int main()
{
    //Window rendering
    sf::RenderWindow window(sf::VideoMode({800, 800}), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
    
    //Loading texture (image)
    sf::Texture texture("Sprites/Shinobi/Idle.png");

    //Create sprite
    sf::Sprite sprite(texture);

    //Game Loop
    while (window.isOpen()){
        while (const std::optional event = window.pollEvent()){
            if (event -> is<sf::Event::Closed>()){
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                    window.close();
                }
            }    
            
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)){
            sprite.move({-6.0f, 0.0f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)){
            sprite.move({6.0f, 0.0f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
            sprite.move({0.0f, 6.0f});
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
            sprite.move({0.0f, -6.0f});
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
