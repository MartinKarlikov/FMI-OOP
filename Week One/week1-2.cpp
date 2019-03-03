#include<iostream>
#include<cmath>
using namespace std;

struct Point{
    double x, y;
};

double getLength(const Point a, const Point b){
    return sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}


struct Triangle{
    Point A, B, C;
    double getS2(){
        double a=getLength(B, C), b=getLength(A, C), c=getLength(A, B);
        double p=(a+b+c)/2;
        return p*(p-a)*(p-b)*(p-c);
    }
};

int main()
{
    int n;
    cin>>n;
    Triangle *t = new Triangle[n+1];
    for(int i=0; i<n; i++){
        cin>>t[i].A.x>>t[i].A.y>>t[i].B.x>>t[i].B.y>>t[i].C.x>>t[i].C.y;
    }

    int maxcnt=0;
    for(int i=0; i<n; i++){
        int cnt=1;
        int s=t[i].getS2();
        for(int j=i+1; j<n; j++){
            int s1=t[j].getS2();
            if(s1==s)cnt++;
        }
        if(cnt>maxcnt)maxcnt=cnt;
    }
    cout<<maxcnt<<endl;

    delete[] t;

    return 0;
}
