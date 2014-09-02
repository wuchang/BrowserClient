#ifndef C2CONFIG_H
#define C2CONFIG_H

#include <QObject>

class C2Config {

public:
	QString GetStartUrl();

public:
	C2Config( );
	~C2Config();

private:
	QSettings *setting;

};

#endif // C2CONFIG_H
