#include<iostream>
#include<SFML\Graphics.hpp>
#include<vector>
#include<ctime>
//#include<SFML/System/Vector2.hpp>
//#include<SFML/Window/Mouse.hpp>




class Platforms
{
public:
    Platforms(float x, float y, int l, int w, sf::Color color);
    sf::RectangleShape platform();
    bool ballCollision(int bx, int by);
    void kill();
    bool checkDead();
private:
    bool isDead;
    float xPos;
    float yPos;
    int Length;
    int Width;
    sf::Color colorCode;

};

int main() {

srand(time(NULL));

std::vector<Platforms*> blocks;
std::vector<Platforms*>::iterator iter;


//game set up 
sf::RenderWindow renderWindow(sf::VideoMode(1300, 800), "Breakout!"); //set up screen
sf::Event event; //set up event queue
sf::Clock clock; //set up the clock (needed for game timing)
const float FPS = 60.0f; //FPS
renderWindow.setFramerateLimit(FPS); //set FPS

//player setup----------------------------------------------------------------------
sf::RectangleShape player(sf::Vector2f(200, 10));//size of player (30x30 square)
player.setFillColor(sf::Color::White);
float playerX = 550;
float playerY = 780;
player.setPosition(playerX, playerY); //set position: this is where the top left corner will be
//player velocity
float pVelx = .0;

//ball setup
int randomVelocity = 5;
float ballX = rand() % 1000 + 1;
float ballY = 400;
float bVelx = randomVelocity;
float bVely = randomVelocity;
sf::CircleShape ball(10.f);
ball.setFillColor(sf::Color(0, 255, 0));
ball.setPosition(ballX, ballY);

//platform setup
int xShift;
int yShift;
sf::Color Colors[7] = { sf::Color::Red, sf::Color(252,134,0), sf::Color::Yellow, sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color(159,0,255) };
for (int j = 0; j <= 6; j++) {
    for (int i = 0; i <= 12; i++) {
        int xShift = (100 * i);
        int yShift = (50 * (j + 1));
        Platforms* plats = new Platforms(xShift, yShift, 100, 50, Colors[j]);
        blocks.push_back(plats);
    }
}



//###################GAME LOOP###############################################################
while (renderWindow.isOpen()) {//the game runs while the game is open:)

    while (renderWindow.pollEvent(event)) { //look for events-----------------------

        //this checks if the user has closed the game window
        if (event.type == sf::Event::EventType::Closed)
            renderWindow.close();
    }//end event loop---------------------------------------------------------------

    //keyboard input-----------------------------------------------------------
    //right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { //checks if "D" is pressed
        pVelx = 8;
    }

    //left movement
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //checks if "A" is pressed
        pVelx = -8;
    }

    //friction
    pVelx *= .95; //because of where this is located, the player only ever move at a max of 95% of 8, then decrease by 95% each loop.

    //player movement---------------------------------------------------------
    playerX += pVelx;
    player.setPosition(playerX, playerY);

    //ball movement
    ballX += bVelx;
    ballY += bVely;
    ball.setPosition(ballX, ballY);
    if (ball.getPosition().x < 0 || ball.getPosition().x + 10 > 1300) {
        bVelx *= -1;
    }
    else if (ball.getPosition().y < 0) {
        bVely *= -1;
    }
    else if (ball.getPosition().y + 10 > 800) {
        return 0;
    }
    if (ball.getPosition().x + 10 > player.getPosition().x && ball.getPosition().x < player.getPosition().x + 200 && ball.getPosition().y + 10 >= player.getPosition().y) {
        bVely *= -1;
    }

    for (iter = blocks.begin(); iter != blocks.end(); ++iter) { //for loop to draw each platform object
        if ((*iter)->checkDead() == false && ((*iter)->ballCollision(ballX, ballY) == true)) {
            (*iter)->kill();
            bVely *= -1;
        }
    }

    clock.restart(); //?
    //render section-----------------------------------------
    renderWindow.clear(); //wipes screen
    renderWindow.draw(player); //draw player
    renderWindow.draw(ball);
    for (iter = blocks.begin(); iter != blocks.end(); ++iter) { //for loop to draw each platform object
        if ((*iter)->checkDead() == false) {
            renderWindow.draw((*iter)->platform());
        }
    }
    renderWindow.display(); //flips screen

}//######################## end game loop ###################################################################################
}//end game

Platforms::Platforms(float x, float y, int l, int w, sf::Color color) { //wow, constructor!
    xPos = x;
    yPos = y;
    Length = l;
    Width = w;
    colorCode = color;
    isDead = false;
}

sf::RectangleShape Platforms::platform() { //platform generation function, see that function type?
    sf::RectangleShape platform(sf::Vector2f(Length, Width));
    platform.setFillColor(colorCode);
    platform.setPosition(xPos, yPos);
    return platform;
}

bool Platforms::ballCollision(int bx, int by) {
    if ((bx >= xPos) && (bx <= xPos + 100) && (by < yPos + 50) && (by + 10 > yPos)) {
        return true;
    }
    else
        return false;
}

void Platforms::kill() {
    isDead = true;
    std::cout << "Killethed\n";
}

bool Platforms::checkDead() {
    return isDead;
}
