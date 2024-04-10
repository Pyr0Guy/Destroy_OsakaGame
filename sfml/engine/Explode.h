#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Clock.hpp>

#include <iostream>

class Explode
{
	sf::Texture Texture;

	void InitVariables();

public:
	Explode();

	void Update();
	void Render(sf::RenderTarget& target);

	sf::Sprite ExplodeSprite;
	bool finish;
	int clock;
	sf::IntRect UVShit;
};

