#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Audio/Sound.hpp>]
#include <SFML/Audio/SoundBuffer.hpp>

#include <iostream>

class Explode
{
	sf::Sprite p_Explode;
	sf::IntRect UVShit;
	sf::Sound p_ExplodeSound;

	int frame;
	int clock;

public:
	Explode(const sf::Vector2f& Vec, const sf::Texture* texture, sf::SoundBuffer* snd);

	bool Finish;

	void Update();
	void Render(sf::RenderTarget* target);
};

