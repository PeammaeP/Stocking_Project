//All Node related function
#ifndef NodeLL_cpp
#define NodeLL_cpp
#include <iostream>
#include <iomanip>
#include <fstream>
#include "ctime"
using namespace std;
ofstream save;//create text file

// <------------- Node ------------->
#include "NodeLL.h"

/*Node*/
NODE::NODE(){
      static long x = 130000;
      NodeID = ++x;
      if(dev){
      cout << "adding NodeID @ NODE : " << x << endl;
      }
}
 NODE:: ~NODE(){
      if(dev){
      cout << "NodeID " << NodeID << " is being deleted" << endl;
      }
}
void NODE:: show_data(){
     if(dev){
      cout << "NodeID @ NODE : " << NodeID << endl;
     }
     cout << "| " << setw(6) << left << NodeID << " | " ;
}


/*general*/
general::general(string inName, string inmfg, string inexp, long inLotNo):NODE(){
      static long x = 0, y = 500000;
      LotID = ++x;
      if(!inLotNo) LotNo = ++y; // Default inLotNo should be 0
      else LotNo = inLotNo;
      name = inName;
      mfg = inmfg;
      expire = inexp;

      // time input
      time_t curr_time;
	curr_time = time(NULL);
      string realtime = ctime(&curr_time);
      string textDay, day, textMonth, year, hh, mm, ss, time;
	if(dev) cout << "Today is : " << realtime; //In this format >> Tue Apr 25 12:31:25 2023
      textDay = textDay + realtime[0] + realtime[1] + realtime[2]; // Tue
      day = day + realtime[8] + realtime[9]; // 25
      textMonth = textMonth + realtime[4] + realtime[5] + realtime[6]; // Apr
      year = year + realtime[20] + realtime[21] + realtime[22] + realtime[23]; //2023
      hh = hh + realtime[11] + realtime[12]; //12
      mm = mm + realtime[14] + realtime[15]; //31
      ss = ss + realtime[17] + realtime[18]; //25
      time = time + hh + ":" + mm + ":" + ss; // hh:mm:ss
      updateTime = updateTime + " " + textDay + " " +  day + " " +  textMonth + " " +  year + " @ " +  time; // Tue 25 Apr 2023 12:31:25

      if(dev){
      cout << "textDay :" << textDay << endl;
      cout << "day :" << day << endl;
      cout << "textMonth :" << textMonth << endl;
      cout << "year :" << year << endl;
      cout << "hh :" << hh << endl;
      cout << "mm :" << mm << endl;
      cout << "ss :" << ss << endl;
      cout << "time :" << time << endl;
      cout << "adding name @ general : " << name << endl;
      cout << "adding mfg @ general : " << mfg << endl;
      cout << "adding expire @ general : " << expire << endl;
      cout << "adding updateTime @ general : " << updateTime << endl;
      }
}
general:: ~general(){
      if(dev){
      cout << "name " << name << " is being deleted" << endl;
      cout << "mfg " << mfg << " is being deleted" << endl;
      cout << "expire " << expire << " is being deleted" << endl;
      }
}
void  general:: show_data(){
      if(dev){
      cout << "name @ general : " << name << endl;
      cout << "mfg @ general : " << mfg << endl;
      cout << "expire @ general : " << expire << endl;
      cout << "updateTime @ general : " << updateTime << endl;
      }
      cout << setw(16) << left << name << " | " << setw(7) << left << mfg << " | " << setw(7) << left << expire << " | " << setw(28) << left << updateTime << " | ";
}


