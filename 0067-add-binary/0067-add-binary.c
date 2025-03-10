int max(int a, int b){
    return (a>b)?a:b;
}
char* addBinary(char* a, char* b) {
    int la=strlen(a);
    int lb=strlen(b);
    int m=max(la,lb);

    char* pa=(char*)malloc(m+1);
    char* pb=(char*)malloc(m+1);

    memset(pa,'0',m-la);
    strcpy(pa+(m-la),a);
    pa[m]='\0';

    memset(pb,'0',m-lb);
    strcpy(pb+(m-lb),b);
    pb[m]='\0';

    char* arr = (char*)malloc(m+2);
    int carry=0,ind=0;

    // printf("%s  %s\n",pa,pb);
    // printf("%d  %d",strlen(a),strlen(b));

    while(m--){
        if(pa[m]==pb[m]){
            if(carry==1)arr[ind]='1';
            else arr[ind]='0';
            if(pa[m]=='1')carry=1;
            else carry=0;
        }
        else{
            if(carry==1)arr[ind]='0';
            else arr[ind]='1';
        }
        ind++;
    }
    // printf("%d  ",ind);
    if(carry==1)arr[ind++]='1';
    arr[ind] = '\0';
    // printf("%s",arr);
    int len = ind;
    for (int i = 0; i < len / 2; i++) {
        char t = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = t;
    }


    return arr;
}