#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <string> 
#include <random>
#include <math.h>

using namespace sf;
using namespace std;

class Player {
public:
	Player(int windowX, int windowY) {
		this->player.setSize(Vector2f(20.f, 20.f));
		this->player.setPosition(windowX / 2, windowY / 2);
		this->player.setFillColor(Color::Green);
		this->velocity = 2.8;
		this->keytime = 8;
		this->playerHealthPause = 8;
		this->playerHealth = 3;
		this->points = 0;
	}
	RectangleShape& getPlayer() { return this->player; }
	int getKeytime() { return keytime; }
	float getVelocity() { return velocity; }
	void setKeytime(int kt) { keytime = kt; }
	void incrementKeytime() { keytime++; }
	int getHealth() { return playerHealth; }
	int getPoints() { return points; }
	int getPlayerHealthPause() { return playerHealthPause; }
	void decrementHealth() { if (playerHealth > 0) { playerHealth--; } }
	void decrementPlayerHealthPause() { if (playerHealthPause > 0) { playerHealthPause--; } }
	void setPlayerHealthPause() { playerHealthPause = 150; }
	void increasePoints(int x) { points += x; }
private:
	RectangleShape player;
	float velocity;
	int keytime;
	int playerHealth;
	int playerHealthPause;
	int points;
};

class Bullet {
public:
	Bullet(int radius, int playerCenterPosX, int playerCenterPosY, float dirX, float dirY, int velocity, Color bulletColor) {
		this->bullet.setRadius(radius);
		this->bullet.setPosition(playerCenterPosX, playerCenterPosY);
		this->bullet.setFillColor(bulletColor);
		this->dirX = dirX;
		this->dirY = dirY;
		this->velocity = velocity;
	}
	int getVelocity() { return velocity; }
	float getDirX() { return dirX; }
	float getDirY() { return dirY; }
	CircleShape& getBullet() { return (this->bullet); }

private:
	CircleShape bullet;
	int velocity;
	float dirX;
	float dirY;
};

class Enemy {
public:
	RectangleShape& getEnemy() { return this->enemy; }
	float getVelocity() { return velocity; }
	int getHealth() { return health; }
	void decrementHealth() { if (health > 0) { health--; } }
protected:
	RectangleShape enemy;
	int randomX;
	int randomY;
	int health;
	float velocity;
};

class Zombie : public Enemy {
public:
	Zombie(int windowX, int windowY, Player player) {
		this->enemy.setSize(Vector2f(20.f, 20.f));
		do {
			randomX = rand() % windowX;
			randomY = rand() % windowY;
		} while (abs(randomX - player.getPlayer().getPosition().x) < (player.getPlayer().getSize().x * 3) || abs(randomY - player.getPlayer().getPosition().y) < (player.getPlayer().getSize().y * 3));
		this->enemy.setPosition(randomX, randomY);
		this->enemy.setFillColor(Color::Red);
		this->velocity = float(rand()) / float((RAND_MAX)) + 0.5;
	}
};

class Mutant : public Enemy {
public:
	Mutant(int windowX, int windowY, Player player) {
		this->enemy.setSize(Vector2f(30.f, 30.f));
		do {
			randomX = rand() % windowX;
			randomY = rand() % windowY;
		} while (abs(randomX - player.getPlayer().getPosition().x) < (player.getPlayer().getSize().x * 3) || abs(randomY - player.getPlayer().getPosition().y) < (player.getPlayer().getSize().y * 3));
		this->enemy.setPosition(randomX, randomY);
		this->enemy.setFillColor(Color::Color(128, 0, 0));
		this->velocity = float(rand()) / float((RAND_MAX)) + 0.1;
		this->health = 5;
	}
};

class Skeleton : public Enemy {
public:
	Skeleton(int windowX, int windowY, Player player) {
		this->enemy.setSize(Vector2f(20.f, 20.f));
		do {
			randomX = rand() % windowX;
			randomY = rand() % windowY;
		} while (abs(randomX - player.getPlayer().getPosition().x) < (player.getPlayer().getSize().x * 3) || abs(randomY - player.getPlayer().getPosition().y) < (player.getPlayer().getSize().y * 3));
		this->enemy.setPosition(randomX, randomY);
		this->enemy.setFillColor(Color::Color(255, 179, 179));
		this->velocity = float(rand()) / float((RAND_MAX)) + 0.3;
		this->keytime = rand() % 30;
		this->destX = rand() % windowX;
		this->destY = rand() % windowY;
		this->moveX = -(randomX - destX) / sqrt(pow(randomX - destX, 2) + pow(randomY - destY, 2));
		this->moveY = -(randomY - destY) / sqrt(pow(randomX - destX, 2) + pow(randomY - destY, 2));
		//cout << moveX << " " << moveY;
	}
	int getDestX() { return destX; }
	int getDestY() { return destY; }
	float getMoveX() { return moveX; }
	float getMoveY() { return moveY; }
	int getKeytime() { return keytime; }
	void setDestX(int x) { destX = x; }
	void setDestY(int y) { destY = y; }
	void setMoveX(float x) { moveX = x; }
	void setMoveY(float y) { moveY = y; }
	void setKeytime(int kt) { keytime = kt; }
	void incrementKeytime() { keytime++; }
private:
	int keytime;
	float moveX;
	float moveY;
	int destX;
	int destY;
};

void refresh(RenderWindow& window, Player player, vector <Zombie> zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons, vector <Bullet>& bullets, vector <Bullet> enemyBullets, Text lives, Text score);
void inputEnemies(RenderWindow& window, vector <Zombie>& zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons, Player player, int difficulty);
void keyboardInput(Player& player, RenderWindow& window, vector <Bullet>& bullets);
void updateEnemies(RenderWindow& window, vector <Zombie>& zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons, vector <Bullet>& enemyBullets, Player player);
void updateBullets(vector <Bullet>& bullets, vector <Bullet>& enemyBullets);
void checkCollision(Player& player, vector <Zombie>& zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons, vector <Bullet>& bullets, vector <Bullet>& enemyBullets, RenderWindow& window);
bool checkEndWave(vector <Zombie>& zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons);
Font inputFont();
void inputLives(Text* lives, Font font, Player player);
void updateText(Text& lives, Text& score, Player player);


