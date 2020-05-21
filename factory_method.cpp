#include <iostream>

using namespace std;

class AbstractProduct{
public:
	virtual ~AbstractProduct(){};
	virtual void ShowSelf() = 0;
};

class ProductA: public AbstractProduct{
public:
	ProductA(){
		cout << " Creat A" << endl;
	}

	virtual void ShowSelf(){
		cout << " I am A" << endl;
	}
};

class ProductB: public AbstractProduct{
public:
	ProductB(){
		cout << " Creat B" << endl;
	}

	virtual void ShowSelf(){
		cout << " I am B" << endl;
	}
};

class AbstractFactory{
public:
	virtual ~AbstractFactory(){};
	virtual AbstractProduct* GetProduct() = 0;
};

class FactoryA: public AbstractFactory{
public:
	FactoryA(){
		cout << " FactoryA working" << endl;
	}
	virtual AbstractProduct*  GetProduct(){
		AbstractProduct* ptr = new ProductA();
		return ptr;
	}
};

class FactoryB: public AbstractFactory{
public:
	FactoryB(){
		cout << " FactoryB working" <<endl;
	}
	virtual AbstractProduct* GetProduct(){
		AbstractProduct* ptr = new ProductB();
		return ptr;
	}
};

int main(){
	AbstractProduct* ptr = NULL;

	FactoryA fa;
	ptr = fa.GetProduct();
	if ( ptr != NULL ){
		ptr->ShowSelf();
		delete(ptr);
		ptr = NULL;
	}

	FactoryB fb;
	ptr = fb.GetProduct();
	if ( ptr != NULL ){
		ptr->ShowSelf();
		delete(ptr);
		ptr = NULL;
	}

	return 1;
}

