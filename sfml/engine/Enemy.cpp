#include "Enemy.h"

Enemy::Enemy(const sf::RenderWindow& window, const sf::Texture* textures)
{
	this->Delete = false;
	this->p_Enemy.setTexture(*textures);

	this->speed = static_cast<float>(rand() % 6) + 0.5f;
	this->p_Enemy.setPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(window.getSize().x - this->p_Enemy.getTexture()->getSize().x)),
		static_cast<float>(rand() % static_cast<int>((window.getSize().y - 200.f) - this->p_Enemy.getTexture()->getSize().y))
	));
}

void Enemy::Update(const sf::RenderWindow& window)
{
	this->p_Enemy.move(0.f, this->speed);

	if (this->p_Enemy.getPosition().y > window.getSize().y + this->p_Enemy.getTexture()->getSize().y)
		this->Delete = true;
}

void Enemy::Render(sf::RenderTarget* target)
{
	target->draw(this->p_Enemy);
}

const sf::Sprite Enemy::GetEnemy() const
{
	return this->p_Enemy;
}
