#ifndef C2WEBVIEW_H
#define C2WEBVIEW_H

#include "stdafx.h"

class C2WebView : public QWebView
{
	Q_OBJECT

public:
	C2WebView(QWidget *parent);
	~C2WebView();

protected:

	virtual QWebView *createWindow(QWebPage::WebWindowType type);

private:

};

#endif // C2WEBVIEW_H
