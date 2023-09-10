#ifndef Son_manip_cpp
#define Son_manip_cpp

//Son code
void choice_insert_func() {
	int flag;
	switch(add_choice){
			case 1 :
				ask(name,"Enter name");
				ask(mfg, "Enter MFG");
				ask(expire, "Enter EXP");
				ask(LotNo,"Enter Lot Number");
				ask(weightAll, "Enter Weight All");
				ask(quantityContainer, "Enter Quantity of Container");
				ask(quantityEach, "Enter Quantity of Each");
				ask(weightEach, "Enter Weight of Each");
				
				f = new food(name,mfg,expire,LotNo,weightAll,quantityContainer,quantityEach,weightEach);
				a.add_node(f);
				clear();
				cout << "[!] Insertion Completed" << endl;
				break;

			case 2 :
				ask(name,"Enter name");
				ask(mfg, "Enter MFG");
				ask(expire, "Enter EXP");
				ask(LotNo,"Enter Lot Number");
				ask(weightAll, "Enter Weight All");
				ask(quantityContainer, "Enter Quantity of Container");
				ask(quantityEach, "Enter Quantity of Each");
				ask(volumeEach, "Enter Volume of Each");
				
				dr = new drinks(name,mfg,expire,LotNo,weightAll,quantityContainer,quantityEach,volumeEach);
				b.add_node(dr);
				clear();
				cout << "[!] Insertion Completed" << endl;
				break;

			case 3 :
				ask(name,"Enter name");
				ask(mfg, "Enter MFG");
				ask(expire, "Enter EXP");
				ask(LotNo,"Enter Lot Number");
				ask(Usefor,"Enter Use them for");
				ask(weightAll, "Enter Weight All");
				ask(quantityContainer, "Enter Quantity of Container");
				ask(quantityEach, "Enter Quantity of Each");
				ask(caution, "Enter Product's Caution");
				
				da = new dailyUse(name,mfg,expire,LotNo,Usefor,weightAll,quantityContainer,quantityEach,caution);
				c.add_node(da);
				clear();
				cout << "[!] Insertion Completed" << endl;
				break;

			case 4 :
				ask(name,"Enter name");
				ask(mfg, "Enter MFG");
				ask(expire, "Enter EXP");
				ask(LotNo,"Enter Lot Number");
				ask(Usefor,"Enter Use them for");
				ask(weightAll, "Enter Weight All");
				ask(quantityContainer, "Enter Quantity of Container");
				ask(quantityEach, "Enter Quantity of Each");
				ask(details, "Enter Product's Detail");
				
				s = new specificPurpose(name,mfg,expire,LotNo,Usefor,weightAll,quantityContainer,quantityEach,details);
				d.add_node(s);
				clear();
				cout << "[!] Insertion Completed" << endl;
				break;
			default : clear();
		}
}

