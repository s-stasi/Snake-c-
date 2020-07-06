#include <locale.h>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
#include "Menu.h"
#define _(STRING) gettext(STRING)
using namespace sf;
using std::string;

int width = 600;
int height = 600;
int scl = 20;
int dim = 30;
int dir, num = 4;
bool close, isOn = false, menu_  = true;

// Creazione del bruco
struct Snake 
{ int x,y;}  s[900];

// Creazione della mela
struct Apple
{ int x,y;}  a;

// Funzione spawn mela
void mela()
{
    a.x=rand()%dim;
    a.y=rand()%dim;
}

// Funzione gestione dei movimenti del bruco e posizionamento della mela
void move(){
    // Controllo se il bruco è fuori dal campo di gioco
	if(s[0].x==dim || s[0].y==dim || s[0].x==0-1 || s[0].y==0-1) 
    {
        close = true;
    }
    for (int i = num; i > 0; i--)
    {
        // Spostamento del bruco
        s[i].x=s[i-1].x;
        s[i].y=s[i-1].y;
    }
    
    if (dir==0){s[0].y+=1;}
    if (dir==1){s[0].x-=1;}
    if (dir==2){s[0].x+=1;}
    if (dir==3){s[0].y-=1;}

    // Controllo se il bruco ha mangiato la mela e
    // creazione della nuova mela
    if (s[0].x==a.x && s[0].y==a.y)
    {
        num++;
		mela();
    }

    // Controllo se la mela è sopra al bruco
	while (isOn == true);
    {
		std::cout << "1" << std::endl;
		isOn = false;
        for (int i=0; i<num; i++)
        {
            if (s[i].x==a.x && s[i].y==a.y)
            {
                mela();
				std::cout << "2" << std::endl;
				isOn = true;
            }
        }
    }
}

int main()
{
	char* memory;

	std::ifstream myfile("icon.png", std::ios::binary | std::ios::ate);

	std::ifstream::pos_type size;

	size = myfile.tellg();

	memory = new char[size];

	myfile.seekg(0, std::ios::beg);
	myfile.read(memory, size);
	myfile.close();

	sf::Image icon;
	if (!icon.loadFromMemory(memory, size))
	{
		std::cout << "failed to load image" << std::endl;
	}



    srand(time(0));

    // Creazione fnestra
    RenderWindow window(VideoMode(width, height), "Snake");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Creazione quadrati della mela e del bruco
    RectangleShape rectangle(Vector2f(scl, scl));
    rectangle.setFillColor(Color::Green);
    RectangleShape rectapple(Vector2f(scl, scl));
    rectapple.setFillColor(Color::Red);

    // Oggetti e variabili per il refresh della finestra
    Clock clock;   
    float timer=0, delay=0.7;

    // Prima mela
    mela();

    // loop del gioco
    while (window.isOpen())
    {
    	if (close == true) window.close();
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed || close == true)
            {
                window.close();
            }
        }
        if (menu_)
		{

			Menu menu(window.getSize().x, window.getSize().y);
			menu.draw(window);
			window.display();

            while (menu_)
            {
				window.display();
				if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					menu.moveUp();
					window.display();
				}
				if (Keyboard::isKeyPressed(Keyboard::Down))
				{
					menu.moveDown();
					window.display();
				}
				if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					menu_ = false;
				}
                while (window.pollEvent(e))
                {
                    if (e.type == Event::Closed || close == true)
                    {
                        window.close();
                    }
                }
            }
		}
        if (Keyboard::isKeyPressed(Keyboard::Left) && dir != 2) dir=1;   
        if (Keyboard::isKeyPressed(Keyboard::Right) && dir != 1) dir=2;    
        if (Keyboard::isKeyPressed(Keyboard::Up) && dir != 0) dir=3;
        if (Keyboard::isKeyPressed(Keyboard::Down) && dir != 3) dir=0;

        window.display();
        if (timer>delay)
        {
            timer=0;
            move();
        }
        window.clear(Color::Black);

        for (int i=0;i<num;i++)
        { 
            rectangle.setPosition(s[i].x*scl, s[i].y*scl);
            window.draw(rectangle);
        }
   
        rectapple.setPosition(a.x*scl, a.y*scl);
        window.draw(rectapple);    

        window.display();
    }
    return 0;
}

