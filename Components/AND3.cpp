#include "AND3.h"

AND3::AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void AND3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int first = m_InputPins[0].getStatus();
	int second = m_InputPins[1].getStatus();
	int third = m_InputPins[2].getStatus();
	if (first == 1 && second == 1 && third == 1)
		m_OutputPin.setStatus(HIGH);

	else m_OutputPin.setStatus(LOW);
	//Add you code here
}


// Function Draw
// Draws 2-input OR gate
void AND3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (m_GfxInfo.y1 > UI.ToolBarHeight && m_GfxInfo.y2 < UI.height - UI.StatusBarHeight)
	{
		pOut->DrawAND3(m_GfxInfo, select);
	}
}

//returns status of outputpin
int AND3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int AND3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void AND3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

string AND3::GetComponentType()
{
	return "AND3";
}
