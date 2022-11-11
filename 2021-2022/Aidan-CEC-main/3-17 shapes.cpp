#include <SFML/Graphics.hpp>
#include<iostream>
#include<math.h>
using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Circles");
    sf::CircleShape circle;

    int xpos = 400;
    int ypos = 400;
    int size = 1;
    float i = 0;


    //while (window.isOpen())//GAME LOOP--------------------------------
    //{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

    }
    window.clear();
    //modify these arguments so each is a different slot of the vectors above
    while (i < 62.8) {
        //for (int i = 0; i < 10000; i+=300) {

        circle.setRadius(size);
        circle.setFillColor((sf::Color(152, 152, 219, 200)));
        //xpos = 200 * sin(i) + 400;
        //ypos = 200 * cos(i) + 400;
        //circle.setPosition(xpos + 400, ypos + 400);
        circle.setPosition(29 * cos(38 * i) *  cos(i) + 500, 18 * cos(2 * i) * cos(i) + 500);
        circle.setPosition(29 * sin(38 * i) * sin(i) + 500, 18 * sin(2 * i) * sin(i) + 500);
        circle.setPosition(29 * tan(38 * i) * tan(i) + 500, 18 * tan(2 * i) * tan(i) + 500);
        window.draw(circle);
        i += 3.14 / 4000;

    }
    window.display();

    // }//end game loop-------------------------------------------------
    system("pause");
    return 0;
} //end main
