char* addBinary(char* a, char* b) {
    int la=strlen(a);
    int lb=strlen(b);
    int m=(la>lb)?la:lb;
    char* arr = (char*)malloc(m+2);
    int carry=0,ind=0;
    
    int i=la-1,j=lb-1;

    // continue adding till smaller length array
    while(i>=0 && j>=0){
        if(a[i]==b[j]){
            if(carry==1)arr[ind]='1';
            else arr[ind]='0';
            if(a[i]=='1')carry=1;
            else carry=0;
        }
        else{
            if(carry==1)arr[ind]='0';
            else arr[ind]='1';
        }
        ind++;
        i--;j--;
    }

    // if first array is not finished then we'll check for rest elements
    while(i>=0){
        if(carry==(a[i]-'0')){
            arr[ind]='0';
        }
        else{
            arr[ind]='1';
            carry=0;
        }
        i--;
        ind++;
    }

    // if second array is not finished then we'll check for rest elements
    while(j>=0){
        if(carry==(b[j]-'0')){
            arr[ind]='0';
        }
        else{
            arr[ind]='1';
            carry=0;
        }
        j--;
        ind++;
    }

    //if carry left
    if(carry==1)arr[ind++]='1';
    arr[ind] = '\0';
    int len = ind;

    //for reversing string
    for(int i=0;i<len/2;i++){
        char t=arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=t;
    }

    return arr;
}