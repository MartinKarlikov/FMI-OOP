#include<iostream>
#include<cstring>
using namespace std;

struct Histogram{
    char name[128];
    int n;
};

void add(Histogram *&h, int &m, char* name){
    Histogram *temp = new Histogram[m+1];
    for(int i=0; i<m; i++){
        strcpy(temp[i].name, h[i].name);
        temp[i].n = h[i].n;
    }
    strcpy(temp[m].name, name);
    temp[m].n = 1;
    delete[] h;
    h = temp;
    m++;


}

void sort(Histogram *h, int m){
    for(int i=0; i<m; i++){
        for(int j=i+1; j<m; j++){
            if(h[i].n<h[j].n)swap(h[i], h[j]);
        }
    }
}


int main()
{
    int m=0, n;
    char name[128];
    Histogram *h = new Histogram[m];
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>name;
        int j=0;
        while(j<m && strcmp(h[j].name, name))j++;
        if(j==m)add(h, m, name);
        else h[j].n++;
    }

    sort(h, m);

    cout<<h[0].name<<" "<<h[0].n<<endl;
    delete[] h;

    return 0;
}
