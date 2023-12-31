#include "CHexagon.h"
CHexagon::CHexagon(int *_xCoords, int* _yCoords, int _vertexes, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
    xCoordinates = _xCoords;
    yCoordinates = _yCoords;
	vertexes = _vertexes;
}


void CHexagon::DrawMe(GUI* pGUI) const
{
	//Call Output::DrawHexagon to draw a hexagon on the screen	
	pGUI->DrawHexagon(xCoordinates, yCoordinates, vertexes, FigGfxInfo, Selected);
}

bool CHexagon::IsPointInside(int x, int y)
{
    // Check if the point is within the bounding box of the hexagon
    int minX = *std::min_element(xCoordinates, xCoordinates + vertexes);
    int maxX = *std::max_element(xCoordinates, xCoordinates + vertexes);
    int minY = *std::min_element(yCoordinates, yCoordinates + vertexes);
    int maxY = *std::max_element(yCoordinates, yCoordinates + vertexes);

    if (x < minX || x > maxX || y < minY || y > maxY) {
        return false;  // The point is outside the bounding box
    }

    // Check if the point is inside the hexagon using a ray-casting algorithm
    int crossings = 0;
    for (int i = 0; i < vertexes; ++i) {
        int x1 = xCoordinates[i];
        int y1 = yCoordinates[i];
        int x2 = xCoordinates[(i + 1) % vertexes];
        int y2 = yCoordinates[(i + 1) % vertexes];

        if (((y1 <= y && y < y2) || (y2 <= y && y < y1)) &&
            x < (x2 - x1) * (y - y1) / (y2 - y1) + x1) {
            crossings++;
        }
    }

    // If the number of crossings is odd, the point is inside the hexagon
    return (crossings % 2 == 1);
}

//omar return the details