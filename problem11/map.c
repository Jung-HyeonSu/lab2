#include <iostream>
#include <string>
#include <map>
using namespace std;

void print_map(map<string, int>& m, map<string, int>& m2) {
    for (map<string, int>::iterator itr = m.begin(); itr != m.end(); ++itr) {
    	for (map<string, int>::iterator itr2 = m2.begin(); itr2 != m2.end(); ++itr2) {
	    if(itr->first==itr2->first){
	    	cout <<"이름: "<< itr->first << "        중간점수: " << itr->second << " 기말점수: " <<itr2->second <<endl;
	    }	
    	}
    }
}

int main() {
    map<string, int> mScore; // map 컨테이너 생성. 키는 한글 이름, 값은 정수 점수 
    map<string, int> fScore; // map 컨테이너 생성. 키는 한글 이름, 값은 정수 점수 
    
    int num;
    int midterm;
    int final;
    string name;
    cout <<"학생 인원을 입력하세요: ";
    scanf("%d", &num);
    cout <<"이름, 중간점수, 기말점수를 입력하세요."<<endl;
    for(int i=0;i<num;i++){
    	cin >> name >> midterm >> final;
    	mScore.insert(make_pair(name, midterm)); // map에 저장 
    	fScore.insert(make_pair(name, final)); // map에 저장
    	cout<<name<<"님이 map에 추가되었습니다."<<endl;
    }
    print_map(mScore,fScore);
}   


