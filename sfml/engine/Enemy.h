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
	float speed;

public:
	Enemy(const sf::RenderWindow& window, const sf::Texture* textures);

	bool Delete;

	void Update(const sf::RenderWindow& window);
	void Render(sf::RenderTarget* target);

	const sf::Sprite GetEnemy() const;
};