void add_stock(){
	int flag;
	clear();
	do{
		try{
		flag = 0;
		cout<<"Please select the category you wish to add"<<endl;
		cout<<"1 : Food"<<endl;
		cout<<"2 : Drinks"<<endl;
		cout<<"3 : Daily Use Product"<<endl;
		cout<<"4 : Specific Use Product"<<endl;
		cout<<"5 : Back"<<endl;
		cout << "Input number : "; scin(add_choice);
		
		choice_insert_func();
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
	}while(add_choice != 5 || flag == 1);
}

void show_delete_stock(){
	int flag;
	clear();
	do{
		try{
	flag = 0;
	cout<<"Please select the category you wish to delete"<<endl;
	cout<<"1 : Food"<<endl;
	cout<<"2 : Drinks"<<endl;
	cout<<"3 : Daily Use Product"<<endl;
	cout<<"4 : Specific Use Product"<<endl;
	cout<<"5 : Back"<<endl;
	cout << "Input number : "; scin(add_choice);

		s_flag = 0;
		switch(add_choice){
			case 1 :
				clear();
				a.show_all();
				s_flag = 1;
				break;
			case 2 :
				clear();
				b.show_all();
				s_flag = 1;
				break;
			case 3 :
				clear();
				c.show_all();
				s_flag = 1;
				break;
			case 4 :
				clear();
				d.show_all();
				s_flag = 1;
				break;
			default :  clear();
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
	}while(add_choice != 5 && s_flag == 0 || flag == 1);
	//int inNodeID=0;
	if(add_choice !=5){
		do{
			cout<<"Please Enter NodeID you wish to delete"<<endl;
			cout<<"Enter 0 for Back to main menu"<<endl;
			ask(NodeID, "Enter NodeID");
			
			if(add_choice==1){
				if(NodeID==0) { clear(); break; }
				else if(a.check_NodeID(NodeID)) {
					a.delete_stock(NodeID);
					break;
				}
			}
			else if(add_choice==2){
				if(NodeID==0) { clear(); break; }
				else if(b.check_NodeID(NodeID)) {
					b.delete_stock(NodeID);
					break;
				}
			}
			else if(add_choice==3){
				if(NodeID==0) { clear(); break; }
				else if(c.check_NodeID(NodeID)) {
					c.delete_stock(NodeID);
					break;
				}
			}
			else{
				if(NodeID==0) { clear(); break; }
				else if(d.check_NodeID(NodeID)) {
					d.delete_stock(NodeID);
					break;
				}
			}
			
		}while(!a.check_NodeID(NodeID));
	}
}

void edit_stock(){
	int flag;
	clear();
	do{
		try{
		flag = 0;
	cout<<"Please select the category you wish to delete"<<endl;
	cout<<"1 : Food"<<endl;
	cout<<"2 : Drinks"<<endl;
	cout<<"3 : Daily Use Product"<<endl;
	cout<<"4 : Specific Use Product"<<endl;
	cout<<"5 : Back"<<endl;
	cout << "Input number : "; scin(add_choice);

		s_flag = 0;
		switch(add_choice){
			case 1 :
				clear();
				a.show_all();
				s_flag = 1;
				break;
			case 2 :
				clear();
				b.show_all();
				s_flag = 1;
				break;
			case 3 :
				clear();
				c.show_all();
				s_flag = 1;
				break;
			case 4 :
				clear();
				d.show_all();
				s_flag = 1;
				break;
			default :  clear();
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
	}while(add_choice != 5 && s_flag == 0 || flag == 1);
	int tmpNodeID;
	if(add_choice!=5){
		do{
			cout<<"Please Enter NodeID you wish to edit"<<endl;
			cout<<"Enter 0 for Back to main menu"<<endl;
			ask(NodeID, "Enter NodeID");
			
			if(add_choice==1){
				if(NodeID==0) { clear(); break; }
				else if(a.check_NodeID(NodeID)) {
					tmpNodeID = a.LLreturn_NodeID(NodeID);
					a.delete_stock(NodeID);
					clear();
					choice_insert_func();
					a.LLedit_NodeID(tmpNodeID);
					break;
				}
			}
			else if(add_choice==2){
				if(NodeID==0) { clear(); break; }
				else if(b.check_NodeID(NodeID)) {
					tmpNodeID = b.LLreturn_NodeID(NodeID);
					b.delete_stock(NodeID);
					clear();
					choice_insert_func();
					b.LLedit_NodeID(tmpNodeID);
					break;
				}
			}
			else if(add_choice==3){
				if(NodeID==0) { clear(); break; }
				else if(c.check_NodeID(NodeID)) {
					tmpNodeID = c.LLreturn_NodeID(NodeID);
					c.delete_stock(NodeID);
					clear();
					choice_insert_func();
					c.LLedit_NodeID(tmpNodeID);
					break;
				}
			}
			else{
				if(NodeID==0) { clear(); break; }
				else if(d.check_NodeID(NodeID)) {
					tmpNodeID = d.LLreturn_NodeID(NodeID);
					d.delete_stock(NodeID);
					clear();
					choice_insert_func();
					d.LLedit_NodeID(tmpNodeID);
					break;
				}
			}
			
		}while(!a.check_NodeID(NodeID)); /*SHOULD BE EDIT DUE WITH ERROR HANDLING*/
	}
}
#endif