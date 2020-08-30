//需求：设计输入输出文件，传入对象，实现对对象的遍历，同时使用用户的输出函数
//764451199@qq.com
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
template<class T1>
class output_item {
public:
	T1&& item;
	output_item(T1&& obj): item(std::move(obj)) {}
	virtual void output(typename T1::value_type&) {
		//do nothing;
	}
	virtual ~output_item(void) {
		//do nothing;
	}

public:
	void for_each_item(void) {
		for (auto it = item.begin(); it != item.end(); it++) {
			output(*it);
		}
	}
	template<typename Function, typename Cmp>
	void for_each_item(Function func, Cmp conti) {
		for (auto it = item.begin(); it != item.end(); it++) {
			if (conti(*it)) continue;
			output(std::move(*it));
			if (func(*it)) break;
		}
	}
};
template<class T1>
class Output: public output_item<T1> {
public:
	template<typename M>
	Output(M&& obj): output_item<M>::output_item(std::forward<M>(obj)) {}
	void output(typename T1::value_type& it) {
		cout << it << endl;
	}
};
int main(void) {
	vector<string> test;
	test.push_back(string("begin"));
	test.push_back(string("hello world"));
	test.push_back(string("abc"));
	test.push_back(string("end"));
	Output<vector<string>> ptr(vector<string>({ string("begin"), string("hello world"), string("abc"), string("end") }));
	cout << "::for each one" << endl;
	ptr.for_each_item();
	cout << endl;
	cout << "::for each but have exception" << endl;
	ptr.for_each_item(
		[](string _x) -> bool {
			return _x == "abc";
		},
		[](string _x) -> bool {
			return _x == "hello world";
		});
	return 0;
}