/*consumable: general*/
consumable::consumable(string inName, string inmfg, string inexp, long inLotNo, double inweightAll, int inquantityContainer, int inquantityEach):general(inName, inmfg, inexp, inLotNo){
      weightAll = inweightAll;
      quantityContainer = inquantityContainer;
      quantityEach = inquantityEach;
      if(dev){
      cout << "adding weightAll @ consumable : " << weightAll << endl;
      cout << "adding quantityContainer @ consumable : " << quantityContainer << endl;
      cout << "adding quantityEach @ consumable : " << quantityEach << endl;
      }
}
consumable:: ~consumable(){
      if(dev){
      cout << "weightAll " << weightAll << " is being deleted" << endl;
      cout << "quantityContainer " << quantityContainer << " is being deleted" << endl;
      cout << "quantityEach " << quantityEach << " is being deleted" << endl;
      }
}
void  consumable:: show_data(){
      if(dev){
      cout << "weightAll @ consumable : " << weightAll << endl;
      cout << "quantityContainer @ consumable : " << quantityContainer << endl;
      cout << "quantityEach @ consumable : " << quantityEach << endl;
      }
      cout << setw(6) << left << weightAll << " | " << setw(7) << left << quantityContainer << " | " << setw(8) << left << quantityEach << " | ";
}


/*food:consumable*/
food::food(string inName, string inmfg, string inexp, long inLotNo, double inweightAll, int inquantityContainer, int inquantityEach, double inweightEach):consumable(inName, inmfg, inexp, inLotNo, inweightAll, inquantityContainer, inquantityEach){
      weightEach = inweightEach;
      if(dev){
      cout << "adding weightEach @ food : " << weightEach << endl;
      }
}
food:: ~food(){
      if(dev){
      cout << "weightEach " << weightEach << " is being deleted" << endl;
      }
}
void food:: show_data(){
      NODE::show_data();
      general::show_data();
      consumable::show_data();
      if(dev) {
            cout << "weightEach @ food : " << weightEach << endl;
      }
      cout << setw(7) << left << weightEach << " |" ;
}
food *food::move_next(){
      return next;
}

void food::insert(food*& x){
     x->next=this;
}
int food::return_NodeID(){
	return NodeID;
}

double food::return_weightAll() {
      return weightAll;
}

string food::return_mfg() {
      return mfg.substr(0,2) + "/" + mfg.substr(3,4);
}

string food::return_exp() {
      return expire.substr(0,2) + "/" + expire.substr(3,4);
}
void food::edit_NodeID(int inNodeID){
	NodeID = inNodeID;
}
void food::set_next(food* node) {
    next = node;
}
string food::save_data(){
      return name + " " + mfg + " " + expire + " " + to_string(LotNo) + " " + to_string(weightAll) + " " + to_string(quantityContainer) + " " + to_string(quantityEach) + " " + to_string(weightEach) + '\n';
}

/*drinks: consumable*/
drinks::drinks(string inName, string inmfg, string inexp, long inLotNo, double inweightAll, int inquantityContainer, int inquantityEach, double involumeEach):consumable(inName, inmfg, inexp, inLotNo, inweightAll, inquantityContainer, inquantityEach){
      volumeEach = involumeEach;
      if(dev){
      cout << "adding volumeEach @ drinks : " << volumeEach << endl;
      }
}
drinks:: ~drinks(){
      if(dev){
      cout << "volumeEach " << volumeEach << " is being deleted" << endl;
      }
}
void drinks:: show_data(){
      NODE::show_data();
      general::show_data();
      consumable::show_data();
      if(dev){
            cout << "volumeEach @ drinks : " << volumeEach << endl;
      }
      cout << setw(7) << left << volumeEach << " |";
}
drinks *drinks::move_next(){
      return next;
}
void drinks::insert(drinks*& x){
     x->next=this;
}
int drinks::return_NodeID(){
	return NodeID;
}

double drinks::return_weightAll() {
      return weightAll;
}

double drinks::return_volumeAll() {
      return volumeEach;
}

string drinks::return_mfg() {
      return mfg.substr(0,2) + "/" + mfg.substr(3,4);
}

string drinks::return_exp() {
      return expire.substr(0,2) + "/" + expire.substr(3,4);
}
void drinks::edit_NodeID(int inNodeID){
	NodeID = inNodeID;
}
void drinks::set_next(drinks* node) {
    next = node;
}
string drinks::save_data(){
      return name + " " + mfg + " " + expire + " " + to_string(LotNo) + " " + to_string(weightAll) + " " + to_string(quantityContainer) + " " + to_string(quantityEach) + " " + to_string(volumeEach) + '\n';
}


