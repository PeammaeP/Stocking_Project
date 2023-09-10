#include <iostream>
using namespace std;
void scin(int &);
int main(){
    long long i;
    int choice, flag;
    do{
      try{
    flag = 0;
    cout << "Choice : " ;

    scin(choice);
    
    switch (choice) {
    case 1 :
    for(i = 1;;i++){
    cout << i*500000000 << endl;
    int *p = new int[500000000];
    }
    break;
    default : cout << "Exit"  << flag << choice << endl;
    }
        }
    catch( exception &e ){
        cin.clear();
        cin.ignore(100,'\n');
        cout << e.what() << endl;
        flag = 1;
           } 
    catch(...){
        cout << "What is this bro?" << endl;
        cin.clear();
        cin.ignore(100,'\n');
        flag = 1;
    }   
    }while(choice != 9  || flag == 1);


}
void scin(int &choice){
    cin >> choice;
    if(cin.fail()) throw 0;
}