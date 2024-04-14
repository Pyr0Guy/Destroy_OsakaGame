#include "Explode.h"

void Explode::InitVariables(const sf::RenderWindow& window, const sf::Texture& texture, sf::Vector2f Vec)
{
	this->ExplodeSprite.setTexture(texture);
	this->ExplodeSprite.setPosition(Vec.x - 25.f, Vec.y - 45.f);
	this->finish = false;
	this->UVShit = sf::IntRect(0, 0, 72, 100);

	this->ExplodeSprite.setTextureRect(this->UVShit);
}

Explode::Explode(const sf::RenderWindow& window, const sf::Texture& texture, sf::Vector2f Vec)
{
	this->InitVariables(window, texture, Vec);
}

void Explode::Update()
{

	if (this->clock >= 40)
	{
		this->UVShit.left += 72;
		this->ExplodeSprite.setTextureRect(this->UVShit);
		//this->ExplodeSprite.setTexture(this->Texture);

		this->clock = 0;
	}

	this->clock += 10;

	if (this->UVShit.left >= 1225)
		this->finish = true;
}

void Explode::Render(sf::RenderTarget& target)
{
	target.draw(this->ExplodeSprite);
}
