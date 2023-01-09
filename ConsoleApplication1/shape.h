#include<SFML/Graphics.hpp>
#include<iostream>

class Car
{
public:
	sf::Texture car;
    sf::Sprite sprite_car;
    float speed = 0.3;
        

	Car(){
		this->car.loadFromFile("car1.png");
		this->car.setSmooth(true);
        sprite_car.setTexture(this->car);
        sprite_car.setPosition(150, 50);
	}
    void keyb() {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { this->car.loadFromFile("car2.png"); this->sprite_car.move(speed, 0); }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { this->car.loadFromFile("car3.png");  this->sprite_car.move(-speed, 0); }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { this->car.loadFromFile("car4.png");  this->sprite_car.move(0, speed); }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { this->car.loadFromFile("car1.png"); this->sprite_car.move(0, -speed); }
        if (sprite_car.getPosition().x < 0) { this->sprite_car.setPosition(sf::Vector2f(0, this->sprite_car.getPosition().y)); }
        if (sprite_car.getPosition().x > 700) { this->sprite_car.setPosition(sf::Vector2f(700, this->sprite_car.getPosition().y)); }
        if (sprite_car.getPosition().y > 500) { this->sprite_car.setPosition(sf::Vector2f(this->sprite_car.getPosition().x, 500)); }
        if (sprite_car.getPosition().y < 25) { this->sprite_car.setPosition(sf::Vector2f(this->sprite_car.getPosition().x, 25)); }

    }


};

