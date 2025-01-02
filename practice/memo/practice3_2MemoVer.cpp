#include<iostream>
using namespace std;
#include<algorithm>

//타입에 의존하지 않고 데이터를 받을 수 있는 배열을 멤버변수로
// 생성자 ->기본생성자는 크기가 10
// 매개변수는 해당 숫자에 해당하는 크기의 배열

//push_back -> 인자로 받은 원소를 맨 뒤에 추가 void,배열의 크기가 
// 꽉 찰 경우 아무동작도 하지 않는다.
//pop_back ->마지막 원소를 제거, 만일 제거할 원소가 없다면
//아무 동작도 하지 않고 void ,인자x
// size는 인자가 없고, 현재 원소의 개수를 반환
// capacity 현재 내부 배열의 크기를 반환 
//

template <typename T>
class SimpleVector {
public :
	SimpleVector() {
		currentCapacity = 0;
		currentSize = 0;
		cout << "SimpleVector등장! " << endl;
	}
	SimpleVector(int cap) : currentCapacity(cap), currentSize(0) {
	//여기에 할당해줘야할것같은데?
		data = new T[cap];
	}
	~SimpleVector() {
		cout << "벡터 소멸" << endl;
		delete[] data; //문법이 이게 맞나? 
		// delete data[]가 아니라
		// delete[] data;
	}
	void pop_back() {
		if (currentSize == 0) {
			cout << "size is 0" << endl;
		}
		else{ currentSize--; }
		
	}
	void push_back(const T& ins ) { 
		//T& 와  &T의 차이 
		// 결론적으로  T&가 맞다 이걸 T&와 &T 로 볼게 아니라
		// T& ins라고 보면 편한것 같다
		//앰퍼센드와 포인터는 좀 제대로 공부해야할듯
		//const T& ins 와
		//T& const ins의 차이?
		if (currentSize < currentCapacity) {

			data[currentSize++] = ins; // 이게 맞는건지 체크
			cout << "t is " << ins << "  data is :  " << data[currentSize - 1] << endl;
			cout << "\n";
		}
		else { 
			cout <<"size is Full , realloc" << endl;
			resize(5);
			data[currentSize++] = ins;
		}
	
	} 

	int currentsize() const {
		return currentSize;
	}
	int capacity() const {
		return currentCapacity;
	}
	class Print {
	public: 
		void print(const SimpleVector & vec) const{
			
			cout << "print data : ";
			for (int i = 0; i < vec.currentsize(); i++) {
				cout <<" " << vec.data[i] << " ";
				
			}
			cout << "\n";
		}

	};


	//bool compareByData( T& data1, T& data2) {
	//
	//	return data1 < data2; =>이거 til에 써놓자 
	//}

	bool compareByData( T& data1, T& data2) {
	
		return data1 > data2;
	}

	void sortDes(){//내림차순 
		std::sort(data, data + currentSize, 
			[this](T& data1,T&data2)
			{
				return compareByData(data1, data2);
			});
	}
	/**
	* 여기에서 나는 simpleVector클래스 내의 compare을 호출하는것을 알고 있지만
	* 컴퓨터는 그걸 알지 못한다.
	* 하지만 멤버함수에서는 암시적으로 this->가 들어가기 때문에
	* 컴퓨터가 this가 대체 무슨 클래스인지 알지를 못한다.
	* 더 정확하게 클래스 내부에서 std::sort가 작동을 하는데 
	* 우리가 멤버함수로 설정한 값에서는 항상 클래스가 들어가야한다
	* 그 클래스함수를 this->를 사용해서 대체하고, 사용하지 않을 시 
	* this가 암시적으로 호출된다.
	* 
	* 하지만 sort함수 내부에의 조건문에서 멤버함수를 호출할 때
	* 어떤 클래스인지 알 수가 없다.
	* 
	* 따라서 클래스 내부에서 sort가 동작하게 하려면 나는 다음과 같은 해결법중 하나를 선택해야한다.
	* 1. 람다함수 사용 
	  2. 정적 멤버 변수 사용
	  3. 비멤버변수 사용
	  2- 정적 멤버 변수 사용은 멤버변수를 static으로 만들어서 컴퓨터가 인식할 수 있게 하는것이고
	  3- 비멤버 변수를 사용하는 것은 클래스 외부에서 함수를 선언하여, 
	  컴퓨터가 클래스 내부의 멤버함수를 가져오는것이 아닌 외부적으로 독립적인 함수를 가져와
	  인식할 수 있게 해주는 것이다.
	  
	  이 중 람다함수에 대해 사용하고자 한다.
	  이유 ) 람다함수라는걸 처음써봐서

	  조만간 TIL에 정리하여 올리겠지만 간단하게 람다함수란 함수내에서 무언가 새로운 함수를 가져오는것같다
	  좀 ..독립적인?평행한?병렬적인? 느낌이라해야하나? 조만간 느낌을 팩트로 정리하자
	  
	  여튼 함수의 사용법은 [this](T& data1,T&data2)
			{
				return compareByData(data1, data2);
			});
			[ this] 로 해당 클래스에서 사용할것을 캡쳐한다.
			()로 인자를 써주고
			{}로 함수를 작성한다.
			나는 클래스 내부에 멤버함수로써 비교함수를 만들어놨기 때문에
			귀찮기도하고 이렇게 해도 되나? 라는 의문점이 들어서
			클래스 내부 멤버함수를 호출하였다.

	*
	*/
	void sortAsc() {//내림차순 
		std::sort(data, data + currentSize);
	}

