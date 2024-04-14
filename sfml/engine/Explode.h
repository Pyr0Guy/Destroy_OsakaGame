#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>

class Explode
{
	sf::Texture Texture;

	void InitVariables(const sf::RenderWindow& window, const sf::Texture& texture, sf::Vector2f Vec);

public:
	Explode(const sf::RenderWindow& window, const sf::Texture& texture, sf::Vector2f Vec);

	void Update();
	void Render(sf::RenderTarget& target);

	sf::Sprite ExplodeSprite;
	bool finish;
	int clock;
	sf::IntRect UVShit;
};

