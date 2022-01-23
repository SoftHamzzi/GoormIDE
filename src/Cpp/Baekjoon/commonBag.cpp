#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Item {
	private:
	int weight;
	int value;
	double costP;
	
	public:
	Item(int w, int v) {
		this->weight = w;
		this->value = v;
		this->costP = costPerformance(this);
	}
	
	double costPerformance(Item * i) {
		return (double)value/weight;
	}
	
	int getWeight() {
		return this->weight;
	}
	
	double getcostP() {
		return this->costP;
	}
	
	void showData() {
		cout<<this->weight<<" "<<this->value<<" "<<this->costP<<endl;
	}
	
	bool operator<(Item& i) {
		return this->costP > i.costP;
	}
};

int main(void) {
	int n,k; cin>>n>>k;
	int w,v;
	vector<Item> t;
	
	for(int i=0;i<n;i++) {
		cin>>w>>v;
		t.push_back(Item(w,v));
	}
	
	sort(t.begin(),t.end());
	
	int wsum=0;
	int vtotal=0;
	
	vector<Item>::iterator it;
	for(it=t.begin();it!=t.end();it++) {
		if((*it).getWeight() + wsum <= k)
			vtotal += (*it).getcostP();
	}
	
	cout<<"최대 가치 = "<<vtotal<<endl;
	
	for(it=t.begin();it!=t.end();it++) {
		(*it).showData();
	}
	
}