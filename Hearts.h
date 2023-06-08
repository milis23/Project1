#pragma once
#include<SFML/Graphics.hpp>
class Hearts:public sf::Sprite
{
public:
	Hearts(float x,float y);
	void draw(sf::RenderWindow& window);//wyswietla serca
private:
	sf::RenderWindow m_window;
	sf::Sprite m_sprite;
	sf::Texture m_texture;
};

