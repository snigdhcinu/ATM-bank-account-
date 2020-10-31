#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;

struct Point{
    float x;
    float y;
};

struct Result{
    Point p;
    int nr_pts;
    double f_val;
};

Point pt(float x, float y){
    Point p={x,y};
    return p;
}

double f(Point p){
    return pow((p.x*p.x +p.y -11),2) + pow((p.x + p.y*p.y -7),2);    
}

vector<Point> neighbors(Point p,float d){
    
    vector<Point> n;

    n.push_back(pt(p.x+d,p.y));
    n.push_back(pt(p.x-d,p.y));
    n.push_back(pt(p.x,p.y+d));
    n.push_back(pt(p.x,p.y-d));
    n.push_back(pt(p.x+d,p.y+d));
    n.push_back(pt(p.x+d,p.y-d));
    n.push_back(pt(p.x-d,p.y+d));
    n.push_back(pt(p.x-d,p.y-d));
    
    return n;
}

Result FirstChoiceHC(Point p,float step){
    
    Result firstChoice;
    int nr_pts=0;
    int iters=0;
    Point curr=p;
    float f_curr = f(curr);
    vector<Point>&& succ=neighbors(curr,step);
    while(1){

        srand(time(NULL));
        int idx=rand()%succ.size();
        Point nxt=succ[idx];
        succ.erase(succ.begin()+idx);
        
        if (f(nxt)<f_curr){
            curr=nxt;
            f_curr=f(nxt);
            nr_pts++;
            succ=neighbors(curr,step);

        } 

        else if(succ.empty()){
            break;
        } 

        else{
            continue;
        }
            
    }

    firstChoice.p=curr;
    firstChoice.nr_pts=nr_pts;
    firstChoice.f_val=f(curr);

    return firstChoice;
}

Point mincost(vector<Point> neighbors){

    Point min_pt=neighbors[0];
    for(auto i:neighbors){
        if(f(i)<f(min_pt)){
            min_pt=i;
        }
    }

    return min_pt;
}

Result HillClimb(Point p,float step){

    Result temp;
    Point curr=p;
    int nr_pts=0;
    vector<Point>&& succ=neighbors(curr,step);
    while(1){
        
        Point nxt=mincost(succ);
        nr_pts++;
        if(f(nxt)>f(curr)){
            break;
        }
        curr=nxt;
        succ=neighbors(curr,step);
    }

    temp.p=curr;
    temp.nr_pts=nr_pts;
    temp.f_val=f(curr);
    return temp; 
}

Result RandomRestart(Point p,float step, int restarts){
    
    Result randRestart;
    int nr_pts=0;
    Point curr=p;
    vector<Result> temp;
    Result res =HillClimb(curr,step);
    temp.push_back(res);

    int iters=0;

    while(iters<restarts){

        Point start;
        srand(time(NULL));
        start.x=rand()%10 -5;
        start.y=rand()%10 -5;
        Result res =HillClimb(start,step);
        temp.push_back(res);

        iters++;
    }

    int min_idx=0;
    for(int i=1;i<temp.size();i++){
        if(temp[i].f_val<temp[min_idx].f_val){
            min_idx=i;
        }
    }

    for(auto i:temp){
        nr_pts+=i.nr_pts;
    }
    randRestart.p=temp[min_idx].p;
    randRestart.nr_pts=nr_pts;
    randRestart.f_val=temp[min_idx].f_val;

    return randRestart;
}

int main(){
    float step;
    Point start;
    int restarts;
    cout<<"input step size(0.1 to 0.5) and start point (-5.+5)"<<endl;
    cin>>step>>start.x>>start.y;
    cout<<"\nEnter restarts"<<endl;
    cin>>restarts;

    Result randRes=RandomRestart(start,step,restarts);
    Result firstChoice=FirstChoiceHC(start,step);

    cout<<"Rand: "<<randRes.nr_pts<<" "<<randRes.f_val <<endl;
    cout<<"FCHC: "<<firstChoice.nr_pts<<" "<<firstChoice.f_val<<endl;
    
    return 0;
}
