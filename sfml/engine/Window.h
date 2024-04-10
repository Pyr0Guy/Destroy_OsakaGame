#pragma once
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>

#include "enemy.h"

class Game
{
	//Значения всякие
	sf::RenderWindow*	p_Window;
	sf::VideoMode		p_VMode;
	sf::Event			e;
	std::string			p_Title;
	bool				p_Running;

	//Объекты
	std::vector<Enemy> p_EnemyVector;
	Enemy p_Enemy;

	//Шрифт
	sf::Font Font;

	//Текст
	sf::Text Text;

	//Логика
	unsigned int Points;
	float EnemySpawnTimer;
	float EnemySpawnTimerMax;
	unsigned int MaxEnemys;
	bool MouseHeld;

	//Позиция мышки
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

	//Инициализация говна
	void InitVariables();
	void InitWindow();
	void InitFonts();
	void InitText();

	//Процессинг Эвентов
	void HandleEvents();

public:
	Game();
	~Game();

	void UpdateWindow();
	void DrawWindow();
	void UpdateMousePos();
	void UpdateEnemy();
	void RenderText(sf::RenderTarget& target);
	void UpdateText();

	void SpawnEnemy();

	const bool GetGameRunningState() const;
};