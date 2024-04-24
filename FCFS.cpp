#include <iostream>
#include "vector"
#include<algorithm>
using std::vector;
using std::cout;
using std::endl;
class prc{
public:
    int arrive;
    int time;
    int level;
    int end;
    prc(int ar,int ti,int le):arrive(ar),time(ti),level(le),end(0){};
};
double FCFS_avg_wait(vector<prc> & arr){
    double sum=0;
    for(auto & i : arr){
        sum+=static_cast<double>(i.end)-static_cast<double>(i.time);
    }
    cout<<endl;
    return sum/static_cast<double>(arr.size());
};
double FCFS_end_time(const vector<prc>&arr){
    double sum=0;
    for(auto item:arr){
        sum+=static_cast<double>(item.end);
    }
    return sum/static_cast<double>(arr.size());
}
bool cmp(const prc &a,const prc &b){
    return a.arrive<b.arrive;
}
void init(vector<prc>&arr,int &n){
    for(int i=0;i<n;i++){
        int arrive,time,level;
        cout<<"请分别输入进程p"<<i+1<<"的到达时间，运行时间，优先级："<<endl;
        std::cin>>arrive>>time>>level;
        prc a(arrive,time,level);
        arr.push_back(a);
    }
    std::sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<arr.size();i++){
        if(i==0){
            arr[i].end=arr[i].time;
        }else{
            arr[i].end=arr[i].time+arr[i-1].end;
        }
    }
}
int main() {
    int n;
    cout<<"请输入进程个数:";
    std::cin>>n;
    vector<prc>arr;
    init(arr,n);
//    for(auto item:arr){
//        cout<<"结束时间："<<item.end<<" ";
//    }
    double avg_wait= FCFS_avg_wait(arr);
    cout<<"平均等待时间："<<avg_wait<<"s"<<endl;
    cout<<endl;
    double avg_end= FCFS_end_time(arr);
    cout<<"平均运行时间："<<avg_end<<"s"<<endl;
    return 0;
}
