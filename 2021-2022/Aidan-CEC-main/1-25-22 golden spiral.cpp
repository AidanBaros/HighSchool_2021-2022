//golden spiral in SFML
//coded by Dr. Mo, Jan 2022
//dynamicsofanasteroid.com

// QUESTIONS + ANSWERS AT BOTTOM OF CODE

#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

int main()
{


	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Golden Spiral");
	cout << "Eadem mutata resurgo" << endl;
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(3, 3));
	sf::RectangleShape rectangle1;
	rectangle1.setSize(sf::Vector2f(3, 3));
	sf::RectangleShape rectangle2;
	rectangle2.setSize(sf::Vector2f(3, 3));
	sf::RectangleShape rectangle3;
	rectangle3.setSize(sf::Vector2f(3, 3));


	float xpos;
	float ypos;
	float radius = 1;
	float angle = 0;
	int ticker = 0; //to change colors
	int adder = 1; //to change colors
	int i = 0; //iterator for loop
	float a=1;
	float k=.5;


	while (i < 2000) {


		//basic logrithmic spiral
		//xpos = radius * cos(angle)+500;
		//ypos = radius * sin(angle)+500;

		//more measurable version
		//xpos = a*exp(k*angle) * cos(angle)+500;
		//ypos = a*exp(k*angle) * sin(angle)+500;


		//golden spiral
		xpos = sin(angle) * 1.618 * exp(angle / 3.14) + 500;
		ypos = cos(angle) * 1.618 * exp(angle / 3.14) + 500;

		//prints out coordinate points at every 90 degree angle
		if (i % 90 == 0)
			cout << "angle is " << angle << ", x and y are " << xpos - 500 << " , " << ypos - 500 << endl;

		angle = (i * 3.14) / 180; //increase angle (formula is to convert to radians)

		i++;
		//radius++ //uncomment this if you're experimenting with regular logarithmic spirals
		//window.clear();

		//make fun colors
		if (ticker > 254 || ticker < 0) {
			adder *= -1;
		}
		ticker += adder;

		rectangle.setFillColor(sf::Color(ticker, 100, 0));
		rectangle.setPosition(xpos, ypos);
		window.draw(rectangle);
		window.display();

	}


	float xpos1;
	float ypos1;
	float radius1 = 1;
	float angle1 = 0;
	int ticker1 = 0; //to change colors
	int adder1 = 1; //to change colors
	int i1 = 0; //iterator for loop
	float a1 = 1;
	float k1 = .5;

	while (i1 < 2000) {


		//basic logrithmic spiral
		//xpos = radius * cos(angle)+500;
		//ypos = radius * sin(angle)+500;
		
		//more measurable version
		//xpos = a*exp(k*angle) * cos(angle)+500;
		//ypos = a*exp(k*angle) * sin(angle)+500;
		
		
		//golden spiral
		xpos1 = sin(angle1) * 1.618 * exp(angle1 / 3.14) + 500;
		ypos1 = cos(angle1) * 1.618 * exp(angle1 / 3.14) + 500;
		
		//prints out coordinate points at every 90 degree angle
		if (i1 % 90 == 0)
			cout << "angle is " << angle1 << ", x and y are " << xpos1 - 500 << " , " << ypos1 - 500 << endl;
		
		angle1 = (i1 * 3.14) / 180; //increase angle (formula is to convert to radians)
		
		i1++;
		//radius++ //uncomment this if you're experimenting with regular logarithmic spirals
		//window.clear();
		
		//make fun colors
		if (ticker1 > 254 || ticker1 < 0) {
			adder1 *= -1;
		}
		ticker1 += adder1;
		
		rectangle1.setFillColor(sf::Color(ticker1, 0, 250));
		rectangle1.setPosition(((xpos1) * -1) + 1000, ((ypos1) * -1) + 1000);
		window.draw(rectangle1);
		window.display();
		}


	float xpos2;
	float ypos2;
	float radius2 = 1;
	float angle2 = 0;
	int ticker2 = 0; //to change colors
	int adder2 = 1; //to change colors
	int i2 = 0; //iterator for loop
	float a2 = 1;
	float k2 = .5;

	while (i2 < 2000) {


		//basic logrithmic spiral
		//xpos = radius * cos(angle)+500;
		//ypos = radius * sin(angle)+500;

		//more measurable version
		//xpos = a*exp(k*angle) * cos(angle)+500;
		//ypos = a*exp(k*angle) * sin(angle)+500;


		//golden spiral
		xpos2 = sin(angle2) * 1.618 * exp(angle2 / 3.14) + 500;
		ypos2 = cos(angle2) * 1.618 * exp(angle2 / 3.14) + 500;

		//prints out coordinate points at every 90 degree angle
		if (i2 % 90 == 0)
			cout << "angle is " << angle2 << ", x and y are " << xpos2 - 500 << " , " << ypos2 - 500 << endl;

		angle2 = (i2 * 3.14) / 180; //increase angle (formula is to convert to radians)

		i2++;
		//radius++ //uncomment this if you're experimenting with regular logarithmic spirals
		//window.clear();

		//make fun colors
		if (ticker2 > 254 || ticker2 < 0) {
			adder2 *= -1;
		}
		ticker2 += adder2;

		rectangle2.setFillColor(sf::Color(250, ticker2, ticker2));
		rectangle2.setPosition((xpos2), ((ypos2) * -1) + 1000);
		window.draw(rectangle2);
		window.display();
	}


	float xpos3;
	float ypos3;
	float radius3 = 1;
	float angle3 = 0;
	int ticker3 = 0; //to change colors
	int adder3 = 1; //to change colors
	int i3 = 0; //iterator for loop
	float a3 = 1;
	float k3 = .5;

	while (i3 < 2000) {


		//basic logrithmic spiral
		//xpos = radius * cos(angle)+500;
		//ypos = radius * sin(angle)+500;

		//more measurable version
		//xpos = a*exp(k*angle) * cos(angle)+500;
		//ypos = a*exp(k*angle) * sin(angle)+500;


		//golden spiral
		xpos3 = sin(angle3) * 1.618 * exp(angle3 / 3.14) + 500;
		ypos3 = cos(angle3) * 1.618 * exp(angle3 / 3.14) + 500;

		//prints out coordinate points at every 90 degree angle
		if (i3 % 90 == 0)
			cout << "angle is " << angle3 << ", x and y are " << xpos3 - 500 << " , " << ypos3 - 500 << endl;

		angle3 = (i3 * 3.14) / 180; //increase angle (formula is to convert to radians)

		i3++;
		//radius++ //uncomment this if you're experimenting with regular logarithmic spirals
		//window.clear();

		//make fun colors
		if (ticker3 > 254 || ticker3 < 0) {
			adder3 *= -1;
		}
		ticker3 += adder3;

		rectangle3.setFillColor(sf::Color(130, ticker3, ticker3));
		rectangle3.setPosition((((xpos3) * -1) + 1000), (ypos3));
		window.draw(rectangle3);
		window.display();
	}
	
	//this keeps it open after it's done drawing
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


	}



}
/*
1) What do you notice about the coordinates outputted to the console? What patterns do you see, and why are they arising?
	- The coordinates happen at regular intervals of the angle, and show that the angle variable is a float, with its "# . #####" and then it shows the x and y values, and in every line of it, one or the other is very close to the value 0, while the other's very far from 0, although both become further from 0 over time.
2) Pretend I'm an English teacher. Explain how the color shifting algorithm on lines 56-59 works to me in a way I understand.
	- The color shifting algorithm works by adding a tiny bit of red to the color, shifting it from a dark blue to a magenta, and then once it reaches magenta, it starts subtracting a bit from the red from the color, slowly shifting it back to a dark blue color. This pattern repeats, and becomes less obvious the further out from the loop we get.
3) Right now the code prints coordinates at every 90 degrees. How could you change that to every 45 degrees?
	- By changing the code at line 46 from if (i % 90 == 0) to if (i % 45 == 0).
4) What happens if you change Phi to other numbers? Describe how the spiral changes.
	- The higher the number, the quicker the spiral moves outwards, making it much looser.
*/
