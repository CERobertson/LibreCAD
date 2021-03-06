/****************************************************************************
**
** This file is part of the LibreCAD project, a 2D CAD program
**
** Copyright (C) 2010 R. van Twisk (librecad@rvt.dds.nl)
** Copyright (C) 2001-2003 RibbonSoft. All rights reserved.
**
**
** This file may be distributed and/or modified under the terms of the
** GNU General Public License version 2 as published by the Free Software 
** Foundation and appearing in the file gpl-2.0.txt included in the
** packaging of this file.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
**
** This copyright notice MUST APPEAR in all copies of the script!  
**
**********************************************************************/

#ifndef RS_ACTIONDRAWLINETANGENT1_H
#define RS_ACTIONDRAWLINETANGENT1_H

#include "rs_previewactioninterface.h"

class RS_Line;
/**
 * This action class can handle user events to draw tangents from points
 * to circles.
 *
 * @author Andrew Mustun
 */
class RS_ActionDrawLineTangent1 : public RS_PreviewActionInterface {
	Q_OBJECT
private:
    enum Status {
        SetPoint,     /**< Choose the startpoint. */
        SetCircle      /**< Choose the circle / arc. */
    };

public:
    RS_ActionDrawLineTangent1(RS_EntityContainer& container,
                              RS_GraphicView& graphicView);
	~RS_ActionDrawLineTangent1()=default;

    static QAction* createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/);

    virtual RS2::ActionType rtti() const{
        return RS2::ActionDrawLineTangent1;
    }

    virtual void trigger();
	
    virtual void mouseMoveEvent(QMouseEvent* e);
    virtual void mouseReleaseEvent(QMouseEvent* e);
	
	virtual void coordinateEvent(RS_CoordinateEvent* e);
	
    virtual void updateMouseButtonHints();
    virtual void updateMouseCursor();
//    virtual void updateToolBar();

private:
    /** Closest tangent. */
    RS_Line* tangent;
    /** Chosen startpoint */
    RS_Vector point;
    /** Chosen entity */
    RS_Entity* circle;
	const std::vector<RS2::EntityType> circleType={RS2::EntityArc,RS2::EntityCircle,
												   RS2::EntityEllipse, RS2::EntitySplinePoints
												  };
};

#endif
