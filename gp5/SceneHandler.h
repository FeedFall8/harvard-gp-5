#pragma once
#include<vector>
#include<fstream>
#include<string>
#include"Scene.h"
using namespace std;
namespace StoryEngine
{
	
	//see if a string int is a valid integer
	bool isInt(string nstring);

	//set the termination scene
	void SetTermination(vector<Scene*>& scenes);

	//Create Prompt
	void MakePrompt(vector<Scene*>& scenes, ifstream& textstream, char arg);

	//Create Scenes
	void MakeScene(vector<Scene*> &scenes, ifstream& textstream,char arg,string arg3);

	//Handle command input from story file
	void handleCommand(string cmd, ifstream& stream, vector<Scene*> &scenes);

	//fill scenes vector
	void GetScenes(vector <Scene*>& Scenes);

	//begin story.
	void RunSceneSequence(vector <Scene*>& Scenes);
	void DeallocateMem(vector <Scene*>& Scenes);
}