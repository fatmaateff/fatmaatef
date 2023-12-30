#include "ApplicationManager.h"
#include "GUI\GUI.h"
#include "ActionSwitchToPlay.h"
#include "ActionSwitchToDraw.h"



int main()
{
	/*
	GUI* g=new GUI();
	
	
	window* w=g->CreateWind(200, 300, 10, 10);
	int x, y;
	w->WaitMouseClick(x, y);
	*/
	
	ApplicationManager AppManager;
	//ActionSwitchToPlay switchToPlayAction(&AppManager);
	//switchToPlayAction.Execute();
	AppManager.Run();		
	return 0;
}

