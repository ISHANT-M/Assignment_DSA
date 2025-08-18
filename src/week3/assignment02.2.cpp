// Q1 TO Q3 (ANSWERED IN C) are there in week 2




// 4) string functions


#include <iostream>
using namespace std;

void add(char *, char *);
void rev(char *, int);
void del(char *);
void sort(char *);
void utol(char *);
void print(char *);

int main() {
    cout << "1 concatenate \n2 reverse \n3 delete all vowels \n4 sorting \n5 lowercase \n\n";

    int i;
    char arr[] = "Hello How are you?? \0";
    char ar[] = "i am fine! Thank You \0";
    cin >> i;
    int len = sizeof(arr)/sizeof(arr[0]);

    if(i==1) add(arr, ar);
    else if(i==2) rev(arr,len);
    else if(i==3) del(arr);
    else if(i==4) sort(arr);
    else if(i==5) utol(arr);
    return 0;
}

void print(char *array){
    int i = 0;
    while(*(array+i) != '\0'){
        cout << *(array + i);
        i++;
    }
    cout << endl;
}

void add(char* a1, char* a2){
    char s[100];
    int l = 0;
    int i = 0;
    while(*(a1+i)!='\0'){
        *(s+l) = *(a1+i);
        i++;
        l++;
    }
    i=0;
    while(*(a2+i)!='\0'){
        *(s+l) = *(a2+i);
        i++;
        l++;
    }
    l++;
    *(s+l) = '\0';
    print(s);
}

void rev(char *array, int len){
    for(int i = len - 2; i >= 0; i--){
        cout << *(array + i);
    }
    cout << endl;
}

void del(char *array){
    char s[50];
    int i = 0, j = 0;
    while(*(array+i)!='\0'){
        if(*(array+i)!='a' && *(array+i)!='e' && *(array+i)!='i' && *(array+i)!='o' && *(array+i)!='u' &&
           *(array+i)!='A' && *(array+i)!='E' && *(array+i)!='I' && *(array+i)!='O' && *(array+i)!='U'){
            s[j] = *(array+i);
            j++;
        }
        i++;
    }
    s[j] = '\0';
    print(s);
}

void sort(char *array){
    int n = 0;

    // find length of array
    while(array[n] != '\0'){
        n++;
    }

    // bubble sort in-place
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j] > array[j+1]){
                char temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    print(array);
}

void utol(char *array){
    int i = 0;
    while(*(array+i) != '\0'){
        if(array[i] >= 'A' && array[i] <= 'Z'){
            array[i] = array[i] + 32;
        }
        i++;
    }
    print(array);
}







// 5) matrix 


#include <iostream>
using namespace std;

// diagonal
void setDiagonal(int A[], int n, int i, int j, int x) {
    if(i==j) A[i-1] = x;
}
int getDiagonal(int A[], int n, int i, int j) {
    if(i==j) return A[i-1];
    return 0;
}
void displayDiagonal(int A[], int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<getDiagonal(A,n,i,j)<<" ";
        }
        cout<<endl;
    }
}

// Tri-diagonal Matrix 
void setTri(int A[], int n, int i, int j, int x) {
    if(i-j==1) A[i-2]=x;
    else if(i-j==0) A[n-1+i-1]=x;
    else if(i-j==-1) A[2*n-1+i-1]=x;
}
int getTri(int A[], int n, int i, int j) {
    if(i-j==1) return A[i-2];
    else if(i-j==0) return A[n-1+i-1];
    else if(i-j==-1) return A[2*n-1+i-1];
    return 0;
}
void displayTri(int A[], int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<getTri(A,n,i,j)<<" ";
        }
        cout<<endl;
    }
}

// Lower Triangular Matrix
void setLower(int A[], int n, int i, int j, int x) {
    if(i>=j) A[i*(i-1)/2+j-1]=x;
}
int getLower(int A[], int n, int i, int j) {
    if(i>=j) return A[i*(i-1)/2+j-1];
    return 0;
}
void displayLower(int A[], int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<getLower(A,n,i,j)<<" ";
        }
        cout<<endl;
    }
}

//Upper Triangular Matrix
void setUpper(int A[], int n, int i, int j, int x) {
    if(i<=j) A[j*(j-1)/2+i-1]=x;
}
int getUpper(int A[], int n, int i, int j) {
    if(i<=j) return A[j*(j-1)/2+i-1];
    return 0;
}
void displayUpper(int A[], int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<getUpper(A,n,i,j)<<" ";
        }
        cout<<endl;
    }
}

// Symmetric Matrix
void setSym(int A[], int n, int i, int j, int x) {
    if(i>=j) A[i*(i-1)/2+j-1]=x;
    else A[j*(j-1)/2+i-1]=x;
}
int getSym(int A[], int n, int i, int j) {
    if(i>=j) return A[i*(i-1)/2+j-1];
    return A[j*(j-1)/2+i-1];
}
void displaySym(int A[], int n) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cout<<getSym(A,n,i,j)<<" ";
        }
        cout<<endl;
    }
}

// Main
int main() {
    int n=4;

    cout<<"Diagonal Matrix:\n";
    int D[10]={0};
    setDiagonal(D,n,1,1,5);
    setDiagonal(D,n,2,2,8);
    setDiagonal(D,n,3,3,9);
    setDiagonal(D,n,4,4,12);
    displayDiagonal(D,n);

    cout<<"\nTri-diagonal Matrix:\n";
    int T[50]={0};
    setTri(T,n,1,1,4);
    setTri(T,n,2,1,1); setTri(T,n,2,2,5); setTri(T,n,2,3,2);
    setTri(T,n,3,2,3); setTri(T,n,3,3,6); setTri(T,n,3,4,7);
    setTri(T,n,4,3,8); setTri(T,n,4,4,9);
    displayTri(T,n);

    cout<<"\nLower Triangular Matrix:\n";
    int L[50]={0};
    setLower(L,n,1,1,5);
    setLower(L,n,2,1,8); setLower(L,n,2,2,9);
    setLower(L,n,3,1,2); setLower(L,n,3,2,4); setLower(L,n,3,3,7);
    setLower(L,n,4,1,1); setLower(L,n,4,2,3); setLower(L,n,4,3,6); setLower(L,n,4,4,10);
    displayLower(L,n);

    cout<<"\nUpper Triangular Matrix:\n";
    int U[50]={0};
    setUpper(U,n,1,1,5); setUpper(U,n,1,2,8); setUpper(U,n,1,3,2); setUpper(U,n,1,4,1);
    setUpper(U,n,2,2,4); setUpper(U,n,2,3,3); setUpper(U,n,2,4,6);
    setUpper(U,n,3,3,7); setUpper(U,n,3,4,9);
    setUpper(U,n,4,4,10);
    displayUpper(U,n);

    cout<<"\nSymmetric Matrix:\n";
    int S[50]={0};
    setSym(S,n,1,1,1); setSym(S,n,2,1,2); setSym(S,n,2,2,3);
    setSym(S,n,3,1,4); setSym(S,n,3,2,5); setSym(S,n,3,3,6);
    setSym(S,n,4,1,7); setSym(S,n,4,2,8); setSym(S,n,4,3,9); setSym(S,n,4,4,10);
    displaySym(S,n);

    return 0;
}