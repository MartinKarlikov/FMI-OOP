#include<iostream>
#include"exhibition.hpp"
using namespace std;

int main()
{
    int n;
    cin>>n;
    Exhibition *exhibitions=new Exhibition[n];
    for(int i=0; i<n; i++){
        int m, t;
        cin>>m>>t;
        exhibitions[i]=Exhibition(t);
        for(int j=0; j<m; j++){
            int id;
            char author[100], name[100];
            double value;
            cin>>id>>author>>name>>value;
            Painting p(id, author, name, value);
            exhibitions[i].addPainting(p);
        }
    }
    double maxValue=exhibitions[0].getValueSum();
    int index=0;
    for(int i=1; i<n; i++){
        double value=exhibitions[i].getValueSum();
        if(value>maxValue){
            maxValue=value;
            index=i;
        }
    }
    cout<<index<<endl;

    return 0;
}
