#pragma once
#include"Scene.h"
#include<vector>
class SceneReader
{
private:
	int m_currentSceneId=-1;
	int m_currentPromptId = -1;
	int m_numPrompts=0;
	bool isPrompting=false;
	vector <Scene*> prompts;

public:
	SceneReader();
	void HandleChoices(int size,Scene* scene,int&loopint, vector<Scene*> scenes);
	void ReadScenes(const vector<Scene*>& scenes);
};
