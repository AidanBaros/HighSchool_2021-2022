//"bloons" style game, part 2
//coded by Dr. Mo, Feb 2022
//dynamicsofanasteroid.com

// in this part, we add class "bloon" and instantiate a bunch of bloons for the game.

#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
using namespace std;

//note: because class bloon uses this struct, you need to have this *above* the class def in the code!
struct point {
    int x;
    int y;
};


class bloon {
private:
    int xpos;
    int ypos;
    int currPath;
public:
    bloon(int x, int y);
    void move(vector<point>myPath);
    void draw(sf::RenderWindow& window);
};






int main()//start of main=============================================================================
{
    //set up path points using the struct we made
    struct point p1;
    p1.x = 100;
    p1.y = 300;
    struct point p2;
    p2.x = 100;
    p2.y = 250;
    struct point p3;
    p3.x = 200;
    p3.y = 250;
    struct point p4;
    p4.x = 200;
    p4.y = 350;
    struct point p5;
    p5.x = 300;
    p5.y = 350;
    struct point p6;
    p6.x = 300;
    p6.y = 200;
    struct point p7;
    p7.x = 400;
    p7.y = 200;
    struct point p8;
    p8.x = 400;
    p8.y = 400;
    struct point p9;
    p9.x = 500;
    p9.y = 400;
    struct point p10;
    p10.x = 500;
    p10.y = 150;
    struct point p11;
    p11.x = 600;
    p11.y = 150;
    struct point p12;
    p12.x = 600;
    p12.y = 400;
    struct point p13;
    p13.x = 700;
    p13.y = 400;
    struct point p14;
    p14.x = 700;
    p14.y = 200;
    struct point p15;
    p15.x = 800;
    p15.y = 200;
    struct point p16;
    p16.x = 800;
    p16.y = 350;
    struct point p17;
    p17.x = 900;
    p17.y = 350;
    struct point p18;
    p18.x = 900;
    p18.y = 250;
    struct point p19;
    p19.x = 1000;
    p19.y = 250;
    struct point p20;
    p20.x = 1000;
    p20.y = 300;
    struct point p21;
    p21.x = 1150;
    p21.y = 300;



    //set up vector to hold path points, push path points into it
    vector <point> pathPoints;
    pathPoints.push_back(p1);
    pathPoints.push_back(p2);
    pathPoints.push_back(p3);
    pathPoints.push_back(p4);
    pathPoints.push_back(p5);
    pathPoints.push_back(p6);
    pathPoints.push_back(p7);
    pathPoints.push_back(p8);
    pathPoints.push_back(p9);
    pathPoints.push_back(p10);
    pathPoints.push_back(p11);
    pathPoints.push_back(p12);
    pathPoints.push_back(p13);
    pathPoints.push_back(p14);
    pathPoints.push_back(p15);
    pathPoints.push_back(p16);
    pathPoints.push_back(p17);
    pathPoints.push_back(p18);
    pathPoints.push_back(p19);
    pathPoints.push_back(p20);
    pathPoints.push_back(p21);



    // create game window
    sf::RenderWindow window(sf::VideoMode(1100, 550), "bloons");

    //game variables
    int ticker = 0;


    vector<bloon*> BloonBag;
    vector<bloon*>::iterator iter;
    for (int i = 0; i < 50; i++) {
        bloon* newBloon = new bloon(i * -20, 300);
        BloonBag.push_back(newBloon);
    }

    //instantiate more here

    // GAME LOOP----------------------------------------------------------------------------------------
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        ticker++; //slow dem bloons down
        if (ticker % 30 == 0) { //make 30 bigger to slow down baloon more
        
            for (iter = BloonBag.begin(); iter != BloonBag.end(); iter++)
                (*iter)->move(pathPoints);
        }

        // Render section----------------------------------------------------------------
        window.clear(sf::Color::Black);
        for (iter = BloonBag.begin(); iter != BloonBag.end(); iter++)
            (*iter)->draw(window);

        //draw more here
        window.display();
    }

    return 0;//buh bye
}//end of main===========================================================================================

//class function definitions=============================================================================

bloon::bloon(int x, int y) {
    xpos = x;
    ypos = y;
    currPath = 0;
}


//note for part 2: I called my vector by a different name here to show this could work with any vector of points
void bloon::move(vector<point>myPath) {
    if ((xpos == myPath[currPath].x) && (ypos == myPath[currPath].y))
        if (currPath < myPath.size() - 1) //don't walk off end of vector!
            currPath++; //iterate to next point

    //if not there yet, move our x towards x position of next junction
    if (xpos < myPath[currPath].x)
        xpos += 1;
    if (xpos > myPath[currPath].x)
        xpos -= 1;
    //and move our y towards y position of next junction
    if (ypos < myPath[currPath].y)
        ypos += 1;
    if (ypos > myPath[currPath].y)
        ypos -= 1;

}


void bloon::draw(sf::RenderWindow& window) { //passes a POINTER to the gamescreen
    sf::CircleShape baloon(10);
    baloon.setFillColor(sf::Color(250, 0, 0));
    baloon.setPosition(xpos, ypos);
    window.draw(baloon);//draw to gamescreen
}
