#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
class Student {
public:
	string name;
	double age;
	Student(string n, double a) :name(n), age(a) {};//Student(string n, double a) {
		//name = n;
		//age = a;
	//}
	void print() {
		cout << name << " " << age<<endl;
	}
};
void addstudents(vector<Student>&students)
{
	string name;
	int age;
	cout << "请输入姓名";
	cin >> name;
	cout << "请输入年龄";
	cin >> age;
	students.push_back(Student(name, age));
}
void seestudents(vector<Student>students)
{
	if (students.size() == 0) {
		cout << "没有学生信息" << endl;
		return;
	}
	for (int i = 0; i < students.size(); i++)
		students[i].print();
}
void deletestudents(vector<Student>& students)
{
	string name;
	cout << "请输入姓名: ";
	cin >> name;
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].name == name)
		{
			students.erase(students.begin() + i);
			cout << "删除成功" << endl;
			return;
		}
	}
	cout << "没有找到该学生" << endl;
}
void searchstudents(vector<Student>& students)
{
	string name;
	cout << "请输入查找姓名:";
	cin >> name;
	for (int i = 0; i < students.size(); i++) {
		if (students[i].name == name) {
			cout << "找到学生: ";
			students[i].print();
			return;
		}
	}
	cout << "没有找到该学生" << endl;
}
void modifystudents(vector<Student>& students)
{
	string name;
	cout << "请输入要修改的姓名:";
	cin >> name;
	for(int i=0;i<students.size();i++)
	{
		if (students[i].name == name) {
			cout << "请输入新年龄；";
			cin >> students[i].age;
			cout << "修改成功" << endl;
			return;
		}
	}
	cout << "没有找到该学生" << endl;
}
void sortstudents(vector<Student>& students) {
	sort(students.begin(), students.end(), [](Student a, Student b) {
		return a.age < b.age;
	});
	cout << "排序完成(按年龄)" << endl;
}
void showmenu() {
	cout << "----学生管理系统----"<<endl;
	cout << "1 添加学生" << endl;
	cout << "2 显示学生" << endl;
	cout << "3 删除学生" << endl;
	cout << "4 查找学生" << endl;
	cout << "5 修改学生" << endl;
	cout << "6 排序学生" << endl;
	cout << "7 退出 " << endl;
}
void savestudents(vector<Student>& students)
{
	ofstream file("txst.txt");
	for (int i = 0; i < students.size(); i++)
	{
		file << students[i].name << " " << students[i].age << endl;
	}
	file.close();
}
void loadstudents(vector<Student>& students)
{
	ifstream file("txst.txt");
	string name;
	int age;
	while (file >> name >> age)
	{
		students.push_back(Student(name, age));
	}
	file.close();
}
int main()
{
	vector<Student>students;
	loadstudents(students);
	while (true) {
		showmenu();
		int choise;
		cin >> choise;
		switch (choise) {
		case 1:
			addstudents(students);
			break;
		case 2:
			seestudents(students);
			break;
		case 3:
			deletestudents(students);
			break;
		case 4:
			searchstudents(students);
			break;
		case 5:
			modifystudents(students);
			break;
		case 6:
			sortstudents(students);
			break;
		case 7:
			savestudents(students);
			cout << "退出系统" << endl;
			return 0;
		default:
			cout << "输入错误" << endl;
		}
	}
	//addstudents(students);
	//addstudents(students);
	//seestudents(students);
	
}

