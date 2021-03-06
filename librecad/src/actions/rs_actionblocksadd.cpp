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

#include "rs_actionblocksadd.h"

#include <QAction>
#include "rs_graphic.h"
#include "rs_dialogfactory.h"


RS_ActionBlocksAdd::RS_ActionBlocksAdd(RS_EntityContainer& container,
                                       RS_GraphicView& graphicView)
        :RS_ActionInterface("Add Block", container, graphicView) {}



QAction* RS_ActionBlocksAdd::createGUIAction(RS2::ActionType /*type*/, QObject* /*parent*/) {
	QAction* action = new QAction(QIcon(":/ui/blockadd.png"), tr("&Add Block"), nullptr);
	action->setData(RS2::ActionBlocksAdd);
    return action;
}



void RS_ActionBlocksAdd::trigger() {
    RS_DEBUG->print("adding block");
	if (graphic!=nullptr) {
		RS_BlockList* blockList = graphic->getBlockList();
		if (blockList!=nullptr) {
			RS_BlockData d = 
				RS_DIALOGFACTORY->requestNewBlockDialog(blockList);
			if (d.isValid()) {
        		graphic->addBlock(new RS_Block(container, d));
			}
		}
    }
    finish(false);
}



void RS_ActionBlocksAdd::init(int status) {
    RS_ActionInterface::init(status);
    trigger();
}

// EOF
