/*================================================================
 * Author: Фан Линцзюнь(fang0jun)
 * Filename:dataBase.cpp
 * Createtime: 2021-01-01 
 ================================================================*/

#include<bits/stdc++.h>
using namespace std;

enum Country{Russia, China, Germany, Italy, Japan, England, America, France};
const int MAX_SIZE = 32767;


long int RndDouble()  {return rand() * 32768.0 + rand();}
char Rndlet()  {return 'A' + (rand()& 25 );}
int RndDiap(int nMin, int nMax)  {return nMin + rand() % (nMax - nMin + 1);}




bool smaller(string s1, string s2){
	if(s2.size() == 0) return false;
	if(s1.size() == 0) return true;
	char c1 = s1[0];
	char c2 = s2[0];
	if(c1 == c2) return smaller(s1.substr(1), s2.substr(1));  
	if(c2 == ' ') return false;
	if(c1 == ' ') return true;
	return c1 < c2;
}



/////////////////////////////////////////////////////////////////////////////////
class AirlineName{
public:
	string sName;
	
public:
	AirlineName() {}
	AirlineName(const AirlineName& airlineName){this->sName = airlineName.sName; }
	void RndInit();
	string GetString(){ return sName;}
	
	friend ostream& operator<< (ostream& os, const AirlineName& airlineName);
	friend bool operator== (const AirlineName& fio1, const AirlineName& fio2);
	friend bool operator< (const AirlineName& fio1, const AirlineName& fio2);
		
};

void AirlineName::RndInit(){
	sName = "";
	int L = RndDiap(7,10);
	for(int i = 0; i < L;i++) sName+=Rndlet();
}

ostream& operator<< (ostream& os, const AirlineName& f){
	os << f.sName;
	
	// 让名字固定占位30格子 
	int T = 30 - f.sName.size();
	if(T <= 0) return os;
	for(int i = 0; i < T; i++) os<< " ";
	return os;
}

bool operator== (const AirlineName& f1, const AirlineName& f2){
	return f1.sName == f2.sName;
} 

//bool operator< (const AirlineName& f1, const AirlineName& f2){
//	smaller(f1.sName, f2.sName);
//}

bool operator< (const AirlineName& s1, const AirlineName& s2){
	if(s2.sName.size() == 0) return false;
	if(s1.sName.size() == 0) return true;
	char c1 = s1.sName[0];
	char c2 = s2.sName[0];
	if(c1 == c2) return smaller(s1.sName.substr(1), s2.sName.substr(1));  
	if(c2 == ' ') return false;
	if(c1 == ' ') return true;
	return c1 < c2;

}


////////////////////////////////////////////////////////////////////////////////
class Flight{
private:
	AirlineName airlineName;
	Country from;
	Country to;
	int day, mouth, year = 2021;
	int h,m;  //departure time;

public:
	void RndInit(); //Инициализировать информацию о рейсе случайным образом
	AirlineName& GetName() { return airlineName;	}
	Country GetFrom() {return from;}
	Country GetTo() {return to;}
	friend ostream& operator<< (ostream& os, const Flight& s);
	string printAll()const;
	
};


void Flight::RndInit(){
	airlineName.RndInit();
	int T = RndDiap(0, 7);
	switch(T){
		case 0: from = Russia; break;
		case 1: from = China; break;
		case 2: from =  Germany; break;
		case 3: from = Italy; break;
		case 4: from = Japan; break;
		case 5: from = England; break;
		case 6: from = America; break;
		case 7: from = France; break;
	}
	
	T = (T+RndDiap(0, 6) ) % 7; 
	switch(T){
		case 0: to = Russia; break;
		case 1: to = China; break;
		case 2: to =  Germany; break;
		case 3: to = Italy; break;
		case 4: to = Japan; break;
		case 5: to = England; break;
		case 6: to = America; break;
		case 7: to = France; break;
	}
	
	
	
	mouth = RndDiap(1, 12);
	day = RndDiap(1, 28); 
	if(day != 2){
		day += RndDiap(0, 2);
		if(day == 1 || day ==  3|| day ==  5||day ==  7||day ==  8||day ==  10||day ==  12)
			day +=  RndDiap(0, 1);
	}
	
	h = RndDiap(0, 24);
	m = RndDiap(0, 59);
	
}


