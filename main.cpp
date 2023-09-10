#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <typeinfo>
using namespace std;

#define DEV_MODE false // default is false
#define DWORD "NO" // defalut word in file: "NO"

bool dev = DEV_MODE;
#include "NodeLL.cpp"


//Global var
////////////////////////////////////////
LLFood a; LLDrinks b; LLDai c;      LLSpec d;
food *f;  drinks *dr; dailyUse *da; specificPurpose *s;	

long NodeID;
long LotID, LotNo;
string name;
string mfg, expire;
string updateTime;
string Usefor;
string caution;
string details;
double weightAll;
int quantityContainer, quantityEach;
double weightEach,volumeEach;
int s_choice = 0, add_choice,s_flag=0;
////////////////////////////////////////
//function
void clear();

void scin(int &);
void scin(string &);
void scin(long &);
void scin(double &);
void scin(char &);
void scin(int &, int &);
void scin(string &, int &);
void scin(long &, int &);
void scin(double &, int &);
void scin(char &, int &);

void ask(int &choice, string text = "Number Input");
void ask(string &choice, string text = "String Input");
void ask(long &choice, string text = "Long Number Input");
void ask(double &choice, string text = "Double Input");
void ask(char &choice, string text = "Char Input");

void add_stock();
void delete_stock(int);
void show_delete_stock();
void edit_stock();

