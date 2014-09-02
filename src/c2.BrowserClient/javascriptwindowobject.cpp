#include "stdafx.h"
#include "javascriptwindowobject.h"

JavaScriptWindowObject::JavaScriptWindowObject(QObject *parent, QMainWindow *window)
	: QObject(parent)
{
	this->window = window;
	this->setObjectName("c2host");
}

JavaScriptWindowObject::~JavaScriptWindowObject()
{

}

void JavaScriptWindowObject::resize(int w, int h)
{
	if (this->window != NULL)
	{
		this->window->resize(w, h);
	}

}


void JavaScriptWindowObject::alert(const QString msg)
{
	qDebug() << "aliert " << msg;
	QMessageBox::warning(this->window, "提示", msg, QMessageBox::Button::Ok);
}
