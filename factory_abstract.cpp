#include <iostream>

using namespace std;

class AbstractA{
public:
	virtual ~AbstractA(){};
	virtual void ShowSelf() = 0;
};

class ProductA_a: public AbstractA{
public:
	ProductA_a(){
		cout << " Creat A_a" << endl;
	}

	virtual void ShowSelf(){
		cout << " I am A_a" << endl;
	}
};

class ProductA_b: public AbstractA{
public:
	ProductA_b(){
		cout << " Creat A_b" << endl;
	}

	virtual void ShowSelf(){
		cout << " I am A_b" << endl;
	}
};

class AbstractB{
public:
	virtual ~AbstractB(){};
	virtual void ShowSelf() = 0;
};

class ProductB_a: public AbstractB{
public:
	ProductB_a(){
		cout << " Creat B_a" << endl;
	}

	virtual void ShowSelf(){
		cout << " I am B_a" << endl;
	}
};

class ProductB_b: public AbstractB{
public:
	ProductB_b(){
		cout << " Creat B_b" << endl;
	}

	virtual void ShowSelf(){
		cout << " I am B_b" << endl;
	}
};

class AbstractFactory{
public:
	virtual ~AbstractFactory(){};
	virtual AbstractA* GetProductA() = 0;
	virtual AbstractB* GetProductB() = 0;
};

class Factorya: public AbstractFactory{
public:
	Factorya(){
		cout << " Factorya working" << endl;
	}
	virtual AbstractA*  GetProductA(){
		AbstractA* ptr = new ProductA_a();
		return ptr;
	}
	virtual AbstractB*  GetProductB(){
		AbstractB* ptr = new ProductB_a();
		return ptr;
	}
};

class Factoryb: public AbstractFactory{
public:
	Factoryb(){
		cout << " Factoryb working" <<endl;
	}
	virtual AbstractA* GetProductA(){
		AbstractA* ptr = new ProductA_b();
		return ptr;
	}
	virtual AbstractB* GetProductB(){
		AbstractB* ptr = new ProductB_b();
		return ptr;
	}
};

int main(){
	AbstractA* ptrA = NULL;
	AbstractB* ptrB = NULL;

	Factorya fa;
	ptrA = fa.GetProductA();
	if ( ptrA != NULL ){
		ptrA->ShowSelf();
		delete(ptrA);
		ptrA = NULL;
	}
	ptrB = fa.GetProductB();
	if ( ptrB != NULL ){
		ptrB->ShowSelf();
		delete(ptrB);
		ptrB = NULL;
	}

	Factoryb fb;
	ptrA = fb.GetProductA();
	if ( ptrA != NULL ){
		ptrA->ShowSelf();
		delete(ptrA);
		ptrA = NULL;
	}
	ptrB = fb.GetProductB();
	if ( ptrB != NULL ){
		ptrB->ShowSelf();
		delete(ptrB);
		ptrB = NULL;
	}

	return 1;
}

