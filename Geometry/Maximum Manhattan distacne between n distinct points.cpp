***************Maximum Manhattan distance between a distinct pair from N coordinates******************


|Xi – Xj| + |Yi – Yj| = max( (Xi – Yi) – (Xj – Yj),  (-Xi + Yi) – (-Xj + Yj),  (-Xi – Yi) – (-Xj – Yj), (Xi + Yi) – (Xj + Yj))

Follow the below steps to solve the problem:

Initialize two arrays sum[] and diff[].
Store the sum of X and Y coordinates i.e., Xi + Yi in sum[] and their difference i.e., Xi – Yi in diff[].
Sort the sum[] and diff[] in ascending order.
The maximum of the values (sum[N-1] – sum[0]) and (diff[N-1] – diff[0]) is the required result.

  
void an1nd1ta(int tc){

    int n;
    cin >> n;

    vector<ll>sum(n) , dif(n);

    for(int i=0;i<n;i++){

        ll x, y;
        cin >> x >> y;

        sum[i] = x+y;
        dif[i] = x-y;

    }

    sort(sum.begin(),sum.end());
    sort(dif.begin(),dif.end());

    cout << max(sum[n-1]-sum[0] , dif[n-1]-dif[0]) <<endl;

    return;
}
