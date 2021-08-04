#include "AddORgate3.h"
#include "..\ApplicationManager.h"

AddORgate3::AddORgate3(ApplicationManager* pApp) :Action(pApp)
{
}

AddORgate3::~AddORgate3(void)
{
}

void AddORgate3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	if (pManager->ComponentHere(Cx, Cy))
	{
		pOut->PrintMsg("Cannot add a component here");
		return;
	}
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	OR3* pA = new OR3(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddORgate3::Undo()
{}

void AddORgate3::Redo()
{}