/*appliance: general*/
appliance::appliance(string inName, string inmfg, string inexp, long inLotNo, string inUsefor, double inweightAll, int inquantityContainer, int inquantityEach):general(inName, inmfg, inexp, inLotNo){
      Usefor = inUsefor;
      weightAll = inweightAll;
      quantityContainer = inquantityContainer;
      quantityEach = inquantityEach;
      if(dev){
      cout << "adding Usefor @ appliance : " << Usefor << endl;
      cout << "adding weightAll @ appliance : " << weightAll << endl;
      cout << "adding quantityContainer @ appliance : " << quantityContainer << endl;
      cout << "adding quantityEach @ appliance : " << quantityEach << endl;
      }
}
appliance:: ~appliance(){
      if(dev){
      cout << "Usefor " << Usefor << " is being deleted" << endl;
      cout << "weightAll " << weightAll << " is being deleted" << endl;
      cout << "quantityContainer " << quantityContainer << " is being deleted" << endl;
      cout << "quantityEach " << quantityEach << " is being deleted" << endl;
      }
}
void  appliance:: show_data(){
      if(dev){
      cout << "Usefor @ appliance : " << Usefor << endl;
      cout << "weightAll @ appliance : " << weightAll << endl;
      cout << "quantityContainer @ appliance : " << quantityContainer << endl;
      cout << "quantityEach @ appliance : " << quantityEach << endl;
      }
      cout << setw(24) << left << Usefor << " | " << setw(6) << left << weightAll << " | " << setw(7) << left << quantityContainer << " | " << setw(8) << left << quantityEach << " | ";
}


/*dailyUse: appliance*/
dailyUse::dailyUse(string inName, string inmfg, string inexp, long inLotNo, string inUsefor, double inweightAll, int inquantityContainer, int inquantityEach, string indetails):appliance(inName, inmfg, inexp, inLotNo, inUsefor, inweightAll, inquantityContainer, inquantityEach){
      details = indetails;
      if(dev){
      cout << "adding details @ dailyUse : " << details << endl;
      }
}
dailyUse:: ~dailyUse(){
      if(dev){
      cout << "details " << details << " is being deleted" << endl;
      }
}
void dailyUse:: show_data(){
      NODE::show_data();
      general::show_data();
      appliance::show_data();
      if(dev) {
            cout << "details @ dailyUse : " << details << endl;
      }
      cout << setw(24) << left << details << " |";
}
dailyUse *dailyUse::move_next(){
      return next;
}
void dailyUse::insert(dailyUse*& x){
     x->next=this;
}
int dailyUse::return_NodeID(){
	return NodeID;
}

double dailyUse::return_weightAll() {
      return weightAll;
}

string dailyUse::return_mfg() {
      return mfg.substr(0,2) + "/" + mfg.substr(3,4);
}

string dailyUse::return_exp() {
      return expire.substr(0,2) + "/" + expire.substr(3,4);
}
void dailyUse::edit_NodeID(int inNodeID){
	NodeID = inNodeID;
}
void dailyUse::set_next(dailyUse* node) {
    next = node;
}
string dailyUse::save_data(){
      return name + " " + mfg + " " + expire + " " + to_string(LotNo) + " " + Usefor + " " + to_string(weightAll) + " " + to_string(quantityContainer) + " " + to_string(quantityEach) + " " + details + '\n';
}


