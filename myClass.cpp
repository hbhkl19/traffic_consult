#include"myClass.h"
#include<iostream>
#include<algorithm>
#include<QFile>
#include<QTextStream>
using namespace std;
int cityNum = 0;
map<string, int> cityMap;
map<int, string> unCityMap;
int** timePath;
int** costPath;
//根据时刻得到耗费时间
float transToFloat(string s) {
	int length = s.length();
	float i = 0, tempTime1 = 0, tempTime2 = 0;
	while (i < length) {
		if (s[i] != ':') {
			tempTime1 = tempTime1 * 10 + (s[i] - '0');
			i++;
		}
		else {
			i++;
			while (i < length) {
				tempTime2 = tempTime2 * 10 + (s[i] - '0');
				i++;
			}
		}
	}
	float answer = tempTime1 + (tempTime2 / 60);
	return answer;
}
float transTime(string s1, string s2) {
	float firstAnswer = transToFloat(s1);
	float secondAnswer = transToFloat(s2);
	float answer = abs(secondAnswer - firstAnswer);
	return answer;
}

city::city() {
    QFile file("C:\\Users\\xsy\\Documents\\QTProject\\TrafficConsultationSystem\\city.txt");
    QTextStream stram(&file);
    if(file.open(QFile::ReadOnly|QFile::Text)){
        while(!stram.atEnd()){
            QString line=stram.readLine();
            std::string new_line=line.toStdString();
            stringstream is(new_line);
            std::string tempThis,tempNext;
            int tempDis;
            is>>tempThis>>tempNext>>tempDis;
            cityNode* p = new cityNode(tempThis, tempNext, tempDis);
            myCity.push_back(p);
            if (cityMap.count(tempThis) == 0) {
                cityMap.insert(pair<string, int>(tempThis, cityNum));//建立城市名->数字的映射;
                unCityMap.insert(pair<int, string>(cityNum, tempThis));
                cityNum++;//记录出现过的city数目;
            }
            if (cityMap.count(tempNext) == 0) {
                cityMap.insert(pair<string, int>(tempNext, cityNum));//同上;
                unCityMap.insert(pair<int, string>(cityNum, tempNext));
                cityNum++;//同上;
            }
        }
    }
    file.close();
}
bool city::isFind(string s1,string s2) {
	int length = myCity.size();
	for (int i = 0; i < length; i++) {
		if (myCity[i]->thisName == s1 && myCity[i]->nextName == s2) {
			return true;
		}
	}
	return false;
}
//该函数主要实现添加从某个新建的城市到已有的城市的距离;
void city::addCity(string s1,string s2,int d) {
	//
	if (isFind(s1, s2)) {
		cout << "抱歉，该信息已经存在，不可重复添加。";
	}
	else {
		if (cityMap.count(s1) == 0) {
			cityMap.insert(pair<string, int>(s1, cityNum));
			cityNum++;
		}
		else if(cityMap.count(s2)==0){
			cityMap.insert(pair<string, int>(s2, cityNum));
			cityNum++;
		}
		cityNode* p = new cityNode(s1, s2, d);
		myCity.push_back(p);
		cityDisMatrix.resize(cityNum);
		for (int i = 0; i < cityNum; i++) {
			cityDisMatrix[i].resize(cityNum);
		}
		cityDisMatrix[cityMap[s1]][cityMap[s2]] = d;
		cout << "添加成功!";
	}
}
void city::deleteCity(string s1,string s2) {
	//
	if (isFind(s1, s2)) {
		cout << "抱歉，该条信息不存在。";
	}
	else {
		//
	}
}
void city::createDisMatrix() {
	cityDisMatrix.resize(cityNum);
	int length = myCity.size();
	for (int i = 0; i < cityNum; i++) {
		cityDisMatrix[i].resize(cityNum);
	}
	for (int i = 0; i < length; i++) {
		cityDisMatrix[cityMap[myCity[i]->thisName]][cityMap[myCity[i]->nextName]] = myCity[i]->cityDistance;
		cityDisMatrix[cityMap[myCity[i]->nextName]][cityMap[myCity[i]->thisName]] = myCity[i]->cityDistance;
	}
}
myPlane::myPlane() {
    QFile file("C:\\Users\\xsy\\Documents\\QTProject\\TrafficConsultationSystem\\planeTimeTable.txt");
    QTextStream stram(&file);
    string tempThis, tempNext, tempId;
    string tempBegin, tempEnd;
    int tempMoney, times;
    if(file.open(QFile::ReadOnly|QFile::Text)){
        while(!stram.atEnd()){
            QString line = stram.readLine();
            std::string new_line=line.toStdString();
            stringstream is(new_line);
            is >> tempThis >> tempNext >> tempMoney >> times;
            vector<normalNode*> tempV;
            for (int i = 0; i < times; i++) {
                is >> tempBegin >> tempId >> tempEnd;
                normalNode* p = new normalNode(tempBegin, tempEnd, tempId);
                tempV.push_back(p);
            }
            aPlaneNode* q = new aPlaneNode(tempThis, tempNext, tempMoney, tempV);
            planeInfo.push_back(q);
        }
    }
    file.close();
}
void myPlane::createPlaneMoneyMatrix() {
	//
	planeMoneyMatrix.resize(cityNum);
	for (int i = 0; i < cityNum; i++) {
		planeMoneyMatrix[i].resize(cityNum);
	}
	int length = planeInfo.size();
	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < cityNum; j++) {
			if (i == j)
				planeMoneyMatrix[i][j] = 0;
			else
				planeMoneyMatrix[i][j] = INF;
		}
	}
	for (int i = 0; i < length; i++) {
		planeMoneyMatrix[cityMap[planeInfo[i]->beginAddress]][cityMap[planeInfo[i]->endAddress]] = planeInfo[i]->money;
	}
}
void myPlane::createPlaneTimeMatrix() {
	//
	planeTimeMatrix.resize(cityNum);
	for (int i = 0; i < cityNum; i++) {
		planeTimeMatrix[i].resize(cityNum);
	}
	int length = planeInfo.size();
	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < cityNum; j++) {
			if (i == j)
				planeTimeMatrix[i][j] = 0;
			else
				planeTimeMatrix[i][j] = INF;
		}
	}
	for (int i = 0; i < length; i++) {

		planeTimeMatrix[cityMap[planeInfo[i]->beginAddress]][cityMap[planeInfo[i]->endAddress]] = transTime(planeInfo[i]->flights[0]->beginTime,planeInfo[i]->flights[0]->endTime);
	}
}
bool myPlane::addFlight(string tempBeginA,string tempEndA,string tempBeginT,string tempEndT,string tempId) {//还缺少对费用的添加;
	//还差个判断输入班次是否存在
    if(cityMap.count(tempBeginA)==0||cityMap.count(tempEndA)==0)
        return false;
    else{
        normalNode* p = new normalNode(tempBeginT, tempEndT, tempId);
        int length = planeInfo.size();
        for (int i = 0; i < length; i++) {
            if (planeInfo[i]->beginAddress == tempBeginA && planeInfo[i]->endAddress == tempEndA){
                for(int j=0;j<planeInfo[i]->flights.size();j++){
                    if(planeInfo[i]->flights[j]->beginTime==tempBeginT&&planeInfo[i]->flights[j]->endTime==tempEndT&&(planeInfo[i]->flights[j]->Id==tempId))
                        return false;
                    else
                        continue;
                }
                planeInfo[i]->flights.push_back(p);
                return true;
            }
            else
                continue;
        }
        vector<normalNode*> myV;
        normalNode* pq=new normalNode(tempBeginT,tempEndT,tempId);
        myV.push_back(pq);
        aPlaneNode *q=new aPlaneNode(tempBeginA,tempEndA,100,myV);
        planeInfo.push_back(q);
        return true;
    }
    return true;
}
bool myPlane::deleteFlight(string tempBeginA,string tempEndA,string tempBeginT,string tempEndT) {
	//
    if(cityMap.count(tempBeginA)==0||cityMap.count(tempEndA)==0)
        return false;//false 表示不能删除;
    else{
        int length = planeInfo.size();
        for (int i = 0; i < length; i++) {
            if (planeInfo[i]->beginAddress == tempBeginA && planeInfo[i]->endAddress == tempEndA){
                for(int j=0;j<planeInfo[i]->flights.size();j++){
                    if(planeInfo[i]->flights[j]->beginTime==tempBeginT&&planeInfo[i]->flights[j]->endTime==tempEndT)
                    {
                        int flightTime=planeInfo[i]->flights.size();
                        for(int k=j;k<flightTime-1;k++)
                            planeInfo[i]->flights[k]=planeInfo[i]->flights[k+1];
                        planeInfo[i]->flights.resize(flightTime-1);
                        return true;
                    }
                    else
                        continue;
                }
                return false;
            }
            else
                continue;
        }
        return false;//没有找到可以删除的信息，返回false;
    }
    return true;
}
bool myPlane::deleteAll(string tempBeginA,string tempEndA){
    if(cityMap.count(tempBeginA)==0||cityMap.count(tempEndA)==0)
        return false;//false 表示不能删除;
    else{
        int length = planeInfo.size();
        for (int i = 0; i < length; i++) {
            if (planeInfo[i]->beginAddress == tempBeginA && planeInfo[i]->endAddress == tempEndA){
                planeInfo[i]->flights.resize(0);
                return true;
            }
            else
                continue;
        }
        return false;//没有找到可以删除的信息，返回false;
    }
    return true;
}
//得到航班所有路径;
void myPlane::getAllPath(string v, string t) {
	int startPoint = cityMap[v];
	int target = cityMap[t];
	queue<preNode*> qu;
	preNode* p = new preNode(startPoint);
	int* visited = new int[cityNum];
	for (int i = 0; i < cityNum; i++) {
		visited[i] = 0;
	}
	qu.push(p);
	while (!qu.empty()) {
		preNode* tempP = qu.front();
		if (tempP->cityId == target) {
			vector<int> tempV;
			tempV.push_back(tempP->cityId);
			while (tempP->pre != nullptr) {
				tempP = tempP->pre;
				tempV.push_back(tempP->cityId);
			}
            reverse(tempV.begin(), tempV.end());
			planeAllPath.push_back(tempV);
		}
		else {
			int length = cityNum;
			for (int i = 0; i < length; i++) {
				if (planeMoneyMatrix[tempP->cityId][i] != 0 && planeMoneyMatrix[tempP->cityId][i] != INF&& visited[i]==0) {
					if (i != target) {
						visited[i] = 1;
					}
					preNode* q = new preNode(i, tempP);
					qu.push(q);
				}
			}
		}
		qu.pop();
	}
	int l = planeAllPath.size();
	for (int i = 0; i < l; i++) {
		int l2 = planeAllPath[i].size();
		for (int j = 0; j < l2; j++)
			cout << planeAllPath[i][j] << " ";
		cout << endl;
	}
}
int myPlane::findPlaneInfoId(string s1, string s2) {
	int length = planeInfo.size();
	for (int i = 0; i < length; i++) {
		if (planeInfo[i]->beginAddress == s1 && planeInfo[i]->endAddress == s2)
			return i;
	}
	return -1;
}
void myPlane::saveInfo(){
    std::ofstream ofs("C:\\Users\\xsy\\Documents\\QTProject\\TrafficConsultationSystem\\planeTimeTable.txt");
    int length = planeInfo.size();
    for (int i = 0; i < length; i++) {
        ofs << planeInfo[i]->beginAddress << " " << planeInfo[i]->endAddress << " " << planeInfo[i]->money << " ";
        int lengthT = planeInfo[i]->flights.size();
        for (int j = 0; j < lengthT; j++) {
            ofs << planeInfo[i]->flights[j]->beginTime << " " << planeInfo[i]->flights[j]->Id << " " << planeInfo[i]->flights[j]->endTime;
            if (j != lengthT - 1)
                ofs << " ";
        }
        if (i != length - 1)
            ofs << endl;
    }
}
myTrain::myTrain() {
    QFile file("C:\\Users\\xsy\\Documents\\QTProject\\TrafficConsultationSystem\\trainTimeTable.txt");
    QTextStream stram(&file);
    string tempThis, tempNext, tempId;
    string tempBegin, tempEnd;
    int tempMoney, times;
    if(file.open(QFile::ReadOnly|QFile::Text)){
        while(!stram.atEnd()){
            QString line = stram.readLine();
            std::string new_line=line.toStdString();
            stringstream is(new_line);
            is >> tempThis >> tempNext >> tempMoney >> times;
            vector<normalNode*> tempV;
            for (int i = 0; i < times; i++) {
                is >> tempBegin >> tempId >> tempEnd;
                normalNode* p = new normalNode(tempBegin, tempEnd, tempId);
                tempV.push_back(p);
            }
            aTrainNode* q = new aTrainNode(tempThis, tempNext, tempMoney, tempV);
            trainInfo.push_back(q);
        }
    }
    file.close();
}
void myTrain::createTrainMoneyMatrix() {
	trainMoneyMatrix.resize(cityNum);
	for (int i = 0; i < cityNum; i++) {
		trainMoneyMatrix[i].resize(cityNum);
	}
	int length = trainInfo.size();
	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < cityNum; j++) {
			if (i == j)
				trainMoneyMatrix[i][j] = 0;
			else
				trainMoneyMatrix[i][j] = INF;
		}
	}
	for (int i = 0; i < length; i++) {
		trainMoneyMatrix[cityMap[trainInfo[i]->beginAddress]][cityMap[trainInfo[i]->endAddress]] = trainInfo[i]->money;
	}
}
bool myTrain::addTrainTrip() {
	//差个判断;
	string tempBegin, tempEnd, tempId, tempBeginA, tempEndA;
	cout << "请依次输入起点站、终点站、列车班次以及始发时间:";
	cin >> tempBeginA >> tempEndA >> tempId >> tempBegin >> tempEnd;
	normalNode* p = new normalNode(tempBegin, tempEnd, tempId);
	int length = trainInfo.size();
	for (int i = 0; i < length; i++) {
		if (trainInfo[i]->beginAddress == tempBeginA && trainInfo[i]->endAddress == tempEndA)
			trainInfo[i]->trainTrips.push_back(p);
	}
}
bool myTrain::deleteTrainTrip(string tempBeginA,string tempEndA,string tempBeginT,string tempEndT) {
	//
    if(cityMap.count(tempBeginA)==0||cityMap.count(tempEndA)==0)
        return false;//false 表示不能删除;
    else{
        int length = trainInfo.size();
        for (int i = 0; i < length; i++) {
            if (trainInfo[i]->beginAddress == tempBeginA && trainInfo[i]->endAddress == tempEndA){
                for(int j=0;j<trainInfo[i]->trainTrips.size();j++){
                    if(trainInfo[i]->trainTrips[j]->beginTime==tempBeginT&&trainInfo[i]->trainTrips[j]->endTime==tempEndT)
                    {
                        int trainTripTime=trainInfo[i]->trainTrips.size();
                        for(int k=j;k<trainTripTime-1;k++)
                            trainInfo[i]->trainTrips[k]=trainInfo[i]->trainTrips[k+1];
                        trainInfo[i]->trainTrips.resize(trainTripTime-1);
                        return true;
                    }
                    else
                        continue;
                }
                return false;
            }
            else
                continue;
        }
        return false;//没有找到可以删除的信息，返回false;
    }
    return true;
}
bool myTrain::deleteAll(string tempBeginA,string tempEndA){
    if(cityMap.count(tempBeginA)==0||cityMap.count(tempEndA)==0)
        return false;//false 表示不能删除;
    else{
        int length = trainInfo.size();
        for (int i = 0; i < length; i++) {
            if (trainInfo[i]->beginAddress == tempBeginA && trainInfo[i]->endAddress == tempEndA){
                trainInfo[i]->trainTrips.resize(0);
                return true;
            }
            else
                continue;
        }
        return false;//没有找到可以删除的信息，返回false;
    }
    return true;
}
void myTrain::createTrainTimeMatrix() {
	//
	trainTimeMatrix.resize(cityNum);
	for (int i = 0; i < cityNum; i++) {
		trainTimeMatrix[i].resize(cityNum);
	}
	int length = trainInfo.size();
	for (int i = 0; i < cityNum; i++) {
		for (int j = 0; j < cityNum; j++) {
			if (i == j)
				trainTimeMatrix[i][j] = 0;
			else
				trainTimeMatrix[i][j] = INF;
		}
	}
	for (int i = 0; i < length; i++) {
		trainTimeMatrix[cityMap[trainInfo[i]->beginAddress]][cityMap[trainInfo[i]->endAddress]] = transTime(trainInfo[i]->trainTrips[0]->beginTime,trainInfo[i]->trainTrips[0]->endTime);
	}
}
void myTrain::saveInfo(){
    std::ofstream ofs("C:\\Users\\xsy\\Documents\\QTProject\\TrafficConsultationSystem\\trainTimeTable.txt");
    int length = trainInfo.size();
    for (int i = 0; i < length; i++) {
        ofs << trainInfo[i]->beginAddress << " " << trainInfo[i]->endAddress << " " << trainInfo[i]->money << " ";
        int lengthT = trainInfo[i]->trainTrips.size();
        for (int j = 0; j < lengthT; j++) {
            ofs << trainInfo[i]->trainTrips[j]->beginTime << " " << trainInfo[i]->trainTrips[j]->Id << " " << trainInfo[i]->trainTrips[j]->endTime;
            if (j != lengthT - 1)
                ofs << " ";
        }
        if (i != length - 1)
            ofs << endl;
    }
}
//有待修改完善;
void myTrain::getAllPath(string v, string t) {
	int startPoint = cityMap[v];
	int target = cityMap[t];
	queue<preNode*> qu;
	preNode* p = new preNode(startPoint);
	int* visited = new int[cityNum];
	for (int i = 0; i < cityNum; i++) {
		visited[i] = 0;
	}
	qu.push(p);
	while (!qu.empty()) {
		preNode* tempP = qu.front();
		if (tempP->cityId == target) {
			vector<int> tempV;
			tempV.push_back(tempP->cityId);
			while (tempP->pre != nullptr) {
				tempP = tempP->pre;
				tempV.push_back(tempP->cityId);
			}
			reverse(tempV.begin(), tempV.end());
			trainAllPath.push_back(tempV);
		}
		else {
			int length = cityNum;
			for (int i = 0; i < length; i++) {
				if (trainMoneyMatrix[tempP->cityId][i] != 0 && trainMoneyMatrix[tempP->cityId][i] != INF && visited[i] == 0) {//先不考虑时间，直接通过是否存在money来判断是否有路径;
					if (i != target) {
						visited[i] = 1;
					}
					preNode* q = new preNode(i, tempP);
					qu.push(q);
				}
			}
		}
		qu.pop();
	}
}
