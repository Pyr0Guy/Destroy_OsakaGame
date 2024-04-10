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
}

void Game::InitWindow()
{
	this->p_VMode.width		= 800;
	this->p_VMode.height	= 600;
	
	this->p_Title			= "Tohou Game";

	this->p_Window			= new sf::RenderWindow(p_VMode, p_Title, sf::Style::Titlebar | sf::Style::Close);
	this->p_Window->setFramerateLimit(60);

	this->p_Running			= true;
}

void Game::InitFonts()
{
	if (!this->Font.loadFromFile("fonts/comic.ttf"))
	{
		std::cout << "Failed to load Font" << std::endl;
	}
}

void Game::InitText()
{
	this->Text.setFont(this->Font);
	this->Text.setCharacterSize(24);
	this->Text.setFillColor(sf::Color::White);
	this->Text.setString("NULL");
}

Game::Game()
{
	this->InitVariables();
	this->InitWindow();
	this->InitFonts();
	this->InitText();
}

Game::~Game()
{
	delete this->p_Window;
}

void Game::UpdateWindow()
{
	this->HandleEvents();
	this->UpdateMousePos();
	this->UpdateEnemy();
	this->UpdateText();
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

	for (auto& a : this->p_EnemyVector)
	{
		this->p_Window->draw(a.GetEnemySprite());
	}

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
		a.Update();

	if (this->p_EnemyVector.size() < this->MaxEnemys)
	{
		if (this->EnemySpawnTimer >= this->EnemySpawnTimerMax)
		{
			this->EnemySpawnTimer = 0.f;
			this->SpawnEnemy();
		}
		this->EnemySpawnTimer += 1.f;
	}

	for (size_t i = 0; i < this->p_EnemyVector.size(); i++)
	{
		//this->p_EnemyVector[i].GetEnemySprite().move(sf::Vector2f(0, this->p_EnemyVector[i].YSpeed));

		if (this->p_EnemyVector[i].GetEnemySprite().getPosition().y > this->p_Window->getSize().y)
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

					this->Points += 1.f;
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

void Game::RenderText(sf::RenderTarget& target)
{
	target.draw(this->Text);
}

void Game::UpdateText()
{
	std::stringstream ss;

	ss << "Points " << this->Points;
	this->Text.setString(ss.str());
}

void Game::SpawnEnemy()
{
	this->p_Enemy.SetPosition(sf::Vector2f(
		static_cast<float>(rand() % static_cast<int>(this->p_Window->getSize().x - this->p_Enemy.GetSize().x)),
		static_cast<float>(rand() % static_cast<int>(this->p_Window->getSize().y - this->p_Enemy.GetSize().y)))
	);

	this->p_EnemyVector.push_back(this->p_Enemy);
}

const bool Game::GetGameRunningState() const
{
	return this->p_Running;
}
