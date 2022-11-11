#include<iostream>
#include "SFML/Graphics.hpp"
using namespace std;

enum DIRECTIONS { LEFT, RIGHT, UP, DOWN };

int main() {
    //game set up (you'll need these lines in every game)
    sf::RenderWindow screen(sf::VideoMode(896, 992), "breakout"); //set up screen
    sf::Event event; //set up event queue
    sf::Clock clock; //set up the clock (needed for game timing)
    const float FPS = 60.0f; //FPS
    screen.setFramerateLimit(FPS); //set FPS

    //load in images
    sf::Texture brick;
    brick.loadFromFile("block.png");
    sf::Sprite wall;
    wall.setTexture(brick);

    sf::Texture ba;
    ba.loadFromFile("bg.png");
    sf::Sprite bg;
    bg.setTexture(ba);


    int map[31][29] = {
          1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
          1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
          1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,
          1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,
          1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,
          1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
          1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,
          1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,
          1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,
          1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,
          1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,
          1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,
          1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,
          1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,
          0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,
          1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,
          1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,
          1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1,1,
          1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,
          1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,
          1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
          1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,
          1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1,1,
          1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,
          1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,
          1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,
          1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1,1,
          1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,
          1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,
          1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,
          1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
    };

    //player setup
    int xpos = 32;
    int ypos = 443;
    int vx = 0;
    int vy = 0;
    int radius = 16;
    sf::CircleShape player(25);
    player.setFillColor(sf::Color(250, 250, 0)); //using RGB value for color here (hex also works)
    player.setPosition(xpos, ypos); //top left "corner" of circle (not center!)
    bool keys[] = { false, false, false, false };
    int score = 0;

    sf::CircleShape dot(3);
    dot.setFillColor(sf::Color(240, 240, 240));

    //################### HOLD ONTO YOUR BUTTS, ITS THE GAME LOOP###############################################################
    while (screen.isOpen()) {//keep window open until user shuts it down

        while (screen.pollEvent(event)) { //look for events-----------------------

            //this checks if the user has clicked the little "x" button in the top right corner
            if (event.type == sf::Event::EventType::Closed)
                screen.close();
            //KEYBOARD INPUT 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                keys[LEFT] = true;
            }
            else keys[LEFT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                keys[RIGHT] = true;
            }
            else keys[RIGHT] = false;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                keys[UP] = true;
            }
            else keys[UP] = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                keys[DOWN] = true;
            }
            else keys[DOWN] = false;


        }//end event loop---------------------------------------------------------------

        //move Mr. Pac
        vx = 0;
        vy = 0;
        if (keys[LEFT] == true)
            vx = -3;

        if (keys[RIGHT] == true)
            vx = 3;

        if (keys[UP] == true)
            vy = -3;

        if (keys[DOWN] == true)
            vy = 3;

        // colission
        //right
        if (vx > 0 && (map[(ypos + 5) / 32][(xpos + radius * 2 + 5) / 32] == 1 || map[(ypos + radius * 2 - 5) / 32][(xpos + radius * 2 + 5) / 32] == 1))
            vx = 0;

        //left
        if (vx < 0 && (map[(ypos + 5) / 32][(xpos - 5) / 32] == 1 || map[(ypos + radius * 2 - 5) / 32][(xpos - 5) / 32] == 1))
            vx = 0;

        //down, so positive
        if (vy > 0 && (map[(ypos + radius * 2 + 5) / 32][(xpos + 5) / 32] == 1 || map[(ypos + radius * 2 + 5) / 32][(xpos + radius * 2 - 5) / 32] == 1))
            vy = 0;

        //up, so negative
        if (vy < 0 && (map[(ypos - 5) / 32][(xpos + radius * 2 - 5) / 32] == 1 || map[(ypos - 5) / 32][(xpos + 5) / 32] == 1))
            vy = 0;

        xpos += vx;
        ypos += vy;
        player.setPosition(xpos, ypos);

        if (map[(ypos + 20) / 32][(xpos + 20) / 32] == 0) {
            map[(ypos + 20) / 32][(xpos + 20) / 32] = 2;
            score += 100;
        }

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << "Score: " << "\n" << score << "\n\n";

                //render section-----------------------------------------
        screen.clear(); //wipes screen, without this things smear

        for (int rows = 0; rows < 31; rows++)
            for (int cols = 0; cols < 28; cols++) {
                if (map[rows][cols] == 1) {
                    wall.setPosition(cols * 32, rows * 32);
                    screen.draw(wall);
                }
            }
        for (int rows = 0; rows < 31; rows++)
            for (int cols = 0; cols < 28; cols++) {
                if (map[rows][cols] <= 0 or map[rows][cols] == 2) {
                    bg.setPosition(cols * 32 - 14, rows * 32 - 14);
                    screen.draw(bg);
                }
            }
        for (int rows = 0; rows < 31; rows++)
            for (int cols = 0; cols < 28; cols++) {
                if (map[rows][cols] == 0) {
                    dot.setPosition(cols * 32 + 16, rows * 32 + 16);
                    screen.draw(dot);
                }
            }
        screen.draw(player); //draw player
        screen.display(); //flips memory drawings onto screen

    }//######################## end game loop ###################################################################################

    cout << "goodbye!" << endl;
} //end of main
