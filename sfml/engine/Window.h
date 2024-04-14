#pragma once
#include <vector>
#include <ctime>
#include <sstream>
#include <map>
#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include "enemy.h"
#include "Explode.h"

class Game
{
	sf::RenderWindow*	p_Window;
	sf::VideoMode		p_VM;
	std::string			p_GameName;

	//Variables
	bool p_GameRunning;
	bool MouseHeld;

	float p_EnemySpawnTimer;
	float p_EnemySpawnTimerMax;
	unsigned int p_Points;
	unsigned int p_MaxEnemys;

	sf::Vector2i p_MousePosWindow;
	sf::Vector2f p_MousePosView;

	sf::Font p_Font;
	sf::Text p_Text;

	sf::Sprite p_BG;

	//Resourses
	std::map<std::string, sf::Texture*>		p_Textures;
	std::map<std::string, sf::SoundBuffer*>	p_Sounds;
	std::vector<Enemy*>						p_EnemyVector;
	std::vector<Explode*>					p_ExplodeVector;

	//Functions
	void InitVariables();
	void InitWindow();
	void InitTextures();
	void InitSounds();
	void InitFontAndText();

	void HandleEvents();

	void UpdateEnemy();
	void RenderEnemy();

	void UpdateMousePosition();
	void UpdateText();

	void UpdateExplode();
	void RenderExplode();

	void SpawnEnemy();
public:
	Game();
	~Game();

	void Update();
	void Render();

	const bool GameRunning() const;
};