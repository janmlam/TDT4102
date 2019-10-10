#include "GameObjects.h"

#include "cannonball.h"
#include <cmath>

// implement all (member) functions in this file
Target::Target(double size, double position) {
	this->size = size;
	this->position = position;
	shape = sf::RectangleShape(sf::Vector2f(50., 20.));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(110, 60);
}

void Target::update() {

}

void Target::draw(sf::RenderWindow & window) {
	window.draw(shape);
}


bool hitTarget(const Cannonball& c, const Target& t) {
    return c.shape.getGlobalBounds().intersects(t.shape.getGlobalBounds());
}

double Cannonball::getPosX() const {
    // write your code here,
    // and change the return value
    return 0;
}

double Cannonball::getPosY() const {
    // write your code here,
    // and change the return value
    return 0;
}

bool Cannonball::hasLanded() const {
    return getPosY() + size < 0;
}

double Cannonball::getAirTime() const {
    return SPEED_FACTOR*clock.getElapsedTime().asSeconds();
}

double Cannon::getTipX() const {
    return length*cos(degToRad(theta));
}

double Cannon::getTipY() const {
    return length*sin(degToRad(theta));
}
