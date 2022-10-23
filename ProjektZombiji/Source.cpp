#include "game.h"

int main() {
	srand(time(NULL));
	RenderWindow window(VideoMode(800, 600), "Zombie Shooter");
	window.setFramerateLimit(30);

	int difficulty = 10;

	Player player(window.getSize().x, window.getSize().y);
	vector <Bullet> bullets;
	vector <Bullet> enemyBullets;
	vector <Zombie> zombies;
	vector <Mutant> mutants;
	vector <Skeleton> skeletons;
	Event event;
	Font font;
	Text endText, score, lives;
	inputEnemies(window, zombies, mutants, skeletons, player, difficulty);
	font.loadFromFile("Calibri Regular.ttf");

	inputLives(&lives, font, player);

	score.setFont(font);
	score.setString(to_string(player.getPoints()));
	score.setCharacterSize(20);
	score.setFillColor(sf::Color::Red);
	score.setStyle(sf::Text::Bold);
	score.setPosition(30, 10);

	while (window.isOpen() && player.getHealth()) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		keyboardInput(player, window, bullets);
		updateEnemies(window, zombies, mutants, skeletons, enemyBullets, player);
		updateBullets(bullets, enemyBullets);
		updateText(lives, score, player);
		checkCollision(player, zombies, mutants, skeletons, bullets, enemyBullets, window);
		if (checkEndWave(zombies, mutants, skeletons)) {
			inputEnemies(window, zombies, mutants, skeletons, player, difficulty);
			difficulty += 5;
		}

		refresh(window, player, zombies, mutants, skeletons, bullets, enemyBullets, lives, score);
	}
	endText.setFont(font);
	endText.setString("Game over!");
	endText.setCharacterSize(166);
	endText.setFillColor(sf::Color::White);
	endText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	endText.setPosition(window.getSize().x / 2 - endText.getLocalBounds().width / 2, window.getSize().y / 2 - endText.getLocalBounds().height / 2);

	window.draw(endText);
	window.display();

	while (1) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
	}
}