/*
   Author: LemonTea
   Title: Tra chanh vi dau!
*/
// Libary **********************************
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
#include <iomanip>
//********************************************

using namespace std;
#define ll long long
//#define int ll
#define db double
#define NO cout<<"NO"<<endl
#define YES cout<<"YES"<<endl
const ll INF=1e17+7;
const double esl= 0.00001;

bool dbequal(double a, double b){
   return fabs(a-b)<esl;
}

// Codespace ******************************************

struct NhanVien{
   char code[10];
   char name[30];
   double salary;
};

struct node{
   NhanVien data;
   node* next=NULL;
};

node* head=NULL; node* tail=NULL;

void insertNode(){
   node* tmp=new node;
   fflush(stdin);
      cin>>tmp->data.code>>tmp->data.name>>tmp->data.salary;
      fflush(stdin);
      if (head==NULL){
         head=tmp;
         tail=tmp;
       }
      else{
         tail->next=tmp;
         tail=tmp;
      }
}
void slove(){
   ll n; cin>>n;
   for (int i=0; i<n; i++){
      insertNode();
   }

   char id1[10], id2[10]; 
   fflush(stdin);
   cin>>id1;
   cin>>id2;
   fflush(stdin);
   char s[30]; cin>>s;

   //tim
   int pos=1;
   node* it=head;
   while(it!=NULL){
      if (strcmp(it->data.code, id1)==0){
         cout<<pos<<endl;
         break;
      }
      pos++;
      it=it->next;
      if (it==NULL) cout<<-1<<endl;
   }
	// xoa
   it=head;
   if (strcmp(head->data.code, id2)==0){
      head=head->next;
   }
   else{
      while(it->next!=NULL){
         if (strcmp(it->next->data.code, id2)==0){
            it->next=it->next->next;
            break;
         }
         pos++;
         it=it->next;
      }
   }
	// tim2
   it=head;
   while(it!=NULL){
      if (strcmp(it->data.name, s)==0){
         cout<<it->data.code<<" "<<it->data.name<<" "<<fixed<<setprecision(4)<<it->data.salary;
         break;
      }
      it=it->next;
      if (it==NULL) cout<<-1;
   }

}

signed main(){
   ios_base::sync_with_stdio(false);
    cin.tie(0);
   #ifndef ONLINE_JUDGE
      freopen("INPUT.txt","r",stdin);
	   freopen("OUTPUT.txt","w",stdout);
      //  ifstream fi("INPUT.txt");
      //  ofstream fo("OUTPUT.txt");
	#endif
 //  clock_t begin = clock();
 //  ll t; cin>>t;
//   while(t--)
    slove();
 //  //   clock_t end = clock();
   //   cout<<"\nTime run: "<<(float)(end-begin)/CLOCKS_PER_SEC<<" s"<<endl;
}