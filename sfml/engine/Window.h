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
	//�������� ������
	sf::RenderWindow*	p_Window;
	sf::VideoMode		p_VMode;
	sf::Event			e;
	std::string			p_Title;
	bool				p_Running;

	//�������
	std::vector<Enemy> p_EnemyVector;
	Enemy p_Enemy;

	std::vector<Explode> p_ExplodeVector;
	sf::Texture BoomTexture;
	Explode p_Boom;

	sf::Texture BG_Texture;
	sf::Sprite	BG;

	//�����
	sf::Font Font;

	//�����
	sf::Text Text;

	//������
	unsigned int Points;
	float EnemySpawnTimer;
	float EnemySpawnTimerMax;
	unsigned int MaxEnemys;
	bool MouseHeld;

	//������� �����
	sf::Vector2i MousePosWindow;
	sf::Vector2f MousePosView;

	//����
	sf::SoundBuffer p_SB;
	sf::Sound snd;

	//������������� �����
	void InitVariables();
	void InitWindow();
	void InitFonts();
	void InitText();
	void InitSound();

	//���������� �������
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
	void SpawnExplode(sf::Vector2f Vec);

	const bool GetGameRunningState() const;
};