/*specificPurpose: appliance*/
specificPurpose::specificPurpose(string inName, string inmfg, string inexp, long inLotNo, string inUsefor, double inweightAll, int inquantityContainer, int inquantityEach, string incaution):appliance(inName, inmfg, inexp, inLotNo, inUsefor, inweightAll, inquantityContainer, inquantityEach){
      caution = incaution;
      if(dev){
      cout << "adding caution @ specificPurpose : " << caution << endl;
      }
}
specificPurpose:: ~specificPurpose(){
      if(dev){
      cout << "caution " << caution << " is being deleted" << endl;
      }
}
void  specificPurpose:: show_data(){
      NODE::show_data(); 
      general::show_data();
      appliance::show_data();
      if(dev){
            cout << "caution @ specificPurpose : " << caution << endl;
      }
      cout << setw(24) << left << caution << " |";
}     
specificPurpose *specificPurpose::move_next(){
      return next;
}
void specificPurpose::insert(specificPurpose*& x){
     x->next=this;
}
int specificPurpose::return_NodeID(){
	return NodeID;
}

double specificPurpose::return_weightAll() {
      return weightAll;
}

string specificPurpose::return_mfg() {
      return mfg.substr(0,2) + "/" + mfg.substr(3,4);
}

string specificPurpose::return_exp() {
      return expire.substr(0,2) + "/" + expire.substr(3,4);
}
void specificPurpose::edit_NodeID(int inNodeID){
	NodeID = inNodeID;
}
void specificPurpose::set_next(specificPurpose* node) {
    next = node;
}
string specificPurpose::save_data(){
      return name + " " + mfg + " " + expire + " " + to_string(LotNo) + " " + Usefor + " " + to_string(weightAll) + " " + to_string(quantityContainer) + " " + to_string(quantityEach) + " " + caution + '\n';
}

// <------------- LL ------------->
/*LLFood*/
LLFood::LLFood(){
       hol=NULL;
       size=0;
}

LLFood::~LLFood(){
     food *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
     cout << "[!] Program is terminated."<<endl; // Because food is declared the first, it will be the last to deconstruct.
}

void LLFood::show_all(){
     food *t = hol;
     int i;
     if(size == 0){
      cout << "[!] Food's data is empty." << endl;
      return;
     }
     cout << endl << "== Show Linkedlist Food ==" << endl;
      cout << "| " << setw(6) << left << "NodeID" << " | " << setw(16) << left << "      Name" << " | " << setw(7) << left << "  MFG" 
      << " | " << setw(7) << left << "  EXP" << " | " << setw(28) << left << "       Upadated Time" << " | "
      << setw(6) << left << "Kg All" << " | " << setw(7) << left << "Qty All" << " | " << setw(8) << left 
      << "Qty Each" << " | " << setw(7) << left << "Kg Each" << " |" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                cout << "" << endl;
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "== End of Show Linkedlist Food ==" << endl;
}
void LLFood::add_node(food *&A){

          hol->insert(A);
          hol=A;

       size++;

 }
int LLFood::LLreturn_NodeID(int get_NodeID){
	food *t=hol;
	int out_NodeID = 0;
	for(int i=0;i<size;i++){
		out_NodeID=t->return_NodeID();
		if(get_NodeID == out_NodeID) out_NodeID = get_NodeID;
		else t=t->move_next();
	}
      return out_NodeID; //Return 0 for defalut This function need to be run after check_NodeID(NodeID);
}
void LLFood::LLedit_NodeID(int inNodeID){
	food *t=hol;
	t->edit_NodeID(inNodeID);
}
bool LLFood::check_NodeID(int inNodeID){
	food *t = hol;
	int i,check_id_flag=0;
	int get_id;
	for(i=0;i<size;i++){
		get_id = t->return_NodeID();
        //check_id_flag = t->return_NodeID();
		if(inNodeID == get_id) {
			check_id_flag=1;
			break;
		}
        //if(t->move_next() != NULL) t = t->move_next();
		t = t->move_next();
    }
	if(check_id_flag == 1) return true;
	else return false; 
}
void LLFood::delete_stock(int inNodeID){
	if(hol == nullptr) return;
	food *t = hol,*tmp = hol, *tmp2=NULL;
	int i, get_NodeID;
	for(i=0;i<size;i++){
		get_NodeID = t->return_NodeID();
		if(inNodeID == get_NodeID){
			//if(i!=0) tmp = t->move_next();
			break;
		}
		else{
			if(i!=0) tmp = t;
			t = t->move_next();
		}
	}
	if(t==hol && t==tmp) hol = t->move_next();
	else if(t->move_next() == NULL) tmp->set_next(NULL);
	else if(t->move_next() != NULL){
		//tmp->move_next() = t->move_next();
		//tmp->set_next(t->move_next());
		tmp2=t->move_next();
		tmp->set_next(tmp2);
	}
	delete t;
	size--;
	cout<<"NodeID : "<<get_NodeID<<" deleted."<<endl;
}
void LLFood::inserttonote()
{
      food *tmp = hol;
      int i;
      save.open("stock_food.txt");
      for(i=0;i<size;i++)
      {
            if(dev) cout << "DATA " << i << " : " << tmp->save_data();
            save << tmp->save_data();
            if(tmp->move_next()!=NULL) tmp = tmp->move_next();
      }
      save.close();
}


 /*LLDrinks*/
