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
    p1.x = 275;
    p1.y = 575;
    struct point p2;
    p2.x = 275;
    p2.y = 425;
    struct point p3;
    p3.x = 325;
    p3.y = 375;
    struct point p4;
    p4.x = 375;
    p4.y = 425;
    struct point p5;
    p5.x = 375;
    p5.y = 575;
    struct point p6;
    p6.x = 275;
    p6.y = 575;
    struct point p7;
    p7.x = 275;
    p7.y = 525;
    struct point p8;
    p8.x = 225;
    p8.y = 525;
    struct point p9;
    p9.x = 175;
    p9.y = 475;
    struct point p10;
    p10.x = 175;
    p10.y = 425;
    struct point p11;
    p11.x = 225;
    p11.y = 375;
    struct point p12;
    p12.x = 225;
    p12.y = 225;
    struct point p13;
    p13.x = 275;
    p13.y = 175;
    struct point p14;
    p14.x = 325;
    p14.y = 225;
    struct point p15;
    p15.x = 325;
    p15.y = 325;
    struct point p16;
    p16.x = 275;
    p16.y = 375;
    struct point p17;
    p17.x = 225;
    p17.y = 325;
    struct point p18;
    p18.x = 175;
    p18.y = 325;
    struct point p19;
    p19.x = 125;
    p19.y = 275;
    struct point p20;
    p20.x = 125;
    p20.y = 175;
    struct point p21;
    p21.x = 175;
    p21.y = 125;
    struct point p22;
    p22.x = 175;
    p22.y = 75;
    struct point p23;
    p23.x = 225;
    p23.y = 25;
    struct point p24;
    p24.x = 425;
    p24.y = 25;
    struct point p25;
    p25.x = 475;
    p25.y = 75;
    struct point p26;
    p26.x = 475;
    p26.y = 125;
    struct point p27;
    p27.x = 525;
    p27.y = 175;
    struct point p28;
    p28.x = 525;
    p28.y = 275;
    struct point p29;
    p29.x = 475;
    p29.y = 325;
    struct point p30;
    p30.x = 425;
    p30.y = 325;
    struct point p31;
    p31.x = 375;
    p31.y = 375;
    struct point p32;
    p32.x = 325;
    p32.y = 325;
    struct point p33;
    p33.x = 325;
    p33.y = 225;
    struct point p34;
    p34.x = 375;
    p34.y = 175;
    struct point p35;
    p35.x = 425;
    p35.y = 225;
    struct point p36;
    p36.x = 425;
    p36.y = 375;
    struct point p37;
    p37.x = 475;
    p37.y = 425;
    struct point p38;
    p38.x = 475;
    p38.y = 475;
    struct point p39;
    p39.x = 425;
    p39.y = 525;
    struct point p40;
    p40.x = 375;
    p40.y = 525;
    struct point p41;
    p41.x = 375;
    p41.y = 575;
    struct point p42;
    p42.x = 375;
    p42.y = 650;



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
    pathPoints.push_back(p22);
    pathPoints.push_back(p23);
    pathPoints.push_back(p24);
    pathPoints.push_back(p25);
    pathPoints.push_back(p26);
    pathPoints.push_back(p27);
    pathPoints.push_back(p28);
    pathPoints.push_back(p29);
    pathPoints.push_back(p30);
    pathPoints.push_back(p31);
    pathPoints.push_back(p32);
    pathPoints.push_back(p33);
    pathPoints.push_back(p34);
    pathPoints.push_back(p35);
    pathPoints.push_back(p36);
    pathPoints.push_back(p36);
    pathPoints.push_back(p37);
    pathPoints.push_back(p38);
    pathPoints.push_back(p39);
    pathPoints.push_back(p40);
    pathPoints.push_back(p41);
    pathPoints.push_back(p42);


    // create game window
    sf::RenderWindow window(sf::VideoMode(700, 650), "bloons");

    //game variables
    int ticker = 0;

    bloon b1(275, 650);
    bloon b2(275, 670);
    bloon b3(275, 690);
    bloon b4(275, 710);
    bloon b5(275, 730);
    bloon b6(275, 750);
    bloon b7(275, 770);
    bloon b8(275, 790);
    bloon b9(275, 810);
    bloon b10(275, 830);
    bloon b11(275, 850);
    bloon b12(275, 870);

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

            b1.move(pathPoints);
            b2.move(pathPoints);
            b3.move(pathPoints);
            b4.move(pathPoints);
            b5.move(pathPoints);
            b6.move(pathPoints);
            b7.move(pathPoints);
            b8.move(pathPoints);
            b9.move(pathPoints);
            b10.move(pathPoints);
            b11.move(pathPoints);
            b12.move(pathPoints);
            //move more here
        }

        // Render section----------------------------------------------------------------
        window.clear(sf::Color::Black);
        b1.draw(window);
        b2.draw(window);
        b3.draw(window);
        b4.draw(window);
        b5.draw(window);
        b6.draw(window);
        b7.draw(window);
        b8.draw(window);
        b9.draw(window);
        b10.draw(window);
        b11.draw(window);
        b12.draw(window);

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
