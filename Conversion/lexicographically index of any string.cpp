//// if we have string from A,B,.....,Z,AA,AB,AC,.....ZZ,AAA,AAB,AAC,.....ZZZ and so on.
//// Here A in index 1 , B in index 2 & AA in index 27 , AB in index 28 && AAA in index 703.

ll ans = 0;
for(int i=0;i<n;i++){
    ans = ans * 26LL + (ll)get_char(s[i]);
}
cout << ans << endl;

input ABC
output 731
  
