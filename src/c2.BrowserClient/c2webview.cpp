#include "stdafx.h"
#include "c2webview.h"

#include "c2browserwindow.h"
#include "c2webview.h"
C2WebView::C2WebView(QWidget *parent)
	: QWebView(parent)
{
	QWebSettings *setting = this->settings();
	setting->setAttribute(QWebSettings::JavascriptEnabled, true);
	setting->setAttribute(QWebSettings::PluginsEnabled, true);

	setting->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);
	setting->setAttribute(QWebSettings::JavascriptCanOpenWindows, true);
	setting->setAttribute(QWebSettings::JavascriptCanAccessClipboard, true);
	setting->setAttribute(QWebSettings::JavascriptCanCloseWindows, true);
	setting->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);
	setting->setAttribute(QWebSettings::SpatialNavigationEnabled, true);

	setting->setAttribute(QWebSettings::LocalContentCanAccessFileUrls, true);
	setting->setAttribute(QWebSettings::LocalContentCanAccessRemoteUrls, true);
	setting->setAttribute(QWebSettings::OfflineStorageDatabaseEnabled, true);
	setting->setAttribute(QWebSettings::AutoLoadImages, true);

	page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);

}

C2WebView::~C2WebView()
{

}

QWebView * C2WebView::createWindow(QWebPage::WebWindowType type) {
	Q_UNUSED(type);

	C2BrowserWindow *win = new	C2BrowserWindow();
	win->setAttribute(Qt::WA_DeleteOnClose, true);

	win->showNormal();
	
	return win->getWebView();
}
