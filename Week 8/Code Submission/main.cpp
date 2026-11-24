#include <bits/stdc++.h>
using namespace std;

string z;
const int max_time = 86400;

unordered_map <string , long long> err_submision; 
unordered_map <string , long long> total_point; 
unordered_map <string , long long> max_point_problem; 
string UserID, ProblemID,Status,TimePoint;
int Point;
long long sub_to_sec[max_time + 1];
long long total_sub[max_time + 1];
int TimeToSecond(const string& t)
{
    int h = (t[0] - '0') * 10 + (t[1] - '0');
    int m = (t[3] - '0') * 10 + (t[4] - '0');
    int s = (t[6] - '0') * 10 + (t[7] - '0');
    return h * 3600 + m * 60 + s;
}
int main()
{
    freopen("main.inp","r",stdin);
    freopen("main.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long total_errol_submision = 0;
    long long total_number_submision = 0;

    while(cin>>UserID)
    {
        if(UserID=="#") break;
        cin>>ProblemID>>TimePoint>>Status>>Point;
        total_number_submision ++ ;
        if(Status == "ERR") 
        {
            total_errol_submision++;
            err_submision[UserID] += 1;
        }
        else 
        {
            int k = max_point_problem[UserID + "#" + ProblemID];
            max_point_problem[UserID + "#" + ProblemID] = max(k,Point);
            if(max_point_problem[UserID + "#" + ProblemID] == Point)
            {
                total_point[UserID] = total_point[UserID] - k + Point;
            }
        }

        int Time = TimeToSecond(TimePoint);
        sub_to_sec[Time] ++ ;
    }
    total_sub[0] = sub_to_sec[0];
    for (int i = 1; i <= max_time; i++) 
    {
        total_sub[i] = total_sub[i - 1] + sub_to_sec[i];
    }
    while (cin>>z)
    {
        if(z=="#") return 0;
        else 
        {
            if(z == "?total_number_submissions")
            {
                cout<<total_number_submision<<'\n';
            }
            else if(z == "?number_error_submision")
            {
                cout<<total_errol_submision<<'\n';
            }
            else if(z == "?total_point_of_user")
            {
                cin>>UserID;
                cout<<total_point[UserID]<<'\n';
            }
            else if(z == "?number_error_submision_of_user")
            {
                cin>>UserID;
                cout<<err_submision[UserID]<<'\n';
            }
            else 
            {
                cin>>TimePoint;
                int x = TimeToSecond(TimePoint);
                cin>>TimePoint;
                int y = TimeToSecond(TimePoint);
                cout<<total_sub[y] - total_sub[x-1]<<'\n';

            }
        }
    }
    return 0;
    
}