#include "sorting.cpp"
#include "Son_manip.cpp"
/////////////////////////////////////////////
int main(int argc, char **argv){
    try{
    clear();
    int i;
    /////////////////////////////////////////
    int num_lines = 1; // number of data lines 
    /////////////////////////////////////////
    if(dev){
    cout << "The argc is " << argc << endl;
    for(i = 0; i < argc ; i++){
        cout << "argv[" << i << "] is " << argv[i] << endl;
    }
}
    ///////////////////////////////////////////////////////
    ifstream RF,RD,RDA,RS;//read text file readfood readdrink readdaily readspecific
    ofstream WF,WD,WDA,WS;//create text file
    ///////////////////////////////////////////////////////


    //////////////////////////create default///////////////
    RF.open("stock_food.txt");//ให้developerเก็บข้อมูล
    if(RF.fail())//if my text file doesn't exist, create one
    {
    WF.open("stock_food.txt");//create+name+open file
    WF.close();//fclose()
    }
    RF.close();//fclose()
    RD.open("stock_drink.txt");//ให้developerเก็บข้อมูล
    if(RD.fail())//if my text file doesn't exist, create one
    {
    WD.open("stock_drink.txt");//name+open file
    WD.close();//fclose()
    }
    RD.close();//fclose()
    RDA.open("stock_dailyuse.txt");//ให้developerเก็บข้อมูล
    if(RDA.fail())//if my text file doesn't exist, create one
    {
    WDA.open("stock_dailyuse.txt");//name+open file
    WDA.close();//fclose()
    }
    RDA.close();//fclose()
    RS.open("stock_specificuse.txt");//ให้developerเก็บข้อมูล
    if(RS.fail())//if my text file doesn't exist, create one
    {
    WS.open("stock_specificuse.txt");//name+open file
    WS.close();//fclose()
    }
    RS.close();//fclose()
    ///////////////////////////////////////////////////////
        
    int choice = 0, flag;
    string extra; // use to accept developer's password
    do{
        try{
        flag = 0;
        if(dev) cout << "[!] Developer Mode" << endl;
        cout << "== Please select command ==" << endl;
        cout << "--> 1 : Load data" << endl;
        cout << "--> 2 : Show All Data" << endl;
		cout << "--> 3 : Add , Delete , Edit your stock" << endl;
        cout << "--> 4 : Sorting Your Stock " << endl;
        cout << "--> 9 : Exit" << endl;
        cout << "--> 99 : Then type: \"dev\" to switch developer mode" << endl;
if(dev) cout << "--> 91 : Try bad_alloc" << endl;
if(dev) cout << "--> 92 : Try remove ALL stock files" << endl;

        cout << "Input number : "; scin(choice);

        switch(choice){
            case 1 : //Load data
                clear();
                RF.open("stock_food.txt");
                while(RF>>name>>mfg>>expire>>LotNo>>weightAll>>quantityContainer>>quantityEach>>weightEach)/*collect food*/
                {
                    f = new food(name,mfg,expire,LotNo,weightAll,quantityContainer,quantityEach,weightEach);             a.add_node(f);
                }
                RF.close();
                RD.open("stock_drink.txt");
                while(RD>>name>>mfg>>expire>>LotNo>>weightAll>>quantityContainer>>quantityEach>>volumeEach)/*collect drink*/
                {
                    dr = new drinks(name,mfg,expire,LotNo,weightAll,quantityContainer,quantityEach,volumeEach);           b.add_node(dr);
                }  
                RD.close();
                RDA.open("stock_dailyuse.txt");
                while(RDA>>name>>mfg>>expire>>LotNo>>Usefor>>weightAll>>quantityContainer>>quantityEach>>caution)/*collect dailyUse*/
                {
                    da = new dailyUse(name,mfg,expire,LotNo,Usefor,weightAll,quantityContainer,quantityEach,caution);    c.add_node(da);
                }
                RDA.close();                  
                RS.open("stock_specificuse.txt");
                while(RS>>name>>mfg>>expire>>LotNo>>Usefor>>weightAll>>quantityContainer>>quantityEach>>details)/*collect specificPurpose*/
                {
                    s = new specificPurpose(name,mfg,expire,LotNo,Usefor,weightAll,quantityContainer,quantityEach,details);  d.add_node(s); 
                }
                RS.close();
                cout << "[!] Data has been loaded." << endl;
                break;
            case 2 : //Showall
                    clear();
                    a.show_all();
                    b.show_all();
                    c.show_all();
                    d.show_all();
                    cout << "" << endl;
                    break;
			case 3 : //Manipulate data
					clear();
					do{
                        try{
						s_flag = flag = 0;
						cout<<"Please select command"<<endl;
						cout<<"1 : Add stock"<<endl;
						cout<<"2 : Delete stock"<<endl;
						cout<<"3 : Edit stock"<<endl;
						cout<<"4 : Back to main menu"<<endl;
                        cout << "Input number : "; scin(s_choice);
						
						switch(s_choice){
							case 1 :
								add_stock();
								s_flag=1;
								//clear();
								break;
							case 2 :
								show_delete_stock();
								s_flag=1;
								clear();
								break;
							case 3 :
								edit_stock();
								s_flag=1;
								break;
							default :
								//s_flag=1;
								clear();
						}
                        }catch( exception &e ){
                        cin.clear();
                        cin.ignore(100,'\n');
                        clear();
                        if(dev) cout << "[Alert!] " << e.what() << endl;
                        else cout << "[!] Input format error please try again." << endl;
                        flag = 1;
                        } 
    	                catch(...){
                        cin.clear();
                        cin.ignore(100,'\n');
                        clear();
                        if(dev) cout << "[Alert!] " << "General Exception" << endl;
                        else cout << "[!] Input format error please try again." << endl;
                        flag = 1;
    	                }   
					}while(s_choice != 4 && s_flag == 0 || flag == 1);
					break;
            case 4: sorting_function(); break;
            case 99 :
                    ask(extra, "Password");
                    if(extra == "dev") dev = !dev;
                    else choice = 0;
                    clear();
                    break;
            case 91 : 
            if(dev){
                long long i;
                for(i = 1;;i++){
                cout << "Allocated : " << i*500000000 << endl;
                int *p = new int[500000000];
                }
            } else choice = 0; 
            clear(); break;
            case 92 : 
            if(dev){
                remove("stock_food.txt");
                remove("stock_drink.txt");
                remove("stock_dailyuse.txt");
                remove("stock_specificuse.txt");
                clear();
                cout << "[!] All Stock Data has been removed." << endl;
            } else choice = 0; 
            break;
            default : clear();
        }
    }
    catch( exception &e ){
        cin.clear();
        cin.ignore(100,'\n');
        clear();
        if(dev) cout << "[Alert!] " << e.what() << endl;
        else cout << "[!] Input format error please try again." << endl;
        flag = 1;
           } 
    catch(...){
        cin.clear();
        cin.ignore(100,'\n');
        clear();
        if(dev) cout << "[Alert!] " << "General Exception" << endl;
        else cout << "[!] Input format error please try again." << endl;
        flag = 1;
    }   
    }while(choice != 9 || flag ==1); //exit program with 9 and no flag (0)
    char save_choice;
    ask(save_choice, "Do you want to save? (Y/N)");
    if(save_choice == 'Y' || save_choice == 'y'){
    a.inserttonote(); // save food to txt
    b.inserttonote(); // save drinks to txt
    c.inserttonote(); // save dailyuse to txt
    d.inserttonote(); // save specificPurpose to txt
    cout << "[!] Saved" << endl;
    }
    return 0;
    }catch( exception &e ){
    cin.clear();
    cin.ignore(100,'\n');
    clear();
    if(dev) cout << "[Alert!] " << e.what() << endl;
    else cout << "[!] File or Memmory corrupted" << endl;
    }	
}

