#include <iostream>
using namespace std;
class link{
public:
string name;
int score;
link * pnext;
link (string n, int s){
	name= n;
	score=s;
	pnext=NULL;
}
void display(){
	cout<<"{"<<name<< ", "<<score<< "}-->";
	}
};

class linked_list{
private:
link * pfirst;

public:
linked_list(){
	pfirst=NULL;
}	
void insert (string n, int s){
	link * pnewnode = new link(n,s);
	pnewnode->pnext=pfirst;
	pfirst=pnewnode;
}
void display_list(){
	cout<< "\n" ;
	link * pcurrent=pfirst;
	while(pcurrent!=NULL){
		pcurrent ->display();
		pcurrent=pcurrent->pnext;
	}
}
	void peek(){
		link * pcurrent=pfirst;
		pcurrent->display();
	}
	void pop(){
		pfirst=pfirst->pnext;
	}

    int linearsearch(){
      int f;
      cout<<"\n What score would you like to find in the scores you gave?:\n ";
      cin>>f;
	link * pcurrent=pfirst;
	while(pcurrent!=NULL){
		if(pcurrent->score==f){
			cout<<"Found";
			return 0;
		}
			pcurrent=pcurrent->pnext;
}
	    cout <<"not found";
		return -1;
}
};

int main() {
    linked_list l1;
    l1.insert("Tom", 70);
    l1.insert("Jay", 30);
    l1.insert("Kim", 55);
    l1.insert("Ian", 40);
    l1.peek();
    cout<< endl;
    l1.pop();
    l1.peek();
    l1.	display_list();
	l1.linearsearch();
    return 0;
}