	//구현해야할것 1. resize , simple생성자 (클래스) , push_back

	SimpleVector(const SimpleVector& vec,int newCapacity) {
		/**여기에서 자기 자신을 인자로 받아서 확장시키고싶은데 그걸 어떻게 하지?*/
		//이건 새롭게 복사를 할 클래스를 하나 만든다. ->깊은복사 ,얕은복사 개념 
		//근데 이거 int값을 새롭게 넣으면 안되는건가?? 왜 안되는거지?
		

		currentSize = vec.currentSize;
		currentCapacity = vec.currentCapacity + newCapacity;
		data = new T[currentCapacity];

		for (int i = 0; i < vec.currentCapacity; i++) {
			// data[i] = vec.[i]; => 틀린이유 : vec[i]가 아니라 vec.data[i]
			data[i] = vec.data[i];
		}
		
	
	}
private : 
	T* data; //동적 배열
	int currentSize;// 현재 원소의 개수
	int currentCapacity; //배열의 최대 크기
	void resize(int newCapacity) {
	/*그러면 만약에 생각을해보자 우리가 지금 new [] 로 배열할당을 했는데
	* 만약에 처음부터 for문으로 하나씩 new를 단일객체할당을 했다고 치면 
	* size부터 다시 newCapacity만큼 단일객체 할당을 하는데 
	* 그러면 오버헤드가 너무 큰가?
	* 그러면 delete[]하고 새로운 사이즈만큼 new[]만큼 해줘야하는건가?
	*/  


		SimpleVector newVector(*this, newCapacity); // 복사 생성자 호출
		delete[] data;
	    data = newVector.data;
		
	    currentCapacity = newVector.currentCapacity;

	    newVector.data = nullptr; // 원본 객체에서 메모리 해제 방지
		//이걸 쓰고 오류가 해결됐다. 이게 뭔지만 알면 과제 끝이다.
		//이건 왜 쓰는거야?
		//진짜 과제3번은 전설이다 개지리네;;
		// 중요한걸 다 다루는느낌이야 와..
		cout << "test2 : " << endl;
		//잘들어 여기에서 newVector는 로컬객체이기 때문에 함수가 끝나면 사라지는거야
		//여기에서 벡터소멸이 출력되는거지 이 함수가 다 끝나고 난 후 
		//  그럼 중복해제가 일어나게 된다고 newVector가 소멸하면서
		// 그래서 사라지는 newVector.data를 강제적으로 null로 만들어주는거야
		// 그러면 같은 데이터에 할당된 2개중에 한개가 남게되고 데이터가 전달되는거지 


	}
};
//아.. 이게 호출할때 인수로<T>를 넣겟다는 말이구나..
// 스마트포인터도 공부해봐야할듯 ->배열엔 어떻게 쓰는건지?
int main() {

	SimpleVector<int> vec(3);// = new SimpleVector<int>(10);
	SimpleVector<int>::Print P;
	
	vec.push_back(3);
	vec.push_back(3);
	vec.push_back(3);
	P.print(vec);
	
	vec.push_back(3);
	
	P.print(vec);
	cout << "size is " << vec.capacity() << endl;

	/*vec.push_back(3);
	P.print(vec);
	cout << "size is " << vec.currentsize() << endl;*/
	
	
	
	
	/*
	vec.push_back(5);
	vec.push_back(14);
	vec.push_back(12);
	vec.push_back(11);
	vec.push_back(10);
	P.print(vec);
	vec.sortAsc();
	cout << "after Sort" << endl;
	P.print(vec);

	cout << "pop start" << endl;
	vec.pop_back();
	P.print(vec);
	
	cout << "pop start" << endl;
	vec.pop_back();
	P.print(vec);
	
	cout << "pop start" << endl;
	vec.pop_back();
	P.print(vec);
	cout << "push start" << endl;
	vec.push_back(10);
	P.print(vec);
	cout << "pop start" << endl;
	vec.pop_back();
	P.print(vec);*/
	// 이걸 포인터로 쓸라면 어케해야하지?

	

	
	// SimpleVector<int>vec; //정적할당이므로 바로 생성자 

	/*delete vec;*/

	return 0;
}