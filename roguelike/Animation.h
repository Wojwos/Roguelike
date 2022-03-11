#ifndef ANIMATIONS_H
#define ANIMATIONS_H

#include "SFML/Graphics.hpp"
#include <vector>

class Animation
{
public:
	Animation();
	void setFrames(std::vector<sf::IntRect*> *frames);
	void setDelay(long d);
	void setFrame(int i);
	void update();
	bool hasPlayedOnce(); 
	sf::IntRect* getImage();
	int getFrame();
	~Animation() {}
private:
	std::vector<sf::IntRect*> *frames;
	int numFrame;
	int currentFrame;
	sf::Clock clock;
	long delay;
	bool playedOnce;
};

#endif
