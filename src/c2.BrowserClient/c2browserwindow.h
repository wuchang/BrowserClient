#ifndef C2BROWSERWINDOW_H
#define C2BROWSERWINDOW_H


#include "c2webview.h"
#include "javascriptwindowobject.h"
class C2BrowserWindow : public QMainWindow
{
	Q_OBJECT

public:
	C2BrowserWindow(QWidget *parent=0);
	~C2BrowserWindow();

public:
	void NavToHome();
	void NavTo(QString url);

	C2WebView* getWebView();
protected:
	//virtual QWebView *	createWindow(QWebPage::WebWindowType type);

private:
	C2WebView *view;
	JavaScriptWindowObject *javaScriptWindowObject;
private:
	void populateJavaScriptWindowObject();
};

#endif // C2BROWSERWINDOW_H
