//需求：设计输入输出文件，传入对象，实现对对象的遍历，同时使用用户的输出函数
#include <iostream>
#include <iterator>
using namespace std;

template <class T>
class output_item
{
    T *item;
    output_item(void)
    {
        item = nullptr;
    }
    output_item(T &obj)
    {
        item = &obj;
    }

    virtual void *output(T::iterator &)
    {
        //do nothing;
    }
    void for_each_item(void)
    {
        for (auto it = item.begin(); it != item.end(); it++)
        {
            output(it);
        }
    }
    template <typename Function>
    void for_each_item(Function func)
    {
        for (auto it = item.begin(); it != item.end(); it++)
        {
            output(it);
            if (func(it))
                break;
        }
    }
    virtual ~output_item(void){
        //do nothing;
    }
};
 int main(void)
{
}