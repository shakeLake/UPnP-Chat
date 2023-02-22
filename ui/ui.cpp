#include "ui.hpp"

UserInterface::UserInterface()
{
	// createToolBar()
	
}

void UserInterface::createToolBar()
{
	// set toolbar
	tool_bar = addToolBar("ToolBar");

	// property
	tool_bar->setMovable(false); 

	// widgets
	tool_bar->addWidget(ip_label);
	tool_bar->addWidget(disconnect_button)	
}