ostream& operator<< (ostream& os, const Flight& s){
	os << "AirlineName: " << s.airlineName << " ";
	
	os << "From: ";
	switch(s.from){
		case Russia: os << " Russia"; break;
		case China: os << " China"; break;
		case Germany: os << " Germany"; break;
		case Italy: os << " Italy"; break;
		case Japan: os << " Japan"; break;
		case England: os << " England"; break;
		case America: os << " America"; break;
		case France: os << " France"; break;
	}
	
	os << " ---> ";
	switch(s.to){
		case Russia: os << " Russia     "; break;
		case China: os <<  " China      "; break;
		case Germany: os <<" Germany    "; break;
		case Italy: os <<  " Italy      "; break;
		case Japan: os <<  " Japan      "; break;
		case England: os <<" England    "; break;
		case America: os <<" America    "; break;
		case France: os << " France     "; break;
	}
	
	
	os.width(8); os << "departure: "; 
	if(s.h < 10) os << 0; os << s.h << ":";
	if(s.m < 10) os << 0; os << s.m;
	
	os.width(10);os << "   Date: " ;
	if(s.day < 10) os << 0; os << s.day << ".";
	if(s.mouth < 10) os << 0; os << s.mouth << ".";
	os.width(4); os << s.year;
	
	os<<endl;
	return os;

}

string Flight::printAll() const{
    stringstream ss;
    streambuf* buffer = cout.rdbuf();
    cout.rdbuf(ss.rdbuf());
    cout << *this;
    string res(ss.str());
    cout.rdbuf(buffer);
    return res;
}


/////////////////////////////////////////////////////////////////////////////////////////


class FlightAll{
private:
	int nNum;  
	Flight flights[MAX_SIZE];
public:
	FlightAll() {nNum = 0;}
	Flight GetFlight(int i)const {return flights[i];}
	int GetKol() { return nNum;}
	AirlineName GetName(int i) {return flights[i].GetName();	} 
	Country GetFrom(int i) {return flights[i].GetFrom();	} 
	Country GetTo(int i) {return flights[i].GetTo();	} 
	bool Add(Flight& st);
	friend ostream& operator<< (ostream& os, const FlightAll& stall);
	string printAll()const;
}stall;

bool FlightAll::Add(Flight& st){
	if(nNum >= MAX_SIZE) return false;
	flights[nNum++] = st;
	return true;
}

ostream& operator<< (ostream& os, const FlightAll& stall){
	for(int i = 0; i < stall.nNum; i++){
		os.width(4); os << i << ". ";
		os<< stall.flights[i];
	}
	return os;
}
string FlightAll::printAll() const{
    stringstream ss;
    streambuf* buffer = cout.rdbuf();
    cout.rdbuf(ss.rdbuf());
    cout << *this;
    string res(ss.str());
    cout.rdbuf(buffer);
    return res;
}

/////////////////////////////////////////////////////////////////////////////////
template <class Key>
class AVLTree{
private:
	int nDepth; 
	Key* pKey; 
	int array[MAX_SIZE];
	int nIndex; 
	AVLTree* pParent;  
	AVLTree* pLeft;
	AVLTree* pRight;
public:
	AVLTree(){ nDepth = -1; }
	~AVLTree() {if(nDepth<0) return; delete pKey; delete pLeft; delete pRight;}
	int GetDepth() { return nDepth;}
	int GetIndex() {return nIndex;}
	AVLTree* GetLeft() {return pLeft;}
	AVLTree* GetRight() {return pRight;}
	
	bool Add(Key* pKey, AVLTree* pParent, int nIndex);
	int* Search(Key* pKey);
    int Search_i(Key* pKey)const;
	string printAll2(Key* pKey,const FlightAll& flall);
};



template <class Key> // 以AirlineName为key 
bool AVLTree<Key>::Add(Key* pKey, AVLTree* pParent, int nI){ 
	if(nDepth < 0){
		nDepth = 0;
		this->pKey = new Key(*pKey);
		this->pParent = pParent;
		this->nIndex = nI;
		this->pLeft = new AVLTree<Key>;
		this->pRight = new AVLTree<Key>;
		return true;
	}
	if(*this->pKey == *pKey) {this->array[nIndex++] = nI; return true;} 
	if(*this->pKey < *pKey){ if(!pLeft->Add(pKey, this, nI)) return false;}
	else 				   {if(!pRight->Add(pKey, this, nI)) return false;}
	
	nDepth = max(pLeft->GetDepth(), pRight->GetDepth()) + 1;
	
	return true;
} 
//
//template <class Key>
//bool AVLTree<Key>::Update(Key* pKey, AVLTree* pParent, int nI){
//	if(nDepth < 0){ // init
//		nDepth = 0;
//		this->pKey = new Key(*pKey);
//		this->pParent = pParent;
//		this->nIndex = nI;
//		this->pLeft = new AVLTree<Key>;
//		this->pRight = new AVLTree<Key>;
//		return true;
//	}
//	if(*this->pKey == *pKey) {this->array[nIndex++] = nI; return true;} 
//	if(*this->pKey < *pKey){ if(!pLeft->Add(pKey, this, nI)) return false;}
//	else 				   {if(!pRight->Add(pKey, this, nI)) return false;}
//	
//	nDepth = max(pLeft->GetDepth(), pRight->GetDepth()) + 1;
//	
//	return true;
//} 



