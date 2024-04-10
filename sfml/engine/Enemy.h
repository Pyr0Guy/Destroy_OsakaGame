#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Enemy
{
	sf::Texture p_EnemyTexture;
	sf::Sprite p_Enemy;


	void InitEnemy();
public:
	float YSpeed;
	
	Enemy();
	~Enemy();

	void Move(sf::Vector2f Vec);
	void SetPosition(sf::Vector2f Vec);
	void Update();
	void Render();
	
	const sf::Vector2u GetSize() const;
	sf::Sprite GetEnemySprite() const;
};

