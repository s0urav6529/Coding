
*******Charecter to Intger****

char ch='7';
int a=(int)(ch-'0');



string s="671235712";
for(int i=0;i<s.size();i++){
     int a=(int)(ch-'0');
     cout<<a<<endl;
}

******string to integer*********

///builtin function

string s="738642";
int n=stoi(s);


///function

int convert(string s) {
    int num=0;
    int n=s.size();

    for(int i=0;i<n;i++)
        num=num*10+(int(s[i])-48);
    return num;
}

********integer to string******

///builtin fumction

int n=214123;
string s=to_string(n);


********integer to charecter*****

string s="";
int a=5,b=6;
char ch=((b-a)+'0');
b+=ch;

or
b+=(char)((b-a)+'0');



