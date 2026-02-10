#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    //Input: time in HH:MM format
    if(!(cin >> s)) return 0;
    
    int X,Y;
    //X = cost per hour step,Y = cost per minute step
    cin >> X >>Y;
    
    //Lambda to convert 2 characters into an integer(for HH or MM)
    auto toint=[&](int a,int b){
    	return (a-'0')*10+(b-'0');
    };
    //Extract hour and minte from input string
    int h0=toint(s[0],s[1]);
    int m0=toint(s[3],s[4]);
    //7-segment binary representation for digits 0-9
    //each bit represents a segment (1=ON,0=OFF)
    static const int seg[10]={
    	0x3F,//0=0b0111111
        0x06,//1=0b0000110
        0x5B,//2=0b1011011
        0x4F,//3=0b1001111
        0x66,// 4 = 0b1100110
        0x6D,// 5 = 0b1101101
        0x7D,// 6 = 0b1111101
        0x07,// 7 = 0b0000111
        0x7F,// 8 = 0b1111111
        0x6F,// 9 = 0b1101111
     };
     
     //Check if two digits differ by exactly one segement
     auto pop1=[&](int a,int b){
     	return __builtin_popcount(a^b)==1;
     };
     //Hour difference in "minute steps' around the clock(circular)
     auto hourSteps=[&](int hour1,int hour2){
     	int d=(hour1-hour2)%12;
        if(d<0)d+=12;
        d=min(d,12-d);
        return d*5;//convert hour difference to equvalent minutes
     };
     //Minute difference aroud the dial (circular)
     auto minuteSteps=[&](int minute1,int minute2){
     	int d=(minute1-minute2)%60;
        if(d<0)d+=60;
        return min(d,60-d);
     };
     
     string best="";  //store best candidate time
     long long bestCost=LLONG_MAX; //minimum weightend cost(X*hs+Y*ms)
     long long bestSteps=LLONG_MAX;  //tie-breaker:total steps(hs+ms)
     
     string cur=s;
     array<int,4>pos={0,1,3,4};  //positions of digits in "HH:MM"
     
     //try changing one digit at a time
     for(int p=0;p<4;++p){
     	int idx=pos[p];
        int curDigit=cur[idx]-'0';
        for(int nd=0;nd<=9;++nd){
        	if(nd==curDigit) continue;
            if(!pop1(seg[curDigit],seg[nd])) continue;
            
            string t=cur;
            t[idx]=char('0'+nd);
            int hh=(t[0]-'0')*10+(t[1]-'0');
            int mm=(t[3]-'0')*10+(t[4]-'0');
            if(hh<1 || hh>12 || mm<0 || mm>59) continue;
            int hs=hourSteps(hh,h0);
            int ms=minuteSteps(mm,m0);
            
            long long cost=1LL*X*hs+1LL*Y*ms;
            long long steps=hs+ms;
            
            if(cost<bestCost ||(cost==bestCost &&(steps<bestSteps ||(steps==bestSteps && t<best)))){
            	bestCost=cost;
                bestSteps=steps;
                best=t;
             }
          }
       }
       
       if(best.empty()){
       	cout<<"No closest valid time possible";
       }else{
       	cout<<best;
       }
       
       return 0;
    }