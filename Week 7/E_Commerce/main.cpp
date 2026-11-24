#include <bits/stdc++.h>
using namespace std;

string z;
const int max_time = 86400;

unordered_map <string , long long> shop_rev; // doanh thu theo ShopID
unordered_map <string , long long> customer_shop_rev; //doanh thu Shop ban cho Customer
string CustomerID, ProductID,ShopID,TimePoint;
int Price;
int rev_to_sec[max_time + 1];
int total_rev[max_time + 1];
int TimeToSecond(const string& t)
{
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    int s = (t[6] - '0') * 10 + (t[7] - '0');
    return h * 3600 + m * 60 + s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long total_revenue = 0;
    long long total_number_orders = 0;

    while(cin>>CustomerID)
    {
        if(CustomerID=="#") break;
        cin>>ProductID>>Price>>ShopID>>TimePoint;
        total_number_orders ++ ;
        total_revenue += Price;

        shop_rev[ShopID] += Price;
        customer_shop_rev[CustomerID + "#" + ShopID] += Price;

        int Time = TimeToSecond(TimePoint);
        rev_to_sec[Time] += Price;
    }
    for(int i=1;i<=max_time;i++)
    {
        total_rev[i] = total_rev[i-1] + rev_to_sec[i];
    }
    while (cin>>z)
    {
        if(z=="#") return 0;
        else 
        {
            if(z == "?total_number_orders")
            {
                cout<<total_number_orders<<'\n';
            }
            else if(z == "?total_revenue")
            {
                cout<<total_revenue<<'\n';
            }
            else if(z == "?revenue_of_shop")
            {
                cin>>ShopID;
                cout<<shop_rev[ShopID]<<'\n';
            }
            else if(z == "?total_consume_of_customer_shop")
            {
                cin>>CustomerID>>ShopID;
                cout<<customer_shop_rev[CustomerID + "#" + ShopID]<<'\n';
            }
            else 
            {
                cin>>TimePoint;
                int x = TimeToSecond(TimePoint);
                cin>>TimePoint;
                int y = TimeToSecond(TimePoint);
                cout<<total_rev[y] - total_rev[x-1]<<'\n';

            }
        }
    }
    return 0;
    
}