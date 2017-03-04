#include "stdafx.h"
#include <cstdlib>
#include <ctime>

#include "BankAcount.h"
#include "TestAllClass.h"
#include "Person.h"
#include "Golf.h"
#include "Sales.h"
#include "Stack.h"
#include "Move.h"
#include "Plorg.h"
#include "List.h"
#include "vector.h"
#include "mytime3.h"
#include "stonewt.h"
#include "complex0.h"
#include "Cow.h"
#include "String2.h"
#include "Stock.h"
#include "Stack12.h"
#include "Queue.h"
#include "Classic.h"
#include "DClassic.h"

void test_class_BA(){
	BankAcount myacount = { "Max Wang", "612500008888", 99999.9 };
	myacount.show();
	cout << "请输入你的操作（存钱：d，取钱：w,退出：q）：";
	char op;
	while (cin >> op){
//		while (cin.get() != '\n')
//			continue;
		double cash = 0;
		switch (op)
		{
		case'd':
		case'D':
			cout << "请存入你的金额：";
			cin >> cash;
			myacount.deposit(cash);
			break;
		case'w':
		case'W':
			cout << "请输入你取出的金额：";
			cin >> cash;
			myacount.withdraw(cash);
			break;
		case'q':
		case'Q':
			return;
		default:
			break;
		}
		cout << "请输入你的操作（存钱：d，取钱：w,退出：q）：";
	}
	return;
}

void test_class_Person(){
	Person one;
	Person two("Max Wang");
	Person tree("Dimi", "Sam");
	one.show();
	one.FormalShow();
	two.show();
	two.FormalShow();
	tree.show();
	tree.FormalShow();
	return;
}

void test_class_Golf(){
	Golf gfone;
	Golf gftwo("Max Wang");
	Golf gftree = { "Golf Three", 123 };
	Golf *pgf = new Golf("Pointer to Golf", 5000);
	gfone.show();
	gftwo.show();
	gftree.show();
	(*pgf).show();
	gfone.set("Liu Teen", 99999);
	gfone.show();
	gftwo.writehand(1000);
	gftwo.show();
	return;
}

void test_class_Sales(){
	using namespace SALES;
	Sales one;
	const double abc[3] = { 23, 56, 10 };
	Sales two(abc, 3);
	one.show();
	two.show();
	one.set(abc, 3);
	one.show();
	return;
}

void test_class_Stack(){
	Stack cust_stack;
	Item one = { "Max Wang", 1 };
	cust_stack.push(one);
	Item two = { "Liu Ting", 9 };
	cust_stack.push(two);
	Item tree = { "LILIS", 1000 };
	cust_stack.push(tree);
	Item fore = { "LAST fore", 123 };
	cust_stack.push(fore);
	cust_stack.show_payment();
	Item temp;
	cust_stack.pop(temp);
	cust_stack.push(fore);
	cust_stack.pop(temp);
	cust_stack.pop(temp);
	cust_stack.pop(temp);
	cust_stack.pop(temp);
	cust_stack.show_payment();
	return;
}

void test_class_Move(){
	Move one = { 120, 450 };
	Move two;
	one.show();
	two.show();
	two.reset(1000, 1000);
	two.show();
	Move tree = one.add(two);
	tree.show();
	return;
}

void test_class_Plorg(){
	Plorg myplorg;
	myplorg = Plorg("Max Wang");
	myplorg.show();
	myplorg.set_ci(99999);
	myplorg.show();
	return;
}

void print_item(Type & it){
	cout << "The item is " << it << endl;
}

