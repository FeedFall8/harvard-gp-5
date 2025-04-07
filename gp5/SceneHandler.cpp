#include"definitions.h"
#include"SceneHandler.h"
#include"SceneReader.h"
#include<assert.h>
#include<vector>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
bool StoryEngine::isInt(string nstring)
{
	bool valid = true;

	for (char n : nstring) {
		if (!(NUMS.find(n) != std::string::npos))
		{
			valid = false;
		}
	}

	return valid;
}
void StoryEngine::SetTermination(vector<Scene*>& scenes)
{
	//go to back of vector and set most recent
	//processed scene to terminate
	Scene* scene = scenes.back();
	
	scene->setTermState(true);
	

}


void StoryEngine::MakePrompt(vector<Scene*>& scenes, ifstream& textstream, char arg)
{
	string text;
	char get = '\0';
	do
	{

		get = textstream.get();
		switch (get)
		{
		case COMMAND:
			break;
		case FANCYQUOTE || FANCYQUOTE2:
			text += '"';
			break;
		default:
			text += get;
			break;
		}


	} while (get != COMMAND && !textstream.eof() && get!=NEWLINE);
	string num;

	do{
		get = textstream.get();
	}while (get == NEWLINE);
	textstream.putback(get);
	

	textstream >> num;
	
	if (isInt(num))
	{
		Scene* scene = scenes.back();
		
		int arg_new = stoi(num);
		string get_n(num);
		int pointingScene = stoi(get_n);
		Prompt* prompt= new Prompt(text, arg_new);
		prompt->setPointingScene(pointingScene);
		prompt->setPrompt(text);
		scene->addPrompt(prompt);
	}
	else
	{
		cout << "There was an issue creating a prompt.";
		
	}
	
	
	
	
}
void StoryEngine::MakeScene(vector<Scene*> &scenes, ifstream& textstream,char arg,string arg3)
{
	
	string text = "";
	char get = '\0';
	//remove whitespace
	get = textstream.get();
	do
	{
		get = textstream.get();
		switch (get)
		{
		case COMMAND:
			textstream.putback(COMMAND);
			break;
		case FANCYQUOTE || FANCYQUOTE2:
			text += '"';
			break;
		default:
			text += get;
			break;
		}
		
		
	} while (get != COMMAND && !textstream.eof());
	string num(1,arg);
	if (arg3 != to_string('\0'))num = arg3;
	int arg_new = stoi(num);
	scenes.push_back(new Scene(text,arg_new));
}

void StoryEngine::handleCommand(string cmd, ifstream& stream, vector<Scene*>& scenes)
{
	//if string is a command
	
	if (cmd.rfind(COMMAND) != string::npos)
	{
		
		char arg1 = cmd[1];
		char arg2 = cmd[2];
		string  arg3 = to_string('\0');
		if (cmd.length() > 3)
		{
			arg3 = cmd;
			arg3.erase(0, 2);
			
		}

		switch (arg1)
		{
		case SCENE:
			MakeScene(scenes, stream,arg2,arg3);
			break;
		case PROMPT:
			MakePrompt(scenes, stream, arg2);
			break;
		case END:
			SetTermination(scenes);
			break;
		default:
			break;
		}

	}
}

void StoryEngine::GetScenes(vector <Scene*> & Scenes)
{
	ifstream file;
	file.open(PATH_TO_STORY);
	if (file.fail())
	{
		cout << "Failed to open:" << PATH_TO_STORY << endl;
	}
	else
	{
		while (!file.eof())
		{
			string reader;
			file >> reader;
			
			handleCommand(reader, file, Scenes);
		}
	}
}

void StoryEngine::RunSceneSequence(vector <Scene*>& Scenes)
{

	SceneReader EngineReader;
	EngineReader.ReadScenes(Scenes);
}

void StoryEngine::DeallocateMem(vector <Scene*>& Scenes)
{
	for (Scene* scene : Scenes)
	{
		if (scene->nPrompts() > 0) 
		{
			for (int x=0; x< scene->nPrompts();x++ )
			{
				Prompt* prompt = scene->getPrompt(x);
				if (prompt)
				{
					delete prompt;
					prompt = nullptr;
				}
			}
		}
		if (scene)
		{
			delete scene;
			scene = nullptr;
		}
	}
}
