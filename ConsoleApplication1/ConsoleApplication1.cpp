
#include "shape.h"
#include<cmath>
#include <windows.h>

#pragma region var
sf::RenderWindow window;
sf::Texture coin;
sf::Sprite sprite_coin;
sf::Texture coin2;
sf::Sprite sprite_coin2;
int speed = 0.3;
int screenW = 800;
int screenH = 600;
int S = 0;
// Timer Variables 
sf::Clock clk;
float duration = 20.0f;
float fMilliseconds, fSeconds;
int intMilliseconds, intSeconds;
sf::String stringMilliseconds;
sf::String stringSeconds;
sf::String timerString;
#pragma endregion var
void resetpos();
int main()
{
    Car e;
    

    //creation du fenetre
    window.create(sf::VideoMode(800, 600), "CAR GAME");
    //position du fenetre
    window.setPosition(sf::Vector2i(200, 200));
    coin.loadFromFile("coin.png");
    coin.setSmooth(true);
    sprite_coin.setTexture(coin);
    sprite_coin.setPosition(100, 50);
    coin2.loadFromFile("coin.png");
    coin2.setSmooth(true);
    sprite_coin2.setTexture(coin2);
    sprite_coin2.setPosition(750, 50);
    sf::Font font;
    if (!font.loadFromFile("OpenSans-Bold.ttf")) {
        std::cout << "error" << std::endl;
        system("pause");
    }

    
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(25);
    text.setPosition(10, 0);
    //Timer
    sf::Text timerText;
    timerText.setFont(font);
    timerText.setString("00:000");
    timerText.setCharacterSize(25);
    timerText.setFillColor(sf::Color::White);
    timerText.setPosition(650, 0);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        sf::String ss = "Score :" + std::to_string(S);
        text.setString(ss);
        //reset timer
        sf::Time time = clk.restart();
        //CountDown
       
        if (duration > 0) {
			// Calculate countdown(timer)
			duration -= time.asSeconds();
			fMilliseconds = std::modf(duration, &fSeconds);
			// Change float to int
			intSeconds = static_cast<int>(fSeconds);
			intMilliseconds = static_cast<int>(fMilliseconds * 1000);
			// Change int to string 
			stringMilliseconds = std::to_string(intMilliseconds);
			stringSeconds =std::to_string(intSeconds);
			
			if (intMilliseconds <= 0) {
				stringMilliseconds = "000";  
			}

			if (intSeconds <= 0) {
				stringSeconds = "00"; 
			}
			else if (intSeconds < 10) {
				stringSeconds = "0" + stringSeconds; 
			}

			timerString = stringSeconds + ":" + stringMilliseconds;
			timerText.setString(timerString);
		}
        else {
            
            sf::RenderWindow window2;
            sf::Text text2;
            text2.setFont(font);
            text2.setCharacterSize(60);
            text2.setPosition(150, 100);
            text2.setString(ss);
            sf::Text Sp;
            Sp.setFont(font);
            Sp.setCharacterSize(30);
            Sp.setPosition(110, 200);
            Sp.setString("Press Space to restart ");
            //creation du fenetre
            window2.create(sf::VideoMode(500, 300), "Menu");
            //position du fenetre
            window2.setPosition(sf::Vector2i(200, 200));
            while (window2.isOpen()) {
                sf::Event event;
                while (window2.pollEvent(event)) {
                    if (event.type == sf::Event::Closed) {
                        window2.close();
                        window.close();
                    }
                }
                window2.draw(text2);
                window2.draw(Sp);
                window2.display();
                window2.clear();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { window2.close(); duration = 20.0f; S = 0;}
            }
        }
       
        //Gestion clavier*/
        e.keyb();
        resetpos();
        sprite_coin.move(0.2,0);
            if ((std::abs((e.sprite_car.getPosition().x + 25) - (sprite_coin.getPosition().x + 25)) < 40) && (std::abs((e.sprite_car.getPosition().y + 25) - (sprite_coin.getPosition().y + 25)) < 40))
            {
                std::cout << "collision   "<< S<< std::endl;
                e.sprite_car.setPosition(sf::Vector2f((sprite_coin.getPosition().x + 40), (sprite_coin.getPosition().y + 40)));
                sprite_coin.setPosition(0, round(rand() % 500));
                S+=1;
                
            };
            sprite_coin2.move(-0.2, 0);
            if ((std::abs((e.sprite_car.getPosition().x + 25) - (sprite_coin2.getPosition().x + 25)) < 40) && (std::abs((e.sprite_car.getPosition().y + 25) - (sprite_coin2.getPosition().y + 25)) < 40))
            {
                std::cout << "collision   " << S << std::endl;
                e.sprite_car.setPosition(sf::Vector2f((sprite_coin2.getPosition().x + 40), (sprite_coin2.getPosition().y + 40)));
                sprite_coin2.setPosition(750, round(rand() % 500));
                S += 1;

            };
        window.draw(text);
        window.draw(timerText);
        window.draw(e.sprite_car);
        window.draw(sprite_coin);
        window.draw(sprite_coin2);
        window.display();
        window.clear();
       

    }

    return 0;
}
void resetpos()
{ //position random des coins
    if (sprite_coin.getPosition().x < 0) { sprite_coin.setPosition(0, round(rand() % 500)); }
    if (sprite_coin.getPosition().x > 700) { sprite_coin.setPosition(0, round(rand() % 500)); }
    if (sprite_coin.getPosition().y > 500) { sprite_coin.setPosition(0, round(rand() % 500)); }
    if (sprite_coin.getPosition().y < 25) { sprite_coin.setPosition(25, round(rand() % 500)); }

    if (sprite_coin2.getPosition().x < 0) { sprite_coin2.setPosition(720, round(rand() % 500)); }
    
}
