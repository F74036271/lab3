#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <fstream>

using namespace std;
int main(){
	ifstream inFile("file.in",ios::in);
	if(!inFile){ 
		cerr<<"Filed opening"<<endl;
		return 0;
	}
	int n;
	inFile>>n;
	vector<int> cow(n);
	for(int i=0;i<n;i++)
		inFile>>cow.at(i);
	for(int i=1;i<n;i++){
		int now_item=i, temp=cow.at(now_item), compare_item=now_item-1;
		while(now_item>0 && cow.at(now_item)>cow.at(compare_item)){
			cow.at(now_item)=cow.at(compare_item);
			cow.at(compare_item)=temp;
			now_item--;
			compare_item=now_item-1;
		}
	}
 	int sum=0;
 	for(int i=0;i<5;i++)
		sum+=cow.at(i);
	cout<<sum<<endl;	
}

