#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

struct Stack
{
    int info;
    Stack* next;
};

Stack* pb(int info, Stack* p)
{
    Stack* t = new Stack;
    t->info = info;
    t->next = p;
    return t;
}

void view(Stack* p)
{
    while(p != NULL){
        cout << p->info << endl;
        p = p->next;
    }
}

void Del_All(Stack *p)
{
    while(p != NULL){
        Stack *t = p;
        p = p -> next;
        delete t;
    };
}

int __min(Stack *p)
{
    int Min = p->info;
    while(p != NULL){
        Min = min(Min, p->info);
        p = p->next;
    }
    return Min;
}

int main()
{
    char code, bcode;
    int len, i, in;
    Stack* begin = NULL;
    srand (time(NULL));

    while(true){
    system("cls");
    cout << "Enter a code:\nCreate - 1\nAdd - 2\nView - 3\nTask - 4\nEXIT - 0" << endl;
    cin >> code;
    switch(code)
    {
        case '1':
            if (begin != NULL){
                cout << "Memory Free!" << endl;
                Del_All(begin);
                begin = NULL;
                _getch();
                break;
            }
            cout << "Enter a code:\nrandom - 1\nmanual - 2" << endl;
            cin >> bcode;
            cout << "Input a length: ";
            cin >> len;

            switch(bcode){
                case '1':
                    for (i = 0; i < len; i++)
                    {
                        in = (rand() % 100 + 1);
                        begin = pb(in, begin);
                    }
                break;
                case '2':
                    cout << "Input elements\n";
                    for (i = 0; i < len; i++)
                    {
                        cin >> in;
                        begin = pb(in, begin);
                    }
                break;
            }
        break;
        case '2':
            cout << "Input a length: ";
            cin >> len;
            cout << "Input elements" << endl;
            for (i = 0; i < len; i++)
            {
                cin >> in;
                begin = pb(in, begin);
            }
        break;
        case '3':
            if (begin == NULL)
            {
                cout << "Stack is empty!" << endl;
                _getch();
                break;
            }
            view(begin);
            _getch();
        break;
        case '4':
        {
            if (begin == NULL)
            {
                cout << "Stack is empty!" << endl;
                _getch();
                break;
            }
            int Min = __min(begin);
            Stack *_begin = begin;
            Stack *res = NULL;
            if (begin->info == Min)
            {
                cout << "Stack's top is a minimum\n";
                _getch();
                break;
            }
            while(_begin != NULL){

                res = pb(_begin->info, res);
                if (_begin->info == Min)
                    break;
                _begin = _begin->next;
            }
            view(res);
            _getch();
        }
        break;
        case '0':
            if (begin != NULL)
                Del_All(begin);
        return 0;

    }
    }
}
