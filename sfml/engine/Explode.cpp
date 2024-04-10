#include "Explode.h"

void Explode::InitVariables()
{
	this->finish = false;
	this->UVShit = sf::IntRect(0, 0, 72, 100);

	if (!this->Texture.loadFromFile("assets/images/explodeFunny.png"))
	{
		std::cout << "Cant load BOOM" << std::endl;
	}

	this->ExplodeSprite.setTexture(this->Texture);
	this->ExplodeSprite.setTextureRect(this->UVShit);
}

Explode::Explode()
{
	this->InitVariables();
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
