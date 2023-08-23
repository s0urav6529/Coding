


class Solution {
public:
    string reorganizeString(string s) {
        vector<pair<int,char>>a;
        vector<int>cnt(26,0);
        int n = s.size();


        for(int i=0;i<n;i++){

            cnt[s[i]-'a']++;
        }

        for(int i=0;i<26;i++){

            a.push_back({cnt[i],(char)('a'+i)});

        }

        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());

        int sum = 0;

        for(int i=1;i<a.size();i++){

            sum += a[i].first;

        }

        if(sum+1 < a[0].first){
            return "";
        }


        string p="";

        p = p + a[0].second +"?";

        n = a.size();

        bool ok = true;
        
        while(ok){

            ok = false;

            for(int i=0;i<n;i++){

                if(a[i].first > 0){ 

                    string temp = "";

                    temp += p[0];

                    ok = true;
                    
                    int N = p.size();

                    a[i].first--;

                    char ch = a[i].second;
                    
                    for(int j=1;j<N;j++){

                        if(p[j-1]!= ch && p[j] != ch){
                            
                            temp += ch;

                            while(j<N){
                                temp += p[j++];
                            }

                        }
                        else temp += p[j];

                    }
                    p = temp;
                }
            }
        }
        p.pop_back();
        return p;



    }
};
