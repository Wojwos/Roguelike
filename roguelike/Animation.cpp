#include "Animation.h"
#include <iostream>

Animation::Animation()
{
	playedOnce = false;
}

void Animation::setFrames(std::vector<sf::IntRect*> *frames)
{
	this->frames = frames;
	currentFrame = 0;
	playedOnce = false;
}

void Animation::setDelay(long d)
{
	delay = d;
}

void Animation::setFrame(int i)
{
	currentFrame = i;
}

void Animation::update() 
{
	if (delay == -1) return;
	long elapsed = clock.getElapsedTime().asMilliseconds();
	if (elapsed > delay) 
	{
		currentFrame++;
		clock.restart();
	}
	if (currentFrame == frames->size()) 
	{
		currentFrame = 0;
		playedOnce = true;
	}
}

bool Animation::hasPlayedOnce()
{
	return playedOnce;
}

sf::IntRect* Animation::getImage()
{ 
	return frames->at(currentFrame); 
}

int Animation::getFrame()
{
	return currentFrame;
}