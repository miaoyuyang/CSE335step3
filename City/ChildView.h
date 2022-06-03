/**
* \file ChildView.h
*
* \author Charles B. Owen
*
*  Class that implements the child window our program draws in.
*
* The window is a child of the main frame, which holds this
* window, the menu bar, and the status bar.
*/

#pragma once

#include "City.h"
#include "PointHistory.h"

class CTile;

/**  The child window our program draws in. */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
    void AddBuilding(const std::wstring &file);
    void AddLandscape(const std::wstring &file);


    /// The city
    CCity   mCity;

    /// True until the first time we draw
    bool mFirstDraw = true;

    long long mLastTime;    ///< Last time we read the timer
    double mTimeFreq;       ///< Rate the timer updates

    /// Any item we are currently dragging
    std::shared_ptr<CTile> mGrabbedItem;

    std::unique_ptr<Gdiplus::Bitmap> mTrashcan; ///< Trashcan image to use
    int mTrashcanTop = 0;           ///< Top line of the trashcan in pixels
    int mTrashcanRight = 0;         ///< Right side of the trashcan in pixels

	CPointHistory mMouseHistory;	///< Mouse movement history

    bool mShowHistory = false;   ///< initials the history of mouse 

    bool mPruning = false;     ///< initials pruning the garden

public:
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
    afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
    afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
    afx_msg void OnMouseMove(UINT nFlags, CPoint point);
    afx_msg void OnTimer(UINT_PTR nIDEvent);
    afx_msg void OnFileOpen();
    afx_msg void OnFileSaveas();

    /** \cond */
    afx_msg void OnBuildingsFarmhouse();
    afx_msg void OnLandscapingGrass();
    afx_msg void OnLandscapingSpartystatue();
    afx_msg void OnBuildingsBlacksmithshop();
    afx_msg void OnLandscapingTallgrass();
    afx_msg void OnBuildingsBrownhouse();
    afx_msg void OnBuildingsYellowhouse();
    afx_msg void OnBuildingsF();
    afx_msg void OnBuildingsHospital();
    afx_msg void OnBuildingsMarket();
    afx_msg void OnBuildingsCondos();
    afx_msg void OnLandscapingTree();
    afx_msg void OnLandscapingTrees();
    afx_msg void OnLandscapingBigtrees();
    afx_msg void OnLandscapingRoad();
    afx_msg void OnBusinessesCoalmine();
    /** \endcond */

    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    /// track the mouse trace and keep in history
    afx_msg void OnViewMousehistory();
    /** keep tracking
    *\param pCmdUI */
    afx_msg void OnUpdateViewMousehistory(CCmdUI* pCmdUI);
    /// the number of building
    afx_msg void OnBuildingsCount();
    /// the garden
    afx_msg void OnLandscapingGarden();
    ///prune the garden
    afx_msg void OnGardenPrune();
    /**prune all garden
    *\param pCmdUI*/
    afx_msg void OnUpdateGardenPrune(CCmdUI* pCmdUI);
    /// prune all garden
	afx_msg void OnGardenPruneall();
};

