#include "stdafx.h"
#include "myclass.h"
#include <QtWidgets/QApplication>

#include "c2browserwindow.h"
#include "appcontext.h"
int main(int argc, char *argv[])
{
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

	QApplication a(argc, argv);
	 
	 
	/*MyClass w;
	w.show();*/

	C2BrowserWindow win;
	//win.setGeometry(0, 0, 800, 600);

	win.show();
	win.NavToHome();

	
	return a.exec();
}
