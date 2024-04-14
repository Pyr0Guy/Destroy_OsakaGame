#include "Window.h"
#include <iostream>

void Game::InitVariables()
{
	this->p_Window	= nullptr;

	this->Points				= 0;
	this->EnemySpawnTimerMax	= 10.f;
	this->EnemySpawnTimer		= this->EnemySpawnTimerMax;
	this->MaxEnemys				= 15;
	this->MouseHeld				= false;

	if (!this->BoomTexture.loadFromFile("assets/images/explodeFunny.png"))
	{
		std::cout << "Cant load BOOM" << std::endl;
	}

	if (!this->EnemyTexture.loadFromFile("assets/images/enemy/enemy.png"))
	{
		std::cout << "Cant load Enemy" << std::endl;
	}

	if (!this->BG_Texture.loadFromFile("assets/images/bg.png"))
	{
		std::cout << "Cant load BG" << std::endl;
	}

	this->BG.setTexture(this->BG_Texture);
}

void Game::InitWindow()
{
	this->p_VMode.width		= 800;
	this->p_VMode.height	= 600;
	
	this->p_Title			= "Destroy the Osaka:The Game";

	this->p_Window			= new sf::RenderWindow(p_VMode, p_Title, sf::Style::Titlebar | sf::Style::Close);
	this->p_Window->setFramerateLimit(60);

	this->p_Running			= true;
}

void Game::InitFontsAndText()
{
	if (!this->Font.loadFromFile("assets/fonts/comic.ttf"))
	{
		std::cout << "Failed to load Font" << std::endl;
	}

	this->Text.setFont(this->Font);
	this->Text.setCharacterSize(24);
	this->Text.setFillColor(sf::Color::White);
	this->Text.setString("NULL");
}

void Game::InitSound()
{
	if (!p_SB.loadFromFile("assets/sound/boom.wav"))
	{
		std::cout << "Cant load BOOM sound" << std::endl;
	}

	snd.setBuffer(p_SB);
}

Game::Game()
{
	this->InitVariables();
	this->InitWindow();
	this->InitFontsAndText(); 
	this->InitSound();
}

Game::~Game()
{
	delete this->p_Window;
}

void Game::UpdateWindow()
{
	this->HandleEvents();
	this->UpdateMousePos();
	this->SpawnEnemy();
	this->UpdateEnemy();
	this->UpdateText();
	this->UpdateExplode();
}

void Game::SpawnEnemy()
{
	if (this->p_EnemyVector.size() < this->MaxEnemys)
	{
		if (this->EnemySpawnTimer >= this->EnemySpawnTimerMax)
		{
			this->EnemySpawnTimer = 0.f;
			//Spawn Enemy
			this->p_EnemyVector.push_back(Enemy(*this->p_Window, this->EnemyTexture));
		}
		this->EnemySpawnTimer += 1.f;
	}
}

void Game::HandleEvents()
{
	while (this->p_Window->pollEvent(this->e))
	{
		if (this->e.type == sf::Event::Closed)
			this->p_Running = false;
	}
}

void Game::DrawWindow()
{
	this->p_Window->clear();

	this->p_Window->draw(this->BG);
	this->RenderEnemy(*this->p_Window);
	this->RenderExplode(*this->p_Window);
	this->RenderText(*this->p_Window);

	this->p_Window->display();
}

void Game::UpdateMousePos()
{
	this->MousePosWindow = sf::Mouse::getPosition(*this->p_Window);
	this->MousePosView = this->p_Window->mapPixelToCoords(this->MousePosWindow);
}

void Game::UpdateEnemy()
{
	for (auto& a : this->p_EnemyVector)
	{
		a.Update(*this->p_Window);
	}

	for (int i = 0; i < this->p_EnemyVector.size(); i++)
	{
		if (this->p_EnemyVector[i].Delete)
			this->p_EnemyVector.erase(this->p_EnemyVector.begin() + i);
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->MouseHeld == false)
		{
			this->MouseHeld = true;
			for (size_t i = 0; i < this->p_EnemyVector.size(); i++)
			{
				if (this->p_EnemyVector[i].GetEnemySprite().getGlobalBounds().contains(this->MousePosView))
				{
					this->p_EnemyVector.erase(this->p_EnemyVector.begin() + i);

					this->Points += 1;
					//Spawn Explosion
					this->p_ExplodeVector.push_back(Explode(*this->p_Window, this->BoomTexture, this->MousePosView));
					snd.play();
					break;
				}
			}
		}
	}
	else
	{
		this->MouseHeld = false;
	}
	
}

void Game::RenderEnemy(sf::RenderTarget& target)
{
	for (auto& a : this->p_EnemyVector)
		a.Render(target);
}

void Game::UpdateExplode()
{
	for (size_t i = 0; i < this->p_ExplodeVector.size(); i++)
	{
		if (this->p_ExplodeVector[i].finish)
		{
			this->p_ExplodeVector.erase(this->p_ExplodeVector.begin() + i);
			break;
		}
	}


	for (auto& a : this->p_ExplodeVector)
		a.Update();
}

void Game::RenderExplode(sf::RenderTarget& target)
{
	for (auto& a : this->p_ExplodeVector)
		a.Render(target);
}

void Game::RenderText(sf::RenderTarget& target)
{
	target.draw(this->Text);
}

void Game::UpdateText()
{
	std::stringstream ss;

	ss << "Points: " << this->Points;
	this->Text.setString(ss.str());
}

const bool Game::GetGameRunningState() const
{
	return this->p_Running;
}
