/// Linear Diaphontine Equation
/// which is (ax+by=c) where c = gcd(a,b) then exits a solution otherwise no solution
/// find x and y of the solution 


int Extended_Euclidian_Algorithm(int a,int b,int &x,int &y){

    if(b==0){
        x=1;
        y=0;
        return a; ///returning GCD
    }

    int x1,y1;
    int g=Extended_Euclidian_Algorithm(b,a%b,x1,y1);

    ///solution of x and y of Extended_Euclidian_Algorithm;
    x=y1;
    y=x1-y1*(a/b);

    return g; ///returning GCD

}
bool solution_exists(int a,int b,int c,int &x,int &y){  ///checking the solution exists or not

    int x0,y0;
    int g=Extended_Euclidian_Algorithm(abs(a),abs(b),x0,y0);

    if(c%g){
        ///solution doesnot exists because c%g!=0
        return false;
    }

    ///solution of x and y in LDE

    x=x0 * c/g;
    y=y0 * c/g;

    if(a<0) x=-x;
    if(b<0) y=-y;
    return true;
}
int main(){

    int a,b,c,x,y;
    cin>>a>>b>>c;

    if(solution_exists(a,b,c,x,y)==false){

        cout<<"No Solution Exists"<<endl;
    }
    else{
        ///solution of x and y
        cout<<x<<"   "<<y<<endl;
    }

}
