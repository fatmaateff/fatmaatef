#include "ActionSwitchToDraw.h"
#include "..\ProjectTeamMerge - 3\GUI\GUI.h"
// #include "ActionLoad.h"
#include "ApplicationManager.h"

ActionSwitchToDraw::ActionSwitchToDraw(ApplicationManager* pApp) :Action(pApp)
{}

//Execute the action
void ActionSwitchToDraw::Execute()
{
	//Get a Pointer to the Interface
	GUI* pGUI = pManager->GetGUI();
	pGUI->ClearToolBar();
	pGUI->CreateDrawToolBar();
	//if (UI.InterfaceMode == MODE_PLAY) {
		//Action* loadAct = new ActionLoad(pManager, 1);
		//loadAct->Execute();
	// }

	pGUI->PrintMessage("Back to Draw mode");
	UI.InterfaceMode = MODE_DRAW;

}
