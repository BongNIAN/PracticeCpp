#include<iostream>
using namespace std;
#include<algorithm>

//Ÿ�Կ� �������� �ʰ� �����͸� ���� �� �ִ� �迭�� ���������
// ������ ->�⺻�����ڴ� ũ�Ⱑ 10
// �Ű������� �ش� ���ڿ� �ش��ϴ� ũ���� �迭

//push_back -> ���ڷ� ���� ���Ҹ� �� �ڿ� �߰� void,�迭�� ũ�Ⱑ 
// �� �� ��� �ƹ����۵� ���� �ʴ´�.
//pop_back ->������ ���Ҹ� ����, ���� ������ ���Ұ� ���ٸ�
//�ƹ� ���۵� ���� �ʰ� void ,����x
// size�� ���ڰ� ����, ���� ������ ������ ��ȯ
// capacity ���� ���� �迭�� ũ�⸦ ��ȯ 
//

template <typename T>
class SimpleVector {
public :
	SimpleVector() {
		currentCapacity = 0;
		currentSize = 0;
		cout << "SimpleVector����! " << endl;
	}
	SimpleVector(int cap) : currentCapacity(cap), currentSize(0) {
	//���⿡ �Ҵ�������ҰͰ�����?
		data = new T[cap];
	}
	~SimpleVector() {
		cout << "���� �Ҹ�" << endl;
		delete[] data; //������ �̰� �³�? 
		// delete data[]�� �ƴ϶�
		// delete[] data;
	}
	void pop_back() {
		if (currentSize == 0) {
			cout << "size is 0" << endl;
		}
		else{ currentSize--; }
		
	}
	void push_back(const T& ins ) { 
		//T& ��  &T�� ���� 
		// ���������  T&�� �´� �̰� T&�� &T �� ���� �ƴ϶�
		// T& ins��� ���� ���Ѱ� ����
		//���ۼ���� �����ʹ� �� ����� �����ؾ��ҵ�
		//const T& ins ��
		//T& const ins�� ����?
		if (currentSize < currentCapacity) {

			data[currentSize++] = ins; // �̰� �´°��� üũ
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
	//	return data1 < data2; =>�̰� til�� ����� 
	//}

	bool compareByData( T& data1, T& data2) {
	
		return data1 > data2;
	}

	void sortDes(){//�������� 
		std::sort(data, data + currentSize, 
			[this](T& data1,T&data2)
			{
				return compareByData(data1, data2);
			});
	}
	/**
	* ���⿡�� ���� simpleVectorŬ���� ���� compare�� ȣ���ϴ°��� �˰� ������
	* ��ǻ�ʹ� �װ� ���� ���Ѵ�.
	* ������ ����Լ������� �Ͻ������� this->�� ���� ������
	* ��ǻ�Ͱ� this�� ��ü ���� Ŭ�������� ������ ���Ѵ�.
	* �� ��Ȯ�ϰ� Ŭ���� ���ο��� std::sort�� �۵��� �ϴµ� 
	* �츮�� ����Լ��� ������ �������� �׻� Ŭ������ �����Ѵ�
	* �� Ŭ�����Լ��� this->�� ����ؼ� ��ü�ϰ�, ������� ���� �� 
	* this�� �Ͻ������� ȣ��ȴ�.
	* 
	* ������ sort�Լ� ���ο��� ���ǹ����� ����Լ��� ȣ���� ��
	* � Ŭ�������� �� ���� ����.
	* 
	* ���� Ŭ���� ���ο��� sort�� �����ϰ� �Ϸ��� ���� ������ ���� �ذ���� �ϳ��� �����ؾ��Ѵ�.
	* 1. �����Լ� ��� 
	  2. ���� ��� ���� ���
	  3. �������� ���
	  2- ���� ��� ���� ����� ��������� static���� ���� ��ǻ�Ͱ� �ν��� �� �ְ� �ϴ°��̰�
	  3- ���� ������ ����ϴ� ���� Ŭ���� �ܺο��� �Լ��� �����Ͽ�, 
	  ��ǻ�Ͱ� Ŭ���� ������ ����Լ��� �������°��� �ƴ� �ܺ������� �������� �Լ��� ������
	  �ν��� �� �ְ� ���ִ� ���̴�.
	  
	  �� �� �����Լ��� ���� ����ϰ��� �Ѵ�.
	  ���� ) �����Լ���°� ó�������

	  ������ TIL�� �����Ͽ� �ø������� �����ϰ� �����Լ��� �Լ������� ���� ���ο� �Լ��� �������°Ͱ���
	  �� ..��������?������?��������? �����̶��ؾ��ϳ�? ������ ������ ��Ʈ�� ��������
	  
	  ��ư �Լ��� ������ [this](T& data1,T&data2)
			{
				return compareByData(data1, data2);
			});
			[ this] �� �ش� Ŭ�������� ����Ұ��� ĸ���Ѵ�.
			()�� ���ڸ� ���ְ�
			{}�� �Լ��� �ۼ��Ѵ�.
			���� Ŭ���� ���ο� ����Լ��ν� ���Լ��� �������� ������
			�����⵵�ϰ� �̷��� �ص� �ǳ�? ��� �ǹ����� ��
			Ŭ���� ���� ����Լ��� ȣ���Ͽ���.

	*
	*/
	void sortAsc() {//�������� 
		std::sort(data, data + currentSize);
	}

	//�����ؾ��Ұ� 1. resize , simple������ (Ŭ����) , push_back

	SimpleVector(const SimpleVector& vec,int newCapacity) {
		/**���⿡�� �ڱ� �ڽ��� ���ڷ� �޾Ƽ� Ȯ���Ű������� �װ� ��� ����?*/
		//�̰� ���Ӱ� ���縦 �� Ŭ������ �ϳ� �����. ->�������� ,�������� ���� 
		//�ٵ� �̰� int���� ���Ӱ� ������ �ȵǴ°ǰ�?? �� �ȵǴ°���?
		

		currentSize = vec.currentSize;
		currentCapacity = vec.currentCapacity + newCapacity;
		data = new T[currentCapacity];

		for (int i = 0; i < vec.currentCapacity; i++) {
			// data[i] = vec.[i]; => Ʋ������ : vec[i]�� �ƴ϶� vec.data[i]
			data[i] = vec.data[i];
		}
		
	
	}
private : 
	T* data; //���� �迭
	int currentSize;// ���� ������ ����
	int currentCapacity; //�迭�� �ִ� ũ��
	void resize(int newCapacity) {
	/*�׷��� ���࿡ �������غ��� �츮�� ���� new [] �� �迭�Ҵ��� �ߴµ�
	* ���࿡ ó������ for������ �ϳ��� new�� ���ϰ�ü�Ҵ��� �ߴٰ� ġ�� 
	* size���� �ٽ� newCapacity��ŭ ���ϰ�ü �Ҵ��� �ϴµ� 
	* �׷��� ������尡 �ʹ� ū��?
	* �׷��� delete[]�ϰ� ���ο� �����ŭ new[]��ŭ ������ϴ°ǰ�?
	*/  


		SimpleVector newVector(*this, newCapacity); // ���� ������ ȣ��
		delete[] data;
	    data = newVector.data;
		
	    currentCapacity = newVector.currentCapacity;

	    newVector.data = nullptr; // ���� ��ü���� �޸� ���� ����
		//�̰� ���� ������ �ذ�ƴ�. �̰� ������ �˸� ���� ���̴�.
		//�̰� �� ���°ž�?
		//��¥ ����3���� �����̴� ��������;;
		// �߿��Ѱ� �� �ٷ�´����̾� ��..
		cout << "test2 : " << endl;
		//�ߵ�� ���⿡�� newVector�� ���ð�ü�̱� ������ �Լ��� ������ ������°ž�
		//���⿡�� ���ͼҸ��� ��µǴ°��� �� �Լ��� �� ������ �� �� 
		//  �׷� �ߺ������� �Ͼ�� �ȴٰ� newVector�� �Ҹ��ϸ鼭
		// �׷��� ������� newVector.data�� ���������� null�� ������ִ°ž�
		// �׷��� ���� �����Ϳ� �Ҵ�� 2���߿� �Ѱ��� ���Եǰ� �����Ͱ� ���޵Ǵ°��� 


	}
};
//��.. �̰� ȣ���Ҷ� �μ���<T>�� �ְٴٴ� ���̱���..
// ����Ʈ�����͵� �����غ����ҵ� ->�迭�� ��� ���°���?
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
	// �̰� �����ͷ� ����� �����ؾ�����?

	

	
	// SimpleVector<int>vec; //�����Ҵ��̹Ƿ� �ٷ� ������ 

	/*delete vec;*/

	return 0;
}