#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //変数宣言
    int answer = -1;
    int question;
    //変数の初期化
    int count = 0;
    //ランダム関数
    srand((unsigned int)time(nullptr));

    question = rand() % 101;

    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;

    while (question != answer)
    {
        count++;

        while (true)
        {
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer;
            //入力チェック
            if (answer < 0 || answer > 100)
            {
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                break;
            }
        }

        if (question > answer)
        {
            cout << "もっと大きい数字です。" << endl;
        }
        else if (question < answer)
        {
            cout << "もっと小さい数字です。" << endl;
        }
    }
    //結果を表示
    cout << endl;
    cout << "おめでとうございます！正解です！" << endl;
    cout << "正解：" << answer << endl;
    cout << count << "回目で当てることができました。" << endl;

    return 0;
}