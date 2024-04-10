#include "Enemy.h"

void Enemy::InitEnemy()
{
	this->p_EnemyTexture.loadFromFile("assets/enemy/enemy.png");
	this->p_Enemy.setTexture(this->p_EnemyTexture);

	this->YSpeed = static_cast<float>(rand() % 6);
}

Enemy::Enemy()
{
	this->InitEnemy();
}

Enemy::~Enemy()
{
}

void Enemy::SetPosition(sf::Vector2f Vec)
{
	this->p_Enemy.setPosition(Vec);
}

void Enemy::Update()
{

	this->p_Enemy.move(sf::Vector2f(
		0,
		this->YSpeed
	));
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


