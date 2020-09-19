//вектор, клас array(шаблонний клас)
#include <iostream>
#include <array>
#include <vector>
#include <time.h>

using namespace std;


//array <int, 10> a1; при виведенні за мейн, в глобальнй простір, масив обнуляється
void test() {
	const int n = 10;
	array <int, n> a1{ 10,20,30 };
	for (auto e : a1) // працює лише з колекціями в яких є ітератор
		cout << e << endl;
	//cout << a1.size() << endl;
	//cout << a1.max_size() << endl;
	//cout << a1.empty() << endl; //boolean, перевіряє чи обєкт пустий
	//auto p = a1.data();
	//delete[] p; // не працює
	cout << a1[1];
	cout << a1.at(2); // ловимо виняткову ситуацію
}

void test1() {
	const int n = 10;
	array <int, n> a1{ 10,20,30 };
	a1.fill(5);
	for (auto e : a1) // працює лише з колекціями в яких є ітератор
		cout << e << endl;
}

void test2() { // двомірний масив
	array <array <int, 3>, 2>  mas{ 10,20,30 };
	mas[1][2] = 60;
	for (auto a : mas) {
		for (auto e : a)
			cout << e << '\t';
		cout << endl;
	}
}
void test3() { // вектор(динамічний масив) https://www.cplusplus.com/reference/vector/vector/?kw=vector
	vector <int> v1{ 5,6,7 };
	cout << v1.size() << endl;
	if (v1.size())
		cout << "Not empty" << endl;
	else
		cout << "Empty" << endl;

	if (!v1.empty()) // empty() виграє в швидкодії
		cout << "Not empty" << endl;
	else
		cout << "Empty" << endl;

	for (auto a : v1) // вивід вектору
		cout << a;

	cout << v1.max_size() << endl;

	cout << v1.capacity() << endl; // скільки зарезервовано памяті
}
void test4() { // вектор https://www.cplusplus.com/reference/vector/vector/?kw=vector
	vector <int> v1{ 5,6,7 };
	for (int i = 0; i < 100; i++) {
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		v1.push_back(i); // дозволяє додавати в кінець
	}
	for (auto a : v1) // вивід вектору
		cout << a;
}
void test5() { // вектор https://www.cplusplus.com/reference/vector/vector/?kw=vector
	vector <int> v1{ 5,6,7 };
	for (int i = 0; i < 100; i++) {
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		v1.emplace_back(i); // дозволяє додавати в кінець (без використання конструкцій копії)б працює швидше
	}
	for (auto a : v1) // вивід вектору
		cout << a;
}
void test6() { // вектор https://www.cplusplus.com/reference/vector/vector/?kw=vector
	int mas[5]{ 3,10,50,-20,15 };
	vector <int> v1{ 10, 20, 30, 40 };
	vector <int> v2(v1.begin() + 1, v1.end() - 1); // беремо значення з іншого вектору
	for (auto a : v2) // вивід вектору
		cout << a << '\t';
	vector <int> v3(mas, mas + 5); // взяли 5 значень з mas[5]
	for (auto a : v3) // вивід вектору
		cout << a << '\t';
	v3 = vector <int>();
	for (auto a : v3) // вивід вектору
		cout << a << '\t';
}
void test7() { // вектор https://www.cplusplus.com/reference/vector/vector/?kw=vector
	vector <int> v1{ 10, 20, 30, 40 };
	vector <int> v2;
	//v1.assign(7, 50); // 7 по 50
	v2.assign(v1.rbegin(), v1.rend()); // копія в зворотньому порядку
	for (auto a : v2) // вивід вектору
		cout << a << '\t';
}
void test8() { // вектор https://www.cplusplus.com/reference/vector/vector/?kw=vector
	vector <int> v1{ 10, 20, 30, 40 };
	vector <int> v2{ 50,60 };
	v2.insert(v2.begin() + 1, v1.begin() + 1, v1.end()); //вставляємо в конкретну позицію
	v2.insert(v2.begin(), 10);//вставляємо на початок 10тку
	v2.insert(v2.begin() + 2, 2, 100);//вставляємо в середину (в 2 позицію ітератора 2 по 100)
	for (auto a : v2) // вивід вектору
		cout << a << '\t';
	//v2.emplace(); - новий insert, краще використовувати emplace замість insert
}

void test9() { // вектор https://www.cplusplus.com/reference/vector/vector/?kw=vector
	vector <int> v1{ 10, 20, 30, 40 };
	vector <int> v2{ 50,60 };
	//v1.erase(v1.begin() + 2); // видаляємо з 2 елементу
	v1.erase(v1.begin(), v1.begin() + 2); //видаляє 2 елементи, з першого по другий
	for (auto a : v1) // вивід вектору
		cout << a << '\t';
}

void test10() { // видаляємо не парні
	vector<int> v{ 10,13,14,15,20 };
	for (int i = 0; i < v.size(); i++)
		if (v[i] % 2) {
			v.erase(v.begin() + i);
			i--;
		}
	for (auto a : v) // вивід вектору
		cout << a << '\t';
}


int main() {
	srand(time(0));
	//test();
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	test10();



}