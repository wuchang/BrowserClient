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
	//配置
	C2Config* Config(); 
	//JavaScriptWindowObject* getJavascriptObject();

private:
	C2Config *config;
 
private:
	AppContext( );//禁止构造函数。
	AppContext(const AppContext &);//禁止拷贝构造函数。
	AppContext & operator=(const AppContext &);//禁止赋值拷贝函数。

	static AppContext* instance;

	//QReadWriteLock internalMutex;//函数使用的读写锁。

	//static QMutex mutex;//实例互斥锁。
	//static QAtomicPointer<AppContext> instance;/*!<使用原子指针,默认初始化为0。*/
};

#endif // APPCONTEXT_H
