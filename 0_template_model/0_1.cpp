//需求：设计输入输出文件，传入对象，实现对对象的遍历，同时使用用户的输出函数
//764451199@qq.com
#include <cstdio>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
//基类，算法模板
template<class T1>
class output_item {
public:
	const T1* item;
	bool flag;
	template<typename M>
	output_item(M&& obj) {
		init_item(std::forward<M>(obj));
	}
	void init_item(T1&& obj) {
		cout << "this is right value" << endl;
		item = new T1(obj);
		flag = true;
	}
	void init_item(T1& obj) {
		cout << "this is left value" << endl;
		item = &obj;
		flag = false;
	}
	virtual void output(const typename T1::value_type&) {
		//do nothing;
	}
	virtual ~output_item(void) {
		if (flag) {
			delete item;
		}
		else {
		/*do nothing*/}
	}

public:
	void for_each_item(void) {
		for (auto it = item->begin(); it != item->end(); it++) {
			output(*it);
		}
	}
	template<typename Function, typename Cmp>
	void for_each_item(Function func, Cmp conti) {
		for (auto it = item->begin(); it != item->end(); it++) {
			if (conti(*it)) continue;
			output(*it);
			if (func(*it)) break;
		}
	}
};
//子类，具体实现，实现指定函数
template<class T1>
class Output: public output_item<T1> {
public:
	template<typename M>
	Output(M&& obj): output_item<T1>::output_item(std::forward<M>(obj)) {
		auto&& it = this->item;
	}
	void output(const typename T1::value_type& it) {
		cout << it << endl;
	}
};
int main(void) {
	Output<vector<string>> ptra(vector<string> { string("begin ptra"), string("hello world"), string("abc"), string("end ptra") });
	vector<string> test { string("begin ptrb"), string("hello world"), string("abc"), string("end ptrb") };
	Output<vector<string>> ptrb(test);
	cout << "::for each one" << endl;
	ptra.for_each_item();
	cout << endl;
	cout << "::for each but have exception" << endl;
	ptrb.for_each_item(
		[](string _x) -> bool {
			return _x == "abc";
		},
		[](string _x) -> bool {
			return _x == "hello world";
		});
	return 0;
}