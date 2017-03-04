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
	cout << "��������Ĳ�������Ǯ��d��ȡǮ��w,�˳���q����";
	char op;
	while (cin >> op){
//		while (cin.get() != '\n')
//			continue;
		double cash = 0;
		switch (op)
		{
		case'd':
		case'D':
			cout << "�������Ľ�";
			cin >> cash;
			myacount.deposit(cash);
			break;
		case'w':
		case'W':
			cout << "��������ȡ���Ľ�";
			cin >> cash;
			myacount.withdraw(cash);
			break;
		case'q':
		case'Q':
			return;
		default:
			break;
		}
		cout << "��������Ĳ�������Ǯ��d��ȡǮ��w,�˳���q����";
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
//ʹ��vector������������randwalk
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
	cout << "��������Ҫ���ԵĴ���N��";
	cin >> i;
	const int N = i;
	cout << "������Ŀ����루q�˳�����";
	while (cin >> target){
		cout << "���벽����";
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
		cout << "���������" << steps << "��֮�������Ѿ���һ�γ���Ŀ�����.\n���ڵ�λ���ǣ�" << result << endl;
//		result.polar_mode();
//		cout << "�����ǣ�" << result << endl;
//		cout << "ƽ��ÿ������ = " << result.magval() / steps << endl;
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
		cout << "������Ŀ����루q�˳�����";
	}
	cout << "����" << N << "�β���.\n�����Բ�����Max = " << maxsteps 
		<< "\n��С���Բ�����Min = " << minsteps 
		<< "\nƽ��������Average = " << int(average/N) << endl;
	cout << "test_class_vector���Գɹ���" << endl;
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
		cout << "������һ��������";
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
	cout << "������һ��������q�˳�����";
	while (cin >> c){
		cout << "c is " << c << endl;
		cout << "complex conjugate is " << ~c << endl;
		cout << "a is " << a << endl;
		cout << "a + c is " << a + c << endl;
		cout << "a - c is " << a - c << endl;
		cout << "a * c is " << a * c << endl;
		cout << "2 * c is " <<  c * 2 << endl;
		cout << "������һ��������q�˳�����";
	}
	cout << "complex��������" << endl;
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
//�����ϰ12-3
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
//�����ϰ12-4
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
//�����ϰ12-5
const int MIN_PER_HR = 60;
void test_class_Queue(){
	
	srand(unsigned(time(0)));
	cout << "�����Ŷ�ģ��ϵͳ\n";
	cout << "�������ŶӶ������ֵ��";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "������ģ��ʱ�䣨Сʱ����";
	int hours = INT_MAX;
	cin >> hours;
	long cyclelimit = 0;
	cyclelimit = MIN_PER_HR * hours;

	cout << "������ÿСʱƽ������������";
	double perhour;
	cin >> perhour;
	double min_per_cust;//�˿�ƽ������ ������/��
	min_per_cust = MIN_PER_HR / perhour;

	Customer temp;
	long turnaways_cust = 0;//full queue and turnaways
	long joined_cust = 0;//joined the queue(not full)
	long served_cust = 0;//served during the simulation
	long sum_line = 0;//cumulative line length
	int wait_time = 0;//time until autoteller is free
	long line_wait = 0;//cumulative time in line
	//��ʼ����
	for (int cycle = 0; cycle < cyclelimit; cycle++){
		//�¹˿͵�
		if (newcustomer(min_per_cust)){
			//�������ˣ��˿��뿪������������
			if (line.isfull()){
				turnaways_cust++;
			}
			else{
				joined_cust++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		//�������ȴ�ʱ��<0,���Ҷ��зǿգ�����ӣ��Թ˿ͽ��з���
		if (wait_time <= 0 && !line.isempty()){
			line.dequeue(temp);
			wait_time = temp.ptime();
			line_wait += cycle - temp.when();//�ۼƵȴ���ʱ��
			served_cust++;
		}
		//����ȴ�ʱ�����0�����һ
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queuecount();//ÿ���Ӷ��д�С�ܺ�
	}
	//������
	if (joined_cust > 0){
		cout << "Customers accepted:" << joined_cust << endl;
		cout << "  Customers served:" << served_cust << endl;
		cout << "Customers turnaway:" << turnaways_cust << endl;
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout <<" averagee queue size:" << (double)sum_line / cyclelimit << endl;
		cout << " average wait time: " << (double)line_wait / served_cust << " minutes\n";//ƽ���ȴ�ʱ�� = �ܵȴ�ʱ��/��������
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
//�����ϰ12-6
double bank2(double people_per_h){
	srand(unsigned(time(0)));
	Queue line1(10);//�Ŷ�1
	Queue line2(10);//�Ŷ�2
	int hours = 100;//ģ��ʱ��
	long cyclelimit = MIN_PER_HR * hours;//ѭ��������
	double people_per_hour = people_per_h;//ƽ��ÿСʱ����˿�
	double min_per_cust = MIN_PER_HR / people_per_hour;//ƽ��ÿ���˿����������

	Customer temp;
	long turnaways_cust = 0;//�뿪�˿�
	long join_cust_line1 = 0;//�ۼƼ����1����
	long join_cust_line2 = 0;//�ۼƼ����2����
	long serverd_cust_line1 = 0;//��1��������
	long serverd_cust_line2 = 0;//��2��������
	long sum_line1 = 0;
	long sum_line2 = 0;
	int wait_time_line1 = 0;
	int wait_time_line2 = 0;
	long time_line1 = 0;
	long time_line2 = 0;
	double aver_qsize = 0.0;//����ÿ���Ӵ�С
	double aver_waitime = 0.0;//�˿�ƽ���ȴ�ʱ��
	//��ʼģ��
	for (int cycle = 0; cycle < cyclelimit; cycle++){
		//�¹˿͵�,��������Ӷ��������뿪�����򣬹˿ͼ��뵽�������ٵĶ�����
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
		//��1����
		if (wait_time_line1 <= 0 && !line1.isempty()){
			line1.dequeue(temp);
			wait_time_line1 = temp.ptime();
			time_line1 += cycle - temp.when();
			serverd_cust_line1++;
		}
		if (wait_time_line1 > 0)
			wait_time_line1--;
		sum_line1 += line1.queuecount();
		//��2����
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
	//����	
	if (join_cust_line1 > 0 || join_cust_line2 > 0){
		cout << "��1�Ŷ�������" << join_cust_line1 << "\t��2�Ŷ�������" << join_cust_line2 << endl;
		cout << "��1����������" << serverd_cust_line1 << "\t��2 ����������" << serverd_cust_line2 << endl;
		cout << "�����뿪������" << turnaways_cust << endl;
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		aver_qsize = (sum_line1 + sum_line2) / cyclelimit;
		cout << "ƽ�����д�С��" << aver_qsize << endl;
		aver_waitime = (time_line1 + time_line2) / (serverd_cust_line1 + serverd_cust_line2);
		cout << "�˿�ƽ���ȴ�ʱ�䣺" << aver_waitime << endl;
	}
	else{
		cout << "û�й˿ͣ�" << endl;
	}
	cout << "Done!\n";
	return aver_waitime;
}
//�����ϰ13-1
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
//�����ϰ13-2
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

	cout << "���ƹ���DClassic:" << endl;
	DClassic last(c2);
	last.Report();
	cout << "BA";
	return;
}