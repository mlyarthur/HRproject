#pragma once


#ifndef HEADER_H
#define HEADER_H
#ifdef AFX_CLASS
#define AFX_EX_CLASS _declspec(dllexport)
#else
#define AFX_EX_CLASS _declspec(dllimport)
#endif
#endif

#include "predefine.h"
using namespace std;

AFX_EX_CLASS typedef list<pair< vector<int>, int>> LISTHR;
AFX_EX_CLASS typedef list<pair< vector<int>, vector<int>>> LISTHP;
AFX_EX_CLASS vector<int> getTime();
AFX_EX_CLASS void addTime(vector<int>& time, int interval);
AFX_EX_CLASS void test();


class Histogram
{
public:
	Histogram(size_t minval, size_t gap, size_t n_bins);
	void record(LISTHR data);
	~Histogram();

public:
	vector<int> vbins;
private:
	size_t * const bins;

	size_t const minval_, maxval_;
	size_t const gap_;
};

struct index
{
	size_t HRMean;
	size_t maxHR;
	size_t minHR;
	double HRStd;
	double HStd;
	double LStd;
	double NStd;
	double HP;
	double LP;
	double NP;
	size_t HMean;
	size_t LMean;
	size_t NMean;
	vector<int> his;

};


class AFX_EX_CLASS sample
{
public:
	sample();
	~sample();



public:
	void downsample(vector<int>start_time, int interval, bool flag, s_type st);
	//map<double, size_t >r_data;//store the realtime data
	//map<double, size_t >d_data;//store the day time data 
	//map<double, size_t >n_data;//store the night time data
	//map<double, size_t >f_data;//the fatigue time data
	//map<double, size_t >p_data;// the pressure time data
public:
	LISTHR tmp_out;
	LISTHP tmp_hp;


};


class AFX_EX_CLASS HRindex
{
public:
	size_t hr_;
	index* result_inx;
	//index* temp;
	//sample sp;//sample object
private:
	size_t hr_mean;
	size_t hr_rest;
	size_t hr_sd;
	index* hr_index;
	fatigue f;
	pressure p;
	isScoop s;
	std::string diff;
public:
	HRindex();
	~HRindex();

public:

	string HR_risk(LISTHR d);//心率函数
	string HR_diff(LISTHR d);//心率变动函数
	string HR_FI(LISTHR d);//普通疲劳指数
	string HR_FI_B(LISTHR d);//蓝牙疲劳指数
	string HR_PI(LISTHR d);//普通压力指数
	string HR_PI_B(LISTHR d);//蓝牙压力指数
	string HR_SI(LISTHR d);//稳定指数
	string HP(LISTHP d);//血压(暂无)
	void HRMonitor(LISTHR d, period p);//分析函数

};

class HPindex
{


};