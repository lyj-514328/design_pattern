//需求：设计输入输出文件，传入对象，实现对对象的遍历，同时使用用户的输出函数
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
template<class T>
class output_item {
public:
	T* item;
	output_item(void) {
		item = nullptr;
	}
	output_item(T& obj) {
		item = &obj;
	}
	virtual void* output(T::iterator&) {
		//do nothing;
	}
	virtual ~output_item(void) {
		//do nothing;
	}

protected:
	void for_each_item(void) {
		for (auto it = item.begin(); it != item.end(); it++) {
			output(it);
		}
	}
	template<typename Function>
	void for_each_item(Function func) {
		for (auto it = item.begin(); it != item.end(); it++) {
			output(it);
			if (func(it)) break;
		}
	}
};
template<class T>
class Output: public: output_item {
protected:
	virtual void* output(T::iterator& it) {
		cout << *it << endl;
	}
};
int main(void) {
	vector<const string> test;
	test.push_back("hell world");
	//To Do
	return 0;
}