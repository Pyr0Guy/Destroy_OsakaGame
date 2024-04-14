#pragma once
#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio.hpp>

#include "enemy.h"
#include "Explode.h"

class Game
{
	sf::RenderWindow*	p_Window;
	sf::VideoMode		p_VMode;
	sf::Event			e;
	std::string			p_Title;
	bool				p_Running;

	std::vector<Enemy> p_EnemyVector;
	sf::Texture EnemyTexture;

	std::vector<Explode> p_ExplodeVector;
	sf::Texture BoomTexture;

	sf::Texture BG_Texture;
	sf::Sprite	BG;

	sf::Font Font;
	sf::Text Text;

	unsigned int Points;
	float EnemySpawnTimer;
	float EnemySpawnTimerMax;
	unsigned int MaxEnemys;
	bool MouseHeld;

	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

	sf::SoundBuffer p_SB;
	sf::Sound snd;

	void InitVariables();
	void InitWindow();
	void InitFontsAndText();
	void InitSound();

	void SpawnEnemy();
	void HandleEvents();

public:
	Game();
	~Game();

	void UpdateWindow();
	void DrawWindow();
	void UpdateMousePos();
	void UpdateEnemy();
	void RenderEnemy(sf::RenderTarget& target);
	void UpdateExplode();
	void RenderExplode(sf::RenderTarget& target);
	void RenderText(sf::RenderTarget& target);
	void UpdateText();

	const bool GetGameRunningState() const;
};