//Micah Mckanstry
//PC
#include"definitions.h"
#include"SceneHandler.h"
#include"Scene.h"
#include"SceneReader.h"
#include<iostream>
int main()
{
	/*
	seeding random to choose random choice
	this will only occur if invalid input is
	given for a choice.
	*/
	srand(time(0));

	vector <Scene*> Scenes;
	StoryEngine::GetScenes(Scenes);
	StoryEngine::RunSceneSequence(Scenes);
	StoryEngine::DeallocateMem(Scenes);
}