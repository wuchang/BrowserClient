#include "stdafx.h"
#include "c2browserwindow.h"

C2BrowserWindow::C2BrowserWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->resize(600, 300);

	this->view = new C2WebView(this);
	this->view->setObjectName("view");
	this->setCentralWidget(this->view);

	this->javaScriptWindowObject = new JavaScriptWindowObject(this, this
		);

	QWebFrame *frame = view->page()->mainFrame();
	connect(frame, &QWebFrame::javaScriptWindowObjectCleared, this, &C2BrowserWindow::populateJavaScriptWindowObject);
	this->view->load(QUrl("http://baidu.com"));

	//connect(this, &QMainWindow::close(), this, &C2BrowserWindow::onWindowClose)

}

C2BrowserWindow::~C2BrowserWindow()
{

}

void C2BrowserWindow::populateJavaScriptWindowObject()
{
	this->view->page()->mainFrame()->addToJavaScriptWindowObject("winhost", this->javaScriptWindowObject);
}

void C2BrowserWindow::NavToHome()
{
	QString url = AppContext::Current()->Config()->GetStartUrl();
	this->NavTo(url);
}
void C2BrowserWindow::NavTo(QString url)
{
	this->view->load(QUrl(url));
}

C2WebView* C2BrowserWindow::getWebView()
{
	return this->view;
}

void C2BrowserWindow::setExitAppOnClose(bool value)
{
	this->exitAppOnClose = value;
}

//void C2BrowserWindow::onWindowClose()
//{
//
//}

void C2BrowserWindow::closeEvent(QCloseEvent *)
{
	if (this->exitAppOnClose)
	{
		//QMessageBox::warning(this, "TITLE", "close");
		exit(0);
	}
}
//QWebView *	C2BrowserWindow::createWindow(QWebPage::WebWindowType type)
//{
//	  return NULL;
//}