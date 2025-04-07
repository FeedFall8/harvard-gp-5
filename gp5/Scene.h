#pragma once
#include<string>
#include<vector>
#include"Prompt.h"
using namespace std;
class Scene
{
private:
	string text;
	vector<Prompt*> prompts;
	int id;
	int points_to_scene = 0;
	bool terminatedScene= false;
public:
	Scene();
	Scene(string,int);
	Scene(const Scene&);
	void display()const;
	void setPointingScene(int n);
	void setTermState(bool);
	int getPointingScene()const;
	bool getTermState()const;
	int getId()const;
	void setId(int n);
	void addPrompt(Prompt*);
	int nPrompts();
	Prompt* getPrompt(int);
};