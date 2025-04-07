
#pragma once
#include<string>
using namespace std;
class Prompt
{
private:
	string prompt_text;
	int id;
	int points_to_scene = 0;
public:
	Prompt();
	Prompt(string, int);
	Prompt(const Prompt&);
	string getPrompt()const;
	void setPrompt(string str);
	void setPointingScene(int n);
	int getPointingScene()const;
	int getId()const;
	void setId(int n);
};