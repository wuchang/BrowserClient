#include "stdafx.h"
#include "c2config.h"

C2Config::C2Config()
{
	this->setting = new QSettings("./config.ini", QSettings::IniFormat);
}

C2Config::~C2Config()
{

}

QString C2Config::GetStartUrl()
{
 QString url=	this->setting->value("main/startUrl", "about:blank").toString();
 return url;
}