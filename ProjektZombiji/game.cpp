#include "game.h"

void refresh(RenderWindow& window, Player player, vector <Zombie> zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons, vector <Bullet>& bullets, vector <Bullet> enemyBullets, Text lives, Text score) {
	window.clear();
	window.draw(score);
	window.draw(player.getPlayer());
	for (int i = 0; i < zombies.size(); i++) {
		window.draw(zombies[i].getEnemy());
	}
	for (int i = 0; i < mutants.size(); i++) {
		window.draw(mutants[i].getEnemy());
	}
	for (int i = 0; i < skeletons.size(); i++) {
		window.draw(skeletons[i].getEnemy());
	}
	for (int i = 0; i < bullets.size(); i++) {
		window.draw(bullets[i].getBullet());
	}
	for (int i = 0; i < enemyBullets.size(); i++) {
		window.draw(enemyBullets[i].getBullet());
	}
	window.display();
}

void inputEnemies(RenderWindow& window, vector <Zombie>& zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons, Player player, int difficulty) {
	for (int i = 0; i < difficulty; i++) {
		Zombie zombie(window.getSize().x, window.getSize().y, player);
		zombies.push_back(zombie);
	}
	for (int i = 0; i < difficulty / 15; i++) {
		Mutant mutant(window.getSize().x, window.getSize().y, player);
		mutants.push_back(mutant);
	}
	for (int i = 0; i < difficulty / 10; i++) {
		Skeleton skeleton(window.getSize().x, window.getSize().y, player);
		skeletons.push_back(skeleton);
	}
}

void keyboardInput(Player& player, RenderWindow& window, vector <Bullet>& bullets) {

	if (player.getKeytime() <= 8) {
		player.incrementKeytime();
	}

	if (Keyboard::isKeyPressed(Keyboard::A) && player.getPlayer().getPosition().x > 0) {
		player.getPlayer().move(-player.getVelocity(), 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::D) && player.getPlayer().getPosition().x + player.getPlayer().getSize().x < window.getSize().x) {
		player.getPlayer().move(player.getVelocity(), 0.f);
	}
	if (Keyboard::isKeyPressed(Keyboard::W) && player.getPlayer().getPosition().y > 0) {
		player.getPlayer().move(0.f, -player.getVelocity());
	}
	if (Keyboard::isKeyPressed(Keyboard::S) && player.getPlayer().getPosition().y + player.getPlayer().getSize().y < window.getSize().y) {
		player.getPlayer().move(0.f, player.getVelocity());
	}
	if (Mouse::isButtonPressed(Mouse::Left) && player.getKeytime() > 8) {
		Bullet bullet(3, player.getPlayer().getPosition().x + player.getPlayer().getSize().x / 4, player.getPlayer().getPosition().y + player.getPlayer().getSize().y / 4, (Mouse::getPosition(window).x - player.getPlayer().getPosition().x) / sqrt(pow(Mouse::getPosition(window).x - player.getPlayer().getPosition().x, 2) + pow(Mouse::getPosition(window).y - player.getPlayer().getPosition().y, 2)), (Mouse::getPosition(window).y - player.getPlayer().getPosition().y) / sqrt((pow(Mouse::getPosition(window).x - player.getPlayer().getPosition().x, 2) + pow(Mouse::getPosition(window).y - player.getPlayer().getPosition().y, 2))), 10, Color::White);
		bullets.push_back(bullet);
		player.setKeytime(0);
		//cout<< (Mouse::getPosition(window).x - player.getPosition().x) / sqrt(pow(Mouse::getPosition(window).x - player.getPosition().x, 2) + pow(Mouse::getPosition(window).y - player.getPosition().y, 2))<<" "<< (Mouse::getPosition(window).y - player.getPosition().y) / sqrt((pow(Mouse::getPosition(window).x - player.getPosition().x, 2) + pow(Mouse::getPosition(window).y - player.getPosition().y, 2)))<<endl;
	}
}