LLDrinks::LLDrinks(){
       hol=NULL;
       size=0;
}

LLDrinks::~LLDrinks(){
     drinks *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
}
void LLDrinks::show_all(){
     drinks *t = hol;
     int i;
      if(size == 0){
      cout << "[!] Drink's data is empty." << endl;
      return;
     }
     cout << endl << "== Show Linkedlist Drinks ==" << endl;
      cout << "| " << setw(6) << left << "NodeID" << " | " << setw(16) << left << "      Name" << " | " << setw(7) << left << "  MFG" 
      << " | " << setw(7) << left << "  EXP" << " | " << setw(28) << left << "       Upadated Time" << " | "
      << setw(6) << left << "Kg All" << " | " << setw(7) << left << "Qty All" << " | " << setw(8) << left 
      << "Qty Each" << " | " << setw(7) << left << "mL Each" << " |" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                cout << "" << endl;
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "== End of Show Linkedlist Drinks ==" << endl;
}
void LLDrinks::add_node(drinks *&A){

          hol->insert(A);
          hol=A;

       size++;

 }
int LLDrinks::LLreturn_NodeID(int get_NodeID){
	drinks *t=hol;
	int out_NodeID = 0;
	for(int i=0;i<size;i++){
		out_NodeID=t->return_NodeID();
		if(get_NodeID == out_NodeID) out_NodeID = get_NodeID;
		else t=t->move_next();
	}
      return out_NodeID; //Return 0 for default This function need to be run after check_NodeID(NodeID);
}
void LLDrinks::LLedit_NodeID(int inNodeID){
	drinks *t=hol;
	t->edit_NodeID(inNodeID);
}
bool LLDrinks::check_NodeID(int inNodeID){
	drinks *t = hol;
	int i,check_id_flag=0;
	int get_id;
	for(i=0;i<size;i++){
		get_id = t->return_NodeID();
        //check_id_flag = t->return_NodeID();
		if(inNodeID == get_id) {
			check_id_flag=1;
			break;
		}
        //if(t->move_next() != NULL) t = t->move_next();
		t = t->move_next();
    }
	if(check_id_flag == 1) return true;
	else return false; 
}
void LLDrinks::delete_stock(int inNodeID){
	if(hol == nullptr) return;
	drinks *t = hol,*tmp = hol, *tmp2=NULL;
	int i, get_NodeID;
	for(i=0;i<size;i++){
		get_NodeID = t->return_NodeID();
		if(inNodeID == get_NodeID){
			//if(i!=0) tmp = t->move_next();
			break;
		}
		else{
			if(i!=0) tmp = t;
			t = t->move_next();
		}
	}
	if(t==hol && t==tmp) hol = t->move_next();
	else if(t->move_next() == NULL) tmp->set_next(NULL);
	else if(t->move_next() != NULL){
		//tmp->move_next() = t->move_next();
		//tmp->set_next(t->move_next());
		tmp2=t->move_next();
		tmp->set_next(tmp2);
	}
	delete t;
	size--;
	cout<<"NodeID : "<<get_NodeID<<" deleted."<<endl;
}
void LLDrinks::inserttonote()
{
      drinks *tmp = hol;
      int i;
      save.open("stock_drink.txt");
      for(i=0;i<size;i++)
      {
            if(dev) cout << "DATA " << i << " : " << tmp->save_data();
            save << tmp->save_data();
            if(tmp->move_next()!=NULL) tmp = tmp->move_next();
      }
      save.close();
}


 /*LLDai*/
