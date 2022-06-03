#pragma once
#include "TileVisitor.h"
/**Class for count buildings*/
class CBuildingCounter :
	public CTileVisitor
{
public:
    /** Get the number of buildings
     * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }

    void CBuildingCounter::VisitBuilding(CTileBuilding* building);

private:
    /// Buildings counter
    int mNumBuildings = 0;
};

