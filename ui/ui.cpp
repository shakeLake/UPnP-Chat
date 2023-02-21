#include "ui.hpp"

UserInterface::UserInterface()
{
	// createToolBar()
	
}

void UserInterface::createToolBar()
{
	// set toolbar
	toolbar = addToolBar("ToolBar");

	// property
	toolbar->setMovable(false); 

	// widgets
	toolbar->addWidget(ipLabe);
	toolbar->addWidget(disconnectButton)	
}
