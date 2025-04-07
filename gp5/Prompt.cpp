#include"Prompt.h"

//default constructor
Prompt::Prompt()
{
	this->prompt_text = "";
	this->id = -1;
}

//Scene constructor, default initialization
Prompt::Prompt(string text, int id)
{
	this->prompt_text = text;
	this->id = id;
	
}

//copy constructor
Prompt::Prompt(const Prompt& scene)
{
	this->id = scene.id;
	this->prompt_text = scene.prompt_text;
}


//get  prompt text
string Prompt::getPrompt()const
{
	return this->prompt_text;
}

//set prompt text
void Prompt::setPrompt(string str)
{
	this->prompt_text = str;
}

//set scene to forward to
void Prompt::setPointingScene(int n)
{
	this->points_to_scene = n;
}


//get what the scene/prompt points to next
int Prompt::getPointingScene()const
{
	return this->points_to_scene;
}


int Prompt::getId() const
{
	return this->id;
}

void Prompt::setId(int n)
{
	this->id = n;
}