#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<class T>
struct plus2
{
	void operator()(T&x)const
	{
		x+=2;
	}
	
};

void printElem(int& elem)
{
  cout << elem << endl;
}


int main()
{
	int ia[]={0,1,2,3,4,5,6};
	for_each(ia,ia+7,printElem);
      cout <<"---------------------------"<<endl;	
	int ib[]={7,8,9,10,11,12,13};
	vector<int> iv(ib,ib+7);
	for_each(iv.begin(),iv.end(),plus2<int>());
//           plus2<int> (ib[0]);
        //  cout<< ib[0]<<endl;
	for_each(iv.begin(),iv.end(),printElem);
	
	
	return 0;
}