void updateEnemies(RenderWindow& window, vector <Zombie>& zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons, vector <Bullet>& enemyBullets, Player player) {
	float destinationX, destinationY;

	for (int i = 0; i < zombies.size(); i++) {
		destinationX = -(zombies[i].getEnemy().getPosition().x - player.getPlayer().getPosition().x) / sqrt(pow(zombies[i].getEnemy().getPosition().x - player.getPlayer().getPosition().x, 2) + pow(zombies[i].getEnemy().getPosition().y - player.getPlayer().getPosition().y, 2));
		destinationY = -(zombies[i].getEnemy().getPosition().y - player.getPlayer().getPosition().y) / sqrt(pow(zombies[i].getEnemy().getPosition().x - player.getPlayer().getPosition().x, 2) + pow(zombies[i].getEnemy().getPosition().y - player.getPlayer().getPosition().y, 2));
		zombies[i].getEnemy().move(destinationX * zombies[i].getVelocity(), destinationY * zombies[i].getVelocity());
	}
	for (int i = 0; i < mutants.size(); i++) {
		destinationX = -(mutants[i].getEnemy().getPosition().x - player.getPlayer().getPosition().x) / sqrt(pow(mutants[i].getEnemy().getPosition().x - player.getPlayer().getPosition().x, 2) + pow(mutants[i].getEnemy().getPosition().y - player.getPlayer().getPosition().y, 2));
		destinationY = -(mutants[i].getEnemy().getPosition().y - player.getPlayer().getPosition().y) / sqrt(pow(mutants[i].getEnemy().getPosition().x - player.getPlayer().getPosition().x, 2) + pow(mutants[i].getEnemy().getPosition().y - player.getPlayer().getPosition().y, 2));
		mutants[i].getEnemy().move(destinationX * mutants[i].getVelocity(), destinationY * mutants[i].getVelocity());
	}
	for (int i = 0; i < skeletons.size(); i++) {

		//provjerava jeli skeleton dosa do destinacije, ako je daje mu novu destinaciju
		if (abs(skeletons[i].getEnemy().getPosition().x - skeletons[i].getDestX()) < 10 && abs(skeletons[i].getEnemy().getPosition().y - skeletons[i].getDestY()) < 10) {
			skeletons[i].setDestX(rand() % window.getSize().x);
			skeletons[i].setDestY(rand() % window.getSize().y);
			skeletons[i].setMoveX(-(skeletons[i].getEnemy().getPosition().x - skeletons[i].getDestX()) / sqrt(pow(skeletons[i].getEnemy().getPosition().x - skeletons[i].getDestX(), 2) + pow(skeletons[i].getEnemy().getPosition().y - skeletons[i].getDestY(), 2)));
			skeletons[i].setMoveY(-(skeletons[i].getEnemy().getPosition().y - skeletons[i].getDestY()) / sqrt(pow(skeletons[i].getEnemy().getPosition().x - skeletons[i].getDestX(), 2) + pow(skeletons[i].getEnemy().getPosition().y - skeletons[i].getDestY(), 2)));
		}
		//ako nije dosa, nastavlja ic u tom smijeru
		else {
			skeletons[i].getEnemy().move(skeletons[i].getMoveX(), skeletons[i].getMoveY());
		}
		//provjerava jel skeleton moze pucat
		if (skeletons[i].getKeytime() > 30) {
			//sivi metak
			Bullet bullet(3, skeletons[i].getEnemy().getPosition().x + skeletons[i].getEnemy().getSize().x / 4, skeletons[i].getEnemy().getPosition().y + skeletons[i].getEnemy().getSize().y / 4, (player.getPlayer().getPosition().x - skeletons[i].getEnemy().getPosition().x) / sqrt(pow(player.getPlayer().getPosition().x - skeletons[i].getEnemy().getPosition().x, 2) + pow(player.getPlayer().getPosition().y - skeletons[i].getEnemy().getPosition().y, 2)), (player.getPlayer().getPosition().y - skeletons[i].getEnemy().getPosition().y) / sqrt((pow(player.getPlayer().getPosition().x - skeletons[i].getEnemy().getPosition().x, 2) + pow(player.getPlayer().getPosition().y - skeletons[i].getEnemy().getPosition().y, 2))), 5, Color::Color(148, 148, 148));
			enemyBullets.push_back(bullet);
			skeletons[i].setKeytime(0);
		}
		skeletons[i].incrementKeytime();
	}
}

