#include<iostream>
#include <vector>
#include <chrono>
#include <set>
#include <string>
#include <windows.h>

#include "../HRproject/clover.h"
#pragma comment(lib,"clover.lib")

using namespace std;





/*
void main()
{
	HRindex p;
	getchar();

}
*/

int main()
{

	//data generation
	vector<int> a,b;
	for (int i = 0; i < 5; i++) {
		a.push_back(i);
	}
	for (int i = 90; i <=95; i+=5) {
		b.push_back(i);
	}
	LISTHR lst;
	LISTHP pst;
	int i = 0;
	for (size_t i = 0; i <= 100; i=i+1)
	{
		lst.push_back(make_pair(a,i));
		pst.push_back(make_pair(a,b));
	}



	HRindex p;
	index* iHR;

	p.HRMonitor(lst,day);
	iHR = p.result_inx;//获取分析型指标中的子指标
	
	//for (size_t i = 0; i < 8; i++)
	//{
	//	//cout << p.result_inx->his[i] << endl;
	//	cout << iHR->his[i] << endl;
	//}
	
	double time1 = 0;
	for (size_t i = 0; i < 100; i++)
	{
		
		double t1 = GetTickCount();
		p.HR_FI(lst);
		double t2 = GetTickCount();
		//cout << "HR_diff:" << double(t2 - t1) << endl;
		time1 += t2 - t1;
	}
	cout << "F:" << time1 / 100 << endl;
	//获取分析型指标

	double time2 = 0;
	for (size_t i = 0; i < 100; i++)
	{

		double t1 = GetTickCount();
	p.HR_SI(lst) ;
		double t2 = GetTickCount();
		//cout << "HR_diff:" << double(t2 - t1) << endl;
		time2 += t2 - t1;
	}
	cout << "S:" << time2 / 100 << endl;

	double time3 = 0;
	for (size_t i = 0; i < 100; i++)
	{

		double t1 = GetTickCount();
		 p.HR_PI(lst) ;
		double t2 = GetTickCount();
		//cout << "HR_diff:" << double(t2 - t1) << endl;
		time3 += t2 - t1;
	}
	cout << "P:" << time3 / 100 << endl;
	cout << p.HR_FI(lst) << endl;
	cout << p.HR_FI_B(lst) << endl;
	cout << p.HR_SI(lst) << endl;
	cout << p.HR_PI(lst) << endl;
	cout << p.HR_PI_B(lst) << endl;
	cout << p.HR_risk(lst) << endl;
	cout << p.HP(pst) << endl;

	getchar();

	return 0;
}
