#include "Window.h"

void Game::InitVariables()
{
	this->p_Window		= nullptr;
	this->p_GameRunning = false;
	this->p_VM.width	= 800;
	this->p_VM.height	= 600;
	this->p_GameName	= "Destroy The Osaka:The Game";

	this->MouseHeld		= false;

	this->p_EnemySpawnTimerMax = 10.f;
	this->p_EnemySpawnTimer = this->p_EnemySpawnTimerMax;
	this->p_Points = 0;
	this->p_MaxEnemys = 15;
}

void Game::InitWindow()
{
	this->p_Window = new sf::RenderWindow(this->p_VM, this->p_GameName, sf::Style::Titlebar | sf::Style::Close);
	this->p_Window->setFramerateLimit(60);
	this->p_GameRunning = true;
}

void Game::InitTextures()
{
	this->p_Textures["BG"] = new sf::Texture();
	this->p_Textures["BG"]->loadFromFile("assets/images/bg.png");
	this->p_BG.setTexture(*this->p_Textures["BG"]);

	this->p_Textures["ENEMY"] = new sf::Texture();
	this->p_Textures["ENEMY"]->loadFromFile("assets/images/enemy/enemy.png");

	this->p_Textures["EXPLOSION"] = new sf::Texture();
	this->p_Textures["EXPLOSION"]->loadFromFile("assets/images/explodeFunny.png");
}

void Game::InitFontAndText()
{
	this->p_Font.loadFromFile("assets/fonts/comic.ttf");
	this->p_Text.setFont(this->p_Font);
	this->p_Text.setCharacterSize(24);
	this->p_Text.setFillColor(sf::Color::White);
	this->p_Text.setString("NULL");
}

void Game::InitSounds()
{
	this->p_Sounds["EXPLODE"] = new sf::SoundBuffer();
	this->p_Sounds["EXPLODE"]->loadFromFile("assets/sound/boom.wav");
}


Game::Game()
{
	this->InitVariables();
	this->InitWindow();
	this->InitTextures();
	this->InitFontAndText();
	this->InitSounds();
}

Game::~Game()
{
	//Delete Fucking Fucking Textures 2
	for (auto& textures : this->p_Textures)
		delete textures.second;

	for (auto& sounds : this->p_Sounds)
		delete sounds.second;

	for (auto* Enemy : this->p_EnemyVector)
		delete Enemy;

	for (auto* Explosions : this->p_ExplodeVector)
		delete Explosions;

	delete this->p_Window;
}

void Game::HandleEvents()
{
	sf::Event ev;
	while (this->p_Window->pollEvent(ev))
	{
		if ((ev.type == sf::Event::Closed) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
			this->p_GameRunning = false;
	}
}

void Game::UpdateEnemy()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) /* && this->MouseHeld == false*/) //Fuck This
	{
		if (this->MouseHeld == false)
		{

			this->MouseHeld = true;
			for (size_t i = 0; i < this->p_EnemyVector.size(); i++)
			{
				if (this->p_EnemyVector[i]->GetEnemy().getGlobalBounds().contains(this->p_MousePosView))
				{
					this->p_EnemyVector[i]->Delete = true;
					this->p_Points += 1;
					
					this->p_ExplodeVector.push_back(new Explode(this->p_MousePosView, this->p_Textures["EXPLOSION"], this->p_Sounds["EXPLODE"]));

					break;
				}
			}
		}
	}
	else
	{
		this->MouseHeld = false;
	}

	for (size_t i = 0; i < this->p_EnemyVector.size(); i++)
	{
		this->p_EnemyVector[i]->Update(*this->p_Window);

		if (this->p_EnemyVector[i]->Delete)
			this->p_EnemyVector.erase(this->p_EnemyVector.begin() + i);
	}

	this->SpawnEnemy();
}

void Game::RenderEnemy()
{
	for (auto* Enemy : this->p_EnemyVector)
		Enemy->Render(this->p_Window);
}

void Game::Update()
{
	this->HandleEvents();
	this->UpdateEnemy();
	this->UpdateMousePosition();
	this->UpdateText();
	this->UpdateExplode();
}

void Game::UpdateMousePosition()
{
	this->p_MousePosWindow = sf::Mouse::getPosition(*this->p_Window);
	this->p_MousePosView = this->p_Window->mapPixelToCoords(this->p_MousePosWindow);
}

void Game::UpdateText()
{
	std::stringstream ss;
	ss << "Points: " << this->p_Points;
	this->p_Text.setString(ss.str());
}

void Game::UpdateExplode()
{
	for (int i = 0; i < this->p_ExplodeVector.size(); i++)
	{
		this->p_ExplodeVector[i]->Update();
		
		if (this->p_ExplodeVector[i]->Finish)
			this->p_ExplodeVector.erase(this->p_ExplodeVector.begin() + i);
	}
}

void Game::RenderExplode()
{
	for (auto* explosion : this->p_ExplodeVector)
		explosion->Render(this->p_Window);
}

void Game::Render()
{
	this->p_Window->clear(sf::Color::Magenta);

	this->p_Window->draw(this->p_BG);
	this->RenderEnemy();
	this->RenderExplode();
	this->p_Window->draw(this->p_Text);

	this->p_Window->display();
}

void Game::SpawnEnemy()
{
	if (this->p_EnemySpawnTimer < 0 && this->p_EnemyVector.size() < this->p_MaxEnemys)
	{
		this->p_EnemyVector.push_back(new Enemy(*this->p_Window, this->p_Textures["ENEMY"]));
		this->p_EnemySpawnTimer = this->p_EnemySpawnTimerMax;
	}

	this->p_EnemySpawnTimer -= 1.f;
}

const bool Game::GameRunning() const
{
	return this->p_GameRunning;
}