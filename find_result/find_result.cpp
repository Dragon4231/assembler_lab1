#include <iostream>
using namespace std;
int getResult(int a, int b, int c, int x) {
    int result;
    int temp = -1;
      __asm {
        mov eax,2
        imul a
        imul c
        mov ebx,eax
        mov eax,b
        cdq
        div x
        imul temp
        add eax,ebx
        sub eax,12
        mov ebx,eax
        mov eax,c
        imul x
        add eax,a
        mov ecx,eax
        mov eax,ebx
        mov ebx,ecx
        cdq
        idiv ebx
        mov result,eax
    } 
    return result;
}

int main()
{
    setlocale(LC_ALL, "ru");
    int a, b, c, x;
    cout << "Введите четыре значения : a, b, c, x. Для нахождения выражения (2ac-b/x-12)/(cx+a)." << endl;
    cout << "Значение a : ";
    cin >> a;
    cout << "Значение b : ";
    cin >> b;
    cout << "Значение c : ";
    cin >> c;
    cout << "Значение x : ";
    cin >> x;
    cout << "result (2ac-b/x-12 )/(cx + a) : " << getResult(a, b, c, x);
}