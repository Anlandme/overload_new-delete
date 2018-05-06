#include<iostream>
#include<cstdlib>

using namespace std;

void* operator new(size_t size)
{
		cout<<"operator new:" << size << " Bytes"<<endl;
		void* p = malloc(size);
		if (NULL == p)
		{
				cout << "bad alloc!" << endl;
		}

		return p;
}

void operator delete(void* p)
{
		if (NULL == p)
		{
				cout << "bad address!!!" << endl;;
		}

		cout << "operator delete" << endl;;
		
		free(p);

		return ;
}

class Demon
{
		public:
				Demon()
				{
						cout << "the constuctor" << endl;
				}
				~Demon() 
				{
						cout << "the destuctor" << endl;
				}
};

int main()
{
		int* q = new int(23);
		delete q;

		int* p = new int[10];
		delete []p;

		Demon* s = new Demon;
		delete s;
		
		return 0;
}
