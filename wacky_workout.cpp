//www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/angry-neighbours/
#include <iostream>
#include <vector>
#define vec vector<vector<unsigned long long int>>
#define ull unsigned long long int
#define modulo 1000000007
using namespace std;

void show_mat(vec a)
{
    for( int i=0; i<a.size(); i++)
    {
        for( int j=0; j<a[i].size(); j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

vec multply(vec a, vec b)
{
    vec result={{1,1},{1,0}};
    for( int i=0; i<2; i++)
    {
        for( int j=0; j<2; j++)
        {
            ull temp=0;
            for( int k=0; k<2; k++)
            {
                // temp = temp % modulo;
                temp += ( a[i][k]  * b[k][j]) % modulo;
            }
            result[i][j]= temp;
        }
    }
    return result;
}

vec calculate_power( vec base, ull exponent )
{
    vec res = {{1,0},{0,1}};

    while(exponent)
    {
        if( exponent & 1 )
        {
            res = multply(res,base);    // res*=base;
            exponent--;
        }
        else
        {
            exponent /=2;
            base = multply ( base,base);
        }
    }
    return res;


    // show_mat(res);
    // if( n == 1)
    // {
    //     return v;
    // }

    // vec temp = calculate_power(v,n/2);

    // if( n&1 )
    // {
    //     return multply( multply(temp,temp),v);
    // }
    // return multply(temp,temp);

}

ull solve(ull n)
{
    int answr[]={1,2,3,5,8};

    if(n<4)
    {
        return answr[n];
    }

    vec a={{1,1},{1,0}};

    vec product=a;

    product = calculate_power (a,n);

    // show_mat(product);

    ull temp=  (product[0][0]*1 )% modulo +  (product[0][1] % modulo);
    temp = temp % modulo;

    // cout<<temp<<"\n";


    return (temp % modulo);

}

int main()
{
    int t=1;
    ull n=49;
    cin>>t;

    while(t--)
    {
        cin>>n;
        cout<<solve(n)<<"\n";
    }

    // for( ull i=0; i<10; i++)
    // {
    //     cout<<i<<" ";
    //     cout<<solve(i)<<"\n";
    // }
}
