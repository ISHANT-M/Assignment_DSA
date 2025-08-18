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

