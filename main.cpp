#include <iostream>
#include <memory>
#include <fstream>
#include <string>
using namespace std;

int getEnter() {
    char dummy;
    while (cin >> dummy) {
        getchar();
        if (dummy == 'n') {
            return 0;
        }
        if (dummy == 'Q') {
            return 1;
        }
    }
    return 0;
}


void run1(){
    cout << '\t' << "For unique_ptr" << endl;
    int* p3 = nullptr;

    {
        unique_ptr<int> p1 = make_unique<int>(10);   // or unique_ptr<CLASS> p1(new CLASS(arguments));
        cout << "p1: " << p1 << '\t' << *p1 << endl;
        unique_ptr<int> p2 = make_unique<int>(20);
        cout << "p2: " <<  p2 << '\t' << *p2 << endl;
        p3=p2.get();
        p2=move(p1);  //moves ownership of p1 to p2
        cout << "moving ownership of p1 to p2; p1 becomes null" << endl;
        cout << "p1: " << p1 << endl;
        cout << "p2: " << p2 << '\t' << *p2 << "\t p2 takes the owner of p1" << endl;
        cout << "memory leak would NOT happen, because p2 is freed while taking p1" << endl;
        cout << "a normal pointer CAN copy a unique pointer, and would cause dangling pointer" << endl;
        cout << "p3: " << p3 << '\t' << *p3 << endl;
        cout << "*p3 becomes dangling when p1 moves to p2" << endl;
    }

    cout << "p1 and p2 is freed automaticly after }, using both normal and smart pointer will fry your brain" << endl;
}



void run2(){
    cout << '\t' << "For shared_ptr" << endl;
    shared_ptr<int> p1 = make_shared<int>(101);
    shared_ptr<int> p2 = p1;

    {
        shared_ptr<int> p3 = p2;
        cout << "p1: " << p1 << '\t' << *p1 << endl;
        cout << "p2: " << p2 << '\t' << *p2 << endl;
        cout << "p3: " << p3 << '\t' << *p3 << endl;
        cout << "use_count is the number of pointeres that OWNS the same memory: " << p3.use_count() << endl;
    }

    cout << "p3 is out of scope, but shared_ptr will not free the memory" << endl <<
    "unless it is the last shared_ptr pointing that memory" << endl;
    cout << "use_count: " << p1.use_count() << endl;
    cout << "p2: " << p2 << '\t' << *p2 << endl;
}


void run3(){
    cout << '\t' << "For weak_ptr" << endl;
    shared_ptr<int> p1 = make_shared<int>(666);
    weak_ptr<int> p2(p1);
    cout << "p1: " << p1 << '\t' << *p1 << endl;
    cout << "use_count:" << p1.use_count() << endl;
    cout << "use_count:" << p2.use_count() << endl;
}


int main() {

     ifstream Fil;
     Fil.open("../present.txt");
     if (!Fil.is_open()) {
         cout << "Could not open file" << endl;
     }
     string str;

     while (getline(Fil, str)) {
         if (str == "run1") {
             run1();
         }
         else if (str == "run2") {
             run2();
         }
         else if (str == "run3") {
             run3();
         }
         else {
             cout << str << endl;
             if (getEnter()==1) {
                 cout << "skipping";
                 Fil.close();
                 break;
             }
         }
     }






}