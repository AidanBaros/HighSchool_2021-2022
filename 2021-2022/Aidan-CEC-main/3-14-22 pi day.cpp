#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include<cmath>
#include<iostream>

using namespace std;
void mat(int x);

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Circles");
    sf::CircleShape circle;

    int xpos = 0;
    int ypos = 0;
    int size = 99;
    mat(size);

    while (window.isOpen())//GAME LOOP--------------------------------
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }
        window.clear();
        //modify these arguments so each is a different slot of the vectors above
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 7; j++) {
                circle.setRadius(size);
                circle.setFillColor((sf::Color(100, 0, 200, 50)));
                circle.setPosition(xpos + i * 100, ypos + j * 100);
                window.draw(circle);

            }
        }

        window.display();
      
    }//end game loop-------------------------------------------------
   
    return 0;
} //end main

void mat(int x) {

    int area = M_PI * x * x;
    cout << area << endl;
}
