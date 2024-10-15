#ifndef _MYCLASS_H
#define _MYCLASS_H
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
#include<map>
#include<queue>
#define INF 0xffffff
using namespace std;
class findInfo;
struct realPathNode {
	vector<int> path;
	int moneyCost;
	float timeCost;
	realPathNode(int a, float b, vector<int> c) {
		moneyCost = a;
		timeCost = b;
		path = c;
	}
};
struct peopleNode {
	string _account;
	string _answer;
	int Enable;
	peopleNode(string ac, string an,int i) :_account(ac), _answer(an),Enable(i){}
};
struct preNode {
	int cityId;
	preNode* pre;
	preNode(int i) :cityId(i), pre(nullptr) {};
	preNode(int i, preNode* p) :cityId(i), pre(p) {};
};
struct normalNode {
	string beginTime, endTime;
	string Id;
	normalNode(string tempBegin, string tempEnd, string tempId) :beginTime(tempBegin), endTime(tempEnd), Id(tempId) {};
};
struct cityNode {
	string thisName, nextName;
	int cityDistance;
	cityNode(string s1, string s2,int tempd) :thisName(s1), cityDistance(tempd),nextName(s2) {};
};
struct aPlaneNode {
	string beginAddress, endAddress;
	int money;
	vector<normalNode*> flights;//从某地到某地的航班的所有趟次;
	aPlaneNode(string beginA, string endA, int c, vector<normalNode*>& aV) :beginAddress(beginA), endAddress(endA), money(c) {
		flights = aV;
	}
};
struct aTrainNode {
	string beginAddress, endAddress;
	int money;
	vector<normalNode*> trainTrips;//从某地到某地的列车的所有趟次;
	aTrainNode(string beginA, string endA, int c, vector<normalNode*>& aV) :beginAddress(beginA), endAddress(endA), money(c) {
		trainTrips = aV;
	}
};
class city {
private:
	vector<cityNode*> myCity;
	vector < vector<int>> cityDisMatrix;
public:
	city();
	~city() {};
	bool isFind(string s1,string s2);
	void addCity(string s1,string s2,int d);
	void deleteCity(string s1,string s2);
	void createDisMatrix();
};
class myPlane {
private:
	vector<aPlaneNode*> planeInfo;//用于储存不同地点所有飞机航班信息;
	vector<vector<int>> planeMoneyMatrix;
	vector<vector<float>> planeTimeMatrix;
public:
	vector<vector<int>> planeAllPath;
	myPlane();
	~myPlane() {};
    friend void getPlaneInfo(myPlane& aPlane, string s1, string s2,findInfo* aFindInfo);
	friend void judgePath(vector<vector<int>>& path,string nowTime,myPlane &aPlane);
	friend bool oneJudge(int beginPlace, int endPlace, string nowTime,myPlane& aPlane,vector<int> &path);
	void getAllPath(string v, string t);
    bool addFlight(string tempBeginA,string tempEndA,string tempBeginT,string tempEndT,string tempId);
    bool deleteFlight(string tempBeginA,string tempEndA,string tempBeginT,string tempEndT);
    bool deleteAll(string tempBeginA,string tempEndA);
	void createPlaneMoneyMatrix();
	void createPlaneTimeMatrix();
	int findPlaneInfoId(string s1, string s2);
    void saveInfo();
};
class myTrain {
private:
	vector<aTrainNode*> trainInfo;
	vector<vector<int>> trainMoneyMatrix;//储存每趟列车费用;
	vector<vector<float>> trainTimeMatrix;//储存每趟列车耗费时间;
	vector<vector<int>> trainAllPath;
public:
	myTrain();
	~myTrain() {};
    friend void getTrainInfo(myTrain& aTrain,string s1,string s2,findInfo* aFindInfo);
    bool addTrainTrip();
    bool deleteTrainTrip(string tempBeginA,string tempEndA,string tempBeginT,string tempEndT);
    bool deleteAll(string tempBeginA,string tempEndA);
	void createTrainMoneyMatrix();
	void createTrainTimeMatrix();
	void getAllPath(string v, string t);
    void saveInfo();
};
#endif
