/*
	This source file is part of Rigs of Rods
	Copyright 2005-2012 Pierre-Michel Ricordel
	Copyright 2007-2012 Thomas Fischer
	Copyright 2013-2014 Petr Ohlidal

	For more information, see http://www.rigsofrods.org/

	Rigs of Rods is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License version 3, as
	published by the Free Software Foundation.

	Rigs of Rods is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Rigs of Rods. If not, see <http://www.gnu.org/licenses/>.
*/

/** 
	@file   GUIMenu.h
	@date   13th of August 2009
	@author Thomas Fischer thomas{AT}thomasfischer{DOT}biz
*/

#ifdef USE_MYGUI

#pragma once

#include "RoRPrerequisites.h"
#include "Singleton.h"

#include <MyGUI.h>

#include <atomic>

namespace RoR {
namespace GUI {

class TopMenubar : public ZeroedMemoryAllocator
{
public:

	TopMenubar();

	~TopMenubar();

	bool IsVisible();

	void SetVisible(bool value);

	int getMenuHeight()
	{ 
		return m_menu_height; 
	};

	void updatePositionUponMousePosition(int x, int y);

	Ogre::UTFString getUserString(user_info_t &user, int num_vehicles);

	void addUserToMenu(user_info_t &user);

	void triggerUpdateVehicleList();

	void ReflectMultiplayerState();

protected:

	void onVehicleMenu(MyGUI::MenuControl* _sender, MyGUI::MenuItem* _item);

	void onMenuBtn(MyGUI::MenuCtrlPtr _sender, MyGUI::MenuItemPtr _item);

	void vehiclesListUpdate();

	void MenubarShowSpawnerReportButtonClicked(MyGUI::Widget* sender);

	std::vector<MyGUI::PopupMenuPtr> m_popup_menus;
	MyGUI::PopupMenuPtr              m_vehicles_menu_widget;
	MyGUI::MenuBarPtr                m_menubar_widget;
	MyGUI::MenuItem*                 m_item_activate_all;
	MyGUI::MenuItem*                 m_item_never_sleep;
	MyGUI::MenuItem*                 m_item_sleep_all;
	int                              m_menu_width;
	int                              m_menu_height;
	std::atomic<bool>                m_vehicle_list_needs_update;
};

} // namespace GUI
} // namespace RoR

#endif // USE_MYGUI