void test_class_List(){
	List mylist;
	const int BUF = 8;
	Type item_list[BUF] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	for (int i = 0; i < BUF; i++)
		mylist.add(item_list[i]);
	mylist.visit(print_item);
	return;
}
//使用vector类完成随机漫步randwalk
void test_class_vector(){
	using VECTOR::Vector;
	srand((unsigned int)time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0 ;
	double target;
	double dstep;
	double maxsteps = DBL_MIN, minsteps = DBL_MAX, average = 0;
	int i = 0;
	cout << "请输入你要测试的次数N：";
	cin >> i;
	const int N = i;
	cout << "请输入目标距离（q退出）：";
	while (cin >> target){
		cout << "输入步长：";
		if (!(cin >> dstep)){
			break;
		}
		while( result.magval() < target){
		//	cout << steps << ": " << result << endl;
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;			
		}
		cout << "在随机漫步" << steps << "步之后，我们已经第一次超过目标距离.\n现在的位置是：" << result << endl;
//		result.polar_mode();
//		cout << "或者是：" << result << endl;
//		cout << "平均每步距离 = " << result.magval() / steps << endl;
		if (steps > maxsteps)
			maxsteps = steps;
		if (steps < minsteps)
			minsteps = steps;
		average += steps;
		steps = 0;
		result.reset(0.0, 0.0);
		i--;
		if (i == 0)
			break;
		cout << "请输入目标距离（q退出）：";
	}
	cout << "经过" << N << "次测试.\n最大测试步数：Max = " << maxsteps 
		<< "\n最小测试步数：Min = " << minsteps 
		<< "\n平均步数：Average = " << int(average/N) << endl;
	cout << "test_class_vector测试成功！" << endl;
	cin.clear();
	while (cin.get() != '\n')
		continue;
	return;
}
void test_class_mytime3(){
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:" << endl;
	cout << aida << ";" << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca = " << temp << endl;
	temp = aida*1.17;
	cout << "Aida * 1.17 = " << temp << endl;
	cout << "10.0 * Tosca = " << 10.0*tosca << endl;
	return;
}
void test_class_stonewt(){
	Stonewt one = 275;
	Stonewt two = Stonewt(285.7);
	Stonewt tree = Stonewt(21, 8);

	cout << "The celebrity weighed " << one << endl;
	cout << "The detective weighed " << two << endl;
	cout << "The President weighed " << tree << endl;
//	one = 276.8;
//	tree = 325;
//	cout << "After dinner ,the celebrity weighed " << one << endl;
//	cout << "After dinner ,the President weighed " << tree << endl;
	Stonewt temp = one + two;
	cout << "The celebrity + detective weighed " << temp << endl;
	temp = tree - one;
	cout << "The President - celebrity weighed " << temp << endl;
	temp = two*3.5;
//	temp.set_mode_pounds();
	temp.set_mode_stone();
	cout << "The detective * 3.5 weighed (STONE Mode)" << temp << endl;
	Stonewt *stone_array = new Stonewt[6]{100,200,150};
	Stonewt max;
	Stonewt min = stone_array[0];
	Stonewt eleven = Stonewt(11, 0);
	eleven.set_mode_pounds();
	cout << eleven << endl;
	int count11 = 0;
	for (int i = 0; i < 3; i++){
		cout << stone_array[i] << endl;
		if (max < stone_array[i])
			max = stone_array[i];
		if (min > stone_array[i])
			min = stone_array[i];
		if (eleven <= stone_array[i])
			count11++;
	}
	for (int i = 3; i < 6; i++){  
		cout << "请输入一个整数：";
		int temp;
		cin >> temp;
		cin.get();
		stone_array[i] = temp;
		if (max < stone_array[i])
			max = stone_array[i];
		if (min > stone_array[i])
			min = stone_array[i];
		if (eleven <= stone_array[i])
			count11++;
	}
	cout << "Max Weight " << max << endl
		<< "Min Weight " << min << endl
		<< ">= 11 STONE is " << count11 << endl;
	return;
}
void test_class_complex(){
	complex a(3.0, 4.0);
	complex c;
	cout << "请输入一个复数（q退出）：";
	while (cin >> c){
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " <<  c * 2 << endl;
		cout << "请输入一个复数（q退出）：";
	}
	cout << "complex类测试完成" << endl;
	return;
}
void test_class_cow(){
	Cow ecow;
	Cow fcow("fcow", "LJB", 86.0);
	Cow tcow(fcow);
	ecow.ShowCow();
	fcow.ShowCow();
	tcow.ShowCow();
	ecow = fcow;
	ecow.ShowCow();
	return;
}
void test_class_String(){
	String s1(" and I am a C++ student.");
	String s2 = "Please enter your name:";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.StringUp();
//	cout << s2 << endl;
	cout << "The string\n" << s2 << "\n contains " << s2.search('A') << " 'A' characters in it.\n";
	s1 = "red";
	String rgb[3] = { String(s1), String("green"), String("blue") };
	cout << "Enter the name of a primary color for mixing light:";
	String ans;
	bool success = false;
	while (cin >> ans){
		ans.StringLow();
		for (int i = 0; i < 3; i++){
			if (ans == rgb[i]){
				cout << "That's right!" << endl;
				success = true;
				break;
			}
		}
		if (success)
			break;
		else{
			cout << "Try again!" << endl;
		}		
	}
	cout << "Bye" << endl;
	return;
}
//编程练习12-3
void test_class_Stock(){
	const int STKS = 4;
	Stock stocks[STKS] = {
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("Monolithic Obelisks", 130, 3.25),
		Stock("Fleep Enterprises", 60, 6.5)
	};
	cout << "Stock holding:" << endl;
	int st;
	for (st = 0; st < STKS; st++)
		cout << stocks[st];
	const Stock *top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);
	cout << "\nMost valuable holding;" << endl;
	cout << *top;
	return;
}
//编程练习12-4
void test_class_Stack12(){
	Stack12 mytest_stack12(5);
	ItemS one = 100;
	mytest_stack12.push(one);
	ItemS two = 200;
	mytest_stack12.push(two);
	ItemS three = 300;
	mytest_stack12.push(three);
	ItemS temp = 0;
	mytest_stack12.pop(temp);
	Stack12 the_stack12;
	the_stack12 = mytest_stack12;
	the_stack12.pop(temp);
	the_stack12.pop(temp);
	mytest_stack12.pop(temp);
	mytest_stack12.pop(temp);

	return;
}
//编程练习12-5
const int MIN_PER_HR = 60;
void test_class_Queue(){
	
	srand(unsigned(time(0)));
	cout << "银行排队模拟系统\n";
	cout << "请输入排队队列最大值：";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "请输入模拟时间（小时）：";
	int hours = INT_MAX;
	cin >> hours;
	long cyclelimit = 0;
	cyclelimit = MIN_PER_HR * hours;

	cout << "请输入每小时平均到达人数：";
	double perhour;
	cin >> perhour;
	double min_per_cust;//顾客平均到达 分钟数/人
	min_per_cust = MIN_PER_HR / perhour;

	Customer temp;
	long turnaways_cust = 0;//full queue and turnaways
	long joined_cust = 0;//joined the queue(not full)
	long served_cust = 0;//served during the simulation
	long sum_line = 0;//cumulative line length
	int wait_time = 0;//time until autoteller is free
	long line_wait = 0;//cumulative time in line
	//开始仿真
	for (int cycle = 0; cycle < cyclelimit; cycle++){
		//新顾客到
		if (newcustomer(min_per_cust)){
			//队列满了，顾客离开；否则加入队列
			if (line.isfull()){
				turnaways_cust++;
			}
			else{
				joined_cust++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		//如果服务等待时间<0,并且队列非空，则出队，对顾客进行服务
		if (wait_time <= 0 && !line.isempty()){
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();//累计等待总时间
			served_cust++;
		}
		//如果等待时间大于0，则减一
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();//每分钟队列大小总和
	}
	//输出结果
	if (joined_cust > 0){
		cout << "Customers accepted:" << joined_cust << endl;
		cout << "  Customers served:" << served_cust << endl;
		cout << "Customers turnaway:" << turnaways_cust << endl;
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout <<" averagee queue size:" << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: " << (double)line_wait / served_cust << " minutes\n";//平均等待时间 = 总等待时间/服务人数
	}
	else{
		cout << "No customers\n";
	}
	cout << "Done!\n";

	return;
}
bool newcustomer(double x){
	return (rand()*x / RAND_MAX < 1);
}
//编程练习12-6
double bank2(double people_per_h){
	srand(unsigned(time(0)));
	Queue line1(10);//排队1
	Queue line2(10);//排队2
	int hours = 100;//模拟时间
	long cyclelimit = MIN_PER_HR * hours;//循环分钟数
	double people_per_hour = people_per_h;//平均每小时到达顾客
	double min_per_cust = MIN_PER_HR / people_per_hour;//平均每个顾客相隔分钟数

	Customer temp;
	long turnaways_cust = 0;//离开顾客
	long join_cust_line1 = 0;//累计加入队1人数
	long join_cust_line2 = 0;//累计加入队2人数
	long serverd_cust_line1 = 0;//队1服务人数
	long serverd_cust_line2 = 0;//队2服务人数
	long sum_line1 = 0;
	long sum_line2 = 0;
	int wait_time_line1 = 0;
	int wait_time_line2 = 0;
	long time_line1 = 0;
	long time_line2 = 0;
	double aver_qsize = 0.0;//队列每分钟大小
	double aver_waitime = 0.0;//顾客平均等待时间
	//开始模拟
	for (int cycle = 0; cycle < cyclelimit; cycle++){
		//新顾客到,如果两个队都满，则离开。否则，顾客加入到人数较少的队列中
		if (newcustomer(min_per_cust)){
			if (line1.isfull() && line2.isfull()){
				turnaways_cust++;
			}
			else{
				if (line1.queuecount() > line2.queuecount()){
					join_cust_line2++;
					temp.set(cycle);
					line2.enqueue(temp);
				}
				else{
					join_cust_line1++;
					temp.set(cycle);
					line1.enqueue(temp);
					
				}				
			}
		}
		//队1服务
		if (wait_time_line1 <= 0 && !line1.isempty()){
			line1.dequeue(temp);
			wait_time_line1 = temp.ptime();
			time_line1 += cycle - temp.when();
			serverd_cust_line1++;
		}
		if (wait_time_line1 > 0)
			wait_time_line1--;
		sum_line1 += line1.queuecount();
		//队2服务
		if (wait_time_line2 <= 0 && !line2.isempty()){
			line2.dequeue(temp);
			wait_time_line2 = temp.ptime();
			time_line2 += cycle - temp.when();
			serverd_cust_line2++;
		}
		if (wait_time_line2 > 0)
			wait_time_line2--;
		sum_line2 += line2.queuecount();		
			
	}
	//报告	
	if (join_cust_line1 > 0 || join_cust_line2 > 0){
		cout << "队1排队人数：" << join_cust_line1 << "\t队2排队人数：" << join_cust_line2 << endl;
		cout << "队1服务人数：" << serverd_cust_line1 << "\t队2 服务人数：" << serverd_cust_line2 << endl;
		cout << "队满离开人数：" << turnaways_cust << endl;
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		aver_qsize = (sum_line1 + sum_line2) / cyclelimit;
		cout << "平均队列大小：" << aver_qsize << endl;
		aver_waitime = (time_line1 + time_line2) / (serverd_cust_line1 + serverd_cust_line2);
		cout << "顾客平均等待时间：" << aver_waitime << endl;
	}
	else{
		cout << "没有顾客！" << endl;
	}
	cout << "Done!\n";
	return aver_waitime;
}
//编程练习13-1
void Bravo(const Cd & disk){
	disk.Report();
}
void test_class_Classic(){
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat,Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd *pcd = &c1;

	cout << "Using object driectly:\n";
	int n = 0;
	cout << n;
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to object:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment:";
	Classic copy;
	copy = c2;
	copy.Report();

	return;
}
//编程练习13-2
void Bravo(const DCd & disk){
	disk.Report();
}
void test_class_DClassic(){
	DCd c1("Beatles", "Capitol", 14, 35.5);
	DClassic c2 = DClassic("Piano Sonata in B flat,Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	DCd *pcd = &c1;

	cout << "Using object driectly:\n";
	int n = 0;
	cout << n;
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to object:\n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment:";
	DClassic copy;
	copy = c2;
	copy.Report();

	cout << "复制构造DClassic:" << endl;
	DClassic last(c2);
	last.Report();
	cout << "BA";
	return;
}