
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000009
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

char s[5007];
struct rec
{
    int l;
    char *p;
};
rec sm[5007];

int strcmp2(const void *a,const void *b)
{
    return strcmp(((rec*)a)->p,((rec*)b)->p);
}

int main() {
    gets(s);
    int l;
    for(l=0;s[l];l++)
    {
        sm[l].p=&s[l];
        sm[l].l=l;
    }
    qsort(sm,l,sizeof rec,strcmp2);
    int res=l-sm[0].l;
    for(int i=1;i<l;i++)
    {
        int j=0;
        while(sm[i].p[j]==sm[i-1].p[j])j++;
        res+=l-sm[i].l-j;
    }
    printf("%d",res);

	return;
}

