#include<iostream>
#include<string>
using namespace std;

class Date {			//建立日期类
private:
	int Year;
	int Month;
	int Day;
public:
	void set_Date();	  //初始设置日期（人工输入）
	void show_Date();	  //展示日期
	Date(int Y = 0, int M = 0, int D = 0) {		   //构造函数,由于函数长度较短故放在类内
		Year = Y;
		Month = M;
		Day = D;
	}
	Date(Date& d) {			  //复制构造函数
		Year = d.Year;
		Month = d.Month;
		Day = d.Day;
	}
	~Date() {			    //析构函数

	}
};

class People {			  //建立People类
private:
	string name;
	string number;
	string sex;
	Date birthday;
	string ID;
public:
	void set_People();		 //用于建立人员信息
	void show_People();		 //用于展示人员信息
	People(Date b, string n, string nu, string se, string id);		//构造函数
	People(People& p);						 //复制构造函数
};

void People::set_People() {
	string set_name, set_number, set_sex, set_ID;	   //建立临时变量（用于输入）
	Date d;											   //初始化日期对象
	d.set_Date();								 
	cout << "请输入姓名：" << endl;			 //录入人员信息
	cin >> set_name;
	cout << "请输入编号：" << endl;
	cin >> set_number;
	cout << "请输入性别：" << endl;
	cin >> set_sex;
	cout << "请输入身份证号码：" << endl;
	cin >> set_ID;
	name = set_name;
	number = set_number;
	sex = set_sex;
	ID = set_ID;
	birthday = d;
}

void People::show_People() {				  //用于展示人员信息
	cout << "姓名：" << name << endl;
	cout << "编号：" << number << endl;
	cout << "性别：" << sex << endl;
	cout << "身份证号码：" << ID << endl;
	birthday.show_Date();					 //输出日期
}

People::People(Date b = '0', string n = "0", string nu = "0", string se = "0", string id = "0") :birthday(b) {		//构造函数
	name = n;
	number = nu;
	sex = se;
	ID = id;
}

People::People(People& p) : birthday(p.birthday) {		   //复制构造函数
	name = p.name;
	number = p.number;
	sex = p.sex;
	ID = p.ID;
}

void Date::set_Date() {						  //手动录入日期
	int Y = 0;
	int M = 0;
	int D = 0;
	cout << "请输入出生年份：" << endl;
	cin >> Y;
	cout << "请输入出生月份：" << endl;
	cin >> M;
	cout << "请输入出生天数：" << endl;
	cin >> D;
	Year = Y;
	Month = M;
	Day = D;
}

void Date::show_Date() {					//展示日期
	cout << "出生日期为：" << Year << "年" << Month << "月" << Day <<"日"<< endl;
}

int main() {
	Date date1(2001,1,1);		   //实例化对象
	People people0(date1,"Zheng Li","1001","女","123456789");
	people0.show_People();
	People people[2];		 //建立长度为2的对象数组
	Date date;
	for (int i = 0; i < 2; i++) {	  //将人员信息录入(默认人数为2)
		people[i].set_People();
	}
	for (int i = 0; i < 2; i++) {	  //输出展示人员信息
		people[i].show_People();
	}
	return 0;
}