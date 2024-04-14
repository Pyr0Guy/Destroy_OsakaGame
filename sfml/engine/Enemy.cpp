#include "Enemy.h"
#include <iostream>

void Enemy::InitEnemy(const sf::RenderWindow& window, const sf::Texture& texture)
{
	this->p_Enemy.setTexture(texture);

	this->p_Enemy.setPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(window.getSize().x - this->p_Enemy.getTexture()->getSize().x)),
		static_cast<float>(rand() % static_cast<int>((window.getSize().y - 200.f) - this->p_Enemy.getTexture()->getSize().y)))
	);

	this->YSpeed = 0.5f + static_cast<float>(rand() % 6);
	this->Delete = false;
}

Enemy::Enemy(const sf::RenderWindow& window, const sf::Texture& texture)
{
	this->InitEnemy(window, texture);
}

Enemy::~Enemy()
{
}

void Enemy::SetPosition(sf::Vector2f Vec)
{
	this->p_Enemy.setPosition(Vec);
}

void Enemy::Update(const sf::RenderWindow& window)
{
	this->p_Enemy.move(sf::Vector2f(0, this->YSpeed));

	if (this->p_Enemy.getPosition().y > window.getSize().y)
		this->Delete = true;
}

void Enemy::Render(sf::RenderTarget& target)
{
	target.draw(this->p_Enemy);
}

void Enemy::Move(sf::Vector2f Vec)
{
	this->p_Enemy.move(Vec);
}

const sf::Vector2u Enemy::GetSize() const
{
	return this->p_Enemy.getTexture()->getSize();
}

sf::Sprite Enemy::GetEnemySprite() const
{
	return this->p_Enemy;
}


