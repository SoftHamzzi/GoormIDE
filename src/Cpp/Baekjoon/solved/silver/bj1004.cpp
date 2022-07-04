#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int t; cin>>t;
	int x1,y1,x2,y2;
	
	int planet;
	int cnt;
	while(t--) {
		cin>>x1>>y1>>x2>>y2;
		cnt=0;
		
		cin>>planet;
		while(planet--) {
			int cx,cy,rad;
			cin>>cx>>cy>>rad;
			if(pow(x1-cx,2)+pow(y1-cy,2) < pow(rad,2))
				if(pow(x2-cx,2)+pow(y2-cy,2) > pow(rad,2))
					cnt++;
			if(pow(x1-cx,2)+pow(y1-cy,2) > pow(rad,2))
				if(pow(x2-cx,2)+pow(y2-cy,2) < pow(rad,2))
					cnt++;
		}
		cout<<cnt<<endl;
	}
}

/*
#include <iostream>
#include <cmath>

using namespace std;

typedef struct _point {
	int x;
	int y;
} Point;

typedef struct _circle {
	int x;
	int y;
	int rad;
} Circle;

int isIn(Circle c, Point s, Point e) {
	bool iI[2]={false,false};
	
	if(pow(c.x-s.x,2)+pow(c.y-s.y,2) < pow(c.rad,2)) {
		iI[0]=true;
	}
	if(pow(c.x-e.x,2)+pow(c.y-e.y,2) < pow(c.rad,2)) {
		iI[1]=true;
	}
	
	if(iI[0]&&iI[1] || !iI[0]&&!iI[1])
		return 0;
	else
		return 1;
}

int main(void) {
	int t; cin>>t;
	
	Point start, end;
	int planet;
	int cnt;
	for(int i=0;i<t;i++) {
		cin>>start.x>>start.y;
		cin>>end.x>>end.y;
		cin>>planet;
		
		cnt=0;
		for(int j=0;j<planet;j++) {
			Circle tempC;
			cin>>tempC.x>>tempC.y>>tempC.rad;
			
			cnt += isIn(tempC, start, end);
		}
		cout<<cnt<<endl;
	}
}
*/