#include <bits/stdc++.h>

using namespace std;

class Screen 
{
    int row, rowsize, size;
    vector <string> seat; //each row is a string consists of 3 chars only(E=empty, A=aisle, R=reserved) 
    public:
        Screen(vector<string> vect)
        {
            string row_str="";
            row = stoi(vect[2]);
            rowsize=stoi(vect[3]);
            for(int i=0;i<rowsize;i++) row_str+='E'; //empty
            
            for(int i=4;i<vect.size(); i++) row_str[stoi(vect[i])-1]='A'; //aisle
            
            for(int i=0;i<row;i++) seat.push_back(row_str);
            
            cout<<"success"<<endl;
        }
        
        string reserve_seat(vector<string> vect) 
        {
            bool flag=true;
            int rownum=stoi(vect[2])-1;
            for(int i=3;i<vect.size();i++)
            {
                int seatnum=stoi(vect[i])-1;
                if(seat[rownum][seatnum]=='R')
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false) return "failure";
            for(int i=3;i<vect.size();i++)
            {
                int seatnum=stoi(vect[i])-1;
                seat[rownum][seatnum]='R';
            }
            return "success";
        }
        
        vector <int> get_unreserved(int rownum)
        {
            vector <int> ans;
            for(int i=0;i<rowsize;i++)
            {
                if(seat[rownum][i]!='R') ans.push_back(i+1);
            }
            return ans;
        }
        
        vector <int> suggest_seats(int num_seats, int rownum, int choice)
        {
            string r=seat[rownum];
            vector <int> ans;
            bool flag=true;
            for(int i=choice-num_seats+1;i>=0 && i<=choice;i++)
            {
                if(r[i]=='R') flag=false;
                if(i>choice-num_seats+1 && r[i-1]=='A' && r[i]=='A') flag=false;
            }
            if(flag==true)
            {
                for(int i=choice-num_seats+1;i>=0 && i<=choice;i++)
                    ans.push_back(i+1);
                return ans;
            }
            flag=true;
            for(int i=choice;i<choice+num_seats;i++)
            {
                if(r[i]=='R') flag=false;
                if(i>choice && r[i-1]=='A' && r[i]=='A') flag=false;
            }
            if(flag==true)
            {
                for(int i=choice;i<choice+num_seats;i++)
                    ans.push_back(i+1);
                return ans;
            }
            return ans;
        }
};


vector<string> words(string str) { 
    stringstream ss(str);
    string token="";
    vector<string> ans;
    while(getline(ss, token, ' '))
    {
        if(token!="") ans.push_back(token);
    }
    return ans;
}

int main() {
	int n;
	unordered_map <string, Screen*> mp;
	cin>>n;
	
	for(int i=0; i<=n; i++) 
	{
	    string str;
	    getline(cin, str);
	    vector <string> line=words(str);
	    if(line.empty()) continue;
	    string screen_name=line[1];
	    
	    if(line[0]=="add-screen")
	    {
	        mp[screen_name]=new Screen(line);   
	    }
	    else if(line[0]=="reserve-seat") 
	    {
	        string res;
	        if(mp.find(screen_name)!=mp.end())
	            res=mp[screen_name]->reserve_seat(line);
	        else
	            res="failure";
	        cout<<res<<endl;
	    }
	    else if(line[0]=="get-unreserved-seats")
	    {
	        if(mp.find(screen_name)!=mp.end())
	        {
	            vector <int> res=mp[screen_name]->get_unreserved(stoi(line[2])-1);
	            for(int x: res) cout<<x<<" ";
	        }
	        else 
	            cout<<"failure";
	        cout<<endl;
	    }
	    else if(line[0]=="suggest-contiguous-seats")
	    {
	        if(mp.find(screen_name)!=mp.end()) 
	        {
	            vector <int> res=mp[screen_name]->suggest_seats(stoi(line[2]), stoi(line[3])-1, stoi(line[4])-1);
	            if(res.empty()) cout<<"none"<<endl;
	            else
	            {
	                for(int x: res) cout<<x<<" ";
	                cout<<endl;
	            }
	        }
	        else
	            cout<<"failure"<<endl;
	    }
	}
	return 0;
}