LLDai::LLDai(){
       hol=NULL;
       size=0;
}
LLDai::~LLDai(){
     dailyUse *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
}
void LLDai::show_all(){
     dailyUse  *t = hol;
     int i;
      if(size == 0){
      cout << "[!] DailyUse's data is empty." << endl;
      return;
     }
     cout << endl << "== Show Linkedlist DailyUse ==" << endl;
      cout << "| " << setw(6) << left << "NodeID" << " | " << setw(16) << left << "      Name" << " | " << setw(7) << left << "  MFG" 
      << " | " << setw(7) << left << "  EXP" << " | " << setw(28) << left << "       Upadated Time" << " | " << setw(24) 
      << left << "        Use for" << " | " << setw(6) << left << "Kg All" << " | " << setw(7) << left << "Qty All" 
      << " | " << setw(8) << left << "Qty Each" << " | " << setw(24) << left << "        Datails" << " |" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                cout << "" << endl;
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "== End of Show Linkedlist DailyUse ==" << endl;
}
void LLDai::add_node(dailyUse *&A){

          hol->insert(A);
          hol=A;

       size++;

 }
int LLDai::LLreturn_NodeID(int get_NodeID){
	dailyUse *t=hol;
	int out_NodeID = 0;
	for(int i=0;i<size;i++){
		out_NodeID=t->return_NodeID();
		if(get_NodeID == out_NodeID) out_NodeID = get_NodeID;
		else t=t->move_next();
	}
      return out_NodeID; //Return 0 for defalut This function need to be run after check_NodeID(NodeID);
}
void LLDai::LLedit_NodeID(int inNodeID){
	dailyUse *t=hol;
	t->edit_NodeID(inNodeID);
}
bool LLDai::check_NodeID(int inNodeID){
	dailyUse *t = hol;
	int i,check_id_flag=0;
	int get_id;
	for(i=0;i<size;i++){
		get_id = t->return_NodeID();
        //check_id_flag = t->return_NodeID();
		if(inNodeID == get_id) {
			check_id_flag=1;
			break;
		}
        //if(t->move_next() != NULL) t = t->move_next();
		t = t->move_next();
    }
	if(check_id_flag == 1) return true;
	else return false; 
}
void LLDai::delete_stock(int inNodeID){
	if(hol == nullptr) return;
	dailyUse *t = hol,*tmp = hol, *tmp2=NULL;
	int i, get_NodeID;
	for(i=0;i<size;i++){
		get_NodeID = t->return_NodeID();
		if(inNodeID == get_NodeID){
			//if(i!=0) tmp = t->move_next();
			break;
		}
		else{
			if(i!=0) tmp = t;
			t = t->move_next();
		}
	}
	if(t==hol && t==tmp) hol = t->move_next();
	else if(t->move_next() == NULL) tmp->set_next(NULL);
	else if(t->move_next() != NULL){
		//tmp->move_next() = t->move_next();
		//tmp->set_next(t->move_next());
		tmp2=t->move_next();
		tmp->set_next(tmp2);
	}
	delete t;
	size--;
	cout<<"NodeID : "<<get_NodeID<<" deleted."<<endl;
}
void LLDai::inserttonote()
{
      dailyUse *tmp = hol;
      int i;
      save.open("stock_dailyuse.txt");
      for(i=0;i<size;i++)
      {
            if(dev) cout << "DATA " << i << " : " << tmp->save_data();
            save << tmp->save_data();
            if(tmp->move_next()!=NULL) tmp = tmp->move_next();
      }
      save.close();
}


 /*LLSpec*/