//template <class Key>
//bool AVLTree<Key>::Delete(Key* pKey){
//	if(nDepth <= 0){ // init
//		return -1;
//	}
//	if(*this->pKey == *pKey) {this->array[nIndex++] = nI; return true;} 
//	if(*this->pKey < *pKey){ if(!pLeft->Add(pKey, this, nI)) return false;}
//	else 				   {if(!pRight->Add(pKey, this, nI)) return false;}
//	
//	nDepth = max(pLeft->GetDepth(), pRight->GetDepth()) - 1;
//	
//	return true;
//} 





template <typename Key>
int* AVLTree<Key>::Search(Key* pKey) {
    if(*this->pKey == *pKey) return this->array;
    return (*this->pKey < *pKey) ? pLeft->Search(pKey) : pRight->Search(pKey);
}

template <class Key>
int AVLTree<Key>::Search_i(Key* pKey) const{
	if(nDepth < 0) return -1;
	if(*this->pKey == *pKey) return this->nIndex;
	return (*this->pKey < *pKey) ? pLeft->Search_i(pKey) : pRight->Search_i(pKey);
}





template <typename Key>
string AVLTree<Key>::printAll2(Key* pKey, const FlightAll& flall){
    stringstream ss;
    streambuf* buffer = cout.rdbuf();
    cout.rdbuf(ss.rdbuf());
    int *res;
    int res_n;
    if((res_n = Search_i(pKey)) != -1) res = Search(pKey);
    for(int i = 0; i < res_n; i++) cout << flall.GetFlight(res[i]) << endl;
    string s(ss.str());
    cout.rdbuf(buffer);
    return s;
}

string Country_to_string(Country);


string Country_to_string(Country c){
    string res;
    switch(c){
        case 0: res = "Russia";break;
        case 1: res = "China";break;
        case 2: res = "Germany";break;
        case 3: res = "Italy";break;
        case 4: res = "Japan";break;
        case 5: res = "England";break;
        case 6: res = "America";break;
        case 7: res = "France";break;
    }
    return res;
}

Country string_to_Country(char* s){  //Чтобы распечатать
    Country c;
    if(strcmp(s,"Russia\n") == 0) c = Russia;
    else if(strcmp(s,"China\n") == 0) c = China;
    else if(strcmp(s,"America\n") == 0) c = America;
    else if(strcmp(s,"England\n") == 0) c = England;
    else if(strcmp(s,"France\n") == 0) c = France;
    else if(strcmp(s,"Germany\n") == 0) c = Germany;
    else if(strcmp(s,"Japan\n") == 0) c = Japan;
    else if(strcmp(s,"Italy\n") == 0) c = Italy;
    else throw "ERROR";
    return c;
}

//////////////////////////////////////////////////////////////////////////////////////



/* 
 *
 * You can view the result directly through the function 'main'
 *
 */




int main(int argc, char* argv[]){
	FlightAll stall;  //stall.flights  Массив самолетов
	AVLTree<AirlineName> avlFIO;  // Возьмите название самолета как ключ к дереву

	
	
	for(int i = 0; i < 100; i++){
		Flight st; st.RndInit();  //Создайте самолет и инициализируйте его
		stall.Add(st);
		
		AirlineName airlineName(stall.GetName(i));  // Получить имя самолета в массиве самолетов и создать объект имени (класса) самолета
		if(avlFIO.Search(&airlineName) >= 0) continue;  //Если самолет уже в дереве, пропустите
	
		
		avlFIO.Add(&airlineName, NULL, stall.GetKol()-1);  //Добавляем к дереву самолет
		
		
	} 
	
	cout << stall << endl << endl; 
	
	AirlineName airlineName = stall.GetName(1);  // Получить имя самолета в массиве самолетов
	Country From = stall.GetFrom(1);  
	Country To = stall.GetTo(1);
	cout << airlineName << endl;
	cout << Country_to_string(From)<< endl;
	cout << Country_to_string(To)<< endl;
	cout << avlFIO.Search(&airlineName) << endl << endl; // Функция поиска
	

}





