#include "stdafx.h"
#include "appcontext.h"

#include <qmutex.h>

AppContext* AppContext::instance = NULL;

AppContext::AppContext()
{
	this->config = new C2Config();
 }

AppContext::~AppContext()
{
	delete this->config;
 }

AppContext* AppContext::Current()
{
	if (instance==NULL)
	{
		instance = new AppContext();
	}
	return instance;
}

//ÅäÖÃ
C2Config* AppContext::Config()
{
	return this->config;
}
 