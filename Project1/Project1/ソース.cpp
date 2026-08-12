#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int dice1 = 0;
    int dice2 = 0;
    int sum;
    int choice;
    bool board[10] = { false };
    srand(time(NULL));

    while (true)
    {
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        sum = dice1 + dice2;

        cout << "\n===== プレイヤー =====" << endl;
        cout << "サイコロ：" << dice1 << " " << dice2 << endl;
        cout << "選べる数字：" << dice1 << " " << dice2 << " " << sum << endl;


        while (true)
        {
            cout << "数字を選んでください：";
            cin >> choice;

            if ((choice == dice1 || choice == dice2 || choice == sum) &&
                choice >= 1 && choice <= 9 &&
                board[choice] == false)
            {
                board[choice] = true;
                break;
            }
            else
            {
                cout << "その数字は選べません。もう一度入力してください。" << endl;
            }
        }
        bool all = true;
        for (int i = 1; i <= 9; i++)
        {
            if (!board[i])
            {
                all = false;
                break;
            }
        }

        if (all)
        {
            cout << "全てのマスが埋まりました！" << endl;
            cout << "プレイヤーの勝ち！" << endl;
            break;
        }

        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        sum = dice1 + dice2;

        cout << "\n===== CPU =====" << endl;
        cout << "サイコロ：" << dice1 << " " << dice2 << endl;

        int select[3] = { dice1, dice2, sum };

        bool take = false;

        for (int i = 0; i < 3; i++)
        {
            if (select[i] >= 1 && select[i] <= 9 && board[select[i]] == false)
            {
                board[select[i]] = true;
                cout << "CPUは " << select[i] << " を取りました。" << endl;
                take = true;
                break;
            }
        }

        if (!take)
        {
            cout << "CPUは取れるマスがありません。" << endl;
            cout << "プレイヤーの勝ち！" << endl;
            break;
        }

        all = true;
        for (int i = 1; i <= 9; i++)
        {
            if (!board[i])
            {
                all = false;
                break;
            }
        }

        if (all)
        {
            cout << "全てのマスが埋まりました！" << endl;
            cout << "CPUの勝ち！" << endl;
            break;
        }
    }

    return 0;
}