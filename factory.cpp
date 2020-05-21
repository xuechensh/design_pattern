#include <iostream>
#include <string>

using namespace std;

class AbstractProduct{
public:
	virtual ~AbstractProduct(){};
	virtual void ShowSelf() = 0;
};

class FootBall: public AbstractProduct{
public:
	FootBall(){
		cout << "Creat FootBall" << endl;
	}
	virtual void ShowSelf(){
		cout << "I am FootBall" << endl;
	}
};

class BasketBall: public AbstractProduct{
public:
	BasketBall(){
		cout << "Creat BasketBall" << endl;
	}
	virtual void ShowSelf(){
		cout << "I am BasketBall" << endl;
	}
};

class Factory{
public:
	Factory(){
		cout << "Creat Factory " << endl;
	}
	
	AbstractProduct* GetInstance(string name){
		AbstractProduct* ptr = NULL;
		if( name == "FootBall" ){
			ptr = new FootBall();
		}
		else if ( name == "BasketBall" ){
			ptr = new BasketBall();
		}
		else{
			cout << "Can not product" << endl;
		}

		return ptr;
	}
};

int main(){
	AbstractProduct* ptr = NULL;
	Factory factoryInstance;

	ptr = factoryInstance.GetInstance("FootBall");
	if( NULL != ptr){
		ptr->ShowSelf();
		delete(ptr);
		ptr = NULL;
	}

	ptr = factoryInstance.GetInstance("BasketBall");
	if( NULL != ptr){	
		ptr->ShowSelf();
		delete(ptr);
		ptr = NULL;
	}
	
	ptr = factoryInstance.GetInstance("PingPang");
	if( NULL != ptr){
		ptr->ShowSelf();
		delete(ptr);
		ptr = NULL;
	}

	return 1;
}
