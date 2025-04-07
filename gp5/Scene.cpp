//Handle Individual scenes and store them for later usage.

#include"Scene.h"
#include<iostream>
#include<string>
using namespace std;

//default constructor
Scene::Scene()
{
	this->text = "";
	this->id = -1;
}

//Scene constructor, default initialization
Scene::Scene(string text,int id)
{
	this->text = text;
	this->id = id;
}

//copy constructor
Scene::Scene(const Scene& scene)
{
	this->text = scene.text;
	this->id = scene.id;
}



//display scene
void Scene::display()const
{
	cout << this->text << endl;
}




//set scene to forward to
void Scene::setPointingScene(int n)
{
	this->points_to_scene = n;
}

//set termination state
void Scene::setTermState(bool state)
{
	this->terminatedScene = state;
}

//get what the scene/prompt points to next
int Scene::getPointingScene()const
{
	return this->points_to_scene;
}

//get termination state
bool Scene::getTermState()const
{
	return this->terminatedScene;
}

int Scene::getId()const
{
	return this->id;
}

void Scene::setId(int n)
{
	this->id = n;
}
void Scene::addPrompt(Prompt* prompt)
{
	this->prompts.push_back(prompt);
}

//get number of prompts
int Scene::nPrompts()
{
	return this->prompts.size();
}

Prompt* Scene::getPrompt(int x)
{
	return this->prompts[x];
}