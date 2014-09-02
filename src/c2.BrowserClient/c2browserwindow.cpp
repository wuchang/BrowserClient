#include "stdafx.h"
#include "c2browserwindow.h"

 C2BrowserWindow::C2BrowserWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->resize(600, 300);

	this->view = new C2WebView(this);
	this->view->setObjectName("view");
	this->setCentralWidget(this->view);

	QWebFrame *frame = view->page()->mainFrame();
	connect(frame, &QWebFrame::javaScriptWindowObjectCleared, this, &C2BrowserWindow::populateJavaScriptWindowObject);
	//this->populateJavaScriptWindowObject();

	this->view->load(QUrl("http://baidu.com"));

	//connect(view,view->)

	this->javaScriptWindowObject = new JavaScriptWindowObject(this,this
		);

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


//QWebView *	C2BrowserWindow::createWindow(QWebPage::WebWindowType type)
//{
//	  return NULL;
//}