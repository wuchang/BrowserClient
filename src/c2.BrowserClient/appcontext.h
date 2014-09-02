#ifndef APPCONTEXT_H
#define APPCONTEXT_H

#include "c2config.h"

#include "javascriptwindowobject.h"
class AppContext 
{
 public:
	~AppContext();

	static AppContext* Current();

public:
	//����
	C2Config* Config(); 
	//JavaScriptWindowObject* getJavascriptObject();

private:
	C2Config *config;
 
private:
	AppContext( );//��ֹ���캯����
	AppContext(const AppContext &);//��ֹ�������캯����
	AppContext & operator=(const AppContext &);//��ֹ��ֵ����������

	static AppContext* instance;

	//QReadWriteLock internalMutex;//����ʹ�õĶ�д����

	//static QMutex mutex;//ʵ����������
	//static QAtomicPointer<AppContext> instance;/*!<ʹ��ԭ��ָ��,Ĭ�ϳ�ʼ��Ϊ0��*/
};

#endif // APPCONTEXT_H
