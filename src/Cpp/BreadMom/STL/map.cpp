#include <iostream>
#include <map>
#include <typeinfo>

using namespace std;

int main(void) {
	
	map<string, int> m;
	multimap<string, int> mm;
	
	m.insert(pair<string,int>("식빵", 5));
	mm.insert(make_pair("소보로", 10));
	mm.insert(make_pair("소보로", 9));
	
	cout << m.find("식빵")->second << endl;

	auto range = mm.equal_range("소보로"); // pair를 반환함
	for (auto itr = range.first; itr != range.second; ++itr) {
		
  		std::cout << itr->first << " : " << itr->second << " " << std::endl;
		
	}
	cout << typeid(range).name();
	
	/*
	for(auto itr : mm.equal_range("소보로")) {
		cout<< itr.second << endl;
	}
	*/

}