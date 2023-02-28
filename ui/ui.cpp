#include "include/ui.hpp"

UserInterface::UserInterface()
{
	CreateToolBar()
	
}

void UserInterface::CreateToolBar()
{
	// set toolbar
	tool_bar = addToolBar(Qt::LeftToolBarArea, "ToolBar");

	// property
	tool_bar->setMovable(false); 
}
