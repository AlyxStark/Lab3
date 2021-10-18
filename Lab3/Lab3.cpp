#include <algorithm>
#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;
int main()
{
    setlocale(0, "");
       SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        int i = 0, k, a=0;
        char ABC[] = { 'А','Б','В','Г','Д','Е','Ж','З','И',
                    'Й','К','Л','М','Н','О','П','Р','С',
                    'Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ',
                    'Ы','Ь','Э','Ю','Я','_','.',',','0',
                    '1','2','3','4','5','6','7','8','9' };
        char msg[80];
        cout << "Введите сообщение: " << endl;
        cin.getline(msg, 80);
        cout << "\nВведите сдвиг:" << endl;
        cin >> k;
        cout << endl;
        cout << "Введите 1 для шифровки или 2 для расшифровки:"<<endl;
        cin >> a;
        if (a == 1) {
            char* begin = ABC;
            char* end = ABC + sizeof(ABC);
            for (; msg[i]; ++i)
            {
                char* ch = find(begin, end, msg[i]);
                if (ch != end) msg[i] = *(begin + (ch - begin + k) % sizeof(ABC));
            }
            cout << "Полученное зашифрованное сообщение: " << endl;
            cout << msg << endl;
        }
        else {
            char* begin = ABC;
            char* end = ABC + sizeof(ABC);
            for (; msg[i]; ++i)
            {
                char* ch = find(begin, end, msg[i]);
                if (ch != end) msg[i] = *(begin + (ch - begin - k) % sizeof(ABC));
            }
            cout << "Полученное расшифрованное сообщение: " << endl;
            cout << msg << endl;
        }
        return 0;
    }