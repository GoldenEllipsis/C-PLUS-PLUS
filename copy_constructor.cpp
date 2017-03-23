#include <iostream>
using namespace std;
class ABC {
private:
    int _num;
public:
    ABC(int num) {
        _num = num;
    }

//	ABC(ABC &b) {
//   	    b._num = 9;
//   	    _num =b._num;
//    }
	
	//不定义拷贝构造函数
	//编译器自动生成如下内容 
	ABC(ABC &b) {
   	    _num =b._num;
    }

    ABC(ABC *b) {
   	    b->_num = 9;
   	    _num =b->_num;
    }
    
    void outnum()
    {
//    	_num = 100;
    	cout<<_num;
	}
};
int main(){
    int a, b;
    cout<<"请输入两个数："<<endl; 
    cin >> a >> b;
    
    ABC A(a);
    cout<<"对象A的数据"<<endl; 
    A.outnum();
    cout<<endl;
    
    ABC B(b);
    cout<<"对象B的数据"<<endl;  
    B.outnum();
    cout<<endl;
    
    ABC C(B);
    cout<<"对象C的数据"<<endl;  
    C.outnum();
    cout<<endl;
    
	cout<<"对象B的数据"<<endl;  
    B.outnum();
    cout<<endl;
    
    cout<<"对象D的数据"<<endl;  
    ABC D(&B);
    D.outnum();
    cout<<endl;
    
    cout<<"对象B的数据"<<endl;  
    B.outnum();
    cout<<endl;

    return 0;
}