LLSpec::LLSpec(){
       hol=NULL;
       size=0;
}

LLSpec::~LLSpec(){
     specificPurpose *t = hol, *temp;
     int i;
     for(i=0;i<size;i++){
                temp = t;
                if(t->move_next() != NULL) t = t->move_next();
                delete temp;
     }
}

void LLSpec::show_all(){
     specificPurpose *t = hol;
     int i;
      if(size == 0){
      cout << "[!] SpecificPurpose's data is empty." << endl;
      return;
     }
     cout << endl << "== Show Linkedlist SpcPurpose ==" << endl;
      cout << "| " << setw(6) << left << "NodeID" << " | " << setw(16) << left << "      Name" << " | " << setw(7) << left << "  MFG" 
      << " | " << setw(7) << left << "  EXP" << " | " << setw(28) << left << "       Upadated Time" << " | " << setw(24) 
      << left << "        Use for" << " | " << setw(6) << left << "Kg All" << " | " << setw(7) << left << "Qty All" 
      << " | " << setw(8) << left << "Qty Each" << " | " << setw(24) << left << "        Caution"<< " |" << endl;
     for(i=0;i<size;i++){
                t->show_data();
                cout << "" << endl;
                if(t->move_next() != NULL) t = t->move_next();
     }
     cout << "== End of Show Linkedlist SpcPurpose ==" << endl;
}
void LLSpec::add_node(specificPurpose *&A){

          hol->insert(A);
          hol=A;

       size++;
}
int LLSpec::LLreturn_NodeID(int get_NodeID){
	specificPurpose *t=hol;
	int out_NodeID = 0;
	for(int i=0;i<size;i++){
		out_NodeID=t->return_NodeID();
		if(get_NodeID == out_NodeID) out_NodeID = get_NodeID;
		else t=t->move_next();
	}
      return out_NodeID; //Return 0 for defalut This function need to be run after check_NodeID(NodeID);
}

void LLSpec::LLedit_NodeID(int inNodeID){
	specificPurpose *t=hol;
	t->edit_NodeID(inNodeID);
}


bool LLSpec::check_NodeID(int inNodeID){
	specificPurpose *t = hol;
	int i,check_id_flag=0;
	int get_id;
	for(i=0;i<size;i++){
		get_id = t->return_NodeID();
        //check_id_flag = t->return_NodeID();
		if(inNodeID == get_id) {
			check_id_flag=1;
			break;
		}
        //if(t->move_next() != NULL) t = t->move_next();
		t = t->move_next();
    }
	if(check_id_flag == 1) return true;
	else return false; 
}


void LLSpec::delete_stock(int inNodeID){
	if(hol == nullptr) return;
	specificPurpose *t = hol,*tmp = hol, *tmp2=NULL;
	int i, get_NodeID;
	for(i=0;i<size;i++){
		get_NodeID = t->return_NodeID();
		if(inNodeID == get_NodeID){
			//if(i!=0) tmp = t->move_next();
			break;
		}
		else{
			if(i!=0) tmp = t->move_next();
			t = t->move_next();
		}
	}
	if(t==hol && t==tmp) hol = t;
	else if(t->move_next() == NULL) tmp->set_next(NULL);
	else if(t->move_next() != NULL){
		//tmp->move_next() = t->move_next();
		//tmp->set_next(t->move_next());
		tmp2=t->move_next();
		tmp->set_next(tmp2);
	}
	delete t;
	size--;
	cout <<"NodeID : " << get_NodeID << " being deleted." << endl;
}
void LLSpec::inserttonote()
{
      specificPurpose *tmp = hol;
      int i;
      save.open("stock_specificuse.txt");
      for(i=0;i<size;i++)
      {
            if(dev) cout << "DATA " << i << " : " << tmp->save_data();
            save << tmp->save_data();
            if(tmp->move_next()!=NULL) tmp = tmp->move_next();
      }
      save.close();
}

#endif