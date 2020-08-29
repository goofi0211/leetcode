// use two pointer each pointer traversal each array 
//compare each value of pointer
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int *cpn1=malloc(sizeof(int)*nums1Size);
    int i;
    for(i=0;i<m;i++){
        cpn1[i]=nums1[i];
    }
    int p1=0,p2=0,index=0;
    while(p1!=m&&p2!=n){
        if(cpn1[p1]>nums2[p2]){
            nums1[index]=nums2[p2];
            p2++;
        }
        else{
            nums1[index]=cpn1[p1];
            p1++;
        }
        index++;
    }
    if(p1!=m)
        for(i=p1;i<m;i++)
            nums1[index++]=cpn1[i];
    else
        for(i=p2;i<n;i++)
            nums1[index++]=nums2[i];
}