void updateBullets(vector <Bullet>& bullets, vector <Bullet>& enemyBullets) {
	int bulletsLen = bullets.size();
	int enemyBulletsLen = enemyBullets.size();
	for (int i = 0; i < bulletsLen; i++) {
		bullets[i].getBullet().move(bullets[i].getDirX() * bullets[i].getVelocity(), bullets[i].getDirY() * bullets[i].getVelocity());
	}
	for (int i = 0; i < enemyBulletsLen; i++) {
		enemyBullets[i].getBullet().move(enemyBullets[i].getDirX() * enemyBullets[i].getVelocity(), enemyBullets[i].getDirY() * enemyBullets[i].getVelocity());
	}
}

void checkCollision(Player& player, vector <Zombie>& zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons, vector <Bullet>& bullets, vector <Bullet>& enemyBullets, RenderWindow& window) {
	int bulletX, bulletY, enemyX, enemyY, enemySize;

	if (bullets.size()) {
		//Kill Zombies
		int bulletRadius = bullets[0].getBullet().getRadius();
		for (int i = 0; i < zombies.size(); i++) {
			enemyX = zombies[i].getEnemy().getPosition().x + zombies[i].getEnemy().getSize().x / 2;
			enemyY = zombies[i].getEnemy().getPosition().y + zombies[i].getEnemy().getSize().y / 2;
			enemySize = zombies[i].getEnemy().getSize().x;
			for (int j = 0; j < bullets.size(); j++) {
				bulletX = bullets[j].getBullet().getPosition().x + bullets[j].getBullet().getRadius();
				bulletY = bullets[j].getBullet().getPosition().y + bullets[j].getBullet().getRadius();
				if (enemySize > sqrt(pow(enemyX - bulletX, 2) + pow(enemyY - bulletY, 2))) {
					zombies.erase(zombies.begin() + i);
					bullets.erase(bullets.begin() + j);
					player.increasePoints(1);
					cout << "points: " << player.getPoints() << endl;
					break;
				}
			}
		}
		//Kill Mutants
		for (int i = 0; i < mutants.size(); i++) {
			enemyX = mutants[i].getEnemy().getPosition().x;
			enemyY = mutants[i].getEnemy().getPosition().y;
			enemySize = mutants[i].getEnemy().getSize().x;
			for (int j = 0; j < bullets.size(); j++) {
				bulletX = bullets[j].getBullet().getPosition().x;
				bulletY = bullets[j].getBullet().getPosition().y;
				if ((bulletX > enemyX && bulletX < (enemyX + enemySize)) && (bulletY > enemyY && bulletY < (enemyY + enemySize))) {
					bullets.erase(bullets.begin() + j);
					mutants[i].decrementHealth();
					if (mutants[i].getHealth() < 1) {
						mutants.erase(mutants.begin() + i);
						player.increasePoints(5);
						cout << "points: " << player.getPoints() << endl;
					}
					break;
				}
			}
		}
		//Kill Skeletons
		for (int i = 0; i < skeletons.size(); i++) {
			enemyX = skeletons[i].getEnemy().getPosition().x;
			enemyY = skeletons[i].getEnemy().getPosition().y;
			enemySize = skeletons[i].getEnemy().getSize().x;
			for (int j = 0; j < bullets.size(); j++) {
				bulletX = bullets[j].getBullet().getPosition().x;
				bulletY = bullets[j].getBullet().getPosition().y;
				if ((bulletX > enemyX && bulletX < (enemyX + enemySize)) && (bulletY > enemyY && bulletY < (enemyY + enemySize))) {
					bullets.erase(bullets.begin() + j);
					skeletons.erase(skeletons.begin() + i);
					player.increasePoints(3);
					cout << "points: " << player.getPoints() << endl;
					break;
				}
			}
		}
		//Delete Bullets
		for (int i = 0; i < bullets.size(); i++) {
			if (bullets[i].getBullet().getPosition().x + 3 < 0 || bullets[i].getBullet().getPosition().x + 3 > window.getSize().x || bullets[i].getBullet().getPosition().y + 3 < 0 || bullets[i].getBullet().getPosition().y + 3 > window.getSize().y) {
				bullets.erase(bullets.begin() + i);
			}
		}
		for (int i = 0; i < enemyBullets.size(); i++) {
			if (enemyBullets[i].getBullet().getPosition().x + 3 < 0 || enemyBullets[i].getBullet().getPosition().x + 3 > window.getSize().x || enemyBullets[i].getBullet().getPosition().y + 3 < 0 || enemyBullets[i].getBullet().getPosition().y + 3 > window.getSize().y) {
				enemyBullets.erase(enemyBullets.begin() + i);
			}
		}
	}
	//Kill Player
	if (player.getPlayerHealthPause())
		player.decrementPlayerHealthPause();
	else {
		player.getPlayer().setFillColor(Color::Green);
	}

	if (!player.getPlayerHealthPause()) {
		int playerX = player.getPlayer().getPosition().x, playerY = player.getPlayer().getPosition().y, playerSize = player.getPlayer().getSize().x;
		//provjera zombija i igraca
		for (int i = 0; i < zombies.size(); i++) {
			enemyX = zombies[i].getEnemy().getPosition().x;
			enemyY = zombies[i].getEnemy().getPosition().y;

			if (abs(playerX - enemyX) < playerSize && abs(playerY - enemyY) < playerSize) {
				player.getPlayer().setFillColor(Color::Magenta);
				player.decrementHealth();
				player.setPlayerHealthPause();
			}
		}
		//provjera mutanta i igraca
		for (int i = 0; i < mutants.size(); i++) {
			enemyX = mutants[i].getEnemy().getPosition().x;
			enemyY = mutants[i].getEnemy().getPosition().y;

			if (abs(playerX - enemyX) < playerSize && abs(playerY - enemyY) < playerSize) {
				player.getPlayer().setFillColor(Color::Magenta);
				player.decrementHealth();
				player.setPlayerHealthPause();
			}
		}
		//provjera skeletonovih metaka i igraca
		for (int i = 0; i < enemyBullets.size(); i++) {
			bulletX = enemyBullets[i].getBullet().getPosition().x;
			bulletY = enemyBullets[i].getBullet().getPosition().y;
			if ((bulletX > playerX && bulletX + 3 < (playerX + playerSize)) && (bulletY > playerY && bulletY + 3 < (playerY + playerSize))) {
				enemyBullets.erase(enemyBullets.begin() + i);
				player.getPlayer().setFillColor(Color::Magenta);
				player.decrementHealth();
				player.setPlayerHealthPause();
				break;
			}
		}
	}
}

Font inputFont() {
	Font font;
	font.loadFromFile("Dosis-Light.ttf");
	return font;
}

void inputLives(Text* lives, Font font, Player player) {
	lives->setFont(font);
	lives->setString(to_string(player.getHealth()));
	lives->setCharacterSize(20);
	lives->setFillColor(Color::Red);
	lives->setStyle(Text::Bold);
	lives->setPosition(10, 10);
}

bool checkEndWave(vector <Zombie>& zombies, vector <Mutant>& mutants, vector <Skeleton>& skeletons) {
	int zombieCount = zombies.size();
	int mutantCount = mutants.size();
	int skeletonCount = skeletons.size();
	if (!zombieCount && !mutantCount && !skeletonCount) {
		return true;
	}
	return false;
}

void updateText(Text& lives, Text& score, Player player) {
	score.setString(to_string(player.getPoints()));
	lives.setString(to_string(player.getHealth()));
}
