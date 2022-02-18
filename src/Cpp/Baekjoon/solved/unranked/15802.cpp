#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

int main()
{
	string s;
	cin>>s;
	
	srand(time(NULL));
	int n=rand()%2;
	cout<<"0";
}

/*
#include <iostream>
#include <random>

using namespace std;

int main(void) {
	string s; cin>>s;
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0,1);
	
	if(dis(gen)) cout<<"1"<<endl;
	else cout<<"0"<<endl;
}
/*