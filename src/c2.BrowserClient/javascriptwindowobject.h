#ifndef JAVASCRIPTWINDOWOBJECT_H
#define JAVASCRIPTWINDOWOBJECT_H

#include <QObject>

class JavaScriptWindowObject : public QObject
{
	Q_OBJECT

public:
	JavaScriptWindowObject(QObject *parent,
		QMainWindow *window);
	~JavaScriptWindowObject();

	public slots:
	void resize(int w, int h);
	void alert(const QString msg);

private:
	QMainWindow *window;
};

#endif // JAVASCRIPTWINDOWOBJECT_H
