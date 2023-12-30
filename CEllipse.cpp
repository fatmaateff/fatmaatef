#include "CEllipse.h"
CEllipse::CEllipse(Point P1, Point P2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	pointone = P1;
	pointtwo = P2;
}


void CEllipse::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawRect to draw a Square on the screen	
	pGUI->DrawEllipse(pointone, pointtwo, FigGfxInfo, Selected);
}

bool CEllipse::IsPointInside(int x, int y)
{
    // Calculate the normalized coordinates relative to the center
    double normalizedX = (x - (pointone.x + pointtwo.x) / 2.0) / ((pointtwo.x - pointone.x) / 2.0);
    double normalizedY = (y - (pointone.y + pointtwo.y) / 2.0) / ((pointtwo.y - pointone.y) / 2.0);

    // Check if the point satisfies the ellipse equation
    return (normalizedX * normalizedX + normalizedY * normalizedY) <= 1.0;
}

//omar return the details