#include "Explode.h"

Explode::Explode(const sf::Vector2f& Vec, const sf::Texture* texture, sf::SoundBuffer* snd)
{
	this->Finish = false;
	this->UVShit = { 0, 0, 72, 100 };
	this->frame = 0;
	this->clock = 0;

	this->p_Explode.setTexture(*texture);
	this->p_Explode.setPosition(Vec.x - 50.f, Vec.y - 40.f);
	this->p_Explode.setTextureRect(this->UVShit);

	this->p_ExplodeSound.setBuffer(*snd);
	this->p_ExplodeSound.setVolume(30.f);
	this->p_ExplodeSound.play();
}

void Explode::Update()
{
	if (this->clock >= 40)
	{
		this->UVShit.left += 72;
		this->p_Explode.setTextureRect(this->UVShit);
		this->clock = 0;
	}

	this->clock += 10;

	if (this->UVShit.left >= 1225)
		this->Finish = true;
}

void Explode::Render(sf::RenderTarget* target)
{
	target->draw(this->p_Explode);
}
