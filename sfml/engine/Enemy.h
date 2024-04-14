#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/System/Vector2.hpp>

class Enemy
{
	sf::Sprite p_Enemy;

	void InitEnemy(const sf::RenderWindow& window, const sf::Texture& texture);
public:
	float YSpeed;
	bool Delete;
	
	Enemy(const sf::RenderWindow& window, const sf::Texture& texture);
	~Enemy();

	void Move(sf::Vector2f Vec);
	void SetPosition(sf::Vector2f Vec);
	void Update(const sf::RenderWindow& window);

	void Render(sf::RenderTarget& target);
	
	const sf::Vector2u GetSize() const;
	sf::Sprite GetEnemySprite() const;
};

