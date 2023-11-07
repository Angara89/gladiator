#pragma once
#include "common.h"

class Window
{
private:
	sf::RenderWindow* renderW;
	list<sf::Drawable*> drawList;
	thread mainTheard;


public:
	Window(sf::VideoMode& vm, string& name)
	{
		renderW = new  sf::RenderWindow(vm, name);
		drawList = list<sf::Drawable*>();
		main_loop();
	}

	~Window()
	{
		mainTheard.join();
		delete renderW;
	}

	void add_drawable(sf::Drawable* drawn)
	{
		drawList.push_back(drawn);
	}

	void main_loop()
	{


		while (renderW->isOpen())
		{
			sf::Event event;
			while (renderW->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					renderW->close();
				}
			}

			renderW->clear();
			for (auto drawn : drawList)
			{
				renderW->draw(*drawn);
			}
			renderW->display();
		}
		
	}

};