void clear() {
#if defined(__linux__) // Or #if __linux__
  system("clear");
  if(dev) cout << "[!] This system is running on LINUX" << endl;
#elif __APPLE__
  system("clear");
  if(dev) cout << "[!] This system is running on MacOS" << endl;
#elif _WIN32
  system("cls");
  if(dev) cout << "[!] This system is running on Windows" << endl;
#endif
}

//Secured cin
void scin(int &choice){
    cin >> choice;
    if(cin.fail()) throw 0;
}
void scin(string &choice){
    cin >> choice;
    if(cin.fail()) throw 0;
}
void scin(long &choice){
    cin >> choice;
    if(cin.fail()) throw 0;
}
void scin(double &choice){
    cin >> choice;
    if(cin.fail()) throw 0;
}
void scin(char &choice){
    cin >> choice;
    if(cin.fail()) throw 0;
}

//Secured cin with Check
void scin(int &choice, int &choice_check){
    try{
    cin >> choice;
    if(cin.fail()) {
        throw 0;
    }
    }catch( exception &e ){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << e.what() << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
           } 
    catch(...){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << "General Exception" << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
    }  
}
void scin(string &choice, int &choice_check){
    try{
    cin >> choice;
    if(cin.fail()) {
        throw 0;
    }
    }catch( exception &e ){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << e.what() << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
           } 
    catch(...){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << "General Exception" << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
    }  
}
void scin(long &choice, int &choice_check){
    try{
    cin >> choice;
    if(cin.fail()) {
        throw 0;
    }
    }catch( exception &e ){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << e.what() << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
           } 
    catch(...){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << "General Exception" << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
    }  
}
void scin(double &choice, int &choice_check){
    try{
    cin >> choice;
    if(cin.fail()) {
        throw 0;
    }
    }catch( exception &e ){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << e.what() << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
           } 
    catch(...){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << "General Exception" << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
    }  
}
void scin(char &choice, int &choice_check){
    try{
    cin >> choice;
    if(cin.fail()) {
        throw 0;
    }
    }catch( exception &e ){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << e.what() << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
           } 
    catch(...){
        cin.clear();
        cin.ignore(100,'\n');
        if(dev) cout << "[Alert!] " << "General Exception" << endl;
        else cout << "[!] Input format error please try again." << endl;
        choice_check = 1;
    }  
}

//Ask User
void ask(int &choice, string text){
    int ask_flag;
    do{
        ask_flag = 0;
        cout << text << " : ";
        scin(choice,ask_flag);
    }while(ask_flag == 1);
}
void ask(string &choice, string text){
    int ask_flag;
    do{
        ask_flag = 0;
        cout << text << " : ";
        scin(choice,ask_flag);
    }while(ask_flag == 1);
}
void ask(long &choice, string text){
    int ask_flag;
    do{
        ask_flag = 0;
        cout << text << " : ";
        scin(choice,ask_flag);
    }while(ask_flag == 1);
}
void ask(double &choice, string text){
    int ask_flag;
    do{
        ask_flag = 0;
        cout << text << " : ";
        scin(choice,ask_flag);
    }while(ask_flag == 1);
}
void ask(char &choice, string text){
    int ask_flag;
    do{
        ask_flag = 0;
        cout << text << " : ";
        scin(choice,ask_flag);
    }while(ask_flag == 1);
}