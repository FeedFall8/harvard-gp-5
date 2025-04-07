#include"SceneReader.h"
#include<iostream>
using namespace std;
SceneReader::SceneReader()
{

}

void SceneReader::HandleChoices(int size, Scene* scene,int & loopint,vector<Scene*> scenes)
{
	int x = 0;
	for (int z = 0; z < size; z++)
	{
		Prompt* prompt = scene->getPrompt(z);
		cout << z << ":" << prompt->getPrompt();
		x = z;
		
	}
	int choice;
	cout <<"Make a descision: ";
	if (!(cin >> choice))
	{
		cout << endl << "Invalid input. Chosing for you." << endl;
		choice = rand() % x + 0;
	}
	else if (choice < 0 || choice > x)
	{
		cout << endl << "Choice exceeds current options. Chosing for you." << endl;
		choice = rand() % x + 0;
	}
	else 
	{
		cout << endl;
		Prompt* prompt = scene->getPrompt(choice);
		for (int x = 0; x < scenes.size(); x++)
		{
			if (prompt->getPointingScene() == scenes[x]->getId())
			{
				loopint = x-1;
				break;
			}
		}
		
	}

}
void SceneReader::ReadScenes(const vector<Scene*>& scenes)
{
	for (int i = 0; i < scenes.size(); i++)
	{
		Scene* scene = scenes[i];
		//if this scene contains prompts
		scene->display();
		if (scene->getTermState())
		{
			cout << "The End." << endl;
			exit(0);
		}
		if (scene->nPrompts() > 0)
		{
			HandleChoices(scene->nPrompts(), scene, i, scenes);
		}
	}
	
}