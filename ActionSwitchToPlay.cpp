#include "ActionSwitchToPlay.h"
// #include "ActionSave.h"
// #include "ActionLoad.h"
#include "..\ProjectTeamMerge - 3\GUI\GUI.h"
#include "ApplicationManager.h"

ActionSwitchToPlay::ActionSwitchToPlay(ApplicationManager* pMan) :Action(pMan)
{

}

void ActionSwitchToPlay::Execute() {

	GUI* pGUI = pManager->GetGUI();
	// Action* newAct = new ActionSave(pManager, 1);
	// pManager->ExecuteAction(newAct);
	pGUI->ClearToolBar();
	pGUI->CreatePlayToolBar();
	pGUI->ClearStatusBar();
	pGUI->PrintMessage("Welcome to play mode